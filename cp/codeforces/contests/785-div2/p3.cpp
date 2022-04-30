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

const int MOD = 1e9 + 7, N = 4e4 + 5;

int add(int x, int y)
{
    x += y;
    x %= MOD;
    while (x >= MOD)
        x -= MOD;
    while (x < 0)
        x += MOD;
    return x;
}

vector<int> nums;
int dp[N];
void init()
{
    auto is_palindromic = [](int x) -> bool
    {
        string str = to_string(x);
        for (int l = 0, r = (int)str.length() - 1; l < r; l++, r--)
            if (str[l] != str[r])
                return false;
        return true;
    };
    for (int i = 1; i < N; i++)
        if (is_palindromic(i))
            nums.pb(i);
    dp[0] = 1;
    for (int num : nums)
        for (int j = num; j < N; j++)
            dp[j] = add(dp[j], dp[j - num]);
}

int solve()
{
    int n;
    cin >> n;
    return dp[n];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    int t;
    cin >> t;
    while (t-- > 0)
        cout << solve() << "\n";
    return 0;
}