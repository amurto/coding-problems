#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int solve()
{
    int n, k, res = 0, d = 0;
    cin >> n >> k;
    map<int, int> mp;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for (int i = 0; i < k; i++)
    {
        mp[arr[i]]++;
        if (mp[arr[i]] == 1)
            d++;
    }
    res = max(res, d);
    for (int i = k; i < n; i++)
    {
        mp[arr[i - k]]--;
        if (mp[arr[i - k]] == 0)
            d--;
        mp[arr[i]]++;
        if (mp[arr[i]] == 1)
            d++;
        res = max(res, d);
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}