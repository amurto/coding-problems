// https://codeforces.com/contest/1428/problem/D
// Bouncing Boomerangs

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n + 1), use(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    vector<vector<int>> col(n + 1);
    int r = n;
    stack<int> st, tst;
    for (int i = n; i > 0; i--)
    {
        if (arr[i] == 0)
            continue;
        if (arr[i] == 1)
        {
            if (r <= 0)
            {
                cout << "-1\n";
                return;
            }
            use[r]++;
            col[i].pb(r--);
            st.push(i);
        }
        else if (arr[i] == 2)
        {
            if (st.empty())
            {
                cout << "-1\n";
                return;
            }
            int tp = st.top();
            st.pop();
            use[col[tp].back()]++;
            col[i].pb(col[tp].back());
            tst.push(i);
        }
        else
        {
            if (r <= 0 || (st.empty() && tst.empty()))
            {
                cout << "-1\n";
                return;
            }
            int tp = -1;
            if (tst.empty())
            {
                tp = st.top();
                st.pop();
            }
            else
            {
                tp = tst.top();
                tst.pop();
            }
            use[r] += 2;
            col[tp].pb(r);
            col[i].pb(r);
            r--;
            tst.push(i);
        }
    }
    int sz = 0;
    for (int i = 1; i <= n; i++)
        sz += (int)col[i].size();
    cout << sz << "\n";
    for (int i = 1; i <= n; i++)
        for (int x : col[i])
            cout << x << " " << i << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}