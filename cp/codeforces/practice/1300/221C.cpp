// https://codeforces.com/contest/221/problem/C
// Little Elephant and Problem

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

bool solve()
{
    int n, cnt = 0;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<int> b = a;
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++)
        cnt += (a[i] != b[i]);
    return cnt <= 2;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve() ? cout << "YES\n" : cout << "NO\n";
    return 0;
}