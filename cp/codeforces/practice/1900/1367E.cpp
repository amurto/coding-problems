// https://codeforces.com/contest/1367/problem/E
// Necklace Assembly

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int bs(vector<int> &st, int x)
{
    int l = 1, r = st[0], res = 0;
    while (l <= r)
    {
        int mid = l + (r - l) / 2, sum = 0;
        for (int v : st)
            sum += v / mid;
        if (sum >= x)
        {
            res = max(res, mid);
            l = mid + 1;
        }
        else
            r = mid - 1;
    }
    return res * x;
}

int solve()
{
    int n, k, res = 0;
    string str;
    cin >> n >> k >> str;
    vector<int> st(26);
    for (char ch : str)
        st[ch - 'a']++;
    sort(st.rbegin(), st.rend());
    for (int i = 1; i * i <= k; i++)
    {
        if (k % i == 0)
        {
            res = max(res, bs(st, i));
            res = max(res, bs(st, k / i));
        }
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