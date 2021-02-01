#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int solve()
{
    int n;
    string str;
    cin >> n >> str;
    vector<int> suf(2), pre(2);
    suf[0] = count(str.begin(), str.end(), '0');
    suf[1] = count(str.begin(), str.end(), '1');
    int res = min(suf[0], suf[1]);
    for (char ch : str)
    {
        suf[ch - '0']--;
        pre[ch - '0']++;
        res = min(res, pre[1] + suf[0]);
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