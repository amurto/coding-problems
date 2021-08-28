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
    int n;
    cin >> n;
    vector<int> arr(n), dis(n, n + 1);
    vector<bool> good(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int mx = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        mx = max(mx, arr[i]);
        if (arr[i] == mx)
            good[i] = true;
    }
    if (!good[0])
        return -1;
    stack<int> st;
    st.push(0);
    dis[0] = 0;
    for (int i = 1; i < n; i++)
    {
        while (!st.empty() && arr[st.top()] <= arr[i])
            st.pop();
        if (st.empty())
        {
            if (arr[i] == arr[0])
                dis[i] = 1;
        }
        else
            dis[i] = dis[st.top()] + 1;
        st.push(i);
    }
    return dis[n - 1] > n ? -1 : dis[n - 1];
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