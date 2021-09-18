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

class attraction
{
public:
    ll h;
    int s, t;
    attraction() {}
    attraction(ll h, int s, int t) : h(h), s(s), t(t) {}
    bool operator<(const attraction &other) const
    {
        return s < other.s;
    }
};

ll solve()
{
    int d, n, k, s, t;
    ll h, cur_sum = 0, res = 0;
    cin >> d >> n >> k;
    vector<attraction> arr;
    for (int i = 0; i < n; i++)
    {
        cin >> h >> s >> t;
        arr.pb(attraction(h, s, t));
    }
    sort(arr.begin(), arr.end());
    auto cmp = [&](int &i1, int &i2)
    {
        return arr[i1].t > arr[i2].t;
    };
    priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
    multiset<ll> ms1, ms2;
    for (int i = 1, cur = 0; i <= d; i++)
    {
        while (cur < n && arr[cur].s == i)
        {
            pq.push(cur);
            ms1.insert(arr[cur].h);
            cur_sum += arr[cur].h;
            cur++;
        }
        int sz = (int)ms1.size();
        while (sz < k && !ms2.empty())
        {
            ms1.insert(*ms2.rbegin());
            cur_sum += *ms2.rbegin();
            ms2.erase(--ms2.end());
            sz++;
        }
        while (sz > k)
        {
            ms2.insert(*ms1.begin());
            cur_sum -= *ms1.begin();
            ms1.erase(ms1.begin());
            sz--;
        }
        res = max(res, cur_sum);
        while (!pq.empty() && arr[pq.top()].t == i)
        {
            int id = pq.top();
            pq.pop();
            if (!ms2.empty() && ms2.count(arr[id].h))
                ms2.erase(ms2.lower_bound(arr[id].h));
            else
            {
                cur_sum -= arr[id].h;
                ms1.erase(ms1.lower_bound(arr[id].h));
            }
        }
        sz = (int)ms1.size();
        while (sz < k && !ms2.empty())
        {
            ms1.insert(*ms2.rbegin());
            cur_sum += *ms2.rbegin();
            ms2.erase(--ms2.end());
            sz++;
        }
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int tc = 1; tc <= t; tc++)
        cout << "Case #" << tc << ": " << solve() << "\n";
    return 0;
}