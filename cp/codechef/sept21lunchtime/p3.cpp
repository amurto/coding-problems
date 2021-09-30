#ifdef use_debug
#define TERMINAL
#include "headers/debug.cpp"
#else
#define d(...) 0
#endif
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int find_lis(vector<int> &arr, vector<int> &dp, vector<bool> &mark, int n)
{
    vector<int> small(n + 1, n);
    small[0] = -1;
    for (int i = 0; i < n; i++)
    {
        int low = 0, high = n - 1, v = 0;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (small[mid] <= arr[i])
            {
                v = max(v, mid);
                low = mid + 1;
            }
            else
                high = mid - 1;
        }
        dp[i] = v + 1;
        small[v + 1] = arr[i];
    }
    int mx = *max_element(dp.begin(), dp.end());
    vector<int> last(n + 1, -1);
    for (int i = n - 1; i >= 0; i--)
    {
        if (dp[i] == mx)
            mark[i] = true;
        else if (last[dp[i] + 1] >= arr[i])
            mark[i] = true;
        if (mark[i])
            last[dp[i]] = max(last[dp[i]], arr[i]);
    }
    return mx;
}

int solve()
{
    int n, res = 0;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        arr[i]--;
    }
    vector<int> dp_lis(n), dp_lds(n), last(n, -1), mn_val(n + 1, -1), mx_val(n + 1, -1), dp(n);
    vector<bool> is_lis(n), is_lds(n), valley(n), peak(n);
    int mx_lis = find_lis(arr, dp_lis, is_lis, n);
    reverse(arr.begin(), arr.end());
    int mx_lds = find_lis(arr, dp_lds, is_lds, n);
    reverse(arr.begin(), arr.end());
    reverse(dp_lds.begin(), dp_lds.end());
    reverse(is_lds.begin(), is_lds.end());
    vector<vector<int>> ids(n);
    for (int i = 0; i < n; i++)
        ids[arr[i]].pb(i);
    for (int i = 0; i < n; i++)
    {
        if (!ids[i].empty())
        {
            int last_id = -1, mx_i = 0, mx_d = 0, cur = 0;
            for (int id : ids[i])
            {
                if (is_lis[id])
                {
                    if (last_id != -1 && is_lis[last_id] && dp_lis[last_id] + 1 == dp_lis[id])
                        cur++;
                    else
                        cur = 1;
                }
                else
                    cur = 0;
                mx_i = max(mx_i, cur);
                last_id = id;
            }
            last_id = -1;
            cur = 0;
            for (int id : ids[i])
            {
                if (is_lds[id])
                {
                    if (last_id != -1 && is_lds[last_id] && dp_lds[last_id] - 1 == dp_lds[id])
                        cur++;
                    else
                        cur = 1;
                }
                else
                    cur = 0;
                mx_d = max(mx_d, cur);
                last_id = id;
            }
            res = max(res, min(mx_i, mx_d));
        }
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        cout << solve() << "\n";
    return 0;
}