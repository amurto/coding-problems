// https://codeforces.com/contest/304/problem/C
// Lucky Permutation Triple

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n), c(n);
    unordered_set<int> SET;
    for (int i = 0; i < n; i++)
    {
        a[i] = b[i] = i;
        c[i] = (a[i] + b[i]) % n;
        if (SET.count(c[i]))
        {
            cout << "-1\n";
            return;
        }
        SET.insert(c[i]);
    }
    for (int e : a)
        cout << e << " ";
    cout << "\n";
    for (int e : b)
        cout << e << " ";
    cout << "\n";
    for (int e : c)
        cout << e << " ";
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}