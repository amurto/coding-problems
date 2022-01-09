#ifdef use_debug
#define TERMINAL
#include "headers/debug.cpp"
#else
#define d(...) 0
#endif
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const ll MX = 2e17;
vector<ll> nums;
void dfs(ll num, int last, int diff)
{
    if (num > MX)
        return;
    nums.pb(num);
    if (last + diff >= 0 && last + diff <= 9)
        dfs(num * 10 + last + diff, last + diff, diff);
}

ll solve()
{
    ll n;
    cin >> n;
    int id = lower_bound(nums.begin(), nums.end(), n) - nums.begin();
    return nums[id];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    for (int i = 1; i <= 9; i++)
        for (int diff = -9; diff <= 9; diff++)
            dfs(i, i, diff);
    sort(nums.begin(), nums.end());
    cout << solve() << "\n";
    return 0;
}