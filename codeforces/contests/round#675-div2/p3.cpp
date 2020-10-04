#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

ll MOD = 1e9+7;

ll add(ll x, ll y)
{
    x += y;
    while (x >= MOD)
        x -= MOD;
    while (x < 0)
        x += MOD;
    return x;
}

ll mul(ll x, ll y)
{
    return (x * 1ll * y) % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string str;
    cin>>str;
    int n = str.length();
    ll arr[n], ans=0;
    ll DP[n][n];
    for (int i=0; i<n; i++) {
        arr[i] = str[i] - 48;
        DP[i][i] = arr[i];
        ans = add(ans, arr[i]);
    }
    for (int gap=1; gap<n; gap++) {
        for (int i=0, j=gap; j<n; j++) {
            DP[i][j] = add(mul(DP[i][j-1],10), arr[j]);
            cout<<DP[i][j]<<"\n";
            ans = add(ans, DP[i][j]);
        }
    }
    cout<<ans<<"\n";
    return 0;
}