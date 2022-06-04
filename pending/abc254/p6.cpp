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

const int LGN = 18;

int combine(int x, int y)
{
    return __gcd(x, y);
}

struct sparse_table
{
    vector<vector<int>> sp;
    vector<int> hp;
    sparse_table(int n)
    {
        sp.resize(n, vector<int>(LGN));
        hp.resize(n + 1);
        // highest power of 2 less than i
        hp[0] = hp[1] = 0;
        for (int i = 2; i <= n; i++)
            hp[i] = hp[i / 2] + 1;
    }
    sparse_table() = default;

    void build(vector<int> &arr, int n)
    {
        // sparse table initialization with input array
        for (int i = 0; i < n; i++)
            sp[i][0] = arr[i];
        // works for min, max, gcd
        // updates not supported
        for (int k = 1; k < LGN; k++)
            for (int i = 0; i < n; i++)
                sp[i][k] = combine(sp[i][k - 1], sp[min(n - 1, i + (1 << (k - 1)))][k - 1]);
    }

    int query(int l, int r)
    {
        int dis = r - l + 1;
        return combine(sp[l][hp[dis]], sp[r - (1 << hp[dis]) + 1][hp[dis]]);
    }
};

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> A(n), B(n), A_g(n), B_g(n);
    for (int i = 0; i < n; i++)
        cin >> A[i];
    for (int i = 1; i < n; i++)
        A_g[i] = abs(A[i] - A[i - 1]);
    for (int i = 0; i < n; i++)
        cin >> B[i];
    for (int i = 1; i < n; i++)
        B_g[i] = abs(B[i] - B[i - 1]);
    sparse_table stA(n);
    stA.build(A_g, n);
    sparse_table stB(n);
    stB.build(B_g, n);
    for (int i = 0; i < q; i++)
    {
        int h1, h2, w1, w2, a = 0, b = 0, ans = 1;
        cin >> h1 >> h2 >> w1 >> w2;
        h1--;
        h2--;
        w1--;
        w2--;
        if (h1 != h2)
            a = stA.query(h1 + 1, h2);
        if (w1 != w2)
            b = stB.query(w1 + 1, w2);
        int c = __gcd(a, b), e = A[h1] + B[w1];
        if (c == 0)
            ans = e;
        else
        {
            int rem = e % c;
            ans = __gcd(rem, c);
        }
        cout << ans << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}