#include <bits/stdc++.h>
using namespace std;

float findAvg(vector<int> arr)
{
    float sum = 0;
    for (auto a : arr)
        sum += a;
    return sum / arr.size();
}

void RR(vector<int> p, vector<int> bt, vector<int> at, int q)
{
    vector<int> rem_bt = bt;
    int n = p.size(), time = INT_MAX;
    vector<int> wt(n, 0), ta(n, 0), ct(n, 0);
    queue<int> wq;
    for (auto i = 0; i < n; i++)
        time = min(at[i], time);
    for (auto i = 0; i < n; i++)
        if (at[i] == time)
            wq.push(p[i]);
    while (!wq.empty())
    {
        int proc = wq.front();
        wq.pop();
        int runtime = min(rem_bt[proc - 1], q);
        rem_bt[proc - 1] -= runtime;
        time += runtime;
        for (auto i = 0; i < n; i++)
            if (at[i] <= time && at[i] > time - runtime)
                wq.push(p[i]);
        if (rem_bt[proc - 1])
            wq.push(proc);
        else
            ct[proc - 1] = time;
    }
    for (auto i = 0; i < n; i++)
    {
        ta[i] = ct[i] - at[i];
        wt[i] = ta[i] - bt[i];
    }
    cout << "Process\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time\tCompletion Time\n";
    for (auto i = 0; i < n; i++)
    {
        cout << p[i] << "\t";
        cout << bt[i] << "\t";
        cout << at[i] << "\t";
        cout << wt[i] << "\t";
        cout << ta[i] << "\t";
        cout << ct[i] << "\n";
    }
    cout << "Average Turnaround Time = " << findAvg(ta) << endl;
    cout << "Average Waiting Time = " << findAvg(wt) << endl;
}

int main()
{
    vector<int> process = {1, 2, 3, 4};
    vector<int> burst_time = {5, 4, 2, 1};
    vector<int> arrival_time = {0, 1, 2, 3};
    int time_quantum = 2;
    RR(process, burst_time, arrival_time, time_quantum);
    return 0;
}