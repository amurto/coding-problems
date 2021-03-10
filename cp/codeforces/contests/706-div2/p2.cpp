#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    set<int> st;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        st.insert(arr[i]);
    }
    sort(arr.begin(), arr.end());
    int mex = arr[n - 1] + 1;
    if (arr[0] > 0)
        mex = 0;
    for (int i = 1; i < n; i++)
        if (arr[i] - arr[i - 1] > 1)
            mex = min(mex, arr[i - 1] + 1);
    if (mex > arr[n - 1])
        return n + k;
    if (k > 0)
    {
        int e = (arr[n - 1] + mex + 1) / 2;
        st.insert(e);
    }
    int sz = st.size();
    return sz;
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