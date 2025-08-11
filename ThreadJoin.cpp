#include<iostream>
#include<thread>

using namespace std;

int a[2];

void valueAssign(int i , int j ){
	a[0] = i;
	a[1] = j;
}

void sum(){
	cout << "Sum is: " << a[0] + a[1] << endl;
}

int main(){
	thread pushValues(valueAssign , 12 , 13);
	pushValues.join(); 
	thread showSum(sum);
	showSum.join();

	cout << "Back to Main" << endl;
}

