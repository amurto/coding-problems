// https://codeforces.com/contest/899/problem/F
// Letters Removing

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

const int K = 62;
int ch_id(char ch)
{
    if (ch >= 'a')
        return 36 + ch - 'a';
    else if (ch >= 'A')
        return 10 + ch - 'A';
    return ch - '0';
}

struct FenwickTree
{
    vector<int> bit; // binary indexed tree
    int n;

    FenwickTree(int n)
    {
        this->n = n + 1;
        bit.assign(n + 1, 0);
    }

    FenwickTree(vector<int> a)
        : FenwickTree(a.size())
    {
        // creates same BIT from array using differences
        vector<int> diff = a;
        for (int i = 2; i < a.size(); i++)
            diff[i] = a[i] - a[i - 1];
        for (size_t i = 0; i < diff.size(); i++)
            add(i, diff[i]);
    }

    int sum(int idx)
    {
        int ret = 0;
        for (++idx; idx > 0; idx -= idx & -idx)
            ret += bit[idx];
        return ret;
    }

    int sum(int l, int r)
    {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta)
    {
        for (++idx; idx < n; idx += idx & -idx)
            bit[idx] += delta;
    }
    void range_add(int l, int r, int val)
    {
        add(l, val);
        add(r + 1, -val);
    }
    int point_query(int idx)
    {
        int ret = 0;
        for (++idx; idx > 0; idx -= idx & -idx)
            ret += bit[idx];
        return ret;
    }

    void display()
    {
        for (int i = 0; i < n - 1; i++)
            cout << point_query(i) << " ";
        cout << "\n";
    }
};

int get_initial_id(FenwickTree &ft, int n, int id)
{
    int low = 0, high = n - 1, res = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (ft.point_query(mid) <= id)
        {
            res = max(res, mid);
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    return res;
}

string solve()
{
    int n, m;
    string str;
    cin >> n >> m >> str;
    vector<set<int>> ids(K);
    for (int i = 0; i < n; i++)
        ids[ch_id(str[i])].insert(i);
    vector<int> tmp(n);
    iota(tmp.begin(), tmp.end(), 0);
    FenwickTree ft(tmp);
    for (int i = 0; i < m; i++)
    {
        int l, r;
        char c;
        cin >> l >> r >> c;
        l--;
        r--;
        int cur = ch_id(c), l_id = get_initial_id(ft, n, l), r_id = get_initial_id(ft, n, r);
        auto it = ids[cur].lower_bound(l_id);
        for (auto j = it; j != ids[cur].end() && *j <= r_id; j++)
        {
            int del_id = *j;
            str[del_id] = '.';
            ft.range_add(del_id + 1, n - 1, -1);
        }
        if (it != ids[cur].end())
            ids[cur].erase(it, ids[cur].upper_bound(r_id));
    }
    string res = "";
    for (char ch : str)
        if (ch != '.')
            res.pb(ch);
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