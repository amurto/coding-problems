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

const int LGN = 30;
void solve()
{
    int n, mx = 0, ops = 0;
    cin >> n;
    vector<int> a(n), b(n), flip(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];

    for (int bit = LGN; bit >= 0; bit--)
    {
        int cnt = 0;
        for (int i = 0; i < n; i++)
            if (((a[i] >> bit) & 1) || ((b[i] >> bit) & 1))
                cnt++;
        if (cnt == n)
        {
            mx |= (1 << bit);
            for (int i = 0; i < n; i++)
            {
                int l = ((a[i] >> bit) & 1), r = ((b[i] >> bit) & 1);
                if (l + r == 1)
                {
                    if (l == 1)
                        b[i] = a[i];
                    else
                    {
                        flip[i] = 1;
                        a[i] = b[i];
                        ops++;
                    }
                }
            }
        }
    }
    cout << mx << " " << ops << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        solve();
    return 0;
}