#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n, cur;
        char c;
        cin >> n;
        vector<vector<int>> mat(n, vector<int>(n));
        vector<int> T(10, -1), B(10, -1), L(10, -1), R(10, -1);
        vector<vector<int>> tt(10, vector<int>(n, -1)), bb(10, vector<int>(n, -1)), le(10, vector<int>(n, -1)), rr(10, vector<int>(n, -1));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> c;
                cur = c - '0';
                mat[i][j] = cur;
                if (T[cur] == -1)
                    T[cur] = i;
                if (B[cur] == -1)
                    B[cur] = i;
                else
                    B[cur] = max(B[cur], i);
                if (L[cur] == -1)
                    L[cur] = j;
                else
                    L[cur] = min(L[cur], j);
                if (R[cur] == -1)
                    R[cur] = j;
                else
                    R[cur] = max(R[cur], j);

                if (tt[cur][j] == -1)
                    tt[cur][j] = i;
                if (le[cur][i] == -1)
                    le[cur][i] = j;
                bb[cur][j] = max(bb[cur][j], i);
                rr[cur][i] = max(rr[cur][i], j);
            }
        }
        vector<int> res(10);
        for (int i = 0; i < n; i++)
        {
            for (int d = 0; d <= 9; d++)
            {
                if (tt[d][i] > -1)
                {
                    res[d] = max(res[d], abs(bb[d][i] - tt[d][i]) * max(i - 0, n - i - 1));
                    res[d] = max(res[d], max(abs(n - 1 - tt[d][i]), abs(tt[d][i] - 0)) * max(L[d], R[d]));
                    res[d] = max(res[d], max(abs(n - 1 - bb[d][i]), abs(bb[d][i] - 0)) * max(L[d], R[d]));
                }
                if (le[d][i] > -1)
                {
                    res[d] = max(res[d], abs(rr[d][i] - le[d][i]) * max(i - 0, n - i - 1));
                    res[d] = max(res[d], max(abs(n - 1 - le[d][i]), abs(le[d][i] - 0)) * max(T[d], B[d]));
                    res[d] = max(res[d], max(abs(n - 1 - rr[d][i]), abs(rr[d][i] - 0)) * max(T[d], B[d]));
                }
            }
        }
        for (int d : res)
            cout << d << " ";
        cout << "\n";
    }
    return 0;
}