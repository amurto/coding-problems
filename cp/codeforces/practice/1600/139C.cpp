// https://codeforces.com/contest/139/problem/C
// Literature Lesson

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

bool is_vowel(char v)
{
    return v == 'a' || v == 'e' || v == 'i' || v == 'o' || v == 'u';
}

bool check(vector<string> &rhy, vector<string> &cur)
{
    vector<vector<bool>> arr(4, vector<bool>(4));
    for (int i = 0; i < 4; i++)
        for (int j = i + 1; j < 4; j++)
            arr[i][j] = arr[j][i] = (cur[i] == cur[j]);
    if (arr[0][1] && arr[1][2] && arr[2][3] && arr[3][0])
        return true;
    if (arr[0][1] && arr[2][3])
    {
        rhy.pb("aabb");
        return true;
    }
    if (arr[0][2] && arr[1][3])
    {
        rhy.pb("abab");
        return true;
    }
    if (arr[0][3] && arr[1][2])
    {
        rhy.pb("abba");
        return true;
    }
    return false;
}

string solve()
{
    int n, k;
    cin >> n >> k;
    string str;
    vector<string> rhy;
    bool ret = true;
    for (int i = 0; i < n; i++)
    {
        vector<string> cur(4);
        for (int j = 0; j < 4; j++)
        {
            cin >> str;
            int sz = str.length();
            int i = str.length() - 1, v = 0;
            while (i >= 0 && v < k)
            {
                v += is_vowel(str[i]);
                i--;
            }
            if (v < k)
            {
                ret = false;
                cur[j] = "0";
                continue;
            }
            cur[j] = str.substr(i + 1, sz - i - 1);
        }
        if (!ret)
            continue;
        if (!check(rhy, cur))
            ret = false;
    }
    if (!ret)
        return "NO";
    if (rhy.empty())
        return "aaaa";
    sort(rhy.begin(), rhy.end());
    if (rhy[0] != rhy.back())
        return "NO";
    return rhy[0];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}