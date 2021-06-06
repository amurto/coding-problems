#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int mex(int x, int y)
{
    vector<bool> vis(3);
    vis[x] = true;
    vis[y] = true;
    for (int i = 0; i < 3; i++)
        if (!vis[i])
            return i;
    return 2;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int x, y;
    cin >> x >> y;
    if (x == y)
        cout << x << "\n";
    else
        cout << mex(x, y) << "\n";
    return 0;
}