#include<bits/stdc++.h>
#include<semaphore.h>
using namespace std;
sem_t rw_mutex;
sem_t mutex;
int readers_count = 0;

