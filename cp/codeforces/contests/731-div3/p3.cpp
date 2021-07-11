#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

void solve()
{
    int k, n, m, v;
    cin >> k >> n >> m;
    queue<int> a, b;
    for (int i = 0; i < n; i++)
    {
        cin >> v;
        a.push(v);
    }
    for (int i = 0; i < m; i++)
    {
        cin >> v;
        b.push(v);
    }
    vector<int> seq;
    while (!a.empty() && !b.empty())
    {
        if (a.front() == 0)
        {
            seq.pb(a.front());
            a.pop();
            k++;
        }
        else if (b.front() == 0)
        {
            seq.pb(b.front());
            b.pop();
            k++;
        }
        else if (a.front() > k)
        {
            if (b.front() > k)
            {
                cout << "-1\n";
                return;
            }
            seq.pb(b.front());
            b.pop();
        }
        else
        {
            seq.pb(a.front());
            a.pop();
        }
    }
    while (!a.empty())
    {
        if (a.front() > k)
        {
            cout << "-1\n";
            return;
        }
        if (a.front() == 0)
            k++;
        seq.pb(a.front());
        a.pop();
    }
    while (!b.empty())
    {
        if (b.front() > k)
        {
            cout << "-1\n";
            return;
        }
        if (b.front() == 0)
            k++;
        seq.pb(b.front());
        b.pop();
    }
    for (int e : seq)
        cout << e << " ";
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        solve();
    return 0;
}