// https://codeforces.com/contest/1207/problem/D
// Number Of Permutations

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back

const int MOD = 998244353, N = 3e5 + 5;

int add(int x, int y)
{
    x += y;
    while (x >= MOD)
        x -= MOD;
    while (x < 0)
        x += MOD;
    return x;
}

int mul(int x, int y)
{
    return (x * 1ll * y) % MOD;
}

// Binary Exponentiation O(logn)
// n^m mod p
int power(int n, int m, int p)
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

// factorial and inverse factorial
int fact[N];
void init()
{
    fact[0] = fact[1] = 1;
    int i;
    for (i = 2; i < N; i++)
        fact[i] = (fact[i - 1] * 1ll * i) % MOD;
}

int perm(vector<pii> &arr, int n)
{
    int cnt = 1, l = 0;
    while (l < n)
    {
        int r = l + 1;
        while (r < n && arr[l].first == arr[r].first)
            ++r;
        cnt = mul(cnt, fact[r - l]);
        l = r;
    }
    return cnt;
}

int solve()
{
    int n, x, y;
    cin >> n;
    vector<pii> ab(n);
    for (int i = 0; i < n; i++)
        cin >> ab[i].first >> ab[i].second;
    int mx = fact[n], cntAB = 1, l = 0;
    for (int c = 0; c < 2; c++)
    {
        sort(ab.begin(), ab.end());
        mx = add(mx, -perm(ab, n));
        for (int i = 0; i < n; i++)
            swap(ab[i].first, ab[i].second);
    }
    sort(ab.begin(), ab.end());
    while (l < n)
    {
        int r = l + 1;
        while (r < n && ab[r].first == ab[l].first)
            r++;
        map<int, int> mp;
        for (int i = l; i < r; i++)
            mp[ab[i].second]++;
        for (auto p : mp)
            cntAB = mul(cntAB, fact[p.second]);
        l = r;
    }
    for (int i = 1; i < n; i++)
        if (ab[i - 1].second > ab[i].second)
            cntAB = 0;
    return add(mx, cntAB);
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