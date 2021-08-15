#ifdef amurto
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
    vector<int> arr(2 * n);
    for (int i = 0; i < 2 * n; i++)
        cin >> arr[i];
    sort(arr.begin(), arr.end());
    int sum = arr[0] + arr[2 * n - 1];
    for (int i = 0, j = 2 * n - 1; i < n; i++, j--)
        if (arr[i] + arr[j] != sum)
            return false;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        solve() ? cout << "PERFECT\n" : cout << "IMBALANCED\n";
    return 0;
}