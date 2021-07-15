#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int solve()
{
    int n, a, b;
    string str;
    cin >> n >> a >> b >> str;
    if (b >= 0)
        return n * (a + b);
    vector<int> cnt(2);
    int last = str[0] - '0';
    for (int i = 1; i < n; i++)
    {
        int cur = str[i] - '0';
        if (last != cur)
        {
            cnt[last]++;
            last = cur;
        }
    }
    cnt[last]++;
    if (cnt[0] > cnt[1])
        swap(cnt[0], cnt[1]);
    return n * a + b * cnt[0] + b;
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