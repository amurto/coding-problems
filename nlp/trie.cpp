#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

// String Trie
const int N = 1e5 + 5, K = 26;
int t[N][K], cnt[N], mask = 1;

void init()
{
    memset(t, 0, sizeof(t));
    memset(cnt, 0, sizeof(cnt));
}

// O(len(str))
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

string cs(string str, char ch)
{
    str.pb(ch);
    return str;
}

void display(int cur, string str)
{
    if (cnt[cur] > 0)
        cout << str << "\n";
    for (int i = 0; i < K; i++)
        if (t[cur][i] > 0)
            display(t[cur][i], cs(str, char(i + 'a')));
}

void traverse(string &str)
{
    int cur = 1, i = 0;
    while (i < str.length())
    {
        if (t[cur][str[i] - 'a'] == 0)
            return;
        cur = t[cur][str[i] - 'a'];
        i++;
    }
    display(cur, str);
}

int main()
{
    int n, q;
    string str;
    cin >> n;
    while (n-- > 0)
    {
        cin >> str;
        insert(str);
    }
    cin >> q;
    while (q-- > 0)
    {
        cin >> str;
        traverse(str);
    }
    return 0;
}