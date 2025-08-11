#include <iostream>
using namespace std;

const int MAX = 5;
int buffer[MAX];
int roller = -1, count = 0;

void produce(int val) {
    if(count == MAX ){
	cout << "Overflow : Cannot push " << val << endl;
	return;
	}
    buffer[++roller % MAX] = val;
    cout << "produced " << val << endl;
    count++;
}

void consume() {
    if(count == 0){
    	cout << "Underflow!" << endl;
    	return;
    }
    count--;
    cout << "consumed " << buffer[count - roller%MAX] << endl;
}

void display() {
	cout << "BUffer Status : ";
    for(int i : buffer){
    	cout << i << "\t";
    }
    cout << endl;
}

int main() {
    produce(10);
    produce(20);
    produce(30);
    produce(40);
    produce(50);
    produce(60);
    display();
    consume();
    consume();
    display();
    produce(70);
    display();
    return 0;
}
