#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

void display(vector<int> &st)
{
    for (int i = 0; i < st.size(); i++)
    {
        cout << st[i];
        if (i < st.size() - 1)
            cout << ".";
    }
    cout << "\n";
}

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    vector<int> st;
    for (int i = 0; i < n; i++)
    {
        if (st.empty())
            st.pb(arr[i]);
        else
        {
            if (arr[i] == 1)
                st.pb(1);
            else
            {
                while (!st.empty() && st.back() != arr[i] - 1)
                    st.pop_back();
                st.pop_back();
                st.pb(arr[i]);
            }
        }
        display(st);
    }
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