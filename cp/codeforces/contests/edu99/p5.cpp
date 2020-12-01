#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
    {
        vector<pair<ll, ll>> p(4);
        vector<ll> X(4), Y(4);
        for (int i = 0; i < 4; i++)
        {
            cin >> X[i] >> Y[i];
            p[i].first = X[i];
            p[i].second = Y[i];
        }
        sort(X.begin(), X.end());
        sort(Y.begin(), Y.end());
        sort(p.begin(), p.end());
        ll L = max(X[2] - X[1], Y[2] - Y[1]), res = INT_MAX;
        pair<ll, ll> p1 = {min(X[1], X[3] - L), min(Y[1], Y[3] - L)};
        pair<ll, ll> p2 = {p1.first + L, p1.second};
        pair<ll, ll> p3 = {p1.first, p1.second + L};
        pair<ll, ll> p4 = {p1.first + L, p1.second + L};
        vector<pair<ll, ll>> sq = {p1, p2, p3, p4};
        do
        {
            ll dis = 0;
            for (int i = 0; i < 4; i++)
                dis += abs(p[i].first - sq[i].first) + abs(p[i].second - sq[i].second);
            res = min(res, dis);
        } while (next_permutation(p.begin(), p.end()));
        cout << res << "\n";
    }
    return 0;
}