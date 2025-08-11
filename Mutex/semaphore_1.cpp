#include<iostream>
#include<chrono>
#include<thread>
#include<semaphore>
using namespace std;
counting_semaphore <2> semaphore(2);
void worker(int id){
    cout << "Thread " << id << " Waiting to enter!" << endl;
    semaphore.acquire();
    cout << "Thread " << id << " Entered critical zone" << endl;
    // cout << " SEC 0 "<< id << "\n";
    // this_thread::sleep_for(chrono::seconds(1));
    // cout << " SEC 1 "<< id << "\n";
    this_thread::sleep_for(chrono::seconds(2));
    // cout << " SEC 2 "<< id << "\n";
    cout << "Thread " << id << " Releasing !" << endl;
    semaphore.release();
}
int main(){
    thread t1(worker,1);
    thread t2(worker,2);
    thread t3(worker,3);

    t1.join();
    t2.join();
    t3.join();
}