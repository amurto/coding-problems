#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

vector<vector<int>> mat(4, vector<int>(4));
bool check(int n)
{
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            if (mat[i][j] < 0 || mat[i][j] > n)
                return false;
    int sum = mat[0][0] + mat[0][1] + mat[0][2] + mat[0][3];
    for (int i = 0; i < 4; i++)
    {
        int s1 = 0, s2 = 0;
        for (int j = 0; j < 4; j++)
            s1 += mat[i][j];
        if (s1 != sum)
            return false;
        for (int j = 0; j < 4; j++)
            s2 += mat[j][i];
        if (s2 != sum)
            return false;
    }
    int ds1 = mat[0][0] + mat[1][1] + mat[2][2] + mat[3][3];
    int ds2 = mat[0][3] + mat[1][2] + mat[2][1] + mat[3][0];
    return ds1 == sum && ds2 == sum;
}
int solve()
{
    int n, res = 0;
    cin >> n;
    for (mat[0][0] = 0; mat[0][0] <= n; mat[0][0]++)
        for (mat[0][1] = 0; mat[0][1] <= n; mat[0][1]++)
            for (mat[0][2] = 0; mat[0][2] <= n; mat[0][2]++)
                for (mat[0][3] = 0; mat[0][3] <= n; mat[0][3]++)
                    for (mat[1][0] = 0; mat[1][0] <= n; mat[1][0]++)
                        for (mat[1][1] = 0; mat[1][1] <= n; mat[1][1]++)
                            for (mat[1][2] = 0; mat[1][2] <= n; mat[1][2]++)
                                for (mat[1][3] = 0; mat[1][3] <= n; mat[1][3]++)
                                    for (mat[2][0] = 0; mat[2][0] <= n; mat[2][0]++)
                                        for (mat[2][1] = 0; mat[2][1] <= n; mat[2][1]++)
                                            for (mat[2][2] = 0; mat[2][2] <= n; mat[2][2]++)
                                                for (mat[2][3] = 0; mat[2][3] <= n; mat[2][3]++)
                                                    for (mat[3][0] = 0; mat[3][0] <= n; mat[3][0]++)
                                                    {
                                                        int col0 = mat[0][0] + mat[1][0] + mat[2][0] + mat[3][0];
                                                        mat[3][1] = col0 - (mat[0][1] + mat[1][1] + mat[2][1]);
                                                        mat[3][2] = col0 - (mat[0][2] + mat[1][2] + mat[2][2]);
                                                        mat[3][3] = col0 - (mat[0][3] + mat[1][3] + mat[2][3]);
                                                        res += check(n);
                                                    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    vector<int> res = {1, 34, 621, 5400, 30277, 125794, 423097, 1214992, 3089369, 7130034, 15210869};
    int n;
    cin >> n;
    cout << res[n] << " ";
    return 0;
}