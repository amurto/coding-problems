// https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=63
// 127 - "Accordian" Patience

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string str;
    while (cin >> str && str[0] != '#')
    {
        vector<stack<string>> cards;
        stack<string> tmp;
        tmp.push(str);
        cards.pb(tmp);
        for (int i = 1; i < 52; i++)
        {
            stack<string> s;
            cin >> str;
            s.push(str);
            cards.pb(s);
        }
        int cur = 1;
        while (cur < cards.size())
        {
            if (cur >= 3 && (cards[cur - 3].top()[0] == cards[cur].top()[0] || cards[cur - 3].top()[1] == cards[cur].top()[1]))
            {
                cards[cur - 3].push(cards[cur].top());
                cards[cur].pop();
                if (cards[cur].empty())
                    cards.erase(cards.begin() + cur);
                cur -= 3;
            }
            else if (cur >= 1 && (cards[cur - 1].top()[0] == cards[cur].top()[0] || cards[cur - 1].top()[1] == cards[cur].top()[1]))
            {
                cards[cur - 1].push(cards[cur].top());
                cards[cur].pop();
                if (cards[cur].empty())
                    cards.erase(cards.begin() + cur);
                cur -= 1;
            }
            else
            {
                cur++;
            }
        }
        cout << cards.size();
        cards.size() == 1 ? cout << " pile remaining:" : cout << " piles remaining:";
        for (int i = 0; i < cards.size(); i++)
            cout << " " << cards[i].size();
        cout << "\n";
    }
    return 0;
}