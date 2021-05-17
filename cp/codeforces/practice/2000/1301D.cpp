// https://codeforces.com/contest/1301/problem/D
// Time to Run

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, string> dir;
#define pb push_back

void op(vector<dir> &res, int n, int m, int k)
{
    vector<dir> seq = {{m - 1, "RDU"}, {m - 1, "L"}, {1, "D"}};
    vector<int> moves = {3, 1, 1}, c = {1, -1, m};
    int cur = 0;
    for (int i = 0; k > 0 && cur != (n - 1) * m; i++)
    {
        i %= 3;
        if (moves[i] * seq[i].first > k)
        {
            if (i == 0)
            {
                int p = k / 3, rem = k % 3;
                if (p > 0)
                    res.pb({p, seq[i].second});
                cur += c[i] * p;
                k %= 3;
                if (k > 0)
                    res.pb({1, seq[i].second.substr(0, k)});
                k = 0;
            }
            else
            {
                res.pb({k, seq[i].second});
                cur += c[i] * k;
                k = 0;
            }
        }
        else
        {
            k -= moves[i] * seq[i].first;
            res.pb(seq[i]);
            cur += c[i] * seq[i].first;
        }
    }
    if (k > 0)
    {
        vector<dir> tmp = {{m - 1, "R"}, {m - 1, "L"}, {n - 1, "U"}};
        for (int i = 0; k > 0 && i < 3; i++)
        {
            if (tmp[i].first >= k)
            {
                res.pb({k, tmp[i].second});
                k = 0;
            }
            else
            {
                res.pb(tmp[i]);
                k -= tmp[i].first;
            }
        }
    }
}
void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    int mx = 4 * n * m - 2 * n - 2 * m;
    if (k > mx)
    {
        cout << "NO\n";
        return;
    }
    vector<dir> res;
    if (n == 1)
    {
        vector<dir> tmp = {{m - 1, "R"}, {m - 1, "L"}};
        for (int i = 0; k > 0 && i < 3; i++)
        {
            if (tmp[i].first >= k)
            {
                res.pb({k, tmp[i].second});
                k = 0;
            }
            else
            {
                res.pb(tmp[i]);
                k -= tmp[i].first;
            }
        }
    }
    else if (m == 1)
    {
        vector<dir> tmp = {{n - 1, "D"}, {n - 1, "U"}};
        for (int i = 0; k > 0 && i < 3; i++)
        {
            if (tmp[i].first >= k)
            {
                res.pb({k, tmp[i].second});
                k = 0;
            }
            else
            {
                res.pb(tmp[i]);
                k -= tmp[i].first;
            }
        }
    }
    else
        op(res, n, m, k);
    cout << "YES\n";
    cout << res.size() << "\n";
    for (dir d : res)
        cout << d.first << " " << d.second << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}