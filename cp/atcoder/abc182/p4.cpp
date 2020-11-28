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
    ll cur = 0, sum = 0, MAX = 0, res = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        MAX = max(MAX, sum);

        res = max(res, cur + MAX);
        cur += sum;
    }
    cout << res << "\n";
    return 0;
}