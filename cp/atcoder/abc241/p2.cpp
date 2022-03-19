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
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    map<int, int> cntA, cntB;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        cntA[a[i]]++;
    }
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
        cntB[b[i]]++;
    }
    for (auto x : cntB)
        if (x.second > cntA[x.first])
            return false;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve() ? cout << "Yes\n" : cout << "No\n";
    return 0;
}