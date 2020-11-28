#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m, k, t, q, eligible = 0;
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = 0; j < k; j++)
        {
            cin >> t;
            sum += t;
        }
        cin >> q;
        if (sum >= m && q <= 10)    
            eligible++;
    }
    cout << eligible << "\n";
    return 0;
}