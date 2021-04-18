// https://codeforces.com/contest/1202/problem/D
// Print a 1337-string...

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

ll nc2(int x)
{
    return (x * 1ll * (x - 1)) / 2;
}

int bs(int val)
{
    int low = 1, high = 1e6, res = 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        ll sq = nc2(mid);
        if (sq <= val)
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
    int n;
    cin >> n;
    string res = "7";
    map<int, int> mp;
    while (n > 0)
    {
        int x = bs(n);
        mp[x]++;
        n -= nc2(x);
    }
    int mx = (--mp.end())->first;
    vector<int> st(mx + 1);
    for (auto x : mp)
        st[x.first] = x.second;
    for (int i = 1; i <= mx; i++)
    {
        res.pb('3');
        for (int j = 0; j < st[i]; j++)
            res.pb('1');
    }
    reverse(res.begin(), res.end());
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