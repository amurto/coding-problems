// https://codeforces.com/contest/792/problem/C
// Divide by Three

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

string f(string s)
{
    int sum = 0;
    for (char ch : s)
        sum += (ch - '0');
    int req = sum % 3;
    if (req == 0)
        return s;
    vector<int> last(10), rem = {0, 0, 0};
    bool zero = (s[0] == '0');
    for (int i = 1; i < s.length(); i++)
    {
        int cur = s[i] - '0';
        if (cur == 0)
        {
            zero = true;
            continue;
        }
        if (cur % 3 == req)
            rem = {i};
        for (int j = 1; j <= 9; j++)
            if (last[j] > 0 && (cur + j) % 3 == req && rem.size() == 3)
                rem = {last[j], i - 1};
        last[cur] = i;
    }
    if (rem.size() == 3)
    {
        if (zero)
            return "0";
        else
            return "-1";
    }
    for (int r : rem)
        s.erase(r, 1);
    return s;
}

string solve()
{
    string str;
    cin >> str;
    int n = str.length(), sum = 0, a = 0;
    for (char ch : str)
        sum += (ch - '0');
    if (sum % 3 == 0)
        return str;
    string res = f(str);
    for (int i = 1; a < 2 && i < str.length(); i++)
    {
        if (str[i] == '0')
            continue;
        string ff = f(str.substr(i, n - i));
        a++;
        if (ff == "-1")
            continue;
        if (res == "-1" || ff.length() > res.length())
            res = ff;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}