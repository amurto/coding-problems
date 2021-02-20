#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int f(int x)
{
    vector<int> d;
    while (x > 0)
    {
        d.pb(x % 10);
        x /= 10;
    }
    int a = 0, b = 0;
    sort(d.begin(), d.end());
    for (int e : d)
        a = a * 10 + e;
    reverse(d.begin(), d.end());
    for (int e : d)
        b = b * 10 + e;
    return b-a;
}
int solve()
{
    int n, k;
    cin >> n >> k;
    for (int i = 0; n > 0 && i < k; i++)
        n = f(n);
    return n;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}