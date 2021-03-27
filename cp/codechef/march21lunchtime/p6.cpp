#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

class interval
{
public:
    int l, r;
    ll v;
    interval() {}
    interval(int l, int r, ll v) : l(l), r(r), v(v) {}
    bool operator<(const interval &j) const
    {
        if (l == j.l)
            return (r < j.r);
        return (l < j.l);
    }
};

ll solve()
{
    int n, x, y;
    ll k, v;
    cin >> n >> k;
    vector<interval> arr;
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y >> v;
        arr.pb(interval(x, y, v));
    }
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++)
    {
        int l = arr[i].l;
        for (int j = i; j < n; j++)
        {
            
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}