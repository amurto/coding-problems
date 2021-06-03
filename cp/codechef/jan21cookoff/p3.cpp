#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int MOD = 1e9 + 7;

int add(int x, int y)
{
    x += y;
    while (x >= MOD)
        x -= MOD;
    while (x < 0)
        x += MOD;
    return x;
}

int mul(int x, int y)
{
    return (x * 1ll * y) % MOD;
}

// Binary Exponentiation O(logn)
// n^m mod p
int power(int n, int m, int p)
{
    int res = 1;
    while (m > 0)
    {
        if (m & 1)
            res = (res * 1ll * n) % p;
        n = (n * 1ll * n) % p;
        m /= 2;
    }
    return res;
}

int find_mex(vector<int> &arr, int n)
{
    set<int> st;
    for (int i = 1; i <= n; i++)
        st.insert(arr[i]);
    for (int i = 0; i < n; i++)
        if (st.find(i) == st.end())
            return i;
    return n;
}

int solve()
{
    int n;
    cin >> n;
    vector<int> arr(n + 1), dp(n + 1), pdp(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    int mex = find_mex(arr, n);
    if (mex == 0)
        return power(2, n - 1, MOD);
    vector<int> last(mex, -1);
    multiset<int> ids;
    for (int i = 0; i < mex; i++)
        ids.insert(-1);
    dp[0] = pdp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        if (arr[i] < mex)
        {
            ids.erase(ids.lower_bound(last[arr[i]]));
            last[arr[i]] = i;
            ids.insert(last[arr[i]]);
        }
        int low = *ids.begin();
        if (low != -1)
            dp[i] = add(dp[i], pdp[low - 1]);
        pdp[i] = add(pdp[i - 1], dp[i]);
    }
    return dp[n];
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