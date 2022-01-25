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
    vector<string> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for (int t = 0; t < 2; t++)
    {
        map<string, bool> vis;
        for (int i = n - 1; i >= 0; i--)
        {
            string tmp = arr[i];
            reverse(tmp.begin(), tmp.end());
            int len = (int)arr[i].length();
            if (len == 1)
                return true;
            else if (len == 2)
            {
                if (arr[i][0] == arr[i][1])
                    return true;
                if (vis[tmp])
                    return true;
            }
            else
            {
                if (arr[i][0] == arr[i][2])
                    return true;
                if (vis[tmp.substr(1, 2)])
                    return true;
                if (vis[tmp])
                    return true;
            }
            vis[arr[i]] = true;
        }
        for (int i = 0; i < n; i++)
            reverse(arr[i].begin(), arr[i].end());
        reverse(arr.begin(), arr.end());
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