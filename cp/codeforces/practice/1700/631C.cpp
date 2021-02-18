// https://codeforces.com/contest/631/problem/C
// Report

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> arr(n + 1), q(m + 1), r(m + 1);
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    for (int i = 0; i < m; i++)
        cin >> q[i] >> r[i];
    stack<int> st;
    st.push(m);
    for (int i = m - 1; i >= 0; i--)
        if (r[i] > r[st.top()])
            st.push(i);
    int mx = r[st.top()];
    multiset<int> ms(arr.begin() + 1, arr.begin() + 1 + mx);
    while (!ms.empty() && st.top() < m)
    {
        int tp = st.top();
        st.pop();
        while (r[tp] > r[st.top()])
        {
            if (q[tp] == 1)
            {
                arr[r[tp]--] = *ms.rbegin();
                ms.erase(--ms.end());
            }
            else
            {
                arr[r[tp]--] = *ms.begin();
                ms.erase(ms.begin());
            }
        }
    }
    for (int i = 1; i <= n; i++)
        cout << arr[i] << " ";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}