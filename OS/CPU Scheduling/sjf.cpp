#include <bits/stdc++.h>
using namespace std;

#define mytype pair<int, int>

float findAvg(vector<int> arr)
{
    float sum = 0;
    for (auto a : arr)
        sum += a;
    return sum / arr.size();
}

void SJF(vector<int> &p, vector<int> &bt, vector<int> &at)
{
    int n = p.size(), time = INT_MAX;
    vector<int> wt(n, 0), ta(n, 0), ct(n, 0);
    priority_queue<mytype, vector<mytype>, greater<mytype>> wq;
    for (auto i = 0; i < n; i++)
        time = min(at[i], time);
    for (auto i = 0; i < n; i++)
        if (at[i] == time)
            wq.push({bt[i], p[i]});
    while (!wq.empty())
    {
        mytype proc = wq.top();
        wq.pop();
        ct[proc.second - 1] = time + proc.first;
        time = ct[proc.second - 1];
        for (auto i = 0; i < n; i++)
            if (at[i] <= time && at[i] > time - proc.first)
                wq.push({bt[i], p[i]});
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
    vector<int> process = {1, 2, 3, 4, 5};
    vector<int> burst_time = {7, 5, 1, 2, 8};
    vector<int> arrival_time = {1, 2, 3, 4, 5};
    SJF(process, burst_time, arrival_time);
    return 0;
}
