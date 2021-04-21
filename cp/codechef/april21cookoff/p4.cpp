#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

set<int> st;
map<int, int> p1, p2, ms;

void add(int &t, int x)
{
    ms[x]--;
    if (ms[x] == 0)
    {
        auto itr = st.lower_bound(x);
        int l = -1, r = -1;
        if (itr != st.end())
            r = *itr;
        if (itr != st.begin())
        {
            itr--;
            l = *itr;
        }
        if (l != -1 && p2[l] > p1[x])
            t += 1;
        if (r != -1 && p2[x] > p1[r])
            t += 1;
        if (l != -1 && r != -1 && p2[l] > p1[r])
            t -= 1;
        st.insert(x);
    }
}

void rem(int &t, int x)
{
    if (ms[x] == 0)
    {
        auto itr = st.lower_bound(x);
        st.erase(x);
        int l = -1, r = -1;
        itr = st.lower_bound(x);
        if (itr != st.end())
            r = *itr;
        if (itr != st.begin())
        {
            itr--;
            l = *itr;
        }
        if (l != -1 && p2[l] > p1[x])
            t -= 1;
        if (r != -1 && p2[x] > p1[r])
            t -= 1;
        if (l != -1 && r != -1 && p2[l] > p1[r])
            t += 1;
    }
    ms[x]++;
}

ll solve()
{
    int n, t = 0, r = 0;
    ll res = 0;
    cin >> n;
    vector<int> arr(n);
    st.clear();
    p1.clear();
    p2.clear();
    ms.clear();
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        st.insert(arr[i]);
        if (!p1.count(arr[i]))
            p1[arr[i]] = i;
        p2[arr[i]] = i;
    }
    for (auto it = st.begin(); it != st.end(); it++)
    {
        if (it != st.begin())
        {
            auto prev = --it;
            it++;
            t += (p2[*prev] > p1[*it]);
        }
    }
    if (t == 0)
        return (n * 1ll * (n + 1)) / 2;
    for (int l = 0; l < n; l++)
    {
        while (t > 0 && r < n)
        {
            rem(t, arr[r]);
            r++;
        }
        if (t == 0)
            res += 1ll * (n - r + 1);
        add(t, arr[l]);
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