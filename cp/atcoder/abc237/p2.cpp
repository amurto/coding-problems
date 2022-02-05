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
    int h, w;
    cin >> h >> w;
    vector<vector<int>> A(h, vector<int>(w)), B(w, vector<int>(h));
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            cin >> A[i][j];
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            B[j][i] = A[i][j];
    for (int i = 0; i < w; i++)
    {
        for (int j = 0; j < h; j++)
            cout << B[i][j] << " ";
        cout << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}