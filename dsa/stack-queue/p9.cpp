// https://leetcode.com/problems/merge-intervals/
// Merge Intervals

#include <bits/stdc++.h>
using namespace std;

static bool cmp(vector<int> &a, vector<int> &b)
{
    if (a[0] == b[0])
        return (a[1] < b[1]);
    else
        return (a[0] < b[0]);
}

vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    sort(intervals.begin(), intervals.end(), cmp);
    deque<vector<int>> dq;
    vector<vector<int>> ans;
    for (vector<int> it : intervals)
    {
        int beg = it[0], end = it[1];
        while (!dq.empty() && it[0] <= dq.back().at(1))
        {
            beg = min(beg, dq.back().at(0));
            end = max(end, dq.back().at(1));
            dq.pop_back();
        }
        dq.push_back({beg, end});
    }
    while (!dq.empty())
    {
        ans.push_back(dq.back());
        dq.pop_back();
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> intervals(n, vector<int>(2));
    for (int i = 0; i < n; i++)
        cin >> intervals[i][0] >> intervals[i][1];
    vector<vector<int>> ans = merge(intervals);
    for (vector<int> it : ans)
        cout << it[0] << " " << it[1] << "\n";
    return 0;
}