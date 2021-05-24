#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int solve()
{
    int n, mn = 105;
    cin >> n;
    vector<int> arr(n), freq(105);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        mn = min(mn, arr[i]);
        freq[arr[i]]++;
    }
    return n - freq[mn];
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