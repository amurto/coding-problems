#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

void solve()
{
    int n;
    cin >> n;
    if (n == 2)
    {
        cout << "-1\n";
        return;
    }
    vector<vector<int>> arr(n, vector<int>(n));
    vector<queue<int>> q(2);
    int i = 1;
    for (int c = 1; c <= n * n; i++, c += 2)
        q[0].push(i);
    for (int c = 2; c <= n * n; i++, c += 2)
        q[1].push(i);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = q[(i + j) % 2].front();
            q[(i + j) % 2].pop();
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << arr[i][j] << " ";
        cout << "\n";
    }
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