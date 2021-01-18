// https://codeforces.com/contest/165/problem/C
// Another Problem on Strings

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int k, ones = 0;
    ll res = 0;
    string str;
    cin >> k >> str;
    int n = str.length();
    vector<int> f(n + 1);
    f[0] = 1;
    for (int i = 0; i < n; i++)
    {
        if (str[i] == '1')
            ones++;
        if (ones >= k)
            res += f[ones - k];
        f[ones]++;
    }
    cout << res << "\n";
    return 0;
}