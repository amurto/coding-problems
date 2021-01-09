#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int N[3];
    cin >> N[0] >> N[1] >> N[2];
    ll v;
    vector<ll> sum(3), mn(3, 1e9);
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < N[i]; j++)
        {
            cin >> v;
            mn[i] = min(mn[i], v);
            sum[i] += v;
        }
    }
    sort(mn.begin(), mn.end());
    sort(sum.begin(), sum.end());
    ll s = sum[0] + sum[1] + sum[2];
    cout << max(s - 2 * (mn[0] + mn[1]), s - 2 * sum[0]) << "\n";
    return 0;
}