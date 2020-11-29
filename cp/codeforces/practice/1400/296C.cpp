// https://codeforces.com/contest/296/problem/C
// Greg and Array
// Range Summation in O(n)

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m, k, x, y;
    cin >> n >> m >> k;
    vector<ll> arr(n + 1), L(m + 1), R(m + 1), d(m + 1);
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    for (int i = 1; i <= m; i++)
        cin >> L[i] >> R[i] >> d[i];
    vector<ll> op(m + 1);
    while (k-- > 0)
    {
        cin >> x >> y;
        op[x]++;
        if (y + 1 <= m)
            op[y + 1]--;
    }
    for (int i = 1; i <= m; i++)
        op[i] += op[i - 1];
    vector<ll> f(n + 1);
    for (int i = 1; i <= m; i++)
    {
        f[L[i]] += d[i] * op[i];
        if (R[i] + 1 <= n)
            f[R[i] + 1] -= d[i] * op[i];
    }
    for (int i = 1; i <= n; i++)
    {
        f[i] += f[i - 1];
        arr[i]+=f[i];
    }
    for (int i = 1; i <= n; i++)
        cout << arr[i] << " ";
    cout << "\n";
    return 0;
}