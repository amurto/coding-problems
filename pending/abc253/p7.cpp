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

void solve()
{
    int n;
    ll L, R;
    cin >> n >> L >> R;
    vector<int> arr(n + 1);
    iota(arr.begin(), arr.end(), 0);
    vector<ll> pre(n + 1);
    for (int i = 1; i <= n; i++)
        pre[i] = pre[i - 1] + n - i;
    auto id = [&](ll val) -> pii
    {
        for (int i = 1; i <= n; i++)
            if (pre[i] >= val)
                return {i, val - pre[i - 1] + i};
        return {-1, -1};
    };
    pii l = id(L), r = id(R);
    if (l.first < r.first)
    {
        for (int i = l.first, j = l.second; j <= n; j++)
            swap(arr[i], arr[j]);
    }
    l.first++;
    l.second++;
    if (l.first < r.first)
    {
        int t = r.first - l.first;
        vector<int> terms(n - l.first + 1);
        int itr = 0;
        for (int i = n; i > n - t; i--, itr++)
            terms[itr] = arr[i];
        for (int i = l.first; itr < (int)terms.size(); i++, itr++)
            terms[itr] = arr[i];
        itr = 0;
        for (int j = l.first; j <= n; j++, itr++)
            arr[j] = terms[itr];
    }
    if (l.first <= r.first)
    {
        for (int i = r.first, j = r.first + 1; j <= r.second; j++)
            swap(arr[i], arr[j]);
    }

    for (int i = 1; i <= n; i++)
        cout << arr[i] << " ";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}