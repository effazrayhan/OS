#include<iostream>
#include<condition_variable>
#include<mutex>
using namespace std;

int readerCount = 0;
bool isWriterActive = false;
condition_variable canWrite;
mutex mtx;

void ReaderEnter(int id){
    unique_lock<mutex> lock(mtx);
    while(isWriterActive){
        canWrite.wait(lock);
    }
    readerCount++;
    cout << "Reader " << id << " enters. Total readers : " << readerCount << endl;
}
void ReaderExit(int id){
    unique_lock<mutex> lock(mtx);
    readerCount--;
    cout << "Reader " << id << " exits. Total readers : " << readerCount << endl;
    if(readerCount == 0)
        canWrite.notify_one();
}
void WriterEnter(int id){
    unique_lock<mutex> lock(mtx);
    if(isWriterActive || readerCount > 0)
        canWrite.wait(lock);
    isWriterActive = true;
    cout << "Writer " << id << " enters..." << endl;
}
void WriterExit(int id){
    unique_lock<mutex> lock(mtx);
    isWriterActive = false;
    cout << "Writer " << id << " exits..." << endl;
    canWrite.notify_all();
}
int main(){
    ReaderEnter(1);
    ReaderExit(1);
    WriterEnter(1);
    WriterExit(1);
    ReaderEnter(2);
    ReaderExit(2);
    WriterEnter(2);
    WriterExit(2);
    ReaderEnter(3);
    ReaderExit(3);
}