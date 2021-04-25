// https://www.codechef.com/problems/NPLFLF
// Query On Strings

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

// Keyword Trie
const int N = 1e6 + 10;
int t[N][26], cnt[N], mask = 1;
set<int> st[N];

void insert(string &str, int v, int idx)
{
    if (idx == str.length())
    {
        cnt[v]++;
        return;
    }
    char ch = str[idx];
    if (t[v][ch - 'a'] == 0)
        t[v][ch - 'a'] = ++mask;
    insert(str, t[v][ch - 'a'], idx + 1);
    cnt[v]++;
}

void remove(string &str, int v, int idx)
{
    if (idx == str.length())
    {
        cnt[v]--;
        return;
    }
    char ch = str[idx];
    remove(str, t[v][ch - 'a'], idx + 1);
    cnt[v]--;
}

bool query(int k, int l)
{
    priority_queue<pair<int, int>> pq;
    pq.push({0, 1});
    while (!pq.empty())
    {
        int curr = pq.top().second, deep = pq.top().first;
        pq.pop();
        if (deep >= l)
            return true;
        for (int i = 0; i < 26; i++)
            if (t[curr][i] != 0 && cnt[t[curr][i]] >= k)
                pq.push({deep + 1, t[curr][i]});
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(t, 0, sizeof(t));
    memset(cnt, 0, sizeof(cnt));
    int q, t, k, l, x;
    cin >> q;
    vector<string> s(q);
    vector<bool> vis(q);
    for (int i = 0; i < q; i++)
    {
        cin >> t;
        if (t == 1)
        {
            cin >> s[i];
            reverse(s[i].begin(), s[i].end());
            insert(s[i], 1, 0);
        }
        else if (t == 2)
        {
            cin >> k >> l;
            if (query(k, l))
                cout << "YES\n";
            else
                cout << "NO\n";
        }
        else
        {
            cin >> x;
            x--;
            if (s[x].length() > 0)
            {
                remove(s[x], 1, 0);
                s[x] = "";
            }
        }
    }
    return 0;
}