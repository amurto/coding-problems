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
        int n, m, v;
        cin >> n >> m;
        int cnt = 0;
        vector<int> bottom(101), left(101);
        for (int i = 0; i < n; i++)
        {
            cin >> v;
            bottom[v]++;
        }
        for (int j = 0; j < m; j++)
        {
            cin >> v;
            left[v]++;
        }
        for (int i=1; i<=100; i++) {
            if (bottom[i] && left[i])
                cnt++;
        }
        cout << cnt << "\n";
    }
    return 0;
}