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
    arr[0][0] = arr[n][0] = arr[2 * n][0] = 2;
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
        arr[i + n] = arr[i];
        arr[i + 2 * n] = arr[i];
    }
    array<int, 3> zeroes{1, 2, 0}, ones{2, 0, 1};
    for (int i = n; i < 2 * n; i++)
        for (int j = 0; j < l; j++)
            arr[i][j] = zeroes[arr[i][j]];
    for (int i = 2 * n; i < 3 * n; i++)
        for (int j = 0; j < l; j++)
            arr[i][j] = ones[arr[i][j]];
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