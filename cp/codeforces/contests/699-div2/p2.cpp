#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> h(n);
    for (int i = 0; i < n; i++)
        cin >> h[i];
    int i = 0, last = 0;
    while (k > 0 && i < n)
    {
        if (i == n - 1)
            return -1;
        if (h[i] < h[i + 1])
        {
            h[i]++;
            last = i;
            i = 0;
            k--;
        }
        else
        {
            i++;
        }
    }
    return last + 1;
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