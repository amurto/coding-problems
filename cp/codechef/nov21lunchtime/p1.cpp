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

vector<int> next_smaller(vector<ll> &arr, int n)
{
    // next <=
    vector<int> seq(n, n - 1);
    stack<int> st;
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && arr[st.top()] > arr[i])
            st.pop();
        if (!st.empty())
            seq[i] = st.top();
        st.push(i);
    }
    return seq;
}

ll solve()
{
    int n;
    cin >> n;
    ll res = 0;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    vector<int> seq = next_smaller(arr, n);
    for (int i = 0; i < n - 1;)
    {
        int nxt = seq[i];
        res += arr[i] * (nxt - i + 1) - arr[nxt];
        i = seq[i];
    }
    return max(0ll, res);
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