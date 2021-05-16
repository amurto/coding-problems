#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int query(char ch, int i, int j)
{
    cout << ch << " " << i << " " << j << "\n";
    fflush(stdout);
    int x;
    cin >> x;
    if (x == -1)
        exit(0);
    return x;
}

void solve(int n)
{
    for (int i = 1; i < n; i++)
    {
        int mn = query('M', i, n);
        if (mn != i)
            query('S', i, mn);
    }
    cout << "D\n";
    fflush(stdout);
    int x;
    cin >> x;
    if (x == -1)
        exit(0);
}

int main()
{
    int t, n;
    cin >> t >> n;
    while (t-- > 0)
        solve(n);
    return 0;
}