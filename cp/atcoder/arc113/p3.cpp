#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

void init(vector<int> &cur)
{
    for (int i = 0; i < 26; i++)
        cur[i] = 0;
}

ll solve()
{
    string str;
    cin >> str;
    int n = str.length();
    ll res = 0;
    vector<int> cur(26);
    cur[str[n - 1] - 'a']++;
    for (int i = n - 2; i > 0; i--)
    {
        if (str[i - 1] == str[i])
        {
            int non_cur = n - i - 1 - cur[str[i] - 'a'];
            res += non_cur;
            init(cur);
            cur[str[i] - 'a'] = n - i - 1;
        }
        cur[str[i] - 'a']++;
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