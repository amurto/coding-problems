// https://codeforces.com/contest/490/problem/B
// Queue

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 1e6 + 1;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, a, b, sec = 0;
    cin >> n;
    vector<int> before(N), after(N), res(n), ids;
    vector<bool> vis(N);
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        after[a] = b;
        before[b] = a;
        if (a > 0)
            ids.pb(a);
        if (b > 0)
            ids.pb(b);
        if (a == 0)
            sec = b;
    }

    for (int id : ids)
    {
        if (vis[id])
            continue;
        vector<int> seq;
        int cur = id;
        while (cur != 0)
        {
            vis[cur] = true;
            seq.pb(cur);
            cur = before[cur];
        }
        reverse(seq.begin(), seq.end());
        cur = after[id];
        while (cur != 0)
        {
            vis[cur] = true;
            seq.pb(cur);
            cur = after[cur];
        }
        int itr = 0, j = 0;
        if (seq[0] == sec)
            itr = 1;
        for (int s : seq)
        {
            res[itr] = s;
            itr += 2;
        }
    }
    for (int r: res)
        cout << r << " ";
    return 0;
}