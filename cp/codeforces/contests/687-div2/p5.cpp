#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr.begin(), arr.end());
    for (int v: arr)
        cout << v << " ";
    cout << "\n";
    int sc = 0, b = 0, i;
    for (i = n - 1; i > k - 1; i--)
    {
        sc += b;
        b += arr[i];
    }
    while (i >= 0)
    {
        if (b < 0)
            b = 0;
        sc += b;
        b += arr[i];
        i--;
    }
    cout << sc << "\n";
    return 0;
}