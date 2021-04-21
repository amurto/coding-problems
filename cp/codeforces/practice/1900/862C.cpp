// https://codeforces.com/contest/862/problem/C
// Mahmoud and Ehab and the xor

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

void solve()
{
    int n, x, z = 0;
    cin >> n >> x;
    int pw = 1 << 17;
    vector<int> seq;
    for (int i = 1; i <= n - 3; i++)
    {
        z ^= i;
        seq.pb(i);
    }
    if (n <= 2)
    {
        if (n == 1)
            seq.pb(x);
        else
        {
            if (x == 0)
            {
                cout << "NO\n";
                return;
            }
            seq.pb(0);
            seq.pb(x);
        }
    }
    else
    {
        if (z == x)
        {
            seq.pb(pw);
            seq.pb(pw << 1);
            seq.pb(pw ^ (pw << 1));
        }
        else
        {
            seq.pb(0);
            seq.pb(pw);
            seq.pb(x ^ (pw ^ z));
        }
    }
    cout << "YES\n";
    for (int e : seq)
        cout << e << " ";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}