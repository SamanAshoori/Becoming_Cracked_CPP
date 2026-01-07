//God Damn it here I go do doing babys first coding app.
#include <iostream>
#include <fstream>

void writeFile();

int main(){
    writeFile();
    return 0;
}

void writeFile(std::string input){
    std::ofstream test("test.txt");
    test << "This is a test";
    test.close();
}