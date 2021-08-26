// https://codeforces.com/contest/576/problem/C
// Points on Plane

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

const int N = 1e6;
void solve()
{
    int n;
    cin >> n;
    vector<int> x(n), y(n), ids(n), perm;
    for (int i = 0; i < n; i++)
        cin >> x[i] >> y[i];
    iota(ids.begin(), ids.end(), 0);
    sort(ids.begin(), ids.end(), [&](int &i1, int &i2)
         { return x[i1] < x[i2]; });
    int idx = 0;
    for (int px = 1000; px <= N; px += 1000)
    {
        vector<int> tmp;
        while (idx < n && x[ids[idx]] <= px)
        {
            tmp.pb(ids[idx]);
            idx++;
        }
        sort(tmp.begin(), tmp.end(), [&](int &i1, int &i2)
             { return y[i1] < y[i2]; });
        for (int t : tmp)
            perm.pb(t);
    }
    for (int p : perm)
        cout << p + 1 << " ";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}