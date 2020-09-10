// https://practice.geeksforgeeks.org/problems/number-following-a-pattern/0
// Number following a pattern

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        string str;
        cin >> str;
        int n = str.length(), i = 0, add = 0, cur_max = 1, carry = 0;
        vector<int> ans;
        if (str[i] == 'I')
        {
            ans.pb(1);
        }
        else
        {
            while (str[i] == 'D')
                i++;
            for (int j = i + 1; j > 0; j--)
                ans.pb(j);
            cur_max = i + 1;
        }

        while (i < n)
        {
            if (str[i] == 'I')
            {
                if (i < n - 1 && str[i + 1] == 'D')
                    carry = 1;
                else
                    ans.pb(++cur_max);
                i++;
            }
            else
            {
                add = carry;
                while (str[i] == 'D')
                {
                    add++;
                    i++;
                }
                for (int j = add; j > 0; j--)
                    ans.pb(cur_max + j);
                cur_max += add;
                add = 0;
                carry = 0;
            }
        }

        for (int v : ans)
            cout << v;
        cout << endl;
    }
    return 0;
}