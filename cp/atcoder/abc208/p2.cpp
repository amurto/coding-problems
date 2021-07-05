#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int solve()
{
    int p, res = 0;
    cin >> p;
    vector<int> fac(11);
    fac[0] = 1;
    for (int i = 1; i < 11; i++)
        fac[i] = fac[i - 1] * i;
    for (int i = 10; i > 0; i--)
    {
        int req = p / fac[i];
        p -= fac[i] * req;
        res += req;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}