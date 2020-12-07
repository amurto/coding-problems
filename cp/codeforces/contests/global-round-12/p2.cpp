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
        int n, k, res = -1;
        cin >> n >> k;
        vector<pair<int, int>> p(n);
        for (int i = 0; i < n; i++)
            cin >> p[i].first >> p[i].second;
        for (int i = 0; i < n; i++)
        {
            int cnt = 0;
            for (int j = 0; j < n; j++)
            {
                if (abs(p[i].first - p[j].first) + abs(p[i].second - p[j].second) <= k)
                    cnt++;
            }
            if (cnt == n)
            {
                res = 1;
                break;
            }
        }
        cout << res << "\n";
    }
    return 0;
}