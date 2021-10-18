// https://codeforces.com/contest/1438/problem/D
// Powerful Ksenia

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
    int n, x = 0;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        x ^= arr[i];
    }
    if (n % 2 == 0 && x > 0)
    {
        cout << "NO\n";
        return;
    }
    vector<tuple<int, int, int>> op;
    int last = n;
    if (n % 2 == 0)
        last--;
    for (int i = 2; i < last; i += 2)
        op.pb(make_tuple(i - 2, i - 1, i));
    for (int i = last - 1; i - 2 >= 0; i -= 2)
        op.pb(make_tuple(i - 2, i - 1, i));
    cout << "YES\n";
    cout << (int)op.size() << "\n";
    for (tuple<int, int, int> t : op)
        cout << get<0>(t) + 1 << " " << get<1>(t) + 1 << " " << get<2>(t) + 1 << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}