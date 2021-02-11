// https://codeforces.com/contest/298/problem/C
// Parity Game

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

bool solve()
{
    string a, b;
    cin >> a >> b;
    int o1 = count(a.begin(), a.end(), '1'), o2 = count(b.begin(), b.end(), '1');
    if (o1 & 1)
        o1++;
    return o1 >= o2;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve() ? cout << "YES\n" : cout << "NO\n";
    return 0;
}