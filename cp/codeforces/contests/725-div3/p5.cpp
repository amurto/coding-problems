#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

ll cnt(string &str)
{
    int sz = str.length();
    ll res = 0;
    for (int i = 0; i < sz - 3; i++)
        if (str.substr(i, 4) == "haha")
            res++;
    return res;
}

string get_beg(string &str)
{
    int sz = str.length();
    if (sz < 3)
        return str;
    return str.substr(0, 3);
}

string get_last(string &str)
{
    int sz = str.length();
    if (sz < 3)
        return str;
    return str.substr(sz - 3, 3);
}

class node
{
public:
    ll sz = 0, occ = 0;
    string s1, s2;
    node() {}
    node(string str)
    {
        sz = str.length();
        s1 = get_beg(str);
        s2 = get_last(str);
        occ = cnt(str);
    }
    void merge(node &other)
    {
        string tmp = s2 + other.s1;
        occ += cnt(tmp);
        string tmp1 = s1, tmp2 = other.s2;
        if (sz < 3)
        {
            tmp1 = s1 + other.s1;
            tmp1 = get_beg(tmp1);
        }
        if (other.sz < 3)
        {
            tmp2 = s2 + other.s2;
            tmp2 = get_last(tmp2);
        }
        else
            tmp2 = other.s2;
        occ += other.occ;
        s1 = tmp1;
        s2 = tmp2;
        sz += other.sz;
    }
};

ll solve()
{
    int n;
    cin >> n;
    string str;
    vector<int> tt(n);
    vector<string> vars(n), st, s1(n), s2(n);
    for (int i = 0; i < n; i++)
    {
        cin >> vars[i];
        st.pb(vars[i]);
        char ch;
        cin >> ch;
        if (ch == ':')
        {
            cin >> ch >> s1[i];
        }
        else
        {
            cin >> s1[i] >> ch >> s2[i];
            tt[i] = 1;
        }
    }
    sort(st.begin(), st.end());
    st.resize(unique(st.begin(), st.end()) - st.begin());
    int last = lower_bound(st.begin(), st.end(), vars.back()) - st.begin();
    int sz = st.size();
    vector<node> g(sz);
    for (int i = 0; i < n; i++)
    {
        if (tt[i] == 0)
        {
            int id = lower_bound(st.begin(), st.end(), vars[i]) - st.begin();
            g[id] = node(s1[i]);
        }
        else
        {
            int id = lower_bound(st.begin(), st.end(), vars[i]) - st.begin();
            int id1 = lower_bound(st.begin(), st.end(), s1[i]) - st.begin();
            int id2 = lower_bound(st.begin(), st.end(), s2[i]) - st.begin();
            node nd = g[id1];
            nd.merge(g[id2]);
            g[id] = nd;
        }
    }
    return g[last].occ;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        cout << solve() << "\n";
    return 0;
}