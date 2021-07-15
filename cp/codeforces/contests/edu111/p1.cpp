#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int solve()
{
    int s, sz = 1, cur = 1, sum = 1;
    cin >> s;
    while (sum < s)
    {
        cur += 2;
        sum += cur;
        sz++;
    }
    return sz;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        cout << solve() << "\n";
    return 0;
}