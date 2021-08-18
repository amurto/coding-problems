#ifdef amurto
#define TERMINAL
#include "headers/debug.cpp"
#else
#define d(...) 0
#endif
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int K = 26;

string rem(string s, char c)
{
    string tmp = "";
    for (char ch : s)
        if (ch != c)
            tmp.pb(ch);
    return tmp;
}

void solve()
{
    string str, ord = "";
    cin >> str;
    int n = str.length();
    vector<int> last(K, -1), cnt(K), pos(K), occ(K), chs;
    for (int i = 0; i < n; i++)
    {
        cnt[str[i] - 'a']++;
        last[str[i] - 'a'] = i;
    }
    for (int i = 0; i < K; i++)
        if (last[i] >= 0)
            chs.pb(i);
    sort(chs.begin(), chs.end(), [&](int &i1, int &i2)
         { return last[i1] < last[i2]; });
    for (int i = 0; i < chs.size(); i++)
        pos[chs[i]] = i + 1;
    int sz = chs.size();
    for (int i : chs)
        ord.pb(char('a' + i));
    int sum = 0;
    for (int i = 0; i < K; i++)
    {
        if (cnt[i] > 0)
        {
            if (cnt[i] % pos[i] > 0)
            {
                cout << "-1\n";
                return;
            }
            occ[i] = cnt[i] / pos[i];
            sum += occ[i];
        }
    }
    if (sum > n)
    {
        cout << "-1\n";
        return;
    }
    string res = str.substr(0, sum);
    string tmp = res;
    for (char ch : tmp)
        occ[ch - 'a']--;
    for (int i = 0; i < K; i++)
    {
        if (occ[i] != 0)
        {
            cout << "-1\n";
            return;
        }
    }
    for (int i = sum, j = 0; j < sz-1; j++)
    {
        tmp = rem(tmp, char(chs[j] + 'a'));
        int len = tmp.length();
        if (i + len > n || str.substr(i, len) != tmp)
        {
            cout << "-1\n";
            return;
        }
        i+=len;
    }
    cout << res << " " << ord << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        solve();
    return 0;
}