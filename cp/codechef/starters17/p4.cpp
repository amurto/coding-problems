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
    int n;
    string str;
    cin >> n >> str;
    int e = count(str.begin(), str.end(), '0'), o = count(str.begin(), str.end(), '1');
    if (e == 1 || o == 1)
        return "Alice";
    if (e == 0 || o == 0)
        return "Bob";
    return (n & 1) ? "Alice" : "Bob";
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