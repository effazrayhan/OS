#include <bits/stdc++.h>
using namespace std;
struct process
{
    int id;
    vector<int> allocation;
    vector<int> requirement;
    process(int id , const vector<int> &a, const vector<int> &r)
        : id(id),allocation(a), requirement(r) {}
};
int n;
int rowSize = 0;
vector<process> result;
queue<process> processes;
// Take input - number of process /n max_providable /n sections + max /n  (queue)
// vector for output
// logic
// Store n and compare with size of vector
// int totalAvailable[100]{0};
vector<int> totalAvailable;
void takeInput()
{
    ifstream file("banker.txt");
    file >> n;
    file.ignore(numeric_limits<streamsize>::max(), '\n');
    string line;
    for (int i = 0; i < n; i++)
    {
        vector<int> row1, row2;
        int num;
        if (getline(file, line))
        {
            stringstream ss(line);
            int k = 0;
            while (ss >> num)
            {
                row1.push_back(num);
                if (i == 0)
                {
                    totalAvailable.push_back(num);
                    rowSize++;
                }
                else
                    totalAvailable[k++] += num;
            }
        }
        if (getline(file, line))
        {
            stringstream ss(line);
            while (ss >> num)
            {
                row2.push_back(num);
            }
        }
        process p(i,row1, row2);
        processes.push(p);
    }
    // Section Limits
    int sec_limit;
    for (int i = 0; i < rowSize; i++)
    {
        cout << "Section " << i + 1 << ": Limit -> " << endl;
        cin >> sec_limit;
        totalAvailable[i] = sec_limit - totalAvailable[i];
    }
    // for(int i : totalAvailable){
    //     cout << i << " " ;
    // }
    // cout << rowSize << endl;
}
void logic()
{
    int dlc = 0;
    while (!processes.empty())
    {
        process p = processes.front();
        processes.pop();
        // vector<int> remaining;
        bool isExecutable = true;
        int remaining_;
        for (int i = 0; i < rowSize; i++)
        {
            remaining_ = p.requirement[i] - p.allocation[i];
            if (totalAvailable[i] < remaining_)
            {
                dlc++;
                isExecutable = false;
                processes.push(p);
                break;
            }
            // remaining.push_back( p.requirement[i] - p.allocation[i] );
        }
        if (isExecutable)
        {
            for (int i = 0; i < rowSize; i++)
            {
                totalAvailable[i] += p.allocation[i];
            }
            result.push_back(p);
            dlc = 0;
        }
        if (dlc >= processes.size() && !processes.empty()){
            cout << "DeadLock Detected! " << endl;
            break;
        }
    }
    
}
void showResult(){
    for(process p : result){
        cout << p.id << " -> ";
    }
    cout << endl;
}
int main()
{
    takeInput();
    logic();
    showResult();
}
// INPUT STYLE -> number of process - allocation - requirement
// 5 
// 0 0 1
// 1 7 5
// 2 0 0
// 2 3 2
// 3 0 3
// 9 0 4
// 2 2 2
// 2 2 2
// 0 0 2
// 4 3 3
// Safe -> 12 7 13
// Unsafe -> Less(10 5 7)