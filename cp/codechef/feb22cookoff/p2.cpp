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
    if (str[0] == '0' || str[1] == '0' || str.back() == '0')
    {
        cout << "No\n";
        return;
    }
    vector<int> arr;
    for (int i = 1; i <= n;)
    {
        int r = i;
        if (str[i] == '0')
        {
            while (r <= n && str[r] == '0')
                r++;
            for (int j = r - 1; j >= i - 1; j--)
                arr.pb(j);
            r++;
        }
        else
        {
            arr.pb(i - 1);
            r++;
        }
        i = r;
    }
    cout << "Yes\n";
    for (int x : arr)
        cout << x << " ";
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        solve();
    return 0;
}