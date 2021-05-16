#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    if (is_sorted(arr.begin(), arr.end()))
        return 0;
    if (arr[0] == 1 && arr[n - 1] == n)
        return 1;
    if (arr[0] == 1)
        return 1;
    if (arr[n - 1] == n)
        return 1;
    if (arr[0] == n & arr[n - 1] == 1)
        return 3;
    return 2;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        cout << solve() << "\n";
    return 0;
}