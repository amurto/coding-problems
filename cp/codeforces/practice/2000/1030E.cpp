// https://codeforces.com/contest/1030/problem/E
// Vasya and Good Sequences

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 3e5 + 5, LGN = 20;
int sp[N][LGN], hp[N];

void init()
{
    // highest power of 2 less than i
    hp[0] = hp[1] = 0;
    for (int i = 2; i < N; i++)
        hp[i] = hp[i / 2] + 1;
}

void build(vector<int> &arr, int n)
{
    // sparse table initialization with input array
    for (int i = 0; i < n; i++)
        sp[i][0] = arr[i];
    // works for min, max, gcd
    // updates not supported
    for (int k = 1; k < LGN; k++)
        for (int i = 0; i < n; i++)
            sp[i][k] = min(sp[i][k - 1], sp[min(n - 1, i + (1 << (k - 1)))][k - 1]);
}

int query(int l, int r)
{
    int dis = r - l + 1;
    return min(sp[l][hp[dis]], sp[r - (1 << hp[dis]) + 1][hp[dis]]);
}

ll solve()
{
    int n;
    cin >> n;
    ll v, res = 0;
    vector<int> arr(n + 1), pre(n + 1);
    vector<vector<int>> ids(2);
    for (int i = 1; i <= n; i++)
    {
        cin >> v;
        arr[i] = __builtin_popcountll(v);
        pre[i] = pre[i - 1] + arr[i];
    }
    build(arr, n + 1);
    ids[0].pb(0);
    for (int i = 1; i <= n; i++)
    {
        int p = pre[i] % 2;
        for (int j = ids[p].size() - 1; j >= 0; j--)
        {
            int last = ids[p][j] + 1;
            int mx = query(last, i);
            for (int k = last; k <= i; k++)
                mx = max(mx, arr[k]);
            int sum = pre[i] - pre[last - 1];
            if (sum >= 120)
            {
                res += 1ll * (j + 1);
                break;
            }
            if (sum - mx >= mx)
                res++;
        }
        ids[p].pb(i);
    }
    return res;
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