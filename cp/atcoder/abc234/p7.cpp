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

const int MOD = 998244353, inf = 1e9 + 7;

int add(int x, int y)
{
    x += y;
    while (x >= MOD)
        x -= MOD;
    while (x < 0)
        x += MOD;
    return x;
}

int mul(int x, int y)
{
    return (x * 1ll * y) % MOD;
}

vector<int> prev_greater(vector<int> &arr, int n)
{
    // prev >=
    vector<int> seq(n, -1);
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && arr[st.top()] < arr[i])
            st.pop();
        if (!st.empty())
            seq[i] = st.top();
        st.push(i);
    }
    return seq;
}

vector<int> prev_smaller(vector<int> &arr, int n)
{
    // prev <=
    vector<int> seq(n, -1);
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && arr[st.top()] > arr[i])
            st.pop();
        if (!st.empty())
            seq[i] = st.top();
        st.push(i);
    }
    return seq;
}

vector<int> next_greater(vector<int> &arr, int n)
{
    // next >
    vector<int> seq(n, n);
    stack<int> st;
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && arr[st.top()] <= arr[i])
            st.pop();
        if (!st.empty())
            seq[i] = st.top();
        st.push(i);
    }
    return seq;
}

vector<int> next_smaller(vector<int> &arr, int n)
{
    // next <
    vector<int> seq(n, n);
    stack<int> st;
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && arr[st.top()] >= arr[i])
            st.pop();
        if (!st.empty())
            seq[i] = st.top();
        st.push(i);
    }
    return seq;
}

int get_pref_sum(vector<int> &pre, int l, int r)
{
    if (l == 0)
        return pre[r];
    return pre[r] - pre[l - 1];
}

int solve()
{
    int n;
    cin >> n;
    vector<int> arr(n + 1), dp(n + 2), pre(n + 2);
    dp[0] = pre[0] = 1;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    // last <=, last >=
    // next <, next >
    arr[0] = -inf;
    vector<int> last_sm = prev_smaller(arr, n + 1);
    arr[0] = inf;
    vector<int> last_gr = prev_greater(arr, n + 1);
    vector<int> next_sm = next_smaller(arr, n + 1);
    vector<int> next_gr = next_greater(arr, n + 1);
    int carry = 0;
    for (int i = 1; i <= n; i++)
    {
        int pre_mx = mul(arr[i], get_pref_sum(pre, last_gr[i], i - 1));
        carry = add(carry, pre_mx);
        dp[next_gr[i]] = add(dp[next_gr[i]], -pre_mx);

        int pre_mn = mul(-arr[i], get_pref_sum(pre, last_sm[i], i - 1));
        carry = add(carry, pre_mn);
        dp[next_sm[i]] = add(dp[next_sm[i]], -pre_mn);

        dp[i] = add(dp[i], carry);
        carry = dp[i];

        pre[i] = add(pre[i - 1], dp[i]);
    }
    return dp[n];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}