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

string calc(int n)
{
    string num = to_string(n);
    reverse(num.begin(), num.end());
    int sz = (int)num.length();
    while (sz < 3)
    {
        num.pb('0');
        sz++;
    }
    reverse(num.begin(), num.end());
    return num;
}

string solve()
{
    int n;
    cin >> n;
    if (n >= 42)
        n++;
    return "AGC" + calc(n);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}