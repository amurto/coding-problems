#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

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
    FenwickTree ft(arr);
    return 0;
}