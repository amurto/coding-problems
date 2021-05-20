#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 1e3 + 5;
int dp[N][N];

int dfs(string &str, int i, int j, int n, int flips, int ones)
{
    if (i >= j)
    {
        vector<int> w = {0, 1};
        vector<int> sc(2);
        sc[0] = flips / 2;
        sc[1] = flips / 2;
        if (flips & 1)
            sc[0]++;
        if (flips & 1)
            swap(w[0], w[1]);
        int rem = ones - flips;
        if (n % 2 == 0)
        {
        }
        else
        {
        }
        if (sc[w[0]] > sc[w[1]])
            return w[0];
        else if (sc[w])
    }
}
string solve()
{
    int n, a = 0, b = 0;
    string str;
    cin >> n >> str;
    memset(dp, -1, sizeof(dp));
    int ones = count(str.begin(), str.end(), '1');
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