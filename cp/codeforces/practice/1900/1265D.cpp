// https://codeforces.com/contest/1265/problem/D
// Beautiful Sequence

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

void solve()
{
    vector<int> st(4);
    for (int i = 0; i < 4; i++)
        cin >> st[i];
    deque<int> dq;
    for (int i = 3; i >= 0; i--)
    {
        if (st[i] == 0)
            continue;
        if (!dq.empty() && dq.front() == i + 1 && dq.back() == i + 1)
        {
            dq.push_front(i);
            st[i]--;
        }
        vector<int> u = {i, i - 1};
        if (i == 0)
            u[1]++;
        int p = 0;
        while (st[i] > 0)
        {
            if (st[u[p]] == 0)
            {
                cout << "NO\n";
                return;
            }
            if (dq.empty())
                dq.push_back(u[p]);
            else
            {
                if (dq.front() == u[p] + 1 || dq.back() == u[p] + 1)
                {
                    if (dq.front() == u[p] + 1)
                        dq.push_front(u[p]);
                    else
                        dq.push_back(u[p]);
                }
                else
                {
                    if (abs(dq.front() - u[p]) == 1)
                        dq.push_front(u[p]);
                    else if (abs(dq.back() - u[p]) == 1)
                        dq.push_back(u[p]);
                    else
                    {
                        cout << "NO\n";
                        return;
                    }
                }
            }
            st[u[p]]--;
            p ^= 1;
        }
    }
    vector<int> res;
    while (!dq.empty())
    {
        res.pb(dq.front());
        dq.pop_front();
    }
    for (int i = 1; i < res.size(); i++)
    {
        if (abs(res[i] - res[i - 1]) != 1)
        {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
    for (int r : res)
        cout << r << " ";
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}