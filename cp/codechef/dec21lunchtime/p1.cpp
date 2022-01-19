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
    int n, k;
    string str;
    cin >> n >> k >> str;
    string res = str;
    for (int i = k - 1, j = 0, t = 1; i >= 0; i--, t *= -1)
    {
        res[i] = str[j];
        j += t * i;
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