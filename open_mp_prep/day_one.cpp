#include <iostream>

int main(){
    int arr[100];

    for(int i = 0; i < 100;i++){
        arr[i] = i;
        std::cout << arr[i] << std::endl;
    }
    return 0;
}