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
    vector<int> seq(3);
    for (int i = 0; i < 3; i++)
        cin >> seq[i];
    sort(seq.begin(), seq.end());
    int m;
    cin >> m;
    return seq[0] + seq[1] + seq[2] - 3 >= m && seq[2] - seq[0] - seq[1] - 1 <= m;
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