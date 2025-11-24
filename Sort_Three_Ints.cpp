#include <iostream>
using namespace std;

int main(){
	int a = 5; //Declaring a value for a
	int *B;  //Declaring the pointer

	B = &a;

	cout << a <<" is the value of the variable a."<<endl;
        cout << &a << " is the address of a.\n\n";
	cout << B <<" is the address of the variable.\n";
	cout << *B <<" is the value of B.\n";
	
	return 0;
}