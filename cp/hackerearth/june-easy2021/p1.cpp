#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n), ids;
    set<int> st;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (st.find(arr[i]) == st.end())
        {
            ids.pb(i + 1);
            st.insert(arr[i]);
        }
    }
    cout << ids.size() << "\n";
    for (int id : ids)
        cout << id << " ";
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