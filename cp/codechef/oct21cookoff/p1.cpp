#ifdef use_debug
#define TERMINAL
#include "headers/debug.cpp"
#else
#define d(...) 0
#endif
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back

bool solve()
{
    int n;
    cin >> n;
    vector<pii> arr(n);
    vector<int> rows(n + 1);
    for (int i = 0; i < n; i++)
        cin >> arr[i].first >> arr[i].second;
    sort(arr.begin(), arr.end());
    for (int i = 1; i <= n; i++)
        rows[i] = arr[i - 1].second;
    bool pos1 = true, pos2 = true;
    for (int i = 1, j = rows[1]; pos1 && j > 0; i++, j--)
        if (rows[i] != j)
            pos1 = false;
    for (int i = n, j = rows[n]; pos2 && j <= n; i--, j++)
        if (rows[i] != j)
            pos2 = false;
    return !(pos1 || pos2);
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