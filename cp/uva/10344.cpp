// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1285
// 10344 - 23 out of 5

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int op(int x, int y, char ch)
{
    if (ch == '+')
        return x + y;
    else if (ch == '-')
        return x - y;
    else
        return x * y;
}

bool dfs(vector<int> &arr, int num, int cur)
{
    if (cur == 5)
        return (num == 23);
    bool c1 = dfs(arr, op(num, arr[cur], '+'), cur + 1);
    bool c2 = dfs(arr, op(num, arr[cur], '-'), cur + 1);
    bool c3 = dfs(arr, op(num, arr[cur], '*'), cur + 1);
    return c1 || c2 || c3;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    vector<int> arr(5);
    while (cin >> arr[0] >> arr[1] >> arr[2] >> arr[3] >> arr[4])
    {
        if (arr[0] == 0)
            break;
        bool possible = false;
        sort(arr.begin(), arr.end());
        do
        {
            if (dfs(arr, arr[0], 1))
            {
                possible = true;
                break;
            }
        } while (next_permutation(arr.begin(), arr.end()));
        possible ? cout << "Possible\n" : cout << "Impossible\n";
    }
    return 0;
}