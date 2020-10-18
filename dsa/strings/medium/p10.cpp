// https://practice.geeksforgeeks.org/problems/smallest-window-in-a-string-containing-all-the-characters-of-another-string/0
// Smallest window in a string containing all the characters of another string

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int char_max = 256;
bool allZero(int MAP[])
{
    for (int i = 0; i < char_max; i++)
        if (MAP[i] > 0)
            return false;
    return true;
}

int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        string s, text;
        cin >> s >> text;
        int MAP[char_max];
        memset(MAP, 0, sizeof(MAP));
        for (char c : text)
            MAP[c]++;

        int n = s.length(), start = 0, end = 0, ans = -1, i = 0;
        while (end < n)
        {
            MAP[s[end]]--;
            while (start <= end && allZero(MAP))
            {
                if (ans == -1)
                {
                    ans = end - start + 1;
                    i = start;
                }
                else
                {
                    if (end - start + 1 < ans)
                    {
                        ans = end - start + 1;
                        i = start;
                    }
                }

                MAP[s[start]]++;
                start++;
            }
            end++;
        }
        if (ans == -1)
            cout << -1 << endl;
        else
            cout << s.substr(i, ans) << endl;
    }
    return 0;
}