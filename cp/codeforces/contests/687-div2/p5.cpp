#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr.begin(), arr.end(), greater<ll>());
    ll res = 0;
    priority_queue<ll> pq;
    for (int i = 0; i < k + 1; i++)
        pq.push(0);
    for (int i = 0; i < n; i++)
    {
        ll x = pq.top();
        res += x;
        pq.pop();
        pq.push(x + arr[i]);
    }
    cout << res << "\n";
    return 0;
}