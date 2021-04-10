#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int pre(string &s1, string &s2)
{
    for (int i = 0; i < s1.length() && i < s2.length(); i++)
    {
        if (s1[i] == s2[i])
            continue;
        if (s1[i] > s2[i])
            return 0;
        else
            return 1;
    }
    return -1;
}

string str_sum(string str1, string str2)
{
    if (str1.length() > str2.length())
        swap(str1, str2);
    string str = "";
    int n1 = str1.length(), n2 = str2.length();
    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());

    int carry = 0;
    for (int i = 0; i < n1; i++)
    {
        int sum = ((str1[i] - '0') + (str2[i] - '0') + carry);
        str.push_back(sum % 10 + '0');
        carry = sum / 10;
    }
    for (int i = n1; i < n2; i++)
    {
        int sum = ((str2[i] - '0') + carry);
        str.push_back(sum % 10 + '0');
        carry = sum / 10;
    }
    if (carry)
        str.push_back(carry + '0');
    reverse(str.begin(), str.end());
    return str;
}

int solve()
{
    int n, res = 0;
    cin >> n;
    vector<string> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for (int i = 1; i < n; i++)
    {
        int len = arr[i - 1].length(), clen = arr[i].length(), p = pre(arr[i - 1], arr[i]);
        if (clen > len || (clen == len && p == 1))
            continue;
        if (arr[i - 1] == arr[i])
        {
            arr[i].pb('0');
            res++;
            continue;
        }
        if (p == -1)
        {
            int itr = clen;
            bool nine = true;
            for (int j = itr; j < len; j++)
                if (arr[i - 1][j] != '9')
                    nine = false;
            if (nine)
            {
                int z = len - clen + 1;
                res += z;
                while (z > 0)
                {
                    arr[i].pb('0');
                    z--;
                }
            }
            else
            {
                string a = "";
                while (itr < len)
                {
                    a.pb(arr[i - 1][itr]);
                    itr++;
                }
                string add = str_sum(a, "1");
                res += add.length();
                for (char ch : add)
                    arr[i].pb(ch);
            }
        }
        else
        {
            int z = p == 1 ? len - clen : len - clen + 1;
            res += z;
            while (z > 0)
            {
                arr[i].pb('0');
                z--;
            }
        }
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int tc = 1; tc <= t; tc++)
        cout << "Case #" << tc << ": " << solve() << "\n";
    return 0;
}