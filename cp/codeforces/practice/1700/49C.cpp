// https://codeforces.com/contest/49/problem/C
// Disposition

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
    vector<int> arr(n + 1);
    arr[1] = 1;
    int start = 1;
    if (n & 1)
        start = 2;
    for (int i = start; i <= n; i+=2)
    {
        arr[i] = i + 1;
        arr[i + 1] = i;
    }
    for (int i=1; i<=n; i++)
        cout << arr[i] << " ";
    return 0;
}