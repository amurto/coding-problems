#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

ll create_num(vector<ll> &digs, int x, int pos)
{
    ll num = 0;
    for (int i = 0; i < digs.size(); i++)
    {
        if (i == pos)
        {
            num *= 10;
            num += x;
        }
        num *= 10;
        num += digs[i];
    }
    if (pos == digs.size())
    {
        num *= 10;
        num += x;
    }
    return num;
}

ll solve()
{
    ll n;
    cin >> n;
    vector<ll> digs;
    ll x = n;
    int sum = 0;
    while (n > 0)
    {
        digs.pb(n % 10);
        sum += digs.back();
        n /= 10;
    }
    reverse(digs.begin(), digs.end());
    sum %= 3;
    if (sum == 0)
        return x;
    if (sum == 1)
        sum = 2;
    else
        sum = 1;
    vector<ll> nums;
    for (int pos = 0; pos <= digs.size(); pos++)
        nums.pb(create_num(digs, sum, pos));
    sort(nums.begin(), nums.end());
    return nums[0];
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