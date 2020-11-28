#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

string solve()
{
    int n, x, odd = 0, even = 0;
    cin >> n >> x;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (arr[i] & 1)
            odd++;
        else
            even++;
    }
    if (x & 1)
    {
        if (odd > 0 && (even/2 + (odd-1)/2 >= (x-1)/2)
            return "YES";
    }
    else
    {
        if (odd > 0 && even > 0 && (odd - 1) / 2 + (even - 1) / 2 >= (x - 2) / 2)
            return "YES";
    }
    return "NO";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
    {
        cout << solve() << "\n";
    }
    return 0;
}