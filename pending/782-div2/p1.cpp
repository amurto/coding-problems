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

string solve()
{
    int n, r, b;
    cin >> n >> r >> b;
    string res = "";
    int t = r / (b + 1), rem = r % (b + 1);
    while (r > 0 || b > 0)
    {
        int p = t;
        if (rem > 0)
        {
            p++;
            rem--;
        }
        for (int i = 0; r > 0 && i < p; i++, r--)
            res.pb('R');
        if (b > 0)
        {
            res.pb('B');
            b--;
        }
    }
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