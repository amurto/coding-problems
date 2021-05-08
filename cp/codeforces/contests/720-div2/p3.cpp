#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int query(int t, int i, int j, int x)
{
    cout << "? " << t << " " << i << " " << j << " " << x << "\n";
    fflush(stdout);
    int y;
    cin >> y;
    if (y == -1)
        exit(0);
    return y;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n + 1);
    int last = n;
    for (int i = 2; i <= n; i += 2)
    {
        int q = query(1, i - 1, i, n - 1);
        if (q == n)
            last = i;
        else if (q == n - 1 && query(1, i, i - 1, n - 1) == n)
            last = i - 1;
    }
    arr[last] = n;
    for (int i = 1; i <= n; i++)
        if (i != last)
            arr[i] = query(2, i, last, 1);
    cout << "! ";
    for (int i = 1; i <= n; i++)
        cout << arr[i] << " ";
    cout << "\n";
    fflush(stdout);
}

int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
        solve();
    return 0;
}