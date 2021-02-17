// https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=2853
// 11753 - Creating Palindrome

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int createPal(vector<int> &arr, int L, int R, int cnt, int k)
{
    if (cnt > k || L >= R)
        return cnt;
    if (arr[L] == arr[R])
        return createPal(arr, L + 1, R - 1, cnt, k);
    else
        return min(createPal(arr, L + 1, R, cnt + 1, k), createPal(arr, L, R - 1, cnt + 1, k));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int tc = 1; tc <= t; tc++)
    {
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        cout << "Case " << tc << ": ";
        int res = createPal(arr, 0, n - 1, 0, k);
        if (res > k)
            cout << "Too difficult\n";
        else if (res == 0)
            cout << "Too easy\n";
        else
            cout << res << "\n";
    }
    return 0;
}