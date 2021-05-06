#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        iota(arr.begin(), arr.end(), 1);
        for (int a : arr)
            cout << a << " ";
        cout << "\n";
    }
    return 0;
}