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

const int inf = 1e9 + 7;
int solve()
{
    int n, slast = -1, last = -1, res = inf;
    string str;
    cin >> n >> str;
    vector<vector<int>> cnt(n, vector<int>(3));
    for (int i = 0; i < n; i++)
    {
        if (i > 0)
            cnt[i] = cnt[i - 1];
        cnt[i][str[i] - 'a']++;
        if (str[i] == 'a')
        {
            if (last >= 0)
            {
                int b = cnt[i][1] - cnt[last][1], c = cnt[i][2] - cnt[last][2];
                if (b < 2 && c < 2)
                    res = min(res, 2 + b + c);
            }
            if (slast >= 0)
            {
                int b = cnt[i][1] - cnt[slast][1], c = cnt[i][2] - cnt[slast][2];
                if (b < 3 && c < 3)
                    res = min(res, 3 + b + c);
            }
            slast = last;
            last = i;
        }
    }
    if (res == inf)
        return -1;
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