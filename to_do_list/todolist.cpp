#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <ctime> // Required for time_t

//Class Definition for task
class Task {
public:
    std::string description;
    bool completed;
    std::chrono::system_clock::time_point creationTime;
    std::chrono::system_clock::time_point dueDate; 

    // Constructors
    Task(std::string desc);
    Task(std::string desc, std::chrono::system_clock::time_point due);
    
    // Method
    void markCompleted();
};

//class construction
Task::Task(std::string desc) 
    : description(desc), completed(false), creationTime(std::chrono::system_clock::now()) {}

Task::Task(std::string desc, std::chrono::system_clock::time_point due) 
    : description(desc), completed(false), creationTime(std::chrono::system_clock::now()), dueDate(due) {}

void Task::markCompleted() {
    completed = true;
}


//main.cpp
void writeFile(std::string input); // Function Prototype

int main(){
    // Create the test file first
    writeFile("Hello World! + Saman + Build Test + New Line") ;
    std::cout << "File Created" << std::endl; // Used std::endl to force print

    std::ifstream inputFile("test.txt");
    if(!inputFile){
        std::cerr << "Error opening file" << std::endl;
        return 1; 
    }

    std::string word;
    while (inputFile >> word) {
        std::cout << word << '\n'; 
    }
    inputFile.close();

    std::cout << "---------------------------" << std::endl;

    // Test the Task class
    Task task1("Grocery Shopping");
    std::time_t task1Time = std::chrono::system_clock::to_time_t(task1.creationTime);
    std::cout << "Task Description: " << task1.description << std::endl;
    std::cout << "Task Completed: " << task1.completed << std::endl;
    std::cout << "Task Creation Time: " << std::ctime(&task1Time); // ctime converts time_t to string automatically

    std::cout << "---------------------------" << std::endl;

    Task task2("Pay Bills", std::chrono::system_clock::now() + std::chrono::hours(24));
    std::time_t task2Time = std::chrono::system_clock::to_time_t(task2.creationTime);
    std::time_t task2Due = std::chrono::system_clock::to_time_t(task2.dueDate);

    std::cout << "Task Description: " << task2.description << std::endl;
    std::cout << "Task Completed: " << task2.completed << std::endl;
    std::cout << "Task Creation Time: " << std::ctime(&task2Time);
    std::cout << "Task Due Date: " << std::ctime(&task2Due);

    task1.markCompleted();
    std::cout << "Task1 Completed status updated to: " << task1.completed << std::endl;
    return 0;
}

void writeFile(std::string input){
    std::ofstream test("test.txt");
    test << input;
    test.close();
}