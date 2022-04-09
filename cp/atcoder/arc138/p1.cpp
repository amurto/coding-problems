#ifdef use_debug
#define TERMINAL
#include "headers/debug.cpp"
#else
#define d(...) 0
#endif
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back

const int inf = 1e9 + 7;
int solve()
{
    int n, k, res = inf;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    map<int, int> last;
    for (int i = n - 1; i >= k; i--)
        last[arr[i]] = i;
    vector<pii> seq;
    for (auto x : last)
        seq.pb({x.first, x.second});
    sort(seq.begin(), seq.end());
    int sz = (int)seq.size();
    for (int i = sz - 2; i >= 0; i--)
        seq[i].second = min(seq[i].second, seq[i + 1].second);
    for (int i = 0; i < k; i++)
    {
        int id = lower_bound(seq.begin(), seq.end(), pii(arr[i] + 1, 0)) - seq.begin();
        if (id < sz)
            res = min(res, k - i + seq[id].second - k);
    }
    return res >= inf ? -1 : res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}