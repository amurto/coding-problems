#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back

const int MOD = 1e9 + 7, N = 4e5 + 5;
int arr[N][2], pos[N][2];
bool vis[N];

// Binary Exponentiation O(logn)
// n^m mod p
int power(int n, int m, int p)
{
    int res = 1;
    while (m > 0)
    {
        if (m & 1)
            res = (res * 1ll * n) % p;
        n = (n * 1ll * n) % p;
        m /= 2;
    }
    return res;
}

void dfs(int cur)
{
    vis[cur] = true;
    if (!vis[pos[arr[cur][0]][1]])
        dfs(pos[arr[cur][0]][1]);
    if (!vis[pos[arr[cur][1]][0]])
        dfs(pos[arr[cur][1]][0]);
}

int solve()
{
    int n, con = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i][0];
        pos[arr[i][0]][0] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i][1];
        pos[arr[i][1]][1] = i;
    }
    for (int i = 1; i <= n; i++)
        vis[i] = false;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            dfs(i);
            con++;
        }
    }
    return power(2, con, MOD);
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