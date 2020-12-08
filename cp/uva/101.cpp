// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=37
// 101 - The Blocks Problem

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

stack<int> st[25], tmp;
int block[25];

void init(int n)
{
    for (int i = 0; i < n; i++)
    {
        st[i].push(i);
        block[i] = i;
    }
}

void move_onto(int a, int b)
{
    while (st[block[a]].top() != a)
    {
        int t = st[block[a]].top();
        st[t].push(t);
        block[t] = t;
        st[block[a]].pop();
    }

    while (st[block[b]].top() != b)
    {
        int t = st[block[b]].top();
        st[t].push(t);
        block[t] = t;
        st[block[b]].pop();
    }

    st[block[b]].pop();
    block[b] = b;
    st[b].push(b);

    st[b].push(st[block[a]].top());
    st[block[a]].pop();
    block[a] = b;
}
void move_over(int a, int b)
{
    while (st[block[a]].top() != a)
    {
        int t = st[block[a]].top();
        st[t].push(t);
        block[t] = t;
        st[block[a]].pop();
    }

    st[block[b]].push(st[block[a]].top());
    st[block[a]].pop();
    block[a] = block[b];
}
void pile_onto(int a, int b)
{
    while (st[block[b]].top() != b)
    {
        int t = st[block[b]].top();
        st[t].push(t);
        block[t] = t;
        st[block[b]].pop();
    }

    st[block[b]].pop();
    block[b] = b;
    st[b].push(b);

    while (st[block[a]].top() != a)
    {
        tmp.push(st[block[a]].top());
        st[block[a]].pop();
    }

    tmp.push(st[block[a]].top());
    st[block[a]].pop();

    while (!tmp.empty())
    {
        st[block[b]].push(tmp.top());
        block[tmp.top()] = block[b];
        tmp.pop();
    }
}
void pile_over(int a, int b)
{
    while (st[block[a]].top() != a)
    {
        tmp.push(st[block[a]].top());
        st[block[a]].pop();
    }

    tmp.push(st[block[a]].top());
    st[block[a]].pop();

    while (!tmp.empty())
    {
        st[block[b]].push(tmp.top());
        block[tmp.top()] = block[b];
        tmp.pop();
    }
}

void display(int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << i << ":";
        stack<int> temp;
        while (!st[i].empty())
        {
            temp.push(st[i].top());
            st[i].pop();
        }
        while (!temp.empty())
        {
            cout << " " << temp.top();
            temp.pop();
        }
        cout << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, a, b;
    cin >> n;
    init(n);
    string command, type;
    while (true)
    {
        cin >> command;
        if (command[0] == 'q')
            break;
        cin >> a >> type >> b;
        if (block[a] == block[b])
            continue;
        switch (command[0])
        {
        case 'm':
            if (type[3] == 'o')
                move_onto(a, b);
            else
                move_over(a, b);
            break;
        case 'p':
            if (type[3] == 'o')
                pile_onto(a, b);
            else
                pile_over(a, b);
            break;
        default:
            break;
        }
    }
    display(n);
    return 0;
}