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
    for (int ti = 1; ti <= t; ti++)
    {
        int n;
        cin >> n;
        int minx = 0, maxx = 0, miny = 0, maxy = 0;
        vector<pair<int, int>> p(n);
        for (int i = 0; i < n; i++)
        {
            cin >> p[i].first >> p[i].second;
            minx = min(minx, p[i].first);
            maxx = max(maxx, p[i].first);
            miny = min(miny, p[i].second);
            maxy = max(maxy, p[i].second);
        }
        int row = miny, rc= 0;
        for (int i = miny; i <= maxy; i++)
        {
            int cnt=0;
            for (pair<int, int> po: p)
                if (po.second == i)
                    cnt++;
            if (cnt >= rc)
                row = i;
        }
        
        cout << row << "\n";
    }
    return 0;
}