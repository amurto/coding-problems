#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

void solve()
{
    int n, v;
    cin >> n;
    vector<int> arr;
    set<int> st;
    for (int i = 0; i < n; i++)
    {
        cin >> v;
        arr.pb(v);
        st.insert(v);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (st.find(abs(arr[i] - arr[j])) == st.end())
            {
                arr.pb(abs(arr[i] - arr[j]));
                st.insert(abs(arr[i] - arr[j]));
                n++;
                if (n == 301)
                {
                    cout << "NO\n";
                    return;
                }
            }
        }
    }
    cout << "YES\n";
    cout << arr.size() << "\n";
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
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