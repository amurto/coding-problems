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
    cin >> n;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr.begin(), arr.end());
    ll sum = 0;
    vector<ll> pre(n);
    for (int i = 1; i < n; i++)
    {
        pre[i] = pre[i - 1] + (arr[i] - arr[i - 1]) * i;
        sum += pre[i];
    }
    cout << sum << "\n";
    return 0;
}