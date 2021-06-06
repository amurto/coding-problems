#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

bool solve()
{
    int n, inf = 1e9 + 5;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    multiset<int> ms;
    ms.insert(arr[0]);
    for (int i = 1; i < n; i++)
    {
        if (arr[i] == arr[i - 1])
        {
            ms.insert(-inf);
            ms.insert(inf);
            continue;
        }
        if (arr[i] < arr[i - 1])
        {
            auto it = ms.upper_bound(arr[i]);
            if (it == ms.end() || *it != arr[i - 1])
                return false;
            ms.insert(-inf);
            if (ms.find(arr[i]) == ms.end())
                ms.insert(arr[i]);
            else
                ms.insert(-inf);
        }
        else
        {
            auto it = ms.upper_bound(arr[i - 1]);
            if (it != ms.end() && *it < arr[i])
                return false;
            ms.insert(inf);
            if (ms.find(arr[i]) == ms.end())
                ms.insert(arr[i]);
            else
                ms.insert(inf);
        }
    }
    return true;
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