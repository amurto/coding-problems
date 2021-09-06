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
    int n;
    cin >> n;
    vector<int> p(n + 1), q(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i];
        q[p[i]] = i;
    }
    for (int i = 1; i <= n; i++)
        cout << q[i] << " ";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}