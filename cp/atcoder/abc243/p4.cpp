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

ll solve()
{
    int n;
    ll x;
    string str;
    cin >> n >> x >> str;
    stack<int> st;
    for (char ch : str)
    {
        if (ch == 'U')
        {
            if (st.empty())
                x /= 2;
            else
                st.pop();
        }
        else if (ch == 'L')
            st.push(0);
        else
            st.push(1);
    }
    vector<int> arr;
    while (!st.empty())
    {
        arr.pb(st.top());
        st.pop();
    }
    reverse(arr.begin(), arr.end());
    for (int v : arr)
    {
        x *= 2;
        x += v;
    }
    return x;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}