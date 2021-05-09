#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n;
        cin >> n;
        int arr[3][n], p[n], cur = 0;
        for (int i = 0; i < n; i++)
            cin >> arr[0][i];
        for (int i = 0; i < n; i++)
            cin >> arr[1][i];
        for (int i = 0; i < n; i++)
            cin >> arr[2][i];
        p[0] = arr[0][0];
        for (int i = 1; i < n; i++)
        {
            while (p[i - 1] == arr[cur][i] || (i == n - 1 && arr[cur][i] == p[0]))
                cur = (cur + 1) % 3;
            p[i] = arr[cur][i];
        }
        for (int v : p)
            cout << v << " ";
        cout << endl;
    }
    return 0;
}