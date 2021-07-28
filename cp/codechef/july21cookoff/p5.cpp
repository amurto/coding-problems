#ifdef amurto
#define TERMINAL
#include "headers/debug.cpp"
#else
#define d(...) 0
#endif
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int solve()
{
    int n;
    cin >> n;
    int res = n;
    vector<int> arr(n), seq;
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        mp[arr[i]]++;
    }
    sort(arr.begin(), arr.end());
    arr.resize(unique(arr.begin(), arr.end()) - arr.begin());
    if (arr.size() == 1)
        return 0;
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] & 1)
            seq.pb(arr[i] / 2);
        else
            seq.pb(arr[i] / 2 - 1);
    }
    sort(seq.begin(), seq.end());
    if (seq[0] >= arr[0])
        res = min(res, n - mp[arr[0]]);
    return res;
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