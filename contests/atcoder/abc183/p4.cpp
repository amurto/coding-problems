#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back

const int N = 4e5 + 1;


class triplet
{
public:
    int first, second, third;
    triplet() {}
    triplet(int first, int second, int third) : first(first), second(second), third(third) {}
    bool operator<(const triplet &j) const
    {
        if (first == j.first)
            return (second <= j.second);
        else
            return (first <= j.first);
    }
};
triplet tr[N];
bool solve()
{
    int n, w, s, t, p;
    cin >> n >> w;
    vector<triplet> d;
    for (int i = 0; i < n; i++)
    {
        cin >> s >> t >> p;
        d.pb(triplet(t, 0, p));
        d.pb(triplet(s, 1, p));
    }
    sort(d.begin(), d.end());
    int cur = 0, res = 0;
    for (int i = 0; i < 2 * n; i++)
    {
        if (d[i].second == 0)
            cur -= d[i].third;
        else
            cur += d[i].third;
        res = max(res, cur);
        if (res > w)
            return false;
    }
    return true;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    if (solve())
        cout << "Yes\n";
    else
        cout << "No\n";
    return 0;
}