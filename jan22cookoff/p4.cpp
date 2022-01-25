#ifdef use_debug
#define TERMINAL
#include "headers/debug.cpp"
#else
#define d(...) 0
#endif
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

bool solve()
{
    int n;
    cin >> n;
    vector<int> arr(n), pre_mn(n), pre_mx(n), suf_mn(n), suf_mx(n), mn_val(n), mx_val(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    if (n <= 2)
    {
        if (n == 1)
            return true;
        if (arr[0] < arr[1])
            return true;
        return false;
    }
    pre_mn[0] = pre_mx[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        pre_mn[i] = min(pre_mn[i - 1], arr[i]);
        pre_mx[i] = max(pre_mx[i - 1], arr[i]);
    }
    suf_mn[n - 1] = suf_mx[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        suf_mn[i] = min(suf_mn[i + 1], arr[i]);
        suf_mx[i] = max(suf_mx[i + 1], arr[i]);
    }
    set<int> st;
    for (int i = 0; i < n; i++)
    {
        if (st.empty() || *st.begin() > arr[i])
            st.insert(arr[i]);
        mn_val[i] = *st.rbegin();
        if (i == n - 1)
        {
            if ((int)st.size() == 1)
                return true;
        }
    }
    st.clear();
    for (int i = n - 1; i >= 0; i--)
    {
        if (st.empty() || *st.rbegin() < arr[i])
            st.insert(arr[i]);
        mx_val[i] = *st.begin();
        if (i == 0)
        {
            if ((int)st.size() == 1)
                return true;
        }
    }
    if (arr[0] == 1 || arr[n - 1] == n)
        return true;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 1)
        {
            int pmn = 0, smx = 0;
            if (i - 1 >= 0)
                pmn = mn_val[i - 1];
            if (i + 1 < n)
                smx = suf_mx[i + 1];
            if (pmn < smx)
                return true;
        }
        else if (arr[i] == n)
        {
            int pmn = n + 1, smx = 0;
            if (i - 1 >= 0)
                pmn = pre_mn[i - 1];
            if (i + 1 < n)
                smx = mx_val[i + 1];
            if (pmn < smx)
                return true;
        }
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        solve() ? cout << "YES\n" : cout << "NO\n";
    return 0;
}