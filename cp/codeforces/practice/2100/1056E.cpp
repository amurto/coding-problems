// https://codeforces.com/contest/1056/problem/E
// Check Transcription

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int MOD = 1e9 + 7;

int add(int x, int y, int m = MOD)
{
    x += y;
    while (x >= m)
        x -= m;
    while (x < 0)
        x += m;
    return x;
}

int mul(int x, int y, int m = MOD)
{
    return (x * 1ll * y) % m;
}

// Binary Exponentiation O(logn)
// n^m mod p
int power(int n, int m, int p = MOD)
{
    int res = 1;
    while (m > 0)
    {
        if (m & 1)
            res = (res * 1ll * n) % p;
        n = (n * 1ll * n) % p;
        m /= 2;
    }
    return res;
}

class polyhash
{
public:
    string str;
    int n, m, p, h;
    vector<int> pre, inv;
    polyhash() {}
    polyhash(string str, int m, int p) : str(str), m(m), p(p)
    {
        n = str.length();
        pre.resize(n);
        inv.resize(n);
        precompute();
    }

    void precompute()
    {
        int last = 0, pw = 1;
        for (int i = 0; i < n; i++)
        {
            pre[i] = add(last, mul(pw, str[i] - 'a' + 1));
            last = pre[i];
            pw = mul(pw, p, m);
        }
        int v = power(pw, m - 2, m);
        for (int i = n - 1; i >= 0; i--)
        {
            inv[i] = mul(v, p);
            v = inv[i];
        }
        h = pre.back();
    }

    int query(int l, int r)
    {
        int cur = pre[r];
        if (l > 0)
            cur = add(cur, -pre[l - 1]);
        cur = mul(cur, inv[l]);
        return cur;
    }
};

void flip(string &s)
{
    for (int i = 0; i < s.length(); i++)
        s[i] = char('0' + (s[i] - '0') ^ 1);
}

int solve()
{
    int res = 0;
    string s, t;
    cin >> s >> t;
    polyhash ph = polyhash(t, MOD, 31);
    vector<int> cnt(2), occ(2, MOD);
    for (char ch : s)
        cnt[ch - '0']++;
    if (cnt[0] < cnt[1])
    {
        flip(s);
        swap(cnt[0], cnt[1]);
    }
    for (int i = 0; i < s.length(); i++)
        occ[s[i] - '0'] = min(occ[s[i] - '0'], i);
    int n = t.length();
    // fixing length of 0
    for (int i = 1; i <= n; i++)
    {
        ll v = i * 1ll * cnt[0];
        if (n - v >= 1 && (n - v) % cnt[1] == 0)
        {
            int j = (n - v) / cnt[1];
            // i -> length of 0
            // j -> length of 1
            vector<int> h(2), len(2);
            len[0] = i;
            len[1] = j;
            if (occ[0] == 0)
            {
                h[0] = ph.query(0, i - 1);
                h[1] = ph.query(occ[1] * i, occ[1] * i + j - 1);
            }
            else
            {
                h[1] = ph.query(0, j - 1);
                h[0] = ph.query(occ[0] * j, occ[0] * j + i - 1);
            }
            bool pos = (h[0] != h[1]);
            int itr = 0;
            for (int k = 0; pos && k < s.length(); k++)
            {
                int cur = s[k] - '0';
                pos = (h[cur] == ph.query(itr, itr + len[cur] - 1));
                itr += len[cur];
            }
            res += pos;
        }
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