// https://codeforces.com/contest/1165/problem/F2
// Microtransactions (hard version)

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back

const int N = 2e5 + 5;
bool possible(vector<pii> &q, vector<int> req, int day, int n)
{
    vector<int> last(n, -1);
    vector<vector<int>> st(day + 1);
    for (pii e : q)
        if (e.first <= day)
            last[e.second] = max(last[e.second], e.first);
    for (int i = 0; i < n; i++)
        if (last[i] >= 0)
            st[last[i]].pb(i);
    int b = 0, sum = 0;
    for (int d = 0; d <= day; d++)
    {
        b++;
        for (int e : st[d])
        {
            if (b > req[e])
            {
                b -= req[e];
                req[e] = 0;
            }
            else
            {
                req[e] -= b;
                b = 0;
                break;
            }
        }
    }
    for (int i = 0; i < n; i++)
        sum += req[i];
    return sum * 2 <= b;
}

int solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> req(n);
    vector<pii> q(m);
    for (int i = 0; i < n; i++)
        cin >> req[i];
    for (int i = 0; i < m; i++)
    {
        cin >> q[i].first >> q[i].second;
        q[i].first--;
        q[i].second--;
    }
    int low = 0, high = 2 * N + 5, res = 2 * N + 5;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (possible(q, req, mid, n))
        {
            res = min(res, mid);
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return res + 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}