#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

struct Point
{
	Point(string name = "", int x = 0, int y = 0)
		: name(name), x(x), y(y)
	{

	}
	string name = "";
	int x = 0;
	int y = 0;
};

ostream& operator<<(ostream& os, const Point& point)
{
	return os << "name: " << point.name << " (" << point.x << ", " << point.y << ")";
}

template<typename T>
void Print(const list<T>& diagram)
{
	for (auto it = diagram.begin(); it != diagram.end(); ++it)
	{
		cout << *it << "\n";
	}
}

int main()
{
	list<Point> diagram;

	diagram.emplace_back(Point("A", 50, 200));
	diagram.emplace_back(Point("B", 20, 80));
	diagram.emplace_back(Point("C", 75, 10));
	diagram.emplace_back(Point("D", 130, 80));
	diagram.emplace_back(Point("E", 100, 200));

	cout << " 1. ======================== \n";
	Print<Point>(diagram);

	cout << " 2. ======================== \n";
	Point temp = diagram.back();
	diagram.pop_back();
	diagram.emplace_back(Point("F", 180, 150));
	diagram.emplace_back(temp);
	
	Print<Point>(diagram);

	cout << " 3. ======================== \n";
	for (auto it = diagram.begin(); it != diagram.end(); ++it)
	{
		if ((*it).name == "D")
		{
			(*it).x = 200;
			(*it).y = 100;
			break;
		}
	}

	Print<Point>(diagram);

	cout << " 4. ======================== \n";
	diagram.remove_if([](const Point& p)
		{
			return p.name == "C";
		});
	Print<Point>(diagram);
}