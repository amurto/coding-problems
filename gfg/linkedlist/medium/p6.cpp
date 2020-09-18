// https://practice.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream/0
// First non-repeating character in a stream

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
        int n;
        cin >> n;
        int MAP[26], ans[n], cur = -1;
        memset(MAP, 0, sizeof(MAP));
        queue<int> QUEUE;
        char a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];

        for (int i = 0; i < n; i++)
        {
            if (cur == -1)
            {
                if (MAP[a[i] - 97] == 0)
                {
                    cur = a[i] - 97;
                    MAP[cur]++;
                    QUEUE.push(cur);
                }
            }
            else
            {
                MAP[a[i] - 97]++;
                if (MAP[a[i] - 97] == 1)
                    QUEUE.push(a[i] - 97);
                while (!QUEUE.empty() && MAP[QUEUE.front()] > 1)
                    QUEUE.pop();
                cur = QUEUE.empty() ? -1 : QUEUE.front();
            }

            if (cur > -1)
                cout << (char)(cur + 97) << " ";
            else
                cout << -1 << " ";
        }
        cout << endl;
    }
    return 0;
}