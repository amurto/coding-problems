#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int N = 500001;
vector<vector<int>> G(N);
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m, k, gr, a, b;
    cin >> n >> m >> k;
    vector<int> group(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> group[i];
    for (int i=0; i<m; i++) {
        cin >> a >> b;
        G[a].pb(b);
        G[b].pb(a);
    }
    // int res = 0;
    // for (int i = 1; i <= k; i++)
    // {
    //     for (int j = i + 1; j <= k; j++)
    //     {
    //         cout << i << j;
    //     }
    // }
    return 0;
}