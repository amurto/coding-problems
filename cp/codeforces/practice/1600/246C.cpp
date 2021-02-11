// https://codeforces.com/contest/246/problem/C
// Beauty Pageant

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

void solve()
{
    int n, k, sum = 0;
    cin >> n >> k;
    vector<int> arr(n);
    unordered_set<int> st;
    vector<vector<int>> res;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr.rbegin(), arr.rend());
    for (int i = 0; res.size() < k && i < n; i++)
    {
        if (st.find(arr[i]) == st.end())
        {
            st.insert(arr[i]);
            vector<int> vec = {arr[i]};
            res.pb(vec);
        }
    }
    vector<int> seq;
    for (int i = 0; res.size() < k && i < n; i++)
    {
        sum += arr[i];
        seq.pb(arr[i]);
        for (int j = i + 1; res.size() < k && j < n; j++)
        {
            if (st.find(sum + arr[j]) == st.end())
            {
                st.insert(sum + arr[j]);
                seq.pb(arr[j]);
                res.pb(seq);
                seq.pop_back();
            }
        }
    }
    for (vector<int> s : res)
    {
        cout << s.size() << " ";
        for (int e : s)
            cout << e << " ";
        cout << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}