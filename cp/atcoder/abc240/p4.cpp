#ifdef use_debug
#define TERMINAL
#include "headers/debug.cpp"
#else
#define d(...) 0
#endif
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    stack<pii> st;
    for (int i = 0; i < n; i++)
    {
        if (st.empty() || st.top().first != arr[i])
            st.push({arr[i], 1});
        else
            st.push({arr[i], st.top().second + 1});
        if (!st.empty() && st.top().first == st.top().second)
        {
            while (!st.empty() && st.top().first == arr[i])
                st.pop();
        }
        cout << (int)st.size() << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}