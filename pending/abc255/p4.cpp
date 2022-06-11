#ifdef use_debug
#define TERMINAL
#include "headers/debug.cpp"
#else
#define d(...) 0
#endif
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

void solve()
{
    int n, q, n1 = 0, n2 = 0;
    cin >> n >> q;
    multiset<int> ms;
    ll sum1 = 0, sum2 = 0;
    vector<int> arr(n), x(q), ids(q);
    vector<ll> answers(q);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        ms.insert(arr[i]);
        sum2 += 1ll * arr[i];
        n2++;
    }
    for (int i = 0; i < q; i++)
        cin >> x[i];
    iota(ids.begin(), ids.end(), 0);
    sort(ids.begin(), ids.end(), [&](int i1, int i2)
         { return x[i1] < x[i2]; });
    for (int id : ids)
    {
        while (!ms.empty() && *ms.begin() < x[id])
        {
            int val = *ms.begin();
            sum2 -= 1ll * val;
            sum1 += 1ll * val;
            n2--;
            n1++;
            ms.erase(ms.begin());
        }
        answers[id] = n1 * 1ll * x[id] - sum1 + sum2 - n2 * 1ll * x[id];
    }
    for (ll answer : answers)
        cout << answer << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}