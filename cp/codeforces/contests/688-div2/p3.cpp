#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int N = 10;
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n, e;
        char ch;
        cin >> n;
        vector<vector<int>> grid(n, vector<int>(n));
        vector<int> top(N, -1), left(N, -1), bottom(N, -1), right(N, -1), cnt(N), res(N);
        int st[n][4][N];
        memset(st, -1, sizeof(st));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> ch;
                e = ch - '0';
                cnt[e]++;
                if (top[e] == -1)
                    top[e] = i;
                bottom[e] = max(bottom[e], i);
                if (left[e] == -1)
                    left[e] = j;
                else
                    left[e] = min(left[e], j);
                if (right[e] == -1)
                    right[e] = j;
                else
                    right[e] = max(right[e], j);
                if (st[j][0][e] == -1)
                    st[j][0][e] = i;
                if (st[i][1][e] == -1)
                    st[i][1][e] = j;
                st[j][2][e] = i;
                st[i][3][e] = j;
            }
        }
        for (int d = 0; d < N; d++)
        {
            if (cnt[d] == 0)
                continue;
            int a = 0;
            for (int i = 0; i < n; i++)
            {
                // ith row
                if (st[i][3][d] != -1)
                {
                    int c1 = abs(st[i][3][d] - st[i][1][d]) * max(i, n - i - 1);
                    int c2 = max(n - st[i][1][d] - 1, st[i][3][d]) * abs(top[d] - i);
                    int c3 = max(n - st[i][1][d] - 1, st[i][3][d]) * abs(bottom[d] - i);
                    a = max({a, c1, c2, c3});
                }
                // ith column
                if (st[i][2][d] != -1)
                {
                    int c4 = abs(st[i][2][d] - st[i][0][d]) * max(i, n - i - 1);
                    int c5 = max(n - st[i][0][d] - 1, st[i][2][d]) * abs(left[d] - i);
                    int c6 = max(n - st[i][0][d] - 1, st[i][2][d]) * abs(right[d] - i);
                    a = max({a, c4, c5, c6});
                }
            }
            res[d] = a;
        }
        for (int i = 0; i < N; i++)
            cout << res[i] << " ";
        cout << "\n";
    }
    return 0;
}