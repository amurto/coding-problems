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
    int n;
    cin >> n;
    vector<string> grid(n);
    for (int i = 0; i < n; i++)
        cin >> grid[i];
    for (int i = 0; i < n; i++)
    {
        for (int j = 5; j < n; j++)
        {
            int cnt = 0;
            for (int k = j; k > j - 6; k--)
                cnt += (grid[i][k] == '#');
            if (cnt >= 4)
                return true;
        }
    }
    for (int j = 0; j < n; j++)
    {
        for (int i = 5; i < n; i++)
        {
            int cnt = 0;
            for (int k = i; k > i - 6; k--)
                cnt += (grid[k][j] == '#');
            if (cnt >= 4)
                return true;
        }
    }
    for (int i = 5; i < n; i++)
    {
        for (int j = 5; j < n; j++)
        {
            int cnt = 0;
            for (int t = 0; t < 6; t++)
                cnt += (grid[i - t][j - t] == '#');
            if (cnt >= 4)
                return true;
        }
    }
    for (int i = 0; i < n - 5; i++)
    {
        for (int j = n - 1; j >= 5; j--)
        {
            int cnt = 0;
            for (int t = 0; t < 6; t++)
                cnt += (grid[i + t][j - t] == '#');
            if (cnt >= 4)
                return true;
        }
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve() ? cout << "Yes\n" : cout << "No\n";
    return 0;
}