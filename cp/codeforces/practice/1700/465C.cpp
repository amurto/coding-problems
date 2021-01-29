// https://codeforces.com/contest/465/problem/C
// No to Palindromes!

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

void f(string &str, int idx, int n)
{
    for (int i = idx; i < n; i++)
    {
        char prev1 = (i - 2 >= 0) ? str[i - 2] : 'z' + 3;
        char prev2 = (i - 1 >= 0) ? str[i - 1] : 'z' + 3;
        str[i] = 'a';
        while (str[i] == prev1 || str[i] == prev2)
            str[i]++;
    }
}
string solve()
{
    int n, p;
    string str;
    cin >> n >> p >> str;
    char limit = 'a' + p - 1;
    for (int i = n - 1; i >= 0; i--)
    {
        char prev1 = (i - 2 >= 0) ? str[i - 2] : 'z' + 3;
        char prev2 = (i - 1 >= 0) ? str[i - 1] : 'z' + 3;
        char cur = str[i];
        cur++;
        while (cur == prev1 || cur == prev2)
            cur++;
        if (cur > limit)
            continue;
        str[i] = cur;
        f(str, i + 1, n);
        return str;
    }
    return "NO";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}