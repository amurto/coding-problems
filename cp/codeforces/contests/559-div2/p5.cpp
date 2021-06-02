#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int dfs(vector<int> &arr, vector<int> &nxt, stack<int> &st, int l, int r)
{
    for (int i = l + 1; i < r;)
        i = dfs(arr, nxt, st, i, nxt[i]);
    arr[l] = st.top();
    st.pop();
    return r;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> nxt(n + 1), arr(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> nxt[i];
    for (int i = 1; i <= n; i++)
        if (nxt[i] == -1)
            nxt[i] = i + 1;
    stack<int> border, st;
    for (int i = 1; i <= n; i++)
    {
        while (!border.empty() && i == border.top())
            border.pop();
        if (border.empty())
            border.push(nxt[i]);
        else
        {
            if (nxt[i] > border.top())
            {
                cout << "-1\n";
                return;
            }
            else
                border.push(nxt[i]);
        }
    }
    for (int i = n; i > 0; i--)
        st.push(i);
    for (int i = 1; i <= n;)
        i = dfs(arr, nxt, st, i, nxt[i]);
    for (int i = 1; i <= n; i++)
        cout << arr[i] << " ";
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