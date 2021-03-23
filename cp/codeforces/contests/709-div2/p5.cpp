#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

ll solve()
{
    int n;
    cin >> n;
    vector<ll> h(n + 1), b(n + 1), dp(n + 1), rp(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> h[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    stack<int> st;
    st.push(0);
    for (int i = 1; i <= n; i++)
    {
        ll mx = -1e18;
        while (h[i] < h[st.top()])
        {
            mx = max(mx, rp[st.top()]);
            st.pop();
        }
        rp[st.top()] = max(rp[st.top()], mx);
        dp[i] = rp[st.top()] + b[i];
        if (st.top() > 0)
            dp[i] = max(dp[st.top()], dp[i]);
        rp[i] = dp[i];
        st.push(i);
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