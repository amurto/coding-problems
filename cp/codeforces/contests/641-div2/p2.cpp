#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 1e5 + 5;
vector<int> divs[N];

void init()
{
    for (int i = 1; i < N; i++)
        for (int j = i; j < N; j += i)
            divs[j].pb(i);
}

int solve()
{
    int n;
    cin >> n;
    vector<int> arr(n + 1), dp(n + 1, 1);
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    for (int i = 1; i <= n; i++)
        for (int d : divs[i])
            if (arr[i] > arr[d])
                dp[i] = max(dp[i], 1 + dp[d]);
    return *max_element(dp.begin(), dp.end());
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