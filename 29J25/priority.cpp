#include<bits/stdc++.h>
using namespace std;
const int MAXIMUM = 20;
int priority[ MAXIMUM];
int burst[ MAXIMUM];
int waiting[ MAXIMUM];
int turnAround[ MAXIMUM];
struct Process{
    int pid , bt , pr;
};
bool compara(Process a , Process b){
    return a.pr > b.pr;
}
int main(){
    int task;
    cin >> task;
    Process process[task];
    int i = 0;
    string ntg;
    while(i < task){
        process[i].pid = i + 1;
        cin >> ntg >> process[i].pr >> process[i].bt;
        i++;
    }
    sort(process , process + task , compara);
    waiting[0] = 0;
    for(i = 1 ; i < task ; i++) waiting[i] = waiting[i - 1] + process[i - 1].bt;
    for(i = 0 ; i < task ; i++) turnAround[i] = waiting[i] + process[i].bt;
    cout << "\nProcess\tWT\tTT" << endl;
    int sum = 0;
    int wt = 0;
    for(i = 0 ; i < task ; i++){
        cout << "T" << process[i].pid << "\t" << waiting[i]<< "\t" << turnAround[i] << endl;
        sum += turnAround[i];
        wt += waiting[i];
    }
    cout << "Average TurnAround Time : " << sum / task << endl;
    cout << "Average Waiting Time : " << wt / task << endl;
}