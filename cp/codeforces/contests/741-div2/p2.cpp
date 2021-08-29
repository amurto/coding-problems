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

bool check(int x)
{
    if (x == 1)
        return true;
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0)
            return true;
    return false;
}

void solve()
{
    int n;
    string str;
    cin >> n >> str;
    vector<int> cnt(10);
    vector<bool> is_prime(10);
    is_prime[2] = is_prime[3] = is_prime[5] = is_prime[7] = true;
    for (char ch : str)
        cnt[ch - '0']++;
    for (int i = 1; i < 10; i++)
    {
        if (!is_prime[i] && cnt[i] > 0)
        {
            cout << 1 << "\n"
                 << i << "\n";
            return;
        }
    }
    for (int i = 1; i < 10; i++)
    {
        if (is_prime[i] && cnt[i] >= 2)
        {
            cout << 2 << "\n"
                 << i * 10 + i << "\n";
            return;
        }
    }
    vector<int> st;
    for (char ch : str)
        if (is_prime[ch - '0'])
            st.pb(ch - '0');
    int sz = st.size();
    int bits = 10, ans = 0;
    for (int i = 1; i < (1 << sz); i++)
    {
        int num = 0, digits = 0;
        for (int j = 0; j < sz; j++)
        {
            if ((i >> j) & 1)
            {
                digits++;
                num *= 10;
                num += st[j];
            }
        }
        if (check(num) && digits < bits)
        {
            bits = digits;
            ans = num;
        }
    }
    cout << bits << "\n"
         << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        solve();
    return 0;
}