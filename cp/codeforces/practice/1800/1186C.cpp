// https://codeforces.com/contest/1186/problem/C
// Vus the Cossack and Strings

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int solve()
{
    string s1, s2;
    cin >> s1 >> s2;
    int b = s2.length();
    vector<int> cnt(2), w(2);
    for (char ch : s2)
        cnt[ch - '0']++;
    int res = 0;
    for (int i = 0; i < s1.length(); i++)
    {
        w[s1[i] - '0']++;
        if (i >= b)
            w[s1[i - b] - '0']--;
        if (i >= b - 1)
            res += ((w[0] % 2) == (cnt[0] % 2));
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