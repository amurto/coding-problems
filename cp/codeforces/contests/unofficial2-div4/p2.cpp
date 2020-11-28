#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t-- > 0)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        int L = 0, R = n - 1;
        while (L + 1 < n && arr[L + 1] >= arr[L])
            L++;
        while (R - 1 >= 0 && arr[R - 1] >= arr[R])
            R--;
        if (L >= R)
            cout << n << "\n";
        else
            cout << L + 1 + n - R << "\n";
    }
    return 0;
}