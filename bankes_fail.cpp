#include<bits/stdc++.h>
using namespace std;
struct process{
    int s1, s2, s3;
    int m1, m2, m3;
    process(int s1, int s2, int s3, int m1, int m2, int m3)
        : s1(s1), s2(s2), s3(s3), m1(m1), m2(m2), m3(m3) {}
};
queue<process> processes;
vector<process> result;
process capacity;
int sum_s1 = 0, sum_s2 = 0, sum_s3 = 0;
// Take input - number of process /n max_providable /n sections + max /n  (queue)
// vector for output
// logic
// Store n and compare with size of vector
void takeInput(){
    int n;
    string ss;
    ifstream file("banker.txt");
    file >> n;
    // file >> ss;
    // if(file.is_open())
    //     getline(file,ss);
    // cout << n << ' ' << ss << endl;
    int a, b, c, d, e, f;
    file >> a >> b >> c;
    capacity.m1 = a;
    capacity.m2 = b;
    capacity.m3 = c;
    while(file >> a >> b >> c >> d >> e >> f){
        process p(a,b,c,d,e,f);
        processes.push(p);
        sum_s1 += a;
        sum_s2 += b;
        sum_s3 += c;
    }
}
void logic(){
    
}
int main(){
    takeInput();
}