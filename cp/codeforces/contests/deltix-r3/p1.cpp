#ifdef use_debug
#define TERMINAL
#include "headers/debug.cpp"
#else
#define d(...) 0
#endif
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

ll solve()
{
    int n;
    cin >> n;
    vector<ll> arr(n), seq(n);
    ll cnt = 1, res = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        seq[i] = arr[i];
        while (seq[i] % 2 == 0)
        {
            cnt *= 2;
            seq[i] /= 2;
        }
        res += seq[i];
    }
    ll mx = *max_element(seq.begin(), seq.end());
    res -= mx;
    res += cnt * mx;
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        cout << solve() << "\n";
    return 0;
}