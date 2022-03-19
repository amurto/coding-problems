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

bool is_valid(vector<ll> &seq, vector<ll> &a, int n)
{
    for (int i = 0; i < n; i++)
        if (seq[i] != (a[i] + a[i + 1] + a[i + 2]))
            return false;
    for (int x : a)
        if (x < 0)
            return false;
    return true;
}

void solve()
{
    int n;
    cin >> n;
    vector<ll> s(n), arr(n + 2), res(n + 2);
    for (int i = 0; i < n; i++)
        cin >> s[i];
    vector<ll> seq = s;
    if (n == 1)
        res[0] = s[0];
    else if (n == 2)
    {
        if (s[0] > s[1])
        {
            res[0] = s[0] - s[1];
            s[0] -= res[0];
        }
        res[1] = s[0];
        s[0] -= res[1];
        s[1] -= res[1];
        res[3] = s[1];
    }
    else
    {
        for (int i = 0; i < n; i++)
            arr[i] = s[i];
        for (int i = 1; i < n; i++)
        {
            arr[i] -= arr[i - 1];
            if (arr[i] < 0)
            {
                if (i & 1)
                    arr[0] += arr[i];
                else
                    arr[0] += abs(arr[i]);
            }
        }
        vector<ll> tmp(n + 2);
        tmp[0] = arr[0];
        for (int i = 1; i < n; i++)
            tmp[i] = s[i];
        for (int i = 1; i < n; i++)
        {
            tmp[i] -= tmp[i - 1];
            res[i + 1] = tmp[i - 1];
        }
        if (res[n + 1] + res[n] + res[n - 1] < s[n - 1])
            res[n + 1] += (s[n - 1] - (res[n + 1] + res[n] + res[n - 1]));
        d(res);
        s[0] -= (res[0] + res[1] + res[2]);
        s[1] -= (res[1] + res[2] + res[3]);
        if (s[0] < 0 || s[1] < 0 || s[0] < s[1])
        {
            cout << "No\n";
            return;
        }
        res[0] = s[0] - s[1];
        res[1] = s[1];
    }

    if (!is_valid(seq, res, n))
    {
        cout << "No\n";
        return;
    }

    cout << "Yes\n";
    for (ll x : res)
        cout << x << " ";
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}