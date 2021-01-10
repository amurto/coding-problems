// https://codeforces.com/contest/456/problem/C
// Boredom

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 1e5 + 1;
vector<ll> F(N);
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, mx = 0;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        F[arr[i]]++;
        mx = max(mx, arr[i]);
    }
    ll prev = 0, cur = 0;
    for (int i = 1; i <= mx; i++)
    {
        ll temp = cur;
        cur = max(prev + F[i] * i, cur);
        prev = temp;
    }
    cout << max(prev, cur) << "\n";
    return 0;
}