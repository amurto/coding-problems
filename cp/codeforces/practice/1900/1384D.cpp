// https://codeforces.com/contest/1384/problem/D
// GameGame

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

string solve()
{
    int n, x;
    cin >> n;
    vector<int> b(32);
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        for (int j = 0; x > 0; j++, x >>= 1)
            b[j] += (x & 1);
    }
    for (int i = 31; i >= 0; i--)
    {
        if (b[i] % 2 == 0)
            continue;
        if (b[i] % 4 == 3 && (n - b[i]) % 2 == 0)
            return "LOSE";
        else
            return "WIN";
    }
    return "DRAW";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        cout << solve() << "\n";
    return 0;
}