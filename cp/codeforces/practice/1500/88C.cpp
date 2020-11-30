// https://codeforces.com/contest/88/problem/C
// Trains

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    vector<ll> d(2), t(2), cnt(2);
    cin >> d[0] >> d[1];
    if (d[0] < d[1])
    {
        t[0] += d[0];
        cnt[0] += d[0];
    }
    else
    {
        t[1] += d[1];
        cnt[1] += d[1];
    }
    while (t[0] != t[1])
    {
        if (t[0] + d[0] < t[1] + d[1])
        {
            cnt[0] += t[0] + d[0] - max(t[0], t[1]);
            t[0] += d[0];
        }
        else if (t[0] + d[0] > t[1] + d[1])
        {
            cnt[1] += t[1] + d[1] - max(t[0], t[1]);
            t[1] += d[1];
        }
        else
        {
            if (d[0] > d[1])
                cnt[0] += t[0] + d[0] - max(t[0], t[1]);
            else
                cnt[1] += t[1] + d[1] - max(t[0], t[1]);
            t[0] += d[0];
            t[1] += d[1];
        }
    }
    if (cnt[0] > cnt[1])
        cout << "Dasha\n";
    else if (cnt[0] < cnt[1])
        cout << "Masha\n";
    else
        cout << "Equal\n";
    return 0;
}