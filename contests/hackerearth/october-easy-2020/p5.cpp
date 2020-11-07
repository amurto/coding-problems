#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

bool isDigit(char c)
{
    if (c >= '0' && c <= '9')
        return true;
    return false;
}

bool isLetter(char c)
{
    if (c >= 'a' && c <= 'z')
        return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
    {
        string str;
        cin >> str;
        vector<char> inp(str.length());
        vector<int> digit(10), letter(26);
        for (char ch : str)
            if (isDigit(ch))
                digit[ch - 48]++;
            else
                letter[ch - 97]++;
        for (int i = 1; i < 26; i += 2)
        {
            char c = (char)(i + 97);
            while (letter[i]-- > 0)
                cout << c;
        }
        for (int i = 0; i < 26; i += 2)
        {
            char c = (char)(i + 97);
            while (letter[i]-- > 0)
                cout << c;
        }
        for (int i = 1; i < 10; i += 2)
            while (digit[i]-- > 0)
                cout << i;
        for (int i = 0; i < 10; i += 2)
            while (digit[i]-- > 0)
                cout << i;
        cout << "\n";
    }
    return 0;
}