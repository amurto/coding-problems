// https://www.hackerrank.com/challenges/a-circle-and-a-square/problem
// A Circle and a Square

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

class Point
{
public:
    double x, y;
    Point(const double x, const double y) : x(x), y(y){};
};

class Circle
{
public:
    Point center;
    int r;
    Circle(const Point &center, const int r) : center(center), r(r){};
    static Circle read()
    {
        int x, y, r;
        cin >> x >> y >> r;
        return Circle(Point(x, y), r);
    }

    bool contains(Point p) const
    {
        double dx = p.x - center.x, dy = p.y - center.y;
        return dx * dx + dy * dy <= r * r;
    }
};

class Triangle
{
public:
    Point p1, p2, p3;
    Triangle(const Point &p1, const Point &p2, const Point &p3)
        : p1(p1), p2(p2), p3(p3)
    {
    }
    bool contains(Point p) const
    {
        return this->area() == Triangle(p1, p2, p).area() + Triangle(p2, p3, p).area() + Triangle(p3, p1, p).area();
    }
    double area() const
    {
        return abs((p3.x - p1.x) * (p2.y - p1.y) - (p3.y - p1.y) * (p2.x - p1.x)) / 2;
    }
};

class Square
{
public:
    Point p1, p2, p3, p4;
    Square(const Point &p1, const Point &p2, const Point &p3, const Point &p4)
        : p1(p1), p2(p2), p3(p3), p4(p4)
    {
    }
    static Square read()
    {
        int x1, y1, x3, y3;
        cin >> x1 >> y1 >> x3 >> y3;
        double cx = (x1 + x3) / 2.0;
        double cy = (y1 + y3) / 2.0;
        double dx = x1 - cx;
        double dy = y1 - cy;
        double px = -dy;
        double py = dx;
        // px * dx + py * dy == 0 -> perpendicular
        double x2 = cx + px;
        double y2 = cy + py;
        double x4 = cx - px;
        double y4 = cy - py;
        return Square(Point(x1, y1), Point(x2, y2), Point(x3, y3), Point(x4, y4));
    }

    bool contains(Point p) const
    {
        return Triangle(p1, p3, p2).contains(p) || Triangle(p1, p3, p4).contains(p);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int w, h;
    cin >> w >> h;
    Circle c = Circle::read();
    Square sq = Square::read();
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
            if (c.contains(Point(j, i)) || sq.contains(Point(j, i)))
                cout << '#';
            else
                cout << '.';
        cout << "\n";
    }
    return 0;
}