#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int solve()
{
    int n, x, y, k, cnt = 0;
    cin >> n >> x >> y >> k;
    vector<int> arr(n);
    set<int> st;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (arr[i] >= x && arr[i] <= y)
        {
            st.insert(arr[i]);
            cnt++;
        }
    }
    int d = st.size(), r = y - x + 1;
    r -= d;
    if (cnt > d && r > 0 && k > 0)
    {
        int ch = min({r, k, cnt - d});
        d += ch;
        cnt -= ch;
        r -= ch;
        k -= ch;
    }
    set<int> s;
    int f = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < x || arr[i] > y)
        {
            s.insert(arr[i]);
            f++;
        }
    }
    int sz = s.size();
    d += sz;
    if (r > 0 && k > 0)
        d += min({f - sz, r, k});
    return d;
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