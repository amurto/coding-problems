// https://codeforces.com/contest/992/problem/B
// Nastya Studies Informatics

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int calc(vector<int> &st, int cur, int l, int r, int num1, int num2)
{
    if (cur == st.size())
        return min(num1, num2) >= l && max(num1, num2) <= r;
    return calc(st, cur + 1, l, r, num1 * st[cur], num2) + calc(st, cur + 1, l, r, num1, num2 * st[cur]);
}

int solve()
{
    int l, r, x, y;
    cin >> l >> r >> x >> y;
    if (y % x > 0)
        return 0;
    y /= x;
    vector<int> st;
    for (int i = 2; i * i <= y; i++)
    {
        if (y % i == 0)
        {
            int num = 1;
            while (y % i == 0)
            {
                y /= i;
                num *= i;
            }
            st.pb(num);
        }
    }
    if (y > 1)
        st.pb(y);
    return calc(st, 0, l, r, x, x);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}