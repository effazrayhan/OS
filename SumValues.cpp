#include<iostream>
#include<pthread.h>
using namespace std;

const int SIZE = 1000;
const int THREADS = 10;

int values[SIZE];
long long partialSum[THREADS];

void *add(void *arg){
	int id = *(int *)arg;
	int chunk = SIZE / THREADS;
	int from = id * chunk;
	int to = from + chunk;
	if (id == THREADS - 1) to = SIZE;
	
	partialSum[id] = 0;
	for(int i = from ; i < to ; i++){
		partialSum[id] += values[i];
	}
	return 0;
}

int main(){
	for(int i = 0 ; i < SIZE ; i++){
		values[i] = 1;
	}
	pthread_t t[THREADS];
	int id[THREADS];
	
	for(int i = 0 ; i < THREADS ; i++){
		id[i] = i;
        	pthread_create(&t[i], 0, add, &id[i]);
	}
	int sum = 0;
	for (int i = 0; i < THREADS; i++){
        	pthread_join(t[i], 0);
        	sum += partialSum[i];
        }
	cout << "Sum = " << sum << endl;
}
