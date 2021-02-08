#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int inf = 1e6;

int solve()
{
    int n, e;
    cin >> n;
    vector<int> arr(n + 2);
    arr[0] = arr[n + 1] = inf;
    int l = 1, r = n;
    while (r - l > 20)
    {
        int mid1 = l + (r - l) / 2;
        int mid2 = (mid1 - 1 > 0) ? mid1 - 1 : mid1 + 1;
        if (arr[mid1] == 0)
        {
            cout << "? " << mid1 << "\n";
            fflush(stdout);
            cin >> e;
            arr[mid1] = e;
        }
        if (arr[mid2] == 0)
        {
            cout << "? " << mid2 << "\n";
            fflush(stdout);
            cin >> e;
            arr[mid2] = e;
        }
        if (mid1 > mid2)
            swap(mid1, mid2);
        if (arr[mid1] < arr[mid2])
            r = mid2;
        else
            l = mid1;
    }
    for (int i = l; i <= r; i++)
    {
        if (arr[i] == 0)
        {
            cout << "? " << i << "\n";
            fflush(stdout);
            cin >> arr[i];
        }
    }
    for (int i = l; i <= r; i++)
    {
        if (arr[i - 1] > arr[i] && arr[i] < arr[i + 1])
            return i;
    }
    return r - 1;
}
int main()
{
    int k = solve();
    cout << "! " << k << endl;
    return 0;
}