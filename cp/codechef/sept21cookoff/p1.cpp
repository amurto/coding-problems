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

bool solve()
{
    int n;
    string s, p;
    cin >> n >> s >> p;
    if (s == p)
        return true;
    array<int, 2> cnt{0, 0};
    for (char ch : p)
        cnt[ch - '0']++;
    return max(cnt[0], cnt[1]) < n;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        solve() ? cout << "YES\n" : cout << "NO\n";
    return 0;
}