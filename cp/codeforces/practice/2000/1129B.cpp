// https://codeforces.com/contest/1129/problem/B
// Wrong Answer

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

ll find_answer(int n, vector<int> &arr)
{
    ll res = 0;
    int cur = 0, k = -1;
    for (int i = 0; i < n; i++)
    {
        cur = cur + arr[i];
        if (cur < 0)
        {
            cur = 0;
            k = i;
        }
        res = max(res, 1ll * (i - k) * cur);
    }
    return res;
}

int calc(int n, vector<int> &arr)
{
    vector<int> pre(n);
    pre[0] = arr[0];
    for (int i = 1; i < n; i++)
        pre[i] += pre[i - 1] + arr[i];
    ll res = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            int sum = pre[i];
            if (j > 0)
                sum -= pre[j - 1];
            res = max(res, 1ll * sum * (i - j + 1));
        }
    }
    return res;
}

void solve()
{
    int n = 2000, k;
    cin >> k;
    vector<int> arr(n);
    int x = (k + 1998) / 1999;
    int d = 1999 * x - k;
    arr[n - 2] = -d;
    arr[n - 1] = x + d;
    if (calc(n, arr) - find_answer(n, arr) != k)
    {
        cout << "-1\n";
        return;
    }
    cout << n << "\n";
    for (int a : arr)
        cout << a << " ";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}