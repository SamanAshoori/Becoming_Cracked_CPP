#include <iostream>
using namespace std;

void swap_by_ref(int &a, int &b) //&a means the function gets passed the memory adress of a so we pass in memory adress
{
	//because you cannot change the physical location in memory you have to change the value of the variable
    int temp = a;
	//value of a is now b
    a = b;
	//value of b is now a
    b = temp;
}
void swap_by_ptr(int *a, int *b) //*a means the function gets passed the pointer
{
    int temp = *a;
    *a = *b;
    *b = temp;
	//pointers can be null so you dont have to declare them
}
void sort_three_ints(int &a,int &b,int &c)
{
	int min;
	int max;
	int temp;

	a = min;
	if (a > b){ swap_by_ref(a,b);}
	
}

void swap_by_ptr(int *a, int *b);
void swap_by_ref(int &a, int &b);

int main(){
	int x; //Declaring a value for x
	int y;
	int z;
	int *A;  //Declaring the pointer
	int *B;
	int *C;

	//store memory address of value x in memory address A
	A = &x;
	B = &y;
	C = &z;

	cout << "Enter a integer then press enter (three times please)\n";
	cin >> x;
	cin >> y;
	cin >> z;
	cout << "========================================== \n";

	cout << x << ' ' << y << z << '\n';
    cout << *A <<" is the value of the address A.\n";
    cout << *B <<" is the value of the address B.\n";
	cout << *C <<" is the value of the address C.\n";
	cout << "========================================== \n";
	//Break to make console output easier to see

	swap_by_ref(x,y);
	//Checks to see if the swaps worked
	cout << *A <<" is the value of the address A.\n";
	cout << *B <<" is the value of the address B.\n";
	cout << *C <<" is the value of the address C.\n";

	return 0;
}

