// https://codeforces.com/contest/705/problem/C
// Thor

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, q, type, x, t, last = 0, unread = 0;
    cin >> n >> q;
    vector<int> events;
    vector<bool> read;
    vector<queue<int>> g(n + 1);
    for (int i = 0; i < q; i++)
    {
        cin >> type;
        if (type == 1)
        {
            cin >> x;
            events.pb(x);
            read.pb(false);
            unread++;
            g[x].push(events.size() - 1);
        }
        else if (type == 2)
        {
            cin >> x;
            unread -= g[x].size();
            while (!g[x].empty())
            {
                read[g[x].front()] = true;
                g[x].pop();
            }
        }
        else
        {
            cin >> t;
            for (int j = last; j < t; j++)
            {
                if (read[j])
                    continue;
                g[events[j]].pop();
                unread--;
                read[j] = true;
            }
            last = max(last, t);
        }
        cout << unread << "\n";
    }
    return 0;
}
