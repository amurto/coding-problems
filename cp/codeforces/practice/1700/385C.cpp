// https://codeforces.com/contest/385/problem/C
// Bear and Prime Numbers

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 1e7;
vector<int> lp(N + 1), st(N + 1), pr;
void linear_sieve()
{
    for (int i = 2; i <= N; i++)
    {
        if (lp[i] == 0)
        {
            lp[i] = i;
            pr.push_back(i);
        }
        for (int j = 0; j < (int)pr.size() && pr[j] <= lp[i] && i * pr[j] <= N; ++j)
            lp[i * pr[j]] = pr[j];
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    linear_sieve();
    int n, m, x, l, r, mx = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        mx = max(mx, x);
        while (x > 1)
        {
            int cur = lp[x];
            st[cur]++;
            while (x % cur == 0)
                x /= cur;
        }
    }
    for (int i = 2; i <= N; i++)
        st[i] += st[i - 1];
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> l >> r;
        l = min(l, N);
        r = min(r, N);
        cout << st[r] - st[l - 1] << "\n";
    }
    return 0;
}