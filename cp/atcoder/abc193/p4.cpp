#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int pw(int c)
{
    int res = 1;
    if (c == 0)
        return 1;
    while (c-- > 0)
        res *= 10;
    return res;
}

int sc(vector<int> &st, int last)
{
    int res = 0;
    st[last]++;
    for (int i = 1; i < 10; i++)
        res += i * pw(st[i]);
    st[last]--;
    return res;
}

double solve()
{
    int k;
    string s, t;
    cin >> k >> s >> t;
    vector<int> cnt(10, k), st1(10), st2(10);
    for (int i = 0; i < 4; i++)
    {
        cnt[s[i] - '0']--;
        cnt[t[i] - '0']--;
        st1[s[i] - '0']++;
        st2[t[i] - '0']++;
    }
    ll w1 = 0, w2 = 0;
    for (int i = 1; i <= 9; i++)
    {
        if (cnt[i] == 0)
            continue;
        ll w = cnt[i];
        cnt[i]--;
        for (int j = 1; j <= 9; j++)
        {
            if (cnt[j] == 0)
                continue;
            if (sc(st1, i) > sc(st2, j))
                w1 += w * 1ll * cnt[j];
            else
                w2 += w * 1ll * cnt[j];
        }
        cnt[i]++;
    }
    return w1 * 1.0 / (w1 + w2) * 1.0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(18) << solve() << "\n";
    return 0;
}