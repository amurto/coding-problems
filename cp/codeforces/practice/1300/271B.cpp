// https://codeforces.com/contest/271/problem/B
// Prime Matrix

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 2e7;
bool P[N];
vector<int> p;

// O(nlognlogn)
void sieve()
{
    memset(P, true, sizeof(P));
    P[0] = P[1] = false;
    for (int i = 2; i * i < N; i++)
    {
        if (!P[i])
            continue;
        for (int j = 2; i * j < N; j++)
            P[i * j] = false;
    }
    for (int i=2; i<N; i++)
        if (P[i])
            p.pb(i);
}

int bs(int val)
{
    int mov = INT_MAX, low = 0, high = p.size() - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (p[mid] >= val)
        {
            mov = min(mov, abs(p[mid] - val));
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return mov;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    sieve();
    int n, m, val;
    cin >> n >> m;
    vector<vector<int>> op(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> val;
            op[i][j] = bs(val);
        }
    }
    ll res = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        ll sum = 0;
        for (int j = 0; j < m; j++)
            sum += op[i][j];
        res = min(res, sum);
    }
    for (int j = 0; j < m; j++)
    {
        ll sum = 0;
        for (int i = 0; i < n; i++)
            sum += op[i][j];
        res = min(res, sum);
    }
    cout << res << "\n";
    return 0;
}