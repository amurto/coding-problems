#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

bool solve()
{
    int n;
    ll x;
    cin >> n >> x;
    vector<ll> arr(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 1, j = n; i <= j; i++, j--)
    {
        pq.push(max(arr[i], arr[j]));
        if (i < j)
        {
            if (min(arr[i], arr[j]) > pq.top())
            {
                pq.pop();
                pq.push(min(arr[i], arr[j]));
            }
        }
    }
    ll sum = 0;
    while (!pq.empty())
    {
        sum += pq.top();
        pq.pop();
    }
    return sum >= x;
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