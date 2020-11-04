// https://codeforces.com/problemset/problem/1255/B
// Fridge Lockers

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n, m;
        cin >> n >> m;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        if (m < n || n == 2)
        {
            cout << "-1\n";
            continue;
        }
        int sum = 0;
        for (int val : arr)
            sum += 2 * val;
        cout << sum << "\n";
        for (int i = 1; i < m; i++)
            cout << i << " " << i + 1 << "\n";
        cout << m << " "
             << "1\n";
    }
    return 0;
}