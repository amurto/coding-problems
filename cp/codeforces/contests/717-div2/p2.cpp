#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int solve()
{
    int n, z = 0, cur = 0;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        z ^= arr[i];
    }
    if (z == 0)
        return true;
    for (int i = 0; i < n; i++)
    {
        cur ^= arr[i];
        if (cur == z)
        {
            int k = 0;
            for (int j = i + 1; j < n; j++)
            {
                k ^= arr[j];
                if (k == z)
                    return true;
            }
        }
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        solve() ? cout << "YES\n" : cout << "NO\n";
    return 0;
}