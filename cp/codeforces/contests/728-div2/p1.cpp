#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n + 1);
    if (n & 1)
    {
        arr[1] = 3;
        arr[2] = 1;
        arr[3] = 2;
        for (int i = 4; i <= n; i++)
        {
            if (i & 1)
                arr[i] = i - 1;
            else
                arr[i] = i + 1;
        }
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            if (i & 1)
                arr[i] = i + 1;
            else
                arr[i] = i - 1;
        }
    }
    for (int i = 1; i <= n; i++)
        cout << arr[i] << " ";
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