#ifdef amurto
#define TERMINAL
#include "headers/debug.cpp"
#else
#define d(...) 0
#endif
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

// W -> 1
// B -> 0
int query(int v)
{
    cout << "? " << v << endl;
    char ch;
    cin >> ch;
    if (ch == 'W')
        return 1;
    return 0;
}

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> adj(n+1, vector<int>(n+1));
    vector<int> col(n+1,-1);
    int cnt = (n * (n - 1)) / 2;
    col[1] = query(1);
    for (int i = 2; i <= n; i++)
    {
        col[i] = query(i);
        for (int t = 1; t <= n; t++)
            if (adj[i][t] == 1)
                col[t] ^= 1;
        for (int j = 1; j < i; j++)
        {
            int c = query(j);
            if (col[j] != c)
                adj[i][j] = adj[j][i] = 1;
            else
                adj[i][j] = adj[j][i] = 0;
            col[j] = c;
            for (int t = 1; t <= n; t++)
                if (adj[j][t] == 1)
                    col[t] ^= 1;
        }
    }
    cout << "!" << endl;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            cout << adj[i][j];
        cout << endl;
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