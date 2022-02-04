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

int solve()
{
    string str;
    cin >> str;
    array<int, 2> cnt{0, 0};
    for (char ch : str)
        cnt[ch - '0']++;
    if (min(cnt[0], cnt[1]) < max(cnt[0], cnt[1]))
        return min(cnt[0], cnt[1]);
    return cnt[0] - 1;
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