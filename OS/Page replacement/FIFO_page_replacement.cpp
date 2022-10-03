#include <bits/stdc++.h>
using namespace std;
class FifoPageReplacement
{
private:
    int maxFrames;
    queue<int> frames;
    vector<int> refStr;
    unordered_map<int, bool> isPresent;

public:
    int faultCount;
    vector<queue<int>> frameSnapshots;

    FifoPageReplacement(int maxFrames, vector<int> refStr)
    {
        this->maxFrames = maxFrames;
        this->faultCount = 0;
        this->refStr = refStr;
    }

    vector<queue<int>> run()
    {

        for (int i = 0; i < refStr.size(); i++)
        {
            if (!isPresent[refStr[i]])
            {
                faultCount++;

                frames.push(refStr[i]);
                isPresent[refStr[i]] = true;

                if (frames.size() > maxFrames)
                {
                    int popped = frames.front();
                    frames.pop();
                    isPresent[popped] = false;
                }
                frameSnapshots.push_back(frames);
            }
        }
        cout << faultCount;
        return frameSnapshots;
    }
};

int main()
{
    // freopen("input.txt", "r", stdin);

    int maxFrames;
    cout << "Enter max no of frames :";
    cin >> maxFrames;

    int n;
    cout << "Enter size of reference string :";
    cin >> n;

    vector<int> refStr;
    cout << "Enter Page nos :";
    while (n--)
    {
        int ele;
        cin >> ele;
        refStr.push_back(ele);
    }

    FifoPageReplacement f1(maxFrames, refStr);
    f1.run();

    cout << "\nNo of faults: " << f1.faultCount << endl;

    cout << "Snapshots of frames vs time:\n";
    for (auto q : f1.frameSnapshots)
    {

        while (!q.empty())
        {
            cout << q.front();
            q.pop();
        }
        cout << endl;
    }

    return 0;
}