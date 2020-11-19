#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

bool cd(vector<int> &cnt, vector<int> &quantity, int cur, int q)
{
    if (q == quantity.size())
        return true;
    if (cur == cnt.size())
        return false;
    if (quantity[q] <= cnt[cur])
    {
        cnt[cur] -= quantity[q];
        if (cd(cnt, quantity, 0, q + 1))
            return true;
        cnt[cur] += quantity[q];
    }
    if (cd(cnt, quantity, cur + 1, q))
        return true;
    return false;
}

bool canDistribute(vector<int> &nums, vector<int> &quantity)
{
    int min_cnt = INT_MAX;
    vector<int> MAP(1001);
    for (int num : nums)
        MAP[num]++;
    vector<int> cnt;
    for (int i = 1; i <= 1000; i++)
        if (MAP[i] > 0)
            cnt.push_back(MAP[i]);
    sort(quantity.rbegin(), quantity.rend());
    return cd(cnt, quantity, 0, 0);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n, m;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++)
            cin >> nums[i];
        cin >> m;
        vector<int> quantity(m);
        for (int i = 0; i < m; i++)
            cin >> quantity[i];
        canDistribute(nums, quantity) ? cout << "true\n" : cout << "false\n";
    }
    return 0;
}