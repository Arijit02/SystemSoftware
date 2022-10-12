#include <bits/stdc++.h>
using namespace std;
class Process
{
public:
    int pID, arrivalTime, burstTime, completionTime, turnAroundTime, waitingTime;
    Process(int pID, int arrivalTime, int burstTime)
    {
        this->pID = pID;
        this->arrivalTime = arrivalTime;
        this->burstTime = burstTime;
        this->completionTime = INT_MIN;
        this->turnAroundTime = INT_MIN;
        this->waitingTime = INT_MIN;
    }
    void diplay()
    {
        cout << "Process ID=" << pID << ", arrival time=" << arrivalTime << ", burst time=" << burstTime << ", completion time=" << completionTime << ", turnAround time=" << turnAroundTime << ", waiting time=" << waitingTime << endl;
    }
};
class ProcessScheduling
{
    float findAvgTAT(const vector<Process> &processList)
    {
        float sum = 0;
        for (auto p : processList)
            sum += p.turnAroundTime;
        return sum / processList.size();
    }
    float findAvgWT(const vector<Process> &processList)
    {
        float sum = 0;
        for (auto p : processList)
            sum += p.waitingTime;
        return sum / processList.size();
    }

public:
    void display(const vector<Process> &processList)
    {
        cout << "Process\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n";
        for (auto i = 0; i < processList.size(); i++)
        {
            cout << processList[i].pID << "\t";
            cout << processList[i].arrivalTime << "\t";
            cout << processList[i].burstTime << "\t";
            cout << processList[i].completionTime << "\t";
            cout << processList[i].turnAroundTime << "\t";
            cout << processList[i].waitingTime << "\n";
        }
        cout << "Average Turnaround Time = " << findAvgTAT(processList) << endl;
        cout << "Average Waiting Time = " << findAvgWT(processList) << endl;
    }
    static bool sortIncreasingArrivalTime(Process &p1, Process &p2)
    {
        return (p1.arrivalTime < p2.arrivalTime);
    }
};
class FCFS : public ProcessScheduling
{
public:
    void run(vector<Process> processList)
    {
        sort(processList.begin(), processList.end(), sortIncreasingArrivalTime);
        int time = 0;
        for (int i = 0; i < processList.size(); i++)
        {
            processList[i].completionTime = max(processList[i].arrivalTime, time) + processList[i].burstTime;
            processList[i].turnAroundTime = processList[i].completionTime - processList[i].arrivalTime;
            processList[i].waitingTime = processList[i].turnAroundTime - processList[i].burstTime;
            time = processList[i].completionTime;
        }
        display(processList);
    }
};

class SJF : public ProcessScheduling
{
public:
    void run(vector<Process> processList)
    {
        sort(processList.begin(), processList.end(), sortIncreasingArrivalTime);

        int time = processList[0].arrivalTime;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> waitingQ;//Min heap denoting queue of already arrived processes. Each element of the queue is a pair denoting <burstTime, index of process in processList array>

        waitingQ.push({processList[0].burstTime, 0});
        while (!waitingQ.empty())
        {
            pair<int, int> currProcess = waitingQ.top();
            waitingQ.pop();
            processList[currProcess.second].completionTime = time + currProcess.first;
            time = processList[currProcess.second].completionTime;
            for (int i = currProcess.second + 1; i < processList.size(); i++)
            {
                if (processList[i].arrivalTime <= time && processList[i].arrivalTime > time - currProcess.first)
                    waitingQ.push({processList[i].burstTime, i});
                else
                    break;
            }
        }
        for (auto i = 0; i < processList.size(); i++)
        {
            processList[i].turnAroundTime = processList[i].completionTime - processList[i].arrivalTime;
            processList[i].waitingTime = processList[i].turnAroundTime - processList[i].burstTime;
        }
        display(processList);
    }
};

int main()
{

    vector<Process> processList = {{1, 0, 5}, {2, 3, 9}, {3, 6, 6}};

    FCFS f;
    f.run(processList);

    vector<Process> processList2 = {{1, 1, 7}, {2, 2, 5}, {3, 3, 1}, {4, 4, 2}, {5, 5, 8}};

    SJF s;
    s.run(processList2);

    return 0;
}