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

int solve()
{
    string n;
    int res = 60;
    cin >> n;
    vector<int> nums;

    for (char ch : n)
        nums.pb(ch - '0');
    int len = nums.size();
    ll cur = 1;
    while (cur <= 1e18)
    {
        string s = to_string(cur);
        int sz = s.length();
        int j = 0;
        for (int i = 0; j < sz && i < nums.size(); i++)
            if (nums[i] == s[j] - '0')
                j++;
        res = min(res, len - j + sz - j);
        cur *= 2;
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