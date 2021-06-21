#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 5e5 + 5;
vector<int> divs[N];

void init()
{
    for (int i = 1; i < N; i++)
        for (int j = i; j < N; j += i)
            divs[j].pb(i);
}

int op(string &str, vector<int> &pre, int cur, int d, int n)
{
    int cnt = 0;
    for (int i = cur; i < n; i += d)
    {
        int last = i - d;
        if (last < 0)
        {
            last += n;
            cnt = pre[i] + pre[n - 1] - pre[last];
            cnt -= (str[i] == '1');
            cnt += (str[i] == '0');
        }
        else
        {
            cnt += pre[i] - pre[last];
            cnt -= (str[i] == '1');
            cnt += (str[i] == '0');
        }
    }
    return cnt;
}

int solve()
{
    int n;
    string str;
    cin >> n >> str;
    if (count(str.begin(), str.end(), '1') == 0)
        return 1;
    vector<int> pre(n);
    for (int i = 0; i < n; i++)
    {
        pre[i] = (str[i] == '1');
        if (i > 0)
            pre[i] += pre[i - 1];
    }
    int mn = n;
    for (int d : divs[n])
        for (int i = 0; i < d; i++)
            mn = min(mn, op(str, pre, i, d, n));
    return mn;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    int t;
    cin >> t;
    while (t-- > 0)
        cout << solve() << "\n";
    return 0;
}