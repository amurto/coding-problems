// https://codeforces.com/contest/478/problem/C
// Table Decorations

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    vector<ll> arr(3);
    cin >> arr[0] >> arr[1] >> arr[2];
    sort(arr.rbegin(), arr.rend());
    if (2 * arr[1] + 2 * arr[1] <= arr[0])
        cout << arr[1] + arr[2] << "\n";
    else
        cout << (arr[0] + arr[1] + arr[2]) / 3 << "\n";
    return 0;
}