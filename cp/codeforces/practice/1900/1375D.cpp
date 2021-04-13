// https://codeforces.com/contest/1375/problem/D
// Replace by MEX

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int find_mex(vector<int> &cnt, int n)
{
    for (int i = 0; i <= n; i++)
        if (cnt[i] == 0)
            return i;
    return n;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n), cnt(n + 1), res;
    set<int> st;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for (int i = 0; i < n; i++)
    {
        if (i != arr[i])
            st.insert(i);
        cnt[arr[i]]++;
    }
    int mex = find_mex(cnt, n);
    while (!st.empty())
    {
        if (mex == n)
        {
            int idx = *st.begin();
            res.pb(idx);
            cnt[arr[idx]]--;
            cnt[mex]++;
            swap(mex, arr[idx]);
        }
        else
        {
            res.pb(mex);
            st.erase(mex);
            cnt[mex]++;
            cnt[arr[mex]]--;
            swap(mex, arr[mex]);
        }
        mex = find_mex(cnt, n);
    }
    cout << res.size() << "\n";
    for (int r : res)
        cout << r + 1 << " ";
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