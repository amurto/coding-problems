#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int solve()
{
    int n, mx = 0, res = 0;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        mx = max(mx, arr[i]);
    }
    vector<stack<int>> st(mx + 1);
    st[0].push(n);
    for (int i = n - 1; i >= 0; i--)
    {
        if (st[arr[i]].empty())
            st[arr[i]].push(n);
        st[arr[i]].push(i);
    }
    vector<vector<int>> seq(2);
    seq[0].pb(0);
    seq[1].pb(0);
    for (int i = 0; i < n; i++)
    {
        int cur = 0;
        if (arr[i] != seq[0].back() && arr[i] != seq[1].back())
        {
            if (st[seq[0].back()].top() > st[seq[1].back()].top())
                seq[0].pb(arr[i]);
            else
                seq[1].pb(arr[i]);
            st[arr[i]].pop();
            continue;
        }
        if (seq[cur].back() != arr[i])
            cur ^= 1;
        seq[cur].pb(arr[i]);
        st[arr[i]].pop();
    }
    for (int i = 0; i < 2; i++)
        for (int j = 1; j < seq[i].size(); j++)
            res += (seq[i][j - 1] != seq[i][j]);
    return res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}