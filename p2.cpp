#ifdef amurto
#define TERMINAL
#include "headers/debug.cpp"
#else
#define d(...) 0
#endif
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int match(string s1, string s2, int n)
{
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (s2[i] == '1')
        {
            if (i > 0 && s1[i - 1] == '1')
            {
                s1[i - 1] = '0';
                cnt++;
            }
            else if (i < n && s1[i + 1] == '1')
            {
                s1[i + 1] = '0';
                cnt++;
            }
        }
    }
    return cnt;
}

int solve()
{
    int n, res = 0, cnt = 0;
    string s1, s2;
    cin >> n >> s1 >> s2;
    for (int i = 0; i < n; i++)
    {
        if (s2[i] == '1' && s1[i] == '0')
        {
            s2[i] = '0';
            cnt++;
        }
    }
    for (int i = 0; i < 2; i++)
    {
        res = max(res, cnt + match(s1, s2, n));
        reverse(s1.begin(), s1.end());
        reverse(s2.begin(), s2.end());
    }
    return res;
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