#include<bits/stdc++.h>
using namespace std;
int num = 0;
mutex mx;
void inc(){
    mx.lock();
    for(int i = 0 ;i < 100000 ; i++)
        num++;
    mx.unlock();
}
int main(){
    
    thread t1(inc);
    thread t2(inc);
    
    t1.join();
    t2.join();

    cout << "Value : " << num << endl;
}