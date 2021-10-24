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
    vector<vector<ll>> arr(n, vector<ll>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];
    for (int i2 = 0; i2 < n; i2++)
        for (int i1 = 0; i1 < i2; i1++)
            for (int j2 = 0; j2 < m; j2++)
                for (int j1 = 0; j1 < j2; j1++)
                    if (arr[i1][j1] + arr[i2][j2] > arr[i2][j1] + arr[i1][j2])
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