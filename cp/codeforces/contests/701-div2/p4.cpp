#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int p4(int x)
{
    return x * x * x * x;
}

void solve()
{
    int n, m, v;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> v;
            v = ((i + j) % 2) ? p4(v) : 0;
            cout << 720720 + v << " ";
        }
        cout << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}