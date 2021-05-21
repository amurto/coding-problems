#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

string solveP21(string &str, int n)
{
    int z = count(str.begin(), str.end(), '0');
    if (z == 1)
        return "BOB";
    if (n % 2 == 0)
        return "BOB";
    else
    {
        int mid = str[n / 2] - '0';
        if (mid == 0)
            return "ALICE";
    }
    return "BOB";
}

string solve(int tc)
{
    int n, c = 0;
    string str;
    cin >> n >> str;
    int i = 0, j = n - 1;
    while (i < j)
    {
        if (str[i] != str[j])
        {
            str[i] = str[j] = '1';
            c++;
        }
        i++;
        j--;
    }
    int z = count(str.begin(), str.end(), '0');
    if (c == 0)
        return solveP21(str, n);
    if ((n & 1) && str[n / 2] == '0' && c == 1 && z == 1)
        return "DRAW";
    return "ALICE";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int tc = 1; tc <= t; tc++)
        cout << solve(tc) << "\n";
    return 0;
}

// dp
const int N = 1e3 + 5, inf = 1e9;
int dp[N][N][2][2][2], vis[N][N][2][2][2];

void init()
{
    memset(vis, -1, sizeof(dp));
}

int dfs(int zz, int zo, int mid, int rev, int cur)
{
    if (zz + zo + mid == 0)
        return 0;
    if (vis[zz][zo][mid][rev][cur] == -1)
    {
        vis[zz][zo][mid][rev][cur] = 1;
        int res = 0;
        if (cur == 0)
        {
            res = inf;
            if (zz > 0)
                res = min(res, 1 + dfs(zz - 1, zo + 1, mid, 0, cur ^ 1));
            if (zo > 0)
                res = min(res, 1 + dfs(zz, zo - 1, mid, (zo - 1) == 0, cur ^ 1));
            if (mid > 0)
                res = min(res, 1 + dfs(zz, zo, 0, zo == 0, cur ^ 1));
            if (rev == 0)
                res = min(res, dfs(zz, zo, mid, 1, cur ^ 1));
        }
        else if (cur == 1)
        {
            res = -inf;
            if (zz > 0)
                res = max(res, -1 + dfs(zz - 1, zo + 1, mid, 0, cur ^ 1));
            if (zo > 0)
                res = max(res, -1 + dfs(zz, zo - 1, mid, (zo - 1) == 0, cur ^ 1));
            if (mid > 0)
                res = max(res, -1 + dfs(zz, zo, 0, zo == 0, cur ^ 1));
            if (rev == 0)
                res = max(res, dfs(zz, zo, mid, 1, cur ^ 1));
        }
        dp[zz][zo][mid][rev][cur] = res;
    }
    return dp[zz][zo][mid][rev][cur];
}

string solve()
{
    int n, mid = 0, zo = 0, zz = 0;
    string str;
    cin >> n >> str;
    for (int i = 0, j = n - 1; i < j; i++, j--)
        if (str[i] != str[j])
            zo++;
        else if (str[i] == '0')
            zz++;
    if ((n & 1) && str[n / 2] == '0')
        mid++;
    int res = dfs(zz, zo, mid, zo == 0, 0);
    if (res > 0)
        return "BOB";
    else if (res == 0)
        return "DRAW";
    return "ALICE";
}
