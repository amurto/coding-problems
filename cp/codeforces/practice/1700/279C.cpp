// https://codeforces.com/contest/279/problem/C
// Ladder

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

bool op(vector<int> &arr, vector<int> &up, vector<int> &down, int l, int r)
{
    if (r - l < 2)
        return true;
    int beg = l, ed = r;
    while (beg < ed)
    {
        int m1 = beg + (ed - beg) / 3;
        int m2 = ed - (ed - beg) / 3;
        if (arr[m1] >= arr[m2])
            ed = m2 - 1;
        else
            beg = m1 + 1;
    }
    return beg - up[beg] < l && beg + down[beg] > r;
}

void solve()
{
    int n, m, l, r;
    cin >> n >> m;
    vector<int> arr(n), up(n, 1), down(n, 1);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for (int i = 1; i < n; i++)
        if (arr[i] >= arr[i - 1])
            up[i] += up[i - 1];
    for (int i = n - 2; i >= 0; i--)
        if (arr[i] >= arr[i + 1])
            down[i] += down[i + 1];
    for (int i = 0; i < m; i++)
    {
        cin >> l >> r;
        l--;
        r--;
        op(arr, up, down, l, r) ? cout << "Yes\n" : cout << "No\n";
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