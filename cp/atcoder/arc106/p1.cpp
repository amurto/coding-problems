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

void solve()
{
    ll n;
    cin >> n;
    vector<ll> pw3(39), pw5(27);
    pw3[0] = pw5[0] = 1;
    for (int i = 1; i <= 38; i++)
        pw3[i] = pw3[i - 1] * 3;
    for (int i = 1; i <= 26; i++)
        pw5[i] = pw5[i - 1] * 5;
    for (int i = 1; i <= 38; i++)
    {
        if (pw3[i] < n)
        {
            ll req = n - pw3[i];
            for (int j = 1; j <= 26; j++)
                if (pw5[j] == req)
                {
                    cout << i << " " << j << "\n";
                    return;
                }
        }
    }
    cout << "-1\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}