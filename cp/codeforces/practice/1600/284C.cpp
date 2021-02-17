// https://codeforces.com/contest/284/problem/C
// Cows and Sequence

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

void solve()
{
    ll n, t, a, x, cur = 0, sum = 0, sz = 1;
    cin >> n;
    vector<ll> arr(n + 20), ch(n + 20);
    for (int i = 0; i < n; i++)
    {
        cin >> t;
        if (t == 1)
        {
            cin >> a >> x;
            ch[a - 1] += x;
            sum += a * x;
        }
        else if (t == 2)
        {
            cin >> x;
            sum += x;
            arr[++cur] = x;
        }
        else
        {
            sum -= (arr[cur] + ch[cur]);
            ch[cur - 1] += ch[cur];
            ch[cur] = 0;
            arr[cur--] = 0;
        }
        cout << sum * 1.0 / (cur + 1) << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(6);
    solve();
    return 0;
}