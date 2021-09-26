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

ll get_num(string str, ll k)
{
    int len = str.length();
    ll m = 1, num = 0;
    for (int i = len - 1; i >= 0; i--, m *= k)
        num += m * (str[i] - '0');
    return num;
}

ll solve()
{
    ll k;
    string a, b;
    cin >> k >> a >> b;
    return get_num(a, k) * get_num(b, k);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}