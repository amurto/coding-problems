// https://practice.geeksforgeeks.org/problems/number-formation3506/1
// Number Formation

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back
const int MOD = 1e9 + 7;

int getSum(int X, int Y, int Z)
{
    int sum[X + 1][Y + 1][Z + 1], count[X + 1][Y + 1][Z + 1], ans = 0;
    memset(sum, 0, sizeof(sum));
    memset(count, 0, sizeof(count));
    count[0][0][0] = 1;
    for (int i = 0; i <= X; i++)
    {
        for (int j = 0; j <= Y; j++)
        {
            for (int k = 0; k <= Z; k++)
            {
                if (i > 0)
                {
                    sum[i][j][k] += (sum[i - 1][j][k] * 10 + 4 * count[i - 1][j][k]) % MOD;
                    count[i][j][k] += count[i - 1][j][k] % MOD;
                }
                if (j > 0)
                {
                    sum[i][j][k] += (sum[i][j - 1][k] * 10 + 5 * count[i][j - 1][k]) % MOD;
                    count[i][j][k] += count[i][j - 1][k] % MOD;
                }
                if (k > 0)
                {
                    sum[i][j][k] += (sum[i][j][k - 1] * 10 + 6 * count[i][j][k - 1]) % MOD;
                    count[i][j][k] += count[i][j][k - 1] % MOD;
                }

                ans += sum[i][j][k] % MOD;
                ans %= MOD;
            }
        }
    }
    return ans%MOD;
}

int main()
{
    int X, Y, Z;
    cin >> X >> Y >> Z;
    cout << getSum(X, Y, Z) << endl;
    return 0;
}
