#include<bits/stdc++.h>
using namespace std;

float findAvg(vector<int> arr)
{
    float sum = 0;
    for(auto a: arr)
        sum += a;
    return sum / arr.size();
}

void FCFS(vector<int> p, vector<int> bt, vector<int> at)
{
    int n = p.size(), time = 0;
    vector<int> wt(n, 0), ta(n, 0), ct(n, 0);
    for(auto i = 0; i < n; i++)
    {   
        ct[i] = max(at[i], time) + bt[i];
        ta[i] = ct[i] - at[i];
        wt[i] = ta[i] - bt[i];
        time = ct[i]; 
    }
    cout << "Process\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time\tCompletion Time\n";
    for(auto i = 0; i < n; i++)
    {
        cout << p[i] <<"\t";
        cout << bt[i] <<"\t";
        cout << at[i] <<"\t";
        cout << wt[i] <<"\t";
        cout << ta[i] <<"\t";
        cout << ct[i] <<"\n";
    }
    cout << "Average Turnaround Time = " << findAvg(ta) << endl;
    cout << "Average Waiting Time = " << findAvg(wt) << endl;
}

int main()
{
    vector<int> process = {1, 2, 3};
    vector<int> burst_time = {5, 9, 6};
    vector<int> arrival_time = {0, 3, 6};
    FCFS(process, burst_time, arrival_time);
    return 0;
}