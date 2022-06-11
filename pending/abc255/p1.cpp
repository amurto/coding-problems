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
    int r, c;
    vector<vector<int>> arr(2, vector<int>(2));
    cin >> r >> c >> arr[0][0] >> arr[0][1] >> arr[1][0] >> arr[1][1];
    cout << arr[r - 1][c - 1] << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}