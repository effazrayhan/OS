#include<bits/stdc++.h>
using namespace std;
const int MAXIMUM = 20;
int priority[ MAXIMUM];
int burst[ MAXIMUM];
int waiting[ MAXIMUM];
int turnAround[ MAXIMUM];
int main(){
    int task;
    cin >> task;
    int i = 0;
    string ntg;
    while(i < task){
        cin >> ntg >> priority[i] >> burst[i];
        i++;
    }

    waiting[0] = 0;
    for(i = 1 ; i < task ; i++) waiting[i] = waiting[i - 1] + burst[i - 1];
    for(i = 0 ; i < task ; i++) turnAround[i] = waiting[i] + burst[i];
    cout << "\nProcess\tWT\tTT" << endl;\
    int sum  = 0;
    int wt = 0;
    for(i = 0 ; i < task ; i++){
        cout << "T" << i + 1 << "\t" << waiting[i]<< "\t" << turnAround[i] << endl;
        sum += turnAround[i];
        wt += waiting[i];
    }
    cout << "Average TurnAround Time : " << sum / task << endl;
    cout << "Average Waiting Time : " << wt / task << endl;
}