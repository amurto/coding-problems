#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

// Bit Trie
// set LGN to 60 for long long
const int N = 2e5 + 5, LGN = 30;
int t[N * LGN][2], cnt[N * LGN], mask = 1;

void init()
{
    memset(t, 0, sizeof(t));
    memset(cnt, 0, sizeof(cnt));
}

void insert(int x, int v, int bit)
{
    if (bit == -1)
    {
        cnt[v]++;
        return;
    }
    int child = (x >> bit) & 1;
    if (t[v][child] == 0)
        t[v][child] = ++mask;
    insert(x, t[v][child], bit - 1);
    // keep running sum
    cnt[v]++;
}

bool remove(int x, int v, int bit)
{
    if (bit == -1)
    {
        if (cnt[v] > 0)
            cnt[v]--;
        return cnt[v] == 0;
    }
    int child = (x >> bit) & 1;
    if (t[v][child] > 0)
    {
        if (remove(x, t[v][child], bit - 1))
            t[v][child] = 0;
        cnt[v]--;
    }
    return !(t[v][0] | t[v][1]);
}

// min xor with x
int min_xor_query(int x, int v, int bit)
{
    if (bit == -1)
        return 0;
    int child = (x >> bit) & 1;
    if (t[v][child] > 0)
        return min_xor_query(x, t[v][child], bit - 1);
    return (1 << bit) | min_xor_query(x, t[v][child ^ 1], bit - 1);
}

// max xor with x
int max_xor_query(int x, int v, int bit)
{
    if (bit == -1)
        return 0;
    int child = (x >> bit) & 1;
    if (t[v][child ^ 1] > 0)
        return (1 << bit) | max_xor_query(x, t[v][child ^ 1], bit - 1);
    return max_xor_query(x, t[v][child], bit - 1);
}

// smallest non-negative integer not present in array
// remove running sum, else this will not work
int mex(int v, int bit)
{
    if (bit == -1)
        return 0;
    int mx = 1 << bit;
    vector<int> seq = {0, 1};
    for (int j = 0; j < 2; j++)
    {
        if (t[v][seq[j]] == 0)
            return (j << bit);
        if (cnt[t[v][seq[j]]] < mx)
            return (j << bit) | mex(t[v][seq[j]], bit - 1);
    }
    return 0;
}

// kth minimum xor with x
int k_min(int x, int k, int v, int bit)
{
    if (bit == -1)
        return 0;
    int child = (x >> bit) & 1;
    if (t[v][child] > 0 && cnt[t[v][child]] >= k)
        return k_min(x, k, t[v][child], bit - 1);
    return (1 << bit) | k_min(x, k - cnt[t[v][child]], t[v][child ^ 1], bit - 1);
}

// kth maximum xor with x
int k_max(int x, int k, int v, int bit)
{
    if (bit == -1)
        return 0;
    int child = (x >> bit) & 1;
    if (t[v][child ^ 1] > 0 && cnt[t[v][child ^ 1]] >= k)
        return (1 << bit) | k_max(x, k, t[v][child ^ 1], bit - 1);
    return k_max(x, k - cnt[t[v][child ^ 1]], t[v][child], bit - 1);
}

void display(int x, int v, int bit)
{
    if (bit == -1)
    {
        cout << x << " ";
        return;
    }
    for (int j = 0; j <= 1; j++)
        if (t[v][j] > 0)
            display(x | (j << bit), t[v][j], bit - 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    int q, x;
    cin >> q;
    char ch;
    insert(0, 1, LGN);
    while (q-- > 0)
    {
        cin >> ch >> x;
        if (ch == '+')
            insert(x, 1, LGN);
        else if (ch == '-')
            remove(x, 1, LGN);
        else
            cout << max_xor_query(x, 1, LGN) << "\n";
    }
    return 0;
}

// String Trie
const int N = 1e5 + 5, K = 26;
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