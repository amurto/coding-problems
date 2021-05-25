#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back

int solve()
{
    int n, res = 0;
    cin >> n;
    vector<pii> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i].first >> arr[i].second;
    sort(arr.begin(), arr.end());
    multiset<int> st;
    for (int t = arr[0].first, i = 0; !st.empty() || i < n;)
    {
        while (i < n && arr[i].first == t)
        {
            st.insert(arr[i].second);
            i++;
        }
        if (!st.empty())
        {
            st.erase(st.begin());
            res++;
        }
        while (!st.empty() && *st.begin() == t)
            st.erase(st.begin());
        if (st.empty() && i < n)
            t = arr[i].first;
        else
            t++;
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
    while (t-- > 0)
        cout << solve() << "\n";
    return 0;
}