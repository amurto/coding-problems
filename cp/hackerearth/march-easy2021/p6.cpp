#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

// Fastest approach
// O(nlogn)
// Uses Set to maintain length of Longest Increasing Subsequence
int LIS(vector<int> &arr, int n)
{
    int mx = 0;
    set<int> st;
    for (int i = 0; i < n; i++)
    {
        if (st.lower_bound(arr[i]) == st.end())
            mx++;
        else
            st.erase(st.lower_bound(arr[i]));
        st.insert(arr[i]);
    }
    return mx;
}

int solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    reverse(arr.begin(), arr.end());
    return LIS(arr, n);
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