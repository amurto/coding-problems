// https://codeforces.com/contest/1375/problem/D
// Replace by MEX

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n), res;
    vector<bool> vis(n + 2);
    stack<int> st;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for (int i = 0; i < n; i++)
    {
        if (vis[arr[i]] || arr[i] == n)
            st.push(i);
        if (arr[i] < n)
            vis[arr[i]] = true;
    }
    int mex = 0;
    while (!st.empty())
    {
        while (vis[mex])
            mex++;
        int cur = st.top();
        st.pop();
        arr[cur] = mex;
        res.pb(cur);
        vis[mex] = true;
    }
    mex = n;
    for (int i = 0; i < n; i++)
        if (i != arr[i])
            st.push(i);
    for (int a : arr)
        cout << a << " ";
    cout << "\n";
    while (!is_sorted(arr.begin(), arr.end()) && !st.empty())
    {
        while (!st.empty() && arr[st.top()] == st.top())
            st.pop();
        if (!is_sorted(arr.begin(), arr.end()) && !st.empty())
        {
            int id = st.top();
            st.pop();
            res.pb(id);
            swap(mex, arr[id]);
            while (!is_sorted(arr.begin(), arr.end()) && mex != n)
            {
                res.pb(mex);
                swap(mex, arr[mex]);
            }
        }
    }
    cout << res.size() << "\n";
    for (int r : res)
        cout << r + 1 << " ";
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        solve();
    return 0;
}