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

int query(int pos)
{
    cout << "? " << pos << endl;
    int ans;
    cin >> ans;
    if (ans == 0)
        exit(0);
    return ans;
}
void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n + 1), cycle;
    vector<bool> vis(n + 1);
    for (int i = 1; i <= n;)
    {
        int ans = query(i);
        if (vis[ans])
        {
            if (!cycle.empty())
            {
                if ((int)cycle.size() == 1)
                    arr[cycle[0]] = cycle[0];
                else
                {
                    int sz = (int)cycle.size();
                    for (int j = 1; j < sz; j++)
                        arr[cycle[j - 1]] = cycle[j];
                    arr[cycle[sz - 1]] = cycle[0];
                }
                cycle.clear();
            }
            i++;
        }
        else
        {
            vis[ans] = true;
            cycle.pb(ans);
        }
    }
    cout << "! ";
    for (int i = 1; i <= n; i++)
        cout << arr[i] << " ";
    cout << endl;
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