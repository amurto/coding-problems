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

void solve()
{
    int n;
    string str;
    cin >> n >> str;
    vector<int> prev(n + 1, -1), nxt(n + 1, -1);
    for (int i = 0; i < n; i++)
    {
        int cur = i + 1;
        if (str[i] == 'L')
        {
            if (prev[i] >= 0)
            {
                nxt[prev[i]] = cur;
                prev[cur] = prev[i];
            }
            nxt[cur] = i;
            prev[i] = cur;
        }
        else
        {
            if (nxt[i] >= 0)
            {
                prev[nxt[i]] = cur;
                nxt[cur] = nxt[i];
            }
            prev[cur] = i;
            nxt[i] = cur;
        }
    }
    vector<int> arr;
    for (int i = 0; i <= n; i++)
    {
        if (prev[i] == -1)
        {
            int cur = i;
            while (cur != -1)
            {
                arr.pb(cur);
                cur = nxt[cur];
            }
        }
    }
    for (int x : arr)
        cout << x << " ";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}