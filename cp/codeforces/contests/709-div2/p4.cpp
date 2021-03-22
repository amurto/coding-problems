#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int nxt(set<int> &ids, int cur)
{
    auto it = ids.upper_bound(cur);
    if (it == ids.end())
        return *ids.begin();
    return *it;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n), res;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    set<int> ids, st;
    for (int i = 0; i < n - 1; i++)
        if (__gcd(arr[i], arr[i + 1]) == 1)
            st.insert(i);
    if (__gcd(arr[n - 1], arr[0]) == 1)
        st.insert(n - 1);
    for (int i = 0; i < n; i++)
        ids.insert(i);
    int cur = 0;
    while (!st.empty())
    {
        auto it = st.lower_bound(cur);
        if (it == st.end())
            cur = *st.begin();
        else
            cur = *it;
        int idx = nxt(ids, cur);
        ids.erase(idx);
        st.erase(cur);
        st.erase(idx);
        res.pb(idx + 1);
        int ncur = nxt(ids, cur);
        if (cur != ncur && __gcd(arr[cur], arr[ncur]) == 1)
            st.insert(cur);
        cur = ncur;
    }
    if (ids.size() == 1 && arr[*ids.begin()] == 1)
        res.pb(*ids.begin() + 1);
    cout << res.size() << " ";
    for (int r : res)
        cout << r << " ";
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        solve();
    return 0;
}