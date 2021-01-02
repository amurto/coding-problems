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
    ll aoki = 0, taka = 0;
    vector<ll> A(n), B(n);
    vector<pair<ll, ll>> p;
    for (int i = 0; i < n; i++)
    {
        cin >> A[i] >> B[i];
        aoki += A[i];
        p.pb({2 * A[i] + B[i], i});
    }
    sort(p.rbegin(), p.rend());
    int idx = 0;
    while (taka <= aoki)
    {
        int cur = p[idx].second;
        taka += A[cur] + B[cur];
        aoki -= A[cur];
        idx++;
    }
    cout << idx << "\n";
    return 0;
}