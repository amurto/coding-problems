#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

bool op(vector<int> &arr, int n)
{
    for (int i = 1; i < n; i++)
        if (arr[i] > arr[i - 1])
            return true;
    return false;
}

bool solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    return op(arr, n);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        solve() ? cout << "Yes\n" : cout << "No\n";
    return 0;
}