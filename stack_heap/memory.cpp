// memory.cpp
#include "memory.hpp"
#include <iostream> 
#include <memory> 

void demo_stack_heap() {
    int stack_value = 42;          // stack
    //Using unique pointer now for heap allocation
	std::unique_ptr<int> heap_value = std::make_unique<int>(42); // heap

    std::cout << "Stack value is: " << stack_value
              << " Heap value is: " << *heap_value << '\n';

    //delete heap_value; No longer needed
}