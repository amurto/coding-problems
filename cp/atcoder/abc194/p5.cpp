#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int solve()
{
    int n, m;
    cin >> n >> m;
    set<int> st;
    vector<int> arr(n), ms(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for (int i = 0; i < n; i++)
        st.insert(i);
    for (int i = 0; i < m; i++)
    {
        st.erase(arr[i]);
        ms[arr[i]]++;
    }
    int res = *st.begin();
    for (int i = m; i < n; i++)
    {
        int l = i - m;
        ms[arr[l]]--;
        if (ms[arr[l]] == 0)
            st.insert(arr[l]);
        ms[arr[i]]++;
        st.erase(arr[i]);
        res = min(res, *st.begin());
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}