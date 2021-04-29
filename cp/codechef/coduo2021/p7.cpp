#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 1e3 + 5, ninf = -1e6;
int dp[N][N];

struct AhoCorasick
{
    struct Node
    {
        int next[26], go[26], suf = -1, exit = -1, parent = 0, leaf = 0;
        char ch;
        vector<int> idx;
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
    void insert(string str, int id)
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
        T[cur].idx.pb(id);
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
        if (cur == 0 || T[cur].parent == 0)
            return 0;
        if (T[cur].suf == -1)
            T[cur].suf = transition(get_suffix_link(T[cur].parent), T[cur].ch);
        return T[cur].suf;
    }

    // Traverse through exit links for dictionary matching
    // st stores all matching strings
    int traverse(int cur, vector<int> &st)
    {
        if (cur == 0)
            return 0;
        for (int e : T[cur].idx)
            st.pb(e);
        if (T[cur].exit == -1)
            T[cur].exit = traverse(get_suffix_link(cur), st);
        else
            traverse(T[cur].exit, st);
        return T[cur].idx.empty() ? T[cur].exit : cur;
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

int kuniya(AhoCorasick &A, string &str, int cur, int state)
{

    vector<int> tmp;
    A.traverse(state, tmp);
    if (!tmp.empty())
        return ninf;
    if (cur == str.length())
        return 0;
    if (dp[cur][state] == -1)
        dp[cur][state] = max(kuniya(A, str, cur + 1, state), 1 + kuniya(A, str, cur + 1, A.transition(state, str[cur])));
    return dp[cur][state];
}

int solve()
{
    int n;
    string str;
    cin >> str >> n;
    vector<string> sub(n);
    AhoCorasick A;
    for (int i = 0; i < n; i++)
    {
        cin >> sub[i];
        A.insert(sub[i], i);
    }
    memset(dp, -1, sizeof(dp));
    return kuniya(A, str, 0, 0);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}