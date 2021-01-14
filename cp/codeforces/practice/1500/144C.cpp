// https://codeforces.com/contest/144/problem/C
// Anagram Search

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

bool match(vector<int> &f1, vector<int> &f2)
{
    for (int i = 0; i < 26; i++)
        if (f1[i] < f2[i])
            return false;
    return true;
}

int solve()
{
    string s, p;
    cin >> s >> p;
    int n = s.length(), k = p.length(), res = 0;
    if (k > n)
        return 0;
    vector<int> f1(26), f2(26);
    for (int i = 0; i < k; i++)
        f1[p[i] - 'a']++;
    for (int i = 0; i < k; i++)
        if (s[i] != '?')
            f2[s[i] - 'a']++;
    res += match(f1, f2);
    for (int i = k; i < n; i++)
    {
        if (s[i - k] != '?')
            f2[s[i - k] - 'a']--;
        if (s[i] != '?')
            f2[s[i] - 'a']++;
        res += match(f1, f2);
    }
    return res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}