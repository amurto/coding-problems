// https://codeforces.com/problemset/problem/476/B
// Dreamoon and WiFi

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int dfs(string &str, int cur, int sf, int fin)
{
    if (cur == str.length())
        return (sf == fin);
    int res = 0;
    if (str[cur] == '?')
        res += dfs(str, cur + 1, sf - 1, fin) + dfs(str, cur + 1, sf + 1, fin);
    else if (str[cur] == '+')
        res += dfs(str, cur + 1, sf + 1, fin);
    else
        res += dfs(str, cur + 1, sf - 1, fin);
    return res;
}

double solve()
{
    string str1, str2;
    cin >> str1 >> str2;
    int q = count(str2.begin(), str2.end(), '?'), fin = 0;
    for (char ch : str1)
        if (ch == '+')
            fin++;
        else
            fin--;
    return dfs(str2, 0, 0, fin) * 1.0 / (1 << q);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(12) << solve() << "\n";
    return 0;
}