// https://codeforces.com/contest/1062/problem/B
// Math

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

void solve()
{
    int n, mn = 1, p = 1, inc = 0, op = 0;
    cin >> n;
    if (n == 1)
    {
        cout << "1 0\n";
        return;
    }
    vector<int> st;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            int cnt = 0;
            while (n % i == 0)
            {
                n /= i;
                cnt++;
            }
            mn *= i;
            st.pb(cnt);
        }
    }
    mn *= n;
    if (n > 1)
        st.pb(1);
    sort(st.begin(), st.end());
    while (p < st.back())
    {
        op++;
        p <<= 1;
    }
    for (int s : st)
        inc += (p > s);
    cout << mn << " " << op + (inc > 0) << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}