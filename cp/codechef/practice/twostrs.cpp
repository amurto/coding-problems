// https://www.codechef.com/MAY20A/problems/TWOSTRS
// Buying a New String

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

struct AhoCorasick
{
    struct Node
    {
        int next[26], go[26], suf = -1, exit = -1, parent = 0, leaf = 0;
        vector<ll> idx;
        char ch;
        ll val = 0;
        Node(int p = 0, char c = '0')
        {
            fill(next, next + 26, -1);
            fill(go, go + 26, -1);
            parent = p;
            ch = c;
        }
    };

    vector<Node> T;
    AhoCorasick()
    {
        T.pb(Node());
    }

    // Insert a string and store its id in leaf node
    void insert(string str, ll b)
    {
        int cur = 0, i = 0;
        while (i < str.length())
        {
            if (T[cur].next[str[i] - 'a'] == -1)
            {
                T[cur].next[str[i] - 'a'] = T.size();
                T.pb(Node(cur, str[i]));
            }
            cur = T[cur].next[str[i] - 'a'];
            i++;
        }
        T[cur].idx.pb(b);
        T[cur].leaf++;
    }

    // Transition from current state to next state using character
    // If current state doesn't have character as child, use suffix link
    int transition(int cur, char c)
    {
        if (T[cur].next[c - 'a'] >= 0)
            return T[cur].next[c - 'a'];
        if (T[cur].parent == 0)
            return T[0].next[c - 'a'] >= 0 ? T[0].next[c - 'a'] : 0;
        if (T[cur].go[c - 'a'] >= 0)
            return T[cur].go[c - 'a'];
        return T[cur].go[c - 'a'] = transition(get_suffix_link(cur), c);
    }

    // Compute suffix link for current state
    int get_suffix_link(int cur)
    {
        if (T[cur].parent == 0)
            return T[cur].suf = 0;
        if (T[cur].suf == -1)
            T[cur].suf = transition(get_suffix_link(T[cur].parent), T[cur].ch);
        return T[cur].suf;
    }

    // Traverse through exit links for dictionary matching
    // st stores all matching strings
    pair<int, ll> traverse(int cur)
    {
        if (cur == 0)
            return {0, 0ll};
        if (T[cur].exit == -1)
        {
            for (ll e : T[cur].idx)
                T[cur].val += e;
            pair<int, ll> p = traverse(get_suffix_link(cur));
            T[cur].exit = p.first;
            T[cur].val += p.second;
        }
        if (T[cur].idx.empty())
            return {T[cur].exit, T[cur].val};
        return {cur, T[cur].val};
    }

    ll compute(string str)
    {
        int pos = 0;
        ll sum = 0;
        for (char c : str)
        {
            pos = transition(pos, c);
            sum += traverse(pos).second;
        }
        return sum;
    }

    string cs(char ch)
    {
        string s;
        s.pb(ch);
        return s;
    }

    void display(int cur, string s)
    {
        if (T[cur].leaf > 0)
            cout << s << "\n";
        for (int i = 0; i < 26; i++)
            if (T[cur].next[i] > 0)
                display(T[cur].next[i], s + cs(char(i + 'a')));
    }
};

ll solve()
{
    int n, state = 0;
    string a, b, s;
    ll beauty, pre = 0, res = 0;
    cin >> a >> b >> n;
    int szA = a.length(), szB = b.length();
    AhoCorasick A;
    for (int i = 0; i < n; i++)
    {
        cin >> s >> beauty;
        A.insert(s, beauty);
    }
    vector<ll> suf(szB);
    for (int j = szB - 1, len = 1; j >= 0; j--, len++)
        suf[j] = A.compute(b.substr(j, len)) - A.compute(b.substr(j, min(len, 25)));
    for (int i = 0; i < szA; i++)
    {
        state = A.transition(state, a[i]);
        pre += A.traverse(state).second;
        for (int j = 0; j < szB; j++)
        {
            int tmp = state;
            ll cur_sum = pre + suf[j];
            for (int k = j; k < min(szB, j + 25); k++)
            {
                tmp = A.transition(tmp, b[k]);
                cur_sum += A.traverse(tmp).second;
            }
            res = max(res, cur_sum);
        }
    }
    return res;
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