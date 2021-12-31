#ifdef use_debug
#define TERMINAL
#include "headers/debug.cpp"
#else
#define d(...) 0
#endif
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 2e5 + 5;

int tin[N], left_child[N], right_child[N], dup[N];
void dfs1(vector<int> &seq, int cur, int &t)
{
    if (left_child[cur] >= 0)
        dfs1(seq, left_child[cur], t);
    seq.pb(cur);
    tin[cur] = t;
    t++;
    if (right_child[cur] >= 0)
        dfs1(seq, right_child[cur], t);
}

void dfs2(set<int> &st, vector<int> &seq, vector<int> &suf, int cur, int n, int &k)
{
    st.insert(tin[cur]);
    if (left_child[cur] >= 0)
        dfs2(st, seq, suf, left_child[cur], n, k);
    if (suf[tin[cur]] && st.find(tin[cur]) != st.end() && *st.begin() >= tin[cur])
    {
        int sz = (int)st.size();
        if (sz <= k)
        {
            k -= sz;
            while (!st.empty())
            {
                dup[seq[*st.begin()]] = 1;
                st.erase(st.begin());
            }
        }
    }
    if (right_child[cur] >= 0)
        dfs2(st, seq, suf, right_child[cur], n, k);
    st.erase(tin[cur]);
}

string solve()
{
    int n, k;
    string str, res = "";
    cin >> n >> k >> str;
    for (int i = 0; i < n; i++)
    {
        dup[i] = 0;
        cin >> left_child[i] >> right_child[i];
        left_child[i]--;
        right_child[i]--;
    }
    vector<int> seq;
    int t = 0;
    dfs1(seq, 0, t);
    string in_str = str;
    for (int i = 0; i < n; i++)
        str[i] = in_str[seq[i]];
    vector<int> suf(n);
    for (int i = n - 2; i >= 0; i--)
    {
        if (str[i] < str[i + 1])
            suf[i] = 1;
        else if (str[i] > str[i + 1])
            suf[i] = 0;
        else if (str[i] == str[i + 1])
            suf[i] = suf[i + 1];
    }
    set<int> st;
    dfs2(st, seq, suf, 0, n, k);
    for (int i = 0; i < n; i++)
    {
        res.pb(str[i]);
        if (dup[seq[i]])
            res.pb(str[i]);
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