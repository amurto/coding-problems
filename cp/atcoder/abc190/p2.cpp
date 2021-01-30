#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

bool solve()
{
    int n;
    ll s, d;
    cin >> n >> s >> d;
    vector<ll> X(n), Y(n);
    for (int i = 0; i < n; i++)
        cin >> X[i] >> Y[i];
    for (int i = 0; i < n; i++)
    {
        if (X[i] < s && Y[i] > d)
            return true;
    }
    return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve() ? cout << "Yes\n" : cout << "No\n";
    return 0;
}