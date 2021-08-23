// https://codeforces.com/contest/1446/problem/C
// Xor Tree

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

int dfs(int v, int bit)
{
    if (v == 0)
        return 0;
    if (bit == -1)
        return cnt[v];
    if (cnt[v] == 0)
        return 0;
    int l = dfs(t[v][0], bit - 1), r = dfs(t[v][1], bit - 1);
    return max(l, r) + min(min(l, r), 1);
}

int solve()
{
    int n, res = 0;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for (int a : arr)
        insert(a, 1, LGN);
    return n - dfs(1, LGN);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    cout << solve() << "\n";
    return 0;
}