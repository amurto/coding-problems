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
    int n, q;
    cin >> n >> q;
    string str;
    cin >> str;
    vector<int> pre(n);
    for (int i=0; i<n; i++) {
        char cur = '+';
        if (i&1)
            cur='-';
            
    }
    for (int i = 0; i < 1; i++)
    {
        int l, r;
        cin >> l >> r;
        l--;
        r--;

    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        solve();
    return 0;
}