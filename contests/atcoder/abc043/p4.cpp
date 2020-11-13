#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

pair<int, int> solve()
{
    string s;
    cin >> s;
    int n = s.length();
    if (n == 2)
    {
        if (s[0] == s[1])
            return {1, 2};
        return {-1, -1};
    }
    for (int i = 2; i < n; i++)
        if (s[i] == s[i - 1] || s[i] == s[i - 2])
            return {i - 1, i + 1};
    return {-1, -1};
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    pair<int, int> res = solve();
    cout << res.first << " " << res.second << "\n";
    return 0;
}