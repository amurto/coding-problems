#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int idx(int i, int n)
{
    i %= n;
    if (i < 0)
        i += n;
    return i;
}

void check(int left, int right, int shift, int cnt, int n, int &res)
{
    if (right < shift)
        res = min(res, cnt + 2 * left + shift);
    else
        res = min(res, cnt + 2 * left + 2 * right - shift);
    shift = idx(n - shift, n);
    swap(left, right);
    if (right < shift)
        res = min(res, cnt + 2 * left + shift);
    else
        res = min(res, cnt + 2 * left + 2 * right - shift);
}

int solve()
{
    int k, n, res = INT_MAX;
    cin >> k;
    string x, y;
    cin >> x >> y;
    n = x.length();
    if (count(y.begin(), y.end(), '1') == 0)
        if (count(x.begin(), x.end(), '1') == 0)
            return 0;
        else
            return -1;
    vector<pair<int, int>> p;
    vector<int> L(n), R(n);

    // find closest 1 on left and right sides for all indexes of Y
    for (int i = 0; i < n; i++)
    {
        while (y[idx(i - L[i], n)] == '0')
            L[i]++;
        while (y[idx(i + R[i], n)] == '0')
            R[i]++;
        p.pb({L[i], i});
    }

    // sort all {L[i], i} in non-decreasing order
    sort(p.begin(), p.end(), greater<pair<int, int>>());

    // find minimum operations for all shifts from 0 to n-1
    for (int shift = 0; shift < n; shift++)
    {
        vector<bool> flip(n);
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (x[idx(i + shift, n)] != y[i])
            {
                flip[i] = true;
                cnt++;
            }
        }
        int right = 0;
        for (pair<int, int> uv : p)
        {
            if (!flip[uv.second])
                continue;
            check(uv.first, right, shift, cnt, n, res);
            right = max(right, R[uv.second]);
        }
        check(0, right, shift, cnt, n, res);
    }
    return res*k;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}