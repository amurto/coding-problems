#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

bool solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n), mask(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (arr[i] < k)
            mask[i] = -1;
        else if (arr[i] > k)
            mask[i] = 1;
    }
    if (count(mask.begin(), mask.end(), 0) == 0)
        return false;
    if (n == 1)
        return true;
    for (int i = 1; i < n; i++)
        for (int j = max(0, i - 2); j < i; j++)
            if (mask[j] >= 0 && mask[i] >= 0)
                return true;
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
        solve() ? cout << "yes\n" : cout << "no\n";
    return 0;
}