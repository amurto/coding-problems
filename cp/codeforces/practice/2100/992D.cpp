// https://codeforces.com/contest/992/problem/D
// Nastya and a Game

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

bool is_overflow(ll x, ll y, ll sum)
{
    return x > (sum / y);
}

int solve()
{
    int n, res = 0, t = 0;
    ll k;
    cin >> n >> k;
    vector<ll> arr(n), seq(n);
    vector<int> last(n);
    int b = -1;
    for (int i = 0; i < n; i++)
    {
        last[i] = b;
        cin >> arr[i];
        seq[i] = arr[i] * k;
        if (arr[i] > 1)
            b = i;
    }
    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += seq[i];
        int l = i;
        ll p = 1, cur_sum = 0;
        while (l >= 0 && !is_overflow(p, arr[l], sum))
        {
            if (arr[l] == 1)
            {
                ll ones = l - last[l];
                if (cur_sum <= p && p % k == 0)
                {
                    ll req = (p-cur_sum)/k;
                    if (req>0 && req<=ones)
                        res++;
                }
                cur_sum += ones * k;
                l = last[l];
            }
            else
            {
                cur_sum += seq[l];
                p *= arr[l];
                if (cur_sum == p) 
                    res++;
                l--;
            }
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