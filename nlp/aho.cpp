#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int mask(char ch)
{
    if (ch <= 'Z')
        return ch - 'A';
    return 26 + ch - 'a';
}

string cs(char ch)
{
    string s;
    s.pb(ch);
    return s;
}

struct AhoCorasick
{
    struct Node
    {
        int next[52], go[52], suf = -1, exit = -1, parent = 0, leaf = 0;
        char ch;
        vector<int> idx;
        Node(int p = 0, char c = '0')
        {
            fill(next, next + 52, -1);
            fill(go, go + 52, -1);
            parent = p;
            ch = c;
        }
    };

    vector<Node> T;
    AhoCorasick()
    {
        T.pb(Node());
    }

    // O(len(str))
    // Insert a string and store its id in leaf node
    void insert(string str, int id)
    {
        int cur = 0, i = 0;
        while (i < str.length())
        {
            if (T[cur].next[mask(str[i])] == -1)
            {
                T[cur].next[mask(str[i])] = T.size();
                T.pb(Node(cur, str[i]));
            }
            cur = T[cur].next[mask(str[i])];
            i++;
        }
        T[cur].idx.pb(id);
        T[cur].leaf++;
    }

    // prefix
    // ch = r -> ch = e
    // Transition from current state to next state using character
    // If current state doesn't have character as child, use suffix link
    int transition(int cur, char c)
    {
        if (T[cur].next[mask(c)] >= 0)
            return T[cur].next[mask(c)];
        if (T[cur].parent == 0)
            return T[0].next[mask(c)] >= 0 ? T[0].next[mask(c)] : 0;
        if (T[cur].go[mask(c)] >= 0)
            return T[cur].go[mask(c)];
        return T[cur].go[mask(c)] = transition(get_suffix_link(cur), c);
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

    // a b c
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

    void display(int cur, string s)
    {
        if (T[cur].leaf > 0)
            cout << s << "\n";
        for (int i = 0; i < 26; i++)
            if (T[cur].next[i] > 0)
                display(T[cur].next[i], s + cs(char(i + 'a')));
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t, q;
    string str, tmp;
    AhoCorasick A;
    cin >> str >> q;
    vector<string> arr(q);
    for (int i = 0; i < q; i++)
    {
        cin >> arr[i];
        A.insert(arr[i], i);
    }
    vector<int> st;
    vector<bool> vis(q);
    int cur = 0;
    for (int j = 0; j < str.length(); j++)
    {
        cur = A.transition(cur, str[j]);
        A.traverse(cur, st);
    }
    for (int e : st)
        vis[e] = true;
    cout << "\n";
    for (int i = 0; i < q; i++)
        if (vis[i])
            cout << arr[i] << "\n";
    // O(len(str) + sum of (characters in set))
    return 0;
}