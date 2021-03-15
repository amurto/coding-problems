// https://codeforces.com/contest/1328/problem/D
// Carousel

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int alt(int x)
{
    return (x == 1) ? 2 : 1;
}
void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n), col(n), st = {1, 2};
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    col[0] = 1;
    for (int i = 1; i < n; i++)
    {
        col[i] = col[i - 1];
        if (arr[i] != arr[i - 1])
            col[i] = alt(col[i - 1]);
    }
    int mx = 1;
    for (int i = 0; i < n; i++)
        mx = max(mx, col[i]);
    if (arr[0] != arr[n - 1] && col[0] == col[n - 1])
    {
        bool f = false;
        for (int i = 1; !f && i < n; i++)
        {
            if (arr[i] == arr[i - 1])
            {
                f = true;
                for (int j = i; j < n; j++)
                    col[j] = alt(col[j]);
            }
        }
        if (!f)
            col[0] = 3;
        mx = max(mx, col[0]);
    }

    cout << mx << "\n";
    for (int c : col)
        cout << c << " ";
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        solve();
    return 0;
}