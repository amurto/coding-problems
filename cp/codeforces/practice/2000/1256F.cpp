// https://codeforces.com/contest/1256/problem/F
// Equalizing Two Strings

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

bool solve()
{
    int n;
    string s, t;
    cin >> n >> s >> t;
    vector<int> st1(26), st2(26);
    for (char ch : s)
        st1[ch - 'a']++;
    for (char ch : t)
        st2[ch - 'a']++;
    for (int i = 0; i < 26; i++)
        if (st1[i] != st2[i])
            return false;
    for (int i = 0; i < 26; i++)
        if (st1[i] >= 2)
            return true;
    int inv1 = 0, inv2 = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            inv1 += (s[i] < s[j]);
            inv2 += (t[i] < t[j]);
        }
    }
    return inv1 % 2 == inv2 % 2;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        solve() ? cout << "YES\n" : cout << "NO\n";
    return 0;
}