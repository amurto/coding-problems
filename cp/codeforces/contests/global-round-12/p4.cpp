#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int check(vector<int> &arr, int n)
{
    sort(arr.begin(), arr.end());
    for (int i = 1; i <= n; i++)
        if (arr[i - 1] != i)
            return 0;
    return 1;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n), res(n);
    multiset<int> ms;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        ms.insert(arr[i]);
    }
    int l = 0, r = n - 1, k = 1;
    while (k < n && *ms.begin() == k)
    {
        ms.erase(ms.begin());
        res[n - k] = 1;
        if (arr[l] == k)
            l++;
        else if (arr[r] == k)
            r--;
        else
            break;
        k++;
    }
    res[0] = check(arr, n);
    for (int r : res)
        cout << r;
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