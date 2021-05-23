// https://codeforces.com/contest/1209/problem/G1
// Into Blocks (easy version)

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int solve()
{
    int n, q;
    cin >> n >> q;
    int res = 0, last = -1, len = 0, mx = 0;
    vector<int> arr(n + 1);
    map<int, int> rt, freq;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        rt[arr[i]] = i;
        freq[arr[i]]++;
    }
    for (int i = 1; i <= n; i++)
    {
        if (last == -1)
        {
            last = rt[arr[i]];
            len = 1;
            mx = freq[arr[i]];
        }
        if (i == last)
        {
            res += len - mx;
            mx = 0;
            last = -1;
            len = 0;
        }
        else
        {
            last = max(last, rt[arr[i]]);
            len++;
            mx = max(mx, freq[arr[i]]);
        }
    }
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