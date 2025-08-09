#include <iostream>
#include <semaphore.h>
using namespace std;

int readCount = 0;
sem_t mutex;
sem_t writeLock;

void write(int id)
{
    cout << "Writer " << id << " is trying to write..." << endl;
    sem_wait(&mutex);
    cout << "Writer " << id << " is writing..." << endl;
    cout << "Writer " << id << " finished writing..!" << endl;
    sem_post(&mutex);
}
void read(int id)
{
    cout << "Reader " << id << " is trying to read..." << endl;
    sem_wait(&mutex);
    readCount++;
    if (readCount == 1)
    {
        sem_wait(&writeLock);
    }
    sem_post(&mutex);
    cout << "Reader " << id << " is reading..." << endl;
    cout << "Reader " << id << " finished reading..!" << endl;
    sem_wait(&mutex);
    readCount--;
    if (readCount == 0)
    {
        sem_post(&writeLock);
    }
    sem_post(&mutex);
}
int main()
{
    sem_init(&mutex, 0, 1);
    sem_init(&writeLock, 0, 1);
    read(1);
    write(1);
    read(2);
    write(2);
    read(3);
    sem_destroy(&mutex);
    sem_destroy(&writeLock);
}