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

bool pos(vector<vector<int>> &arr, int d1, int d2, int n)
{
    int c1 = 0, c2 = 0, c3 = 0;
    for (int i = 0; i < n; i++)
    {
        int s = arr[i][d1] + arr[i][d2];
        if (s == 0)
            return false;
        if (s == 2)
            c3++;
        else if (arr[i][d1] == 1)
            c1++;
        else
            c2++;
    }
    int h = n / 2;
    return c1 <= h && c2 <= h;
}

bool solve()
{
    int n;
    cin >> n;
    vector<vector<int>> arr(n, vector<int>(5));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 5; j++)
            cin >> arr[i][j];
    for (int d2 = 0; d2 < 5; d2++)
        for (int d1 = 0; d1 < d2; d1++)
            if (pos(arr, d1, d2, n))
                return true;
    return false;
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