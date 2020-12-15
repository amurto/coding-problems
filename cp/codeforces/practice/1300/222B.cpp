// https://codeforces.com/contest/222/problem/B
// Cosmic Tables

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m, q, x, y;
    cin >> n >> m >> q;
    char type;
    int A[n][m], R[n], C[m];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> A[i][j];
    for (int i = 0; i < n; i++)
        R[i] = i;
    for (int i = 0; i < m; i++)
        C[i] = i;
    for (int i = 0; i < q; i++)
    {
        cin >> type >> x >> y;
        x--;
        y--;
        if (type == 'c')
            swap(C[x], C[y]);
        else if (type == 'r')
            swap(R[x], R[y]);
        else
            cout << A[R[x]][C[y]] << "\n";
    }
    return 0;
}