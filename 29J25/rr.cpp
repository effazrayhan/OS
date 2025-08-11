#include<bits/stdc++.h>
using namespace std;
const int MAXIMUM = 20;
int priority[ MAXIMUM];
int burst[ MAXIMUM];
int waiting[ MAXIMUM];
int turnAround[ MAXIMUM];
int roundTime[MAXIMUM];
struct Process{
    int pid , bt, pri;
};
struct Completion{
    int pid, tt;
};
bool compara(Process a , Process b){
    return a.pri > b.pri;
}
int main() {
    int task;
    cin >> task;
    int timeQ;
    cin >> timeQ;
    queue<Process> processes;
    vector<Process> pr;
    int i = 0;
    string ntg;
    
    for (i = 0; i < task; i++) {
        Process pro;
        pro.pid = i + 1;
        cin >> ntg >> pro.pri >> pro.bt;
        pr.push_back(pro);
    }
    // sort(pr.begin(), pr.end(),compara);
    for(Process p : pr){
        processes.push(p);
        burst[i++] = p.bt;
    }
    int timer = 0;
    vector<Completion> ct;
    while (!processes.empty()) {
        Process curr = processes.front();
        processes.pop();
        int idx = curr.pid - 1;
        if (curr.bt > 0) {
            if (curr.bt > timeQ) {
                timer += timeQ;
                curr.bt -= timeQ;
                processes.push(curr);
            } else {
                timer += curr.bt;
    
                Completion c;
                c.pid = curr.pid;
                c.tt = timer;
                ct.push_back(c);
            }
        }
    }

    // for(int i = 0 ; i < task ; i++){
    //     cout << completionTime[i] << endl;
    // }

    cout << "\nProcess\tTT" << endl;
    int sum = 0;
    // for (i = 0; i < task; i++) {
    //     // cout << "T" << (i + 1) << "\t" << waiting[i] << "\t" << turnAround[i] << endl;
    //     cout << "T" << (i + 1) << "\t" << completionTime[i] << endl;
    //     sum += completionTime[i];
    // }
    for(Completion c : ct){
        cout << "T" << c.pid << "\t" << c.tt << endl;
        sum += c.tt;
    }

    cout << "Average TurnAround Time : " << sum / task << endl;
}