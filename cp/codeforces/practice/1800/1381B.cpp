// https://codeforces.com/contest/1381/problem/B
// Unmerge

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

bool solve()
{
    int n;
    cin >> n;
    vector<int> arr(n << 1), st;
    for (int i = 0; i < arr.size(); i++)
        cin >> arr[i];
    int mx = arr[0], cur = 1;
    for (int i = 1; i < arr.size(); i++, cur++)
    {
        if (arr[i] > mx)
        {
            st.pb(cur);
            mx = arr[i];
            cur = 0;
        }
    }
    st.pb(cur);
    sort(st.begin(), st.end());
    vector<bool> vis(n + 1);
    vis[0] = 1;
    int sz = st.size();
    for (int i = 0; i < sz; i++)
    {
        int r = i;
        while (r < sz && st[r] == st[i])
            r++;
        vector<int> cnt(n + 1);
        for (int sum = st[i]; sum <= n; sum++)
        {
            if (!vis[sum] && vis[sum - st[i]] && cnt[sum - st[i]] < r - i)
            {
                cnt[sum] = cnt[sum - st[i]] + 1;
                vis[sum] = true;
            }
        }
        i = r - 1;
    }
    return vis[n];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        solve() ? cout << "YES\n" : cout << "NO\n";
    return 0;
}