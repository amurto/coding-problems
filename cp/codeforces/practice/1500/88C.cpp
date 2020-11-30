// https://codeforces.com/contest/88/problem/C
// Trains

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int lcm(int x, int y)
{
    return (x * y) / __gcd(x, y);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int a, b, cur = 0;
    vector<int> cnt(2);
    cin >> a >> b;
    if (a < b)
        cur = 1;
    cnt[cur]++;
    for (int i = lcm(a, b) - 1; i >= 1; i--)
    {
        if (i % a == 0)
            cur = 0;
        if (i % b == 0)
            cur = 1;
        cnt[cur]++;
    }

    // cout << cnt[0] << " " << cnt[1] << "\n";
    if (cnt[0] > cnt[1])
        cout << "Dasha\n";
    else if (cnt[0] < cnt[1])
        cout << "Masha\n";
    else
        cout << "Equal\n";
    return 0;
}