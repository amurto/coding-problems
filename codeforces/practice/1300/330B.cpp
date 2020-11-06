// https://codeforces.com/problemset/problem/330/B
// Road Construction

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m, a, b;
    cin >> n >> m;
    vector<bool> edge(n + 1);
    while (m-- > 0)
    {
        cin >> a >> b;
        edge[a] = true;
        edge[b] = true;
    }
    int centre;
    for (centre = 1; centre <= n; centre++)
        if (!edge[centre])
            break;
    cout << n - 1 << "\n";
    for (int i = 1; i <= n; i++)
    {
        if (i == centre)
            continue;
        cout << i << " " << centre << "\n";
    }
    return 0;
}