// https://codeforces.com/contest/405/problem/C
// Unusual Product

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, q, type, x;
    cin >> n;
    int A[n][n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> A[i][j];
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += A[i][i];
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        cin >> type;
        if (type == 1 || type == 2)
        {
            cin >> x;
            x--;
            sum -= A[x][x];
            A[x][x] ^= 1;
            sum += A[x][x];
        }
        else
        {
            cout << sum % 2;
        }
    }
    cout << "\n";
    return 0;
}