#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, mn = 1e5, mx = 0, sum = 0;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        mn = min(mn, arr[i]);
        mx = max(mx, arr[i]);
        sum += arr[i];
    }
    int add = mx * n - sum, rem = sum - mn * n;
    if (add <= rem)
        cout << "Add Light Bulbs\n";
    else
        cout << "Remove Light Bulbs\n";
    return 0;
}