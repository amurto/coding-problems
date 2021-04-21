#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

void display()
{
}
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for (int i = 0; k > 0 && i < n - 1; i++)
    {
        if (arr[i] >= k)
        {
            arr[i] -= k;
            arr[n - 1] += k;
            k = 0;
        }
        else
        {
            arr[n - 1] += arr[i];
            k -= arr[i];
            arr[i] = 0;
        }
    }
    for (int a : arr)
        cout << a << " ";
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        solve();
    return 0;
}