#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    vector<int> vis(200, -1);
    vector<vector<int>> dp(n + 1, vector<int>(200, -1)), last(n + 1, vector<int>(200, -1));
    vis[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        if (vis[arr[i] % 200] > 0)
        {
            cout << "Yes\n";
            vector<int> tmp;
            for (int id = vis[arr[i] % 200], sum = arr[i] % 200; id > 0;)
            {
                tmp.pb(id);
                int tmp_sum = last[id][sum];
                id = dp[id][sum];
                sum = tmp_sum;
            }
            cout << tmp.size() << " ";
            reverse(tmp.begin(), tmp.end());
            for (int t : tmp)
                cout << t << " ";
            cout << "\n";
            cout << "1 " << i << "\n";
            return;
        }
        vis[arr[i] % 200] = i;
        dp[i][arr[i] % 200] = 0;
        for (int j = 1; j < i; j++)
        {
            for (int k = 0; k < 200; k++)
            {
                int m = (k + arr[i]) % 200;
                if (dp[j][k] != -1)
                {
                    if (vis[m] > 0)
                    {
                        // answer
                        cout << "Yes\n";
                        for (int x = 0; x < 2; x++)
                        {
                            vector<int> tmp;
                            for (int id = vis[m], sum = m; id > 0;)
                            {
                                tmp.pb(id);
                                int tmp_sum = last[id][sum];
                                id = dp[id][sum];
                                sum = tmp_sum;
                            }
                            cout << tmp.size() << " ";
                            reverse(tmp.begin(), tmp.end());
                            for (int t : tmp)
                                cout << t << " ";
                            cout << "\n";
                            dp[i][m] = j;
                            last[i][m] = k;
                            vis[m] = i;
                        }
                        return;
                    }
                    else
                    {
                        dp[i][m] = j;
                        last[i][m] = k;
                        vis[m] = i;
                    }
                }
            }
        }
    }
    cout << "No\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}