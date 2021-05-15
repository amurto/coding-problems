#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

bool solve()
{
    vector<int> arr(3);
    for (int i = 0; i < 3; i++)
        cin >> arr[i];
    sort(arr.begin(), arr.end());
    return arr[1] - arr[0] == arr[2] - arr[1];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve() ? cout << "Yes\n" : cout << "No\n";
    return 0;
}