// https://codeforces.com/contest/514/problem/C
// Watto and Mechanism

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

// String Trie
const int N = 6e5 + 5, K = 3;
int t[N][K], cnt[N], mask = 1;

void init()
{
    memset(t, 0, sizeof(t));
    memset(cnt, 0, sizeof(cnt));
}

void insert(string &str)
{
    int cur = 1, i = 0;
    while (i < str.length())
    {
        if (t[cur][str[i] - 'a'] == 0)
            t[cur][str[i] - 'a'] = ++mask;
        cur = t[cur][str[i] - 'a'];
        i++;
    }
    cnt[cur]++;
}

bool present(string &str, int cur, int i, bool change)
{
    if (i == str.length())
        return (change && cnt[cur] > 0);
    char ch = str[i];
    if (change)
        return (t[cur][ch - 'a'] > 0) ? present(str, t[cur][ch - 'a'], i + 1, change) : false;
    bool res = false;
    for (char c = 'a'; c <= 'c'; c++)
        if (t[cur][c - 'a'] > 0)
            res |= present(str, t[cur][c - 'a'], i + 1, c != ch);
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    int n, m;
    string str;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> str;
        insert(str);
    }
    for (int i = 0; i < m; i++)
    {
        cin >> str;
        present(str, 1, 0, false) ? cout << "YES\n" : cout << "NO\n";
    }
    return 0;
}