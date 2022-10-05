#include <bits/stdc++.h>
using namespace std;

void isSafe(vector<int> &processes, vector<int> &available, vector<vector<int>> &max_need,
            vector<vector<int>> &allotted)
{
    int res_type = available.size(), proc_no = processes.size();
    vector<int> safe_sequence, finish(proc_no, 0);
    vector<vector<int>> need(proc_no, vector<int>(res_type, 0));
    for (auto i = 0; i < proc_no; i++)
        for (auto j = 0; j < res_type; j++)
            need[i][j] = max_need[i][j] - allotted[i][j];

    for (auto k = 0; k < proc_no; k++)
    {
        int flag1 = 1;
        for (auto i = 0; i < proc_no; i++)
            if (finish[i] == 0)
            {
                int flag2 = 1;
                for (auto j = 0; j < res_type; j++)
                    if (need[i][j] > available[j])
                    {
                        flag2 = 0;
                        break;
                    }
                if (flag2)
                {
                    for (auto j = 0; j < res_type; j++)
                        available[j] += allotted[i][j];
                    finish[i] = 1;
                    safe_sequence.push_back(processes[i]);
                    flag1 = 0;
                }
            }
        if (flag1)
            break;
    }
    bool is_safe = true;
    for (auto f : finish)
        if (f == 0)
        {
            is_safe = false;
            break;
        }
    if (is_safe)
    {
        cout << "System is in safe state.\n";
        cout << "Safe sequence is: ";
        for (auto ss : safe_sequence)
            cout << ss << " ";
        cout << endl;
    }
    else
        cout << "System is in unsafe state.\n";
}

int main()
{
    vector<int> processes = {0, 1, 2, 3, 4};
    vector<int> available = {3, 3, 2};
    vector<vector<int>> max_need = {{7, 5, 3},
                                    {3, 2, 2},
                                    {9, 0, 2},
                                    {2, 2, 2},
                                    {4, 3, 3}};
    vector<vector<int>> allotted = {{0, 1, 0},
                                    {2, 0, 0},
                                    {3, 0, 2},
                                    {2, 1, 1},
                                    {0, 0, 2}};
    isSafe(processes, available, max_need, allotted);
    return 0;
}
