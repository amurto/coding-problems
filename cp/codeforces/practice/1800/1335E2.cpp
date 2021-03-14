// https://codeforces.com/contest/1335/problem/E2
// Three Blocks Palindrome (hard version)

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int bs(vector<vector<int>> &freq, int cur, int l, int r, int req)
{
    if (l > r)
        return -1;
    while (l < r)
    {
        int mid = l + (r - l) / 2;
        if (req >= freq[mid][cur])
            l = mid + 1;
        else
            r = mid;
    }
    return l - 1;
}

int solve()
{
    int n, res = 0;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    vector<vector<int>> freq(n, vector<int>(201));
    freq[0][arr[0]] = 1;
    for (int i = 1; i < n; i++)
    {
        freq[i] = freq[i - 1];
        freq[i][arr[i]]++;
    }
    for (int i = 0; i < n; i++)
    {
        int sf = freq[i][arr[i]], occ = freq[n - 1][arr[i]];
        res = max(res, occ);
        if (sf * 2 > occ)
            continue;
        int idx = bs(freq, arr[i], i + 1, n - 1, occ - sf);
        if (idx < 0)
            continue;
        for (int j = 0; j <= 200; j++)
            res = max(res, sf * 2 + freq[idx][j] - freq[i][j]);
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        cout << solve() << "\n";
    return 0;
}