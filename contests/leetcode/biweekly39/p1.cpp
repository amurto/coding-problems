#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

vector<int> decrypt(vector<int> &code, int k)
{
    int n = code.size();
    vector<int> res(n);
    if (k == 0)
        return res;
    int sum1 = 0, sum2 = 0, dir = k < 0 ? -1 : 1;
    vector<int> pre(n), suf(n);
    for (int i = 0; i < n; i++)
    {
        sum1 += code[i];
        pre[i] = sum1;
        sum2 += code[n - i - 1];
        suf[n - i - 1] = sum2;
    }
    k = abs(k);
    int change = k / n * sum1;
    k %= n;
    for (int i = 0; i < n; i++)
    {
        if (dir < 0)
        {
            res[i] += change + suf[max(i - k, 0)] - suf[i];
            if (i - k < 0)
                res[i] += suf[n- abs(i - k)];
        }
        else
        {
            res[i] += change + pre[min(i + k, n - 1)] - pre[i];
            if (i + k > n - 1)
                res[i] += pre[(i + k) % n];
        }
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int k = -2;
    vector<int> code = {2, 4, 9, 3};
    vector<int> res = decrypt(code, k);
    for (int val : res)
        cout << val << " ";
    return 0;
}