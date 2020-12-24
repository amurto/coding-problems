// https://codeforces.com/contest/534/problem/B
// Covered Path

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

bool reach(int L, int R, int d, int t, int h)
{
    int change = abs(h - L) / d + abs(h - R) / d;
    int diff = abs(h - L) % d + abs(h - R) % d;
    if (diff > d)
        change += 2;
    else if (diff > 0)
        change++;
    if (change > t - 1)
        return false;
    return true;
}

int solve()
{
    int L, R, t, d, peak = 0;
    cin >> L >> R >> t >> d;
    if (d == 0)
        return L * t;
    if (t == 2)
        return L + R;
    int low = min(L, R), high = 1000;
    while (low <= high)
    {

        int mid = (low + high) / 2;
        if (reach(L, R, d, t, mid))
        {
            peak = max(peak, mid);
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    int sum = 0, cnt = 0;
    while (L < peak)
    {
        cnt++;
        sum += L;
        L += d;
    }
    while (R < peak)
    {
        cnt++;
        sum += R;
        R += d;
    }
    while (cnt++ < t)
        sum += peak;
    return sum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}