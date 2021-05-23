#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int MOD = 1e9 + 7;

int add(int x, int y)
{
    x += y;
    while (x >= MOD)
        x -= MOD;
    while (x < 0)
        x += MOD;
    return x;
}

int mul(int x, int y)
{
    return (x * 1ll * y) % MOD;
}

bool is_dig(char ch)
{
    return ch >= '0' && ch <= '9';
}

int calc(int x, int y, char optr)
{
    if (optr == '+')
        return add(x, y);
    else if (optr == '*')
        return mul(x, y);
    return add(x, y + 1);
}

int convert(string str)
{
    int num = 0;
    for (char ch : str)
    {
        num = mul(num, 10);
        num = add(num, ch - '0');
    }
    return num;
}
void solve()
{
    int n, cur = 1;
    cin >> n;
    vector<string> exp(n);
    vector<vector<string>> eq(n);
    map<string, int> mp;
    for (int i = 0; i < n; i++)
    {
        cin >> exp[i];
        int sz = exp[i].length();
        string num = "";
        for (int j = 0; j < sz; j++)
        {
            if (is_dig(exp[i][j]))
                num.pb(exp[i][j]);
            else
            {
                eq[i].pb(to_string(convert(num)));
                num.clear();
                eq[i].pb(exp[i].substr(j, 1));
            }
        }
        if (!num.empty())
            eq[i].pb(to_string(convert(num)));
    }
    vector<int> mask(n);
    map<int, int> ids;
    int id = 1;
    for (int i = 0; i < n; i++)
    {
        stack<char> op;
        stack<int> nums;
        for (string ch : eq[i])
        {
            if (ch[0] == ')')
            {
                int num1 = nums.top();
                nums.pop();
                int num2 = nums.top();
                nums.pop();
                char optr = op.top();
                op.pop();
                op.pop();
                nums.push(calc(num1, num2, optr));
            }
            else
            {
                if (is_dig(ch[0]))
                    nums.push(stoi(ch));
                else
                    op.push(ch[0]);
            }
        }
        int num = nums.top();
        if (ids[num] == 0)
            ids[num] = id++;
        mask[i] = ids[num];
    }
    for (int i = 0; i < n; i++)
        cout << mask[i] << " ";
    cout << "\n";
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
        cout << "Case #" << tc << ": ";
        solve();
    }
    return 0;
}