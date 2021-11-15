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

string solve()
{
    int n;
    string str;
    cin >> n >> str;
    str = "*" + str;
    string sub1 = "0123456789", sub2 = "1234567890", tr = "2345678901";
    vector<int> prev(n + 1, -1), nxt(n + 1, -1), del;
    for (int i = 0; i < n; i++)
        nxt[i] = i + 1;
    for (int i = 1; i <= n; i++)
        prev[i] = i - 1;
    set<int> st[10][10];
    for (int i = 2; i <= n; i++)
        st[str[i - 1] - '0'][str[i] - '0'].insert(i - 1);
    int c = 0;
    for (int k = 0;; k++)
    {
        k %= 10;
        int ops = 0, l = sub1[k] - '0', r = sub2[k] - '0';
        for (int i : st[l][r])
        {
            if (str[prev[i]] != '*')
                st[str[prev[i]] - '0'][str[i] - '0'].erase(prev[i]);
            if (nxt[nxt[i]] != -1)
                st[str[nxt[i]] - '0'][str[nxt[nxt[i]]] - '0'].erase(nxt[i]);
            str[i] = '*';
            str[nxt[i]] = tr[k];
            nxt[prev[i]] = nxt[i];
            prev[nxt[i]] = prev[i];
            if (str[prev[i]] != '*')
                st[str[prev[i]] - '0'][str[nxt[i]] - '0'].insert(prev[i]);
            if (nxt[nxt[i]] != -1)
                st[str[nxt[i]] - '0'][str[nxt[nxt[i]]] - '0'].insert(nxt[i]);
            del.pb(i);
            ops++;
        }
        for (int dd : del)
            st[l][r].erase(dd);
        del.clear();
        if (k == 0)
            c = 0;
        if (ops > 0)
            c = 0;
        else
            c++;
        if (k == 9 && c == 10)
            break;
    }
    string res = "";
    for (char ch : str)
        if (ch != '*')
            res.pb(ch);
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int tc = 1; tc <= t; tc++)
        cout << "Case #" << tc << ": " << solve() << "\n";
    return 0;
}