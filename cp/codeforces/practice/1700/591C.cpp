// https://codeforces.com/contest/591/problem/C
// Median Smoothing

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

bool match(vector<int> &a, vector<int> &b, int n)
{
    int i = 0;
    while (i < n && a[i] == b[i])
        i++;
    if (i == n)
        return true;
    for (int i = 0; i < n; i++)
        a[i] = b[i];
    return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, cur = 0, res = 0;
    cin >> n;
    vector<int> a(n), b(n), h(n), l(n), r(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    b[0] = a[0];
    b[n - 1] = a[n - 1];
    h[0] = h[n - 1] = 1;
    r[n - 1] = n - 1;
    for (int i = 1; i < n - 1; i++)
        h[i] = (a[i - 1] == a[i] || a[i] == a[i + 1]);
    for (int i = 1; i < n; i++)
        l[i] = (h[i]) ? i : l[i - 1];
    for (int i = n - 2; i >= 0; i--)
        r[i] = (h[i]) ? i : r[i + 1];
    for (int i = 1; i < n - 1; i++)
    {
        int d = min(i - l[i], r[i] - i);
        b[i] = (i - l[i] == d) ? a[l[i]] : a[r[i]];
        res = max(res, d);
    }
    cout << res << "\n";
    for (int v : b)
        cout << v << " ";
    cout << "\n";
    return 0;
}