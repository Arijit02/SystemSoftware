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
};
class FCFS : public ProcessScheduling
{
    static bool sortIncreasingArrivalTime(Process &p1, Process &p2)
    {
        return (p1.arrivalTime < p2.arrivalTime);
    }

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


int main()
{

    vector<Process> processList={{1, 0, 5},{2, 3, 9},{3, 6, 6}};
   
    FCFS f;
    f.run(processList);
    
    return 0;
}