#include <bits/stdc++.h>
using namespace std;

int minimumEffort(vector<vector<int>> &tasks)
{
    int minus = 0, diff = INT_MAX, energy = 0;
    for (int i = 0; i < tasks.size(); i++)
    {
        minus += tasks[i][0];
        diff = min(diff, tasks[i][1] - tasks[i][0]);
        energy = max(energy, tasks[i][1]);
    }
    return max(minus + diff, energy);
}

int main()
{
    vector<vector<int>> tasks = {{1, 7}, {2, 8}, {3, 9}, {4, 10}, {5, 11}, {6, 12}};
    cout << minimumEffort(tasks) << "\n";
    return 0;
}