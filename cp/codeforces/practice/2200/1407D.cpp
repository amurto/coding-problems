// https://codeforces.com/contest/1407/problem/D
// Discrete Centrifugal Jumps

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

int solve()
{
    int n;
    cin >> n;
    vector<int> arr(n), dis(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    stack<int> st_dec, st_inc;
    st_dec.push(0);
    st_inc.push(0);
    for (int i = 1; i < n; i++)
    {
        dis[i] = i + 1;
        while (!st_dec.empty() && arr[i] > arr[st_dec.top()])
        {
            dis[i] = min(dis[i], dis[st_dec.top()] + 1);
            st_dec.pop();
        }
        while (!st_inc.empty() && arr[i] < arr[st_inc.top()])
        {
            dis[i] = min(dis[i], dis[st_inc.top()] + 1);
            st_inc.pop();
        }
        if (!st_dec.empty())
        {
            dis[i] = min(dis[i], dis[st_dec.top()] + 1);
            if (arr[i] == arr[st_dec.top()])
                st_dec.pop();
        }
        if (!st_inc.empty())
        {
            dis[i] = min(dis[i], dis[st_inc.top()] + 1);
            if (arr[i] == arr[st_inc.top()])
                st_inc.pop();
        }
        st_dec.push(i);
        st_inc.push(i);
    }
    return dis[n - 1];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}