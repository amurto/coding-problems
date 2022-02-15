#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

// doesn't support range update and range query
// supports range update and point query
struct FenwickTreeRP
{
    vector<int> bit; // binary indexed tree
    int n;
    FenwickTreeRP(int sz)
    {
        this->n = sz + 1;
        bit.assign(n + 1, 0);
    }
    FenwickTreeRP(vector<int> a)
        : FenwickTreeRP(a.size())
    {
        // creates same BIT from array using differences
        vector<int> diff = a;
        for (int i = 1; i < (int)a.size(); i++)
            diff[i] = a[i] - a[i - 1];
        for (size_t i = 0; i < diff.size(); i++)
            update(i, diff[i]);
    }
    int sum(int idx)
    {
        int ret = 0;
        for (++idx; idx > 0; idx -= idx & -idx)
            ret += bit[idx];
        return ret;
    }
    // int sum(int l, int r)
    // {
    //     return sum(r) - sum(l - 1);
    // }
    void update(int idx, int delta)
    {
        for (++idx; idx < n; idx += idx & -idx)
            bit[idx] += delta;
    }
    void range_update(int l, int r, int val)
    {
        update(l, val);
        update(r + 1, -val);
    }
    // use this
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

// doesn't support range update and range query
// supports point update and range query
struct FenwickTreePR
{
    vector<int> bit; // binary indexed tree
    int n;
    FenwickTreePR(int n)
    {
        this->n = n + 1;
        bit.assign(n + 1, 0);
    }
    FenwickTreePR(vector<int> a)
        : FenwickTreePR(a.size())
    {
        // creates same BIT from array using differences
        vector<int> diff = a;
        for (size_t i = 0; i < diff.size(); i++)
            add(i, diff[i]);
    }
    int range_query(int idx)
    {
        int ret = 0;
        for (++idx; idx > 0; idx -= idx & -idx)
            ret += bit[idx];
        return ret;
    }
    int range_query(int l, int r)
    {
        return range_query(r) - range_query(l - 1);
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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    FenwickTreePR ft(arr);
    return 0;
}