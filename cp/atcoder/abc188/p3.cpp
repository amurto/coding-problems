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
    n = 1 << n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int l = 0, r = n / 2;
    for (int i = 0; i < n / 2; i++)
        if (arr[i] > arr[l])
            l = i;
    for (int i = n / 2; i < n; i++)
        if (arr[i] > arr[r])
            r = i;
    if (arr[l] > arr[r])
        swap(l, r);
    cout << l + 1 << "\n";
    return 0;
}