// https://codeforces.com/contest/136/problem/C
// Replacement

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
    sort(arr.begin(), arr.end());
    arr[n - 1] = (arr[n - 1] == 1) ? 2 : 1;
    sort(arr.begin(), arr.end());
    for (int v : arr)
        cout << v << " ";
    return 0;
}