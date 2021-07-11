#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

bool solve()
{
    int n, x, sum = 0;
    cin >> n >> x;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
        if (i & 1)
            sum--;
    }
    return sum <= x;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve() ? cout << "Yes\n" : cout << "No\n";
    return 0;
}