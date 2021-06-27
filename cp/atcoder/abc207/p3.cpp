#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<pair<int, int>, int> piii;
#define pb push_back

class interval
{
public:
    ll t = 0, l = 0, r = 0;
    interval() {}
    interval(ll t, ll l, ll r) : t(t), l(l), r(r) {}
};

bool intersect(interval i1, interval i2)
{
    if (i1.l > i2.l)
        swap(i1, i2);
    return i1.r >= i2.l;
}
int solve()
{
    int n, res = 0;
    ll t, l, r;
    cin >> n;
    vector<interval> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> t >> l >> r;
        l *= 10;
        r *= 10;
        if (t == 2)
            r--;
        else if (t == 3)
            l++;
        else if (t == 4)
        {
            l++;
            r--;
        }
        arr[i] = interval(t, l, r);
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < i; j++)
            res += intersect(arr[i], arr[j]);
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}