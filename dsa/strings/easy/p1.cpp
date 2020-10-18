// Sum of numbers in string
// https://practice.geeksforgeeks.org/problems/sum-of-numbers-in-string/0

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
        string s;
        cin >> s;
        int n = s.length();
        char c[n];
        for (int i = 0; i < n; i++)
            c[i] = s[i];
        int cur_num = 0, sum = 0, l = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            if (c[i] > '9')
            {
                sum += cur_num;
                cur_num = 0;
                l = 0;
            }
            else
            {
                double tba = pow(10, l) * (c[i] - 48);
                cur_num+=tba;
                l++;
            }
        }
        sum += cur_num;
        cout << sum << endl;
    }
    return 0;
}