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

// Red -> 0, Yellow -> 1, Blue -> 2
int solve()
{
    int n, res = 0, cur = 0;
    string str;
    cin >> n >> str;
    // R
    for (int i = 0; i < n; i++)
    {
        if (str[i] == 'R' || str[i] == 'O' || str[i] == 'P' || str[i] == 'A')
            cur++;
        else
        {
            if (cur > 0)
                res++;
            cur = 0;
        }
    }
    if (cur > 0)
        res++;
    cur = 0;

    // Y
    for (int i = 0; i < n; i++)
    {
        if (str[i] == 'Y' || str[i] == 'O' || str[i] == 'G' || str[i] == 'A')
            cur++;
        else
        {
            if (cur > 0)
                res++;
            cur = 0;
        }
    }
    if (cur > 0)
        res++;
    cur = 0;

    // B
    for (int i = 0; i < n; i++)
    {
        if (str[i] == 'B' || str[i] == 'P' || str[i] == 'G' || str[i] == 'A')
            cur++;
        else
        {
            if (cur > 0)
                res++;
            cur = 0;
        }
    }
    if (cur > 0)
        res++;
    cur = 0;

    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int tc = 1; tc <= t; tc++)
        cout << "Case #" << tc << ": " << solve() << "\n";
    return 0;
}