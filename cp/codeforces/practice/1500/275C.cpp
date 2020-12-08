// https://codeforces.com/contest/275/problem/C
// k-Multiple Free Set

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n, k, res = 0;
    cin >> n >> k;
    vector<ll> arr(n);

    for (int i = 0; i < n; i++)
        cin >> arr[i];
    unordered_set<ll> st(arr.begin(), arr.end());
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++)
    {
        if (st.find(arr[i]) == st.end())
            continue;
        ll cur = arr[i], chain = 0;
        while (st.find(cur) != st.end())
        {
            st.erase(cur);
            cur *= k;
            chain++;
        }
        res += (chain + 1)/2;
    }

    cout << res << "\n";
    return 0;
}