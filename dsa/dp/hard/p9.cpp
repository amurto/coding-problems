// https://leetcode.com/problems/maximum-profit-in-job-scheduling/
// Maximum Profit in Job Scheduling

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

class Job
{
public:
    int start, end, profit;
    Job() {}
    Job(int start, int end, int profit) : start(start), end(end), profit(profit) {}
    bool operator<(const Job &j) const
    {
        if (start == j.start)
            return (end <= j.end);
        else
            return (start <= j.start);
    }
};

int maxProfit(vector<int> &dp, vector<Job> &jobs, int cur)
{
    if (cur == jobs.size())
        return 0;
    if (dp[cur] == -1)
    {
        int i;
        for (i = cur + 1; i < jobs.size(); i++)
            if (jobs[i].start >= jobs[cur].end)
                break;
        dp[cur] = max(jobs[cur].profit + maxProfit(dp, jobs, i), maxProfit(dp, jobs, cur + 1));
    }
    return dp[cur];
}
int jobScheduling(vector<int> &startTime, vector<int> &endTime, vector<int> &profit)
{
    int n = startTime.size();
    vector<Job> jobs(n);
    for (int i = 0; i < n; i++)
        jobs[i] = Job(startTime[i], endTime[i], profit[i]);

    sort(jobs.begin(), jobs.end());
    vector<int> dp(n, -1);
    return maxProfit(dp, jobs, 0);
    return 1;
}

int main()
{
    int n = 4;
    vector<int> startTime = {1, 2, 2, 3}, endTime = {2, 5, 3, 4}, profit = {3, 4, 1, 2};
    cout << jobScheduling(startTime, endTime, profit) << "\n";
    return 0;
}