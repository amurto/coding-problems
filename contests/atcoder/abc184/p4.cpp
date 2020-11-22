#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

double dp[100][100][100];

double ioc(int a, int b, int c)
{
    if (a >= 100 || b >= 100 || c >= 100)
        return 0;
    if (dp[a][b][c] == 0)
    {
        double res = 0;
        res += 1.0 * (ioc(a + 1, b, c) + 1) * a / (a + b + c);
        res += 1.0 * (ioc(a, b + 1, c) + 1) * b / (a + b + c);
        res += 1.0 * (ioc(a, b, c + 1) + 1) * c / (a + b + c);
        dp[a][b][c] = res;
    }
    return dp[a][b][c];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int a, b, c;
    cin >> a >> b >> c;
    memset(dp, 0, sizeof(dp));
    cout << setprecision(8) << ioc(a, b, c) << "\n";
    return 0;
}