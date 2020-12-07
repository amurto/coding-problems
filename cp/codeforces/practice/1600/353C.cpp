// https://codeforces.com/contest/353/problem/C
// Find Maximum

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    vector<int> pre(n);
    pre[0] = arr[0];
    for (int i = 1; i < n; i++)
        pre[i] = pre[i - 1] + arr[i];
    string str;
    cin >> str;
    int res = 0, one = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (str[i] == '1')
        {
            if (i > 0)
                res = max(res, one + pre[i - 1]);
            one += arr[i];
        }
    }
    res = max(res, one);
    cout << res << "\n";
    return 0;
}