// https://codeforces.com/contest/149/problem/C
// Division into Teams

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
    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].first;
        arr[i].second = i + 1;
    }
    sort(arr.begin(), arr.end());
    int x = (n + 1) / 2;
    int y = n - x;
    cout << x << "\n";
    for (int i = 0; i < n; i += 2)
        cout << arr[i].second << " ";
    cout << "\n";
    cout << y << "\n";
    for (int i = 1; i < n; i += 2)
        cout << arr[i].second << " ";
    return 0;
}