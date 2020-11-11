#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int solve()
{
    int n, MAX = 0;
    cin >> n;

    vector<int> arr(n);
    bool zero = false;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (arr[i] == 0)
            zero = true;
        MAX = max(MAX, arr[i]);
    }
    if (n == 1)
        return -1;
    if (n == 2 && zero)
        return MAX;
    int ans = 0;
    for (int j = 1; j <= 1024; j++)
    {
        unordered_set<int> SET;
        int cnt = 0;
        for (int x : arr)
            SET.insert(x ^ j);
        for (int x : arr)
        {
            if (SET.find(x) == SET.end())
                break;
            cnt++;
        }
        if (cnt == n)
            return j;
    }
    return -1;
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