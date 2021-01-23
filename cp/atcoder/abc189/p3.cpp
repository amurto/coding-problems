#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

ll solve()
{
    int n;
    cin >> n;
    vector<int> arr(n), L(n), R(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && arr[i] <= arr[st.top()])
            st.pop();
        L[i] = st.empty() ? 0 : st.top() + 1;
        st.push(i);
    }
    while (!st.empty())
        st.pop();
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && arr[i] <= arr[st.top()])
            st.pop();
        R[i] = st.empty() ? n - 1 : st.top() - 1;
        st.push(i);
    }
    ll res = 0;
    for (int i = 0; i < n; i++)
        res = max(res, (R[i] - L[i] + 1) * 1ll * arr[i]);
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}