#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int N;
    cin >> N;
    vector<vector<int>> MAP(10, vector<int>(10));
    int d = 1;
    for (int i = 1; i <= N; i++)
    {
        if (i / d == 10)
            d = i;
        MAP[i / d][i % 10]++;
    }
    int res = 0;
    for (int i = 1; i <= 9; i++)
        for (int j = 1; j <= 9; j++)
            res = res + MAP[i][j] * MAP[j][i];
    cout << res << "\n";
    return 0;
}