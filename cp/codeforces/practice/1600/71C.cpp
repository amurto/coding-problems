// https://codeforces.com/contest/71/problem/C
// Round Table Knights

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

bool solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    vector<int> fac;
    int temp = n;
    if (temp % 4 == 0)
        fac.pb(4);
    while (temp % 2 == 0)
        temp /= 2;
    for (int i = 3; i * i <= temp; i += 2)
    {
        if (temp % i == 0)
        {
            fac.pb(i);
            while (temp % i == 0)
                temp /= i;
        }
    }
    if (temp > 1)
        fac.pb(temp);
    for (int f : fac)
    {
        vector<int> pre(n);
        int d = n / f;
        for (int i = 0; i < n; i++)
        {
            if (i - d >= 0)
                pre[i] += pre[i - d];
            if (arr[i] == 1)
                pre[i]++;
            if (pre[i] == f)
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
    solve() ? cout << "YES\n" : cout << "NO\n";
    return 0;
}