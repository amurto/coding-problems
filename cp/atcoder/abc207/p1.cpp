#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    vector<int> arr(3);
    for (int i = 0; i < 3; i++)
        cin >> arr[i];
    sort(arr.rbegin(), arr.rend());
    cout << arr[0] + arr[1] << "\n";
    return 0;
}