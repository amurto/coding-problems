// https://codeforces.com/contest/1147/problem/C
// Thanos Nim

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
    count(arr.begin(), arr.end(), *min_element(arr.begin(), arr.end())) <= n / 2 ? cout << "Alice\n" : cout << "Bob\n";
    return 0;
}