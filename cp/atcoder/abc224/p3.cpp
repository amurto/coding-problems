#ifdef use_debug
#define TERMINAL
#include "headers/debug.cpp"
#else
#define d(...) 0
#endif
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;
#define pb push_back

int cmp(ll a, ll b)
{
    if (a < b)
        return -1;
    if (a == b)
        return 0;
    return 1;
}

bool is_between(pii a, pii b, pii c)
{
    return ((b.first - a.first) * (c.second - a.second) == (c.first - a.first) * (b.second - a.second) &&
            abs(cmp(a.first, c.first) + cmp(b.first, c.first)) <= 1 &&
            abs(cmp(a.second, c.second) + cmp(b.second, c.second)) <= 1);
}

int solve()
{
    int n, res = 0;
    cin >> n;
    vector<pii> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i].first >> arr[i].second;
    sort(arr.begin(), arr.end());
    for (int k = 0; k < n; k++)
        for (int j = 0; j < k; j++)
            for (int i = 0; i < j; i++)
                if (!is_between(arr[i], arr[k], arr[j]))
                    res++;
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