// https://codeforces.com/contest/160/problem/C
// Find Pair

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    ll k;
    cin >> n >> k;
    vector<int> arr(n);
    vector<ll> pos(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr.begin(), arr.end());
    unordered_map<int, int> f;
    ll cur = n;
    f[arr[0]]++;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] == arr[i - 1])
            pos[i] = pos[i - 1];
        else
            pos[i] = cur;
        f[arr[i]]++;
        cur += n;
    }
    int idx = (lower_bound(pos.begin(), pos.end(), k) - pos.begin()) - 1;
    int fr = f[arr[idx]], l = 0, r = n - 1;
    k -= pos[idx];
    int req = k / fr + (k % fr > 0 ? 1 : 0);
    cout << arr[idx] << " " << arr[req - 1] << "\n";
    return 0;
}