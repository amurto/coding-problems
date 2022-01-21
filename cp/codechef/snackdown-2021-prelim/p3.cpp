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

const int MOD = 998244353, N = 2e5 + 5;

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

// doesn't support range update and range query
// supports point update and range query
struct FenwickTreePR
{
    vector<int> bit; // binary indexed tree
    int n;
    FenwickTreePR(int sz)
    {
        this->n = sz + 1;
        bit.assign(sz + 1, 0);
    }
    FenwickTreePR(vector<int> a)
        : FenwickTreePR(a.size())
    {
        // creates same BIT from array using differences
        vector<int> diff = a;
        for (size_t i = 0; i < diff.size(); i++)
            upd(i, diff[i]);
    }
    int range_query(int idx)
    {
        int ret = 0;
        for (++idx; idx > 0; idx -= idx & -idx)
            ret = add(ret, bit[idx]);
        return ret;
    }
    int range_query(int l, int r)
    {
        return add(range_query(r), -range_query(l - 1));
    }
    void upd(int idx, int delta)
    {
        for (++idx; idx < n; idx += idx & -idx)
            bit[idx] = add(bit[idx], delta);
    }
    void range_add(int l, int r, int val)
    {
        upd(l, val);
        upd(r + 1, -val);
    }
    int point_query(int idx)
    {
        int ret = 0;
        for (++idx; idx > 0; idx -= idx & -idx)
            ret = add(ret, bit[idx]);
        return ret;
    }
    void display()
    {
        for (int i = 0; i < n - 1; i++)
            cout << point_query(i) << " ";
        cout << "\n";
    }
};

int solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    FenwickTreePR ft(N);
    ft.upd(0, 1);
    for (int x : arr)
        ft.upd(x, ft.range_query(0, x - 1));
    return ft.range_query(0, N - 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}