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

/*
4
10 7 3 6
*/

ll brute(vector<ll> &arr, int n)
{
    ll res = 0;
    string str = "";
    for (int i = 1; i <= n; i++)
    {
        if (i & 1)
        {
            for (int j = 0; j < arr[i]; j++)
                str.pb('(');
        }
        else
        {
            for (int j = 0; j < arr[i]; j++)
                str.pb(')');
        }
    }
    d(str);
    for (int i = 0; i < str.length(); i++)
    {
        int op = 0;
        for (int j = i; op >= 0 && j < str.length(); j++)
        {
            if (str[j] == '(')
                op++;
            else
                op--;
            if (op == 0)
                res++;
        }
    }
    return res;
}
ll solve()
{
    int n;
    ll res = 0;
    cin >> n;
    vector<ll> arr(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    return brute(arr, n);
    for (int i = 1; i <= n; i += 2)
    {
        ll op = arr[i];
        for (int j = i + 1; j <= n; j++)
        {
            if (j & 1)
                op += arr[j];
            else
            {
                ll tmp = op;
                op -= arr[j];
                res += max(0ll, min(tmp, arr[i]) - max(0ll, op));
            }
            if (op < 0)
                break;
        }
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}