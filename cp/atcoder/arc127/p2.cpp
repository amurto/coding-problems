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
    int n, l;
    cin >> n >> l;
    vector<vector<int>> arr(3 * n, vector<int>(l));
    arr[0][0] = 2;
    for (int i = 1; i < n; i++)
    {
        arr[i] = arr[i - 1];
        int carry = 1;
        for (int j = l - 1; carry && j >= 0; j--)
        {
            arr[i][j]++;
            if (arr[i][j] < 3)
                carry = 0;
            else
                arr[i][j] = 0;
        }
    }
    for (int i = n; i < 2 * n; i++)
        for (int j = l - 1; j >= 0; j--)
            arr[i][j] = 2 - arr[i - n][j];
    for (int j = 0; j < l; j++)
    {
        array<int, 3> cnt{0, 0, 0};
        for (int i = 0; i < 2 * n; i++)
            cnt[arr[i][j]]++;
        int cur = 2 * n;
        for (int p = 0; p < 3; p++)
        {
            while (cnt[p] < n)
            {
                arr[cur][j] = p;
                cnt[p]++;
                cur++;
            }
        }
    }
    for (vector<int> s : arr)
    {
        for (int x : s)
            cout << x;
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