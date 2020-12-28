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
        int n, m;
        cin >> n;
        vector<int> r(n);
        for (int i = 0; i < n; i++)
            cin >> r[i];
        cin >> m;
        vector<int> b(m);
        for (int i = 0; i < m; i++)
            cin >> b[i];
        int sum = 0, res1 = 0, res2 = 0;
        for (int i = 0; i < n; i++)
        {
            sum += r[i];
            res1 = max(res1, sum);
        }
        sum = 0;
        for (int i = 0; i < m; i++)
        {
            sum += b[i];
            res2 = max(res2, sum);
        }
        cout << res1 + res2 << "\n";
    }
    return 0;
}