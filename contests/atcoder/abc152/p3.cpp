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
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int MIN = INT_MAX, cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] <= MIN)
            cnt++;
        MIN = min(MIN, arr[i]);
    }
    cout << cnt << "\n";
    return 0;
}