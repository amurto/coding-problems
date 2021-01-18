// https://codeforces.com/contest/84/problem/B
// Magical Array

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll res = 0;
    int n, prev = 0, sz = 0;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for (int i = 0; i < n; i++)
    {
        if (i == 0 || arr[i] != prev)
            sz = 0;
        sz++;
        res += sz;
        prev = arr[i];
    }
    cout << res << "\n";
    return 0;
}