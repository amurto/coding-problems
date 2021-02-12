// https://codeforces.com/contest/373/problem/C
// Counting Kangaroos is Fun

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int solve()
{
    int n, res = 0;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr.begin(), arr.end());
    multiset<int> small(arr.begin(), arr.begin() + n / 2), big(arr.begin() + n / 2, arr.end());
    while (!small.empty() && !big.empty() && big.lower_bound(2 * (*small.begin())) != big.end())
    {
        big.erase(big.begin(), ++big.lower_bound(2 * (*small.begin())));
        small.erase(small.begin());
        res++;
    }
    return res + n - res * 2;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}