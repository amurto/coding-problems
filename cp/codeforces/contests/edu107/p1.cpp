#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int solve()
{
    int n, cnt = 0;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for (int i = 0; i < n; i++)
        if (arr[i] == 1 || arr[i] == 3)
            cnt++;
    return cnt;
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