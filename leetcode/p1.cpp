// https://leetcode.com/problems/numbers-at-most-n-given-digit-set/
// Numbers At Most N Given Digit Set

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int MOD = 1e9 + 7;

// Digit DP Approach
int POW[11];
int ADD(int x, int y)
{
    x += y;
    while (x >= MOD)
        x -= MOD;
    while (x < 0)
        x += MOD;
    return x;
}

int MUL(int x, int y)
{
    return (x * 1ll * y) % MOD;
}

int digitdp(vector<int> &digits, vector<int> &num, int cur)
{
    if (cur < 0)
        return 1;
    int res = 0;
    for (int v : digits)
    {
        if (v < num[cur])
            res = ADD(res, POW[cur]);
        else if (v == num[cur])
            res = ADD(res, digitdp(digits, num, cur - 1));
    }
    return res;
}

int AMNGDS(vector<string> &digits, int n)
{
    int len = digits.size();
    vector<int> d(len);
    for (int i = 0; i < len; i++)
        d[i] = stoi(digits[i]);
    vector<int> num;
    while (n > 0)
    {
        num.push_back(n % 10);
        n /= 10;
    }
    int reqLen = num.size();
    POW[0] = 1;
    for (int i = 1; i <= reqLen; i++)
        POW[i] = MUL(len, POW[i - 1]);
    int ans = digitdp(d, num, reqLen - 1);
    for (int i = 1; i < reqLen; i++)
        ans = ADD(ans, POW[i]);
    return ans;
}

// Bottom Up Approach
int atMostNGivenDigitSet(vector<string> &digits, int n)
{
    string num = to_string(n);
    reverse(num.begin(), num.end());
    int len = digits.size(), ans = 0, reqLen = num.length();
    POW[0] = 1;
    for (int i = 1; i <= reqLen; i++)
        POW[i] = MUL(len, POW[i - 1]);
    for (int i = 1; i < reqLen; i++)
        ans = ADD(ans, POW[i]);

    for (int i = reqLen - 1; i >= 0; i--)
    {
        bool same = false;
        for (string j : digits)
            if (j[0] < num[i])
                ans = ADD(ans, POW[i]);
            else if (j[0] == num[i])
                same = true;
        if (!same)
            return ans;
    }
    return ADD(ans, 1);
}

int main()
{
    int n = 1000000000;
    vector<string> digits = {"1", "4", "9"};
    cout << atMostNGivenDigitSet(digits, n) << endl;
    return 0;
}