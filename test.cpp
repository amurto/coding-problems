#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

void mul(vector<int> &arr, vector<int> &p, int n)
{
    vector<int> x(n + 1);
    for (int i = 1; i <= n; i++)
        x[i] = p[arr[i]];
    arr = x;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> arr(n + 1), p(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        p[i] = arr[i];
    }
    for (int i = 2; i <= 10; i++)
    {
        mul(arr, p, n);
        for (int i = 1; i <= n; i++)
            cout << arr[i] << " ";
        cout << "\n";
    }
    return 0;
}