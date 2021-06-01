#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

bool dfs(vector<int> &nxt, vector<bool> &vis, vector<int> &arr, stack<int> &st, int l, int r)
{
    vis[l] = true;
    stack<int> del;
    for (int i = l + 1; i < r;)
    {
        if (nxt[i] == -1)
        {
            del.push(i);
            i++;
        }
        else
        {
            if (nxt[i] > r || !dfs(nxt, vis, arr, st, i, nxt[i]))
                return false;
            i = nxt[i];
        }
    }
    while (!del.empty())
    {
        vis[del.top()] = true;
        arr[del.top()] = st.top();
        del.pop();
        st.pop();
    }
    arr[l] = st.top();
    st.pop();
    return true;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> nxt(n + 1), arr(n + 1);
    vector<bool> vis(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> nxt[i];
    stack<int> st;
    for (int i = n; i >= 1; i--)
        st.push(i);
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            if (nxt[i] != -1)
            {
                if (!dfs(nxt, vis, arr, st, i, nxt[i]))
                {
                    cout << "-1\n";
                    return;
                }
            }
            else
            {
                arr[i] = st.top();
                st.pop();
            }
        }
    }
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