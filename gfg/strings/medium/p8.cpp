// https://practice.geeksforgeeks.org/problems/longest-palindrome-in-a-string/0
// Longest Palindrome in a String

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

// Dynamic Programming Approach
// Time O(n^2)
// Space O(n^2)
string dpspace(char str[], int n, string s)
{
    int m = 0, start = 0, P[n][n];
    memset(P, 0, sizeof(P));
    // P[i][j] = 1 if substr(i....j) is palindrome
    for (int gap = 0; gap < n; gap++)
    {
        for (int i = 0; i < n - gap; i++)
        {
            int j = i + gap;
            if (str[i] == str[j] && (gap <= 1 || P[i + 1][j - 1]))
            {
                P[i][j] = 1;
                if (gap + 1 > m)
                {
                    m = gap + 1;
                    start = i;
                }
            }
        }
    }
    return s.substr(start, m);
}


// Dynamic Programming Approach
// Time O(n^2)
// Space O(1)
// Select on an index as centre and start expanding left and right
string dpnospace(char str[], int n, string s) {
    int gap=1, start=0, left, right;
    for (int i=1; i<n;i++) {

        // odd length substrings
        left = i-1;
        right=i+1;
        while (left>=0 && right<n && str[left]==str[right]) {
            if (right-left+1 > gap) {
                gap=right-left+1;
                start=left;
            }
            left--;
            right++;
        }

        //even length substrings
        left=i-1;
        right=i;
        while (left>=0 && right<n && str[left]==str[right]) {
            if (right-left+1 > gap) {
                gap=right-left+1;
                start=left;
            }
            left--;
            right++;
        }

    }

    return s.substr(start, gap);
}

int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        string s;
        cin >> s;
        int n = s.length();
        char str[n];
        for (int i = 0; i < n; i++)
            str[i] = s[i];
        // cout << dpspace(str, n, s) << endl;
        cout << dpnospace(str, n, s) << endl;
    }
    return 0;
}