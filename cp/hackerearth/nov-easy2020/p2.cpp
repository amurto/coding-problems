// https://www.hackerearth.com/practice/basic-programming/implementation/basics-of-implementation/practice-problems/algorithm/beauty-factor-bab8f334/
// A beauty factor

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int beautyFactor(int num)
{
    while (num >= 10)
    {
        int temp = 0;
        while (num > 0)
        {
            temp += num % 10;
            num /= 10;
        }
        num = temp;
    }
    return num;
}

int bf(vector<bool> &vis, int k, int b, int num)
{
    if (k == 0)
    {
        if (beautyFactor(num) == b)
            return num;
        return -1;
    }
    for (int i = 1; i <= 9; i++)
    {
        if (vis[i])
            continue;
        vis[i] = true;
        int res = bf(vis, k - 1, b, num * 10 + i);
        if (res != -1)
            return res;
        vis[i] = false;
    }
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int b, k;
    cin >> b >> k;
    vector<bool> vis(10);
    cout << bf(vis, k, b, 0) << "\n";
    return 0;
}