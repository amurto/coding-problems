#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

bool same(vector<int> &arr, int n)
{
    for (int i = 1; i < n; i++)
        if (arr[i - 1] != arr[i])
            return false;
    return true;
}
int solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int op = 0;
    while (!(same(arr, n)))
    {

        vector<int> b(n);
        for (int i = 0; i < n - 1; i++)
            b[i] = __gcd(arr[i], arr[i + 1]);
        b[n - 1] = __gcd(arr[n - 1], arr[0]);
        arr = b;
        op++;
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << "\n";
    }
    return op;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        cout << solve() << "\n";
    return 0;
}