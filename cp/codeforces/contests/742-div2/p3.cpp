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

int get_num(vector<int> st)
{
    reverse(st.begin(), st.end());
    int num = 0;
    for (int x : st)
        num = num * 10 + x;
    return num;
}

ll solve()
{
    int n;
    cin >> n;
    vector<vector<int>> st(2);
    for (int i = 0; n > 0; i ^= 1)
    {
        st[i].pb(n % 10);
        n /= 10;
    }
    vector<int> nums(2);
    for (int i = 0; i < 2; i++)
        nums[i] = get_num(st[i]);
    return (nums[0] + 1) * 1ll * (nums[1] + 1) - 2;
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