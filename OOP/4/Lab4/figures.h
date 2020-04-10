#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#define Pi 3.14159265
//#define ScreenHeight 720
//#define ScreenWidth 1270

using namespace std;
using namespace sf;
class EllipseShape : public sf::Shape
{
public:

	explicit EllipseShape(const sf::Vector2f& radius = sf::Vector2f(0, 0)) :
		m_radius(radius)
	{
		update();
	}

	void setRadius(const sf::Vector2f& radius)
	{
		m_radius = radius;
		update();
	}

	const sf::Vector2f& getRadius() const
	{
		return m_radius;
	}

	virtual std::size_t getPointCount() const
	{
		return 30; // fixed, but could be an attribute of the class if needed
	}
	virtual sf::Vector2f getPoint(std::size_t index) const
	{
		static const float pi = 3.141592654f;

		float angle = index * 2 * pi / getPointCount() - pi / 2;
		float x = std::cos(angle) * m_radius.x;
		float y = std::sin(angle) * m_radius.y;

		return sf::Vector2f(m_radius.x + x, m_radius.y + y);
	}

private:

	sf::Vector2f m_radius;
};
class Point
{
private:
	//static int ScreenHeight;
	//static int ScreenWidth;
protected:
	int x;
	int y;
	int dx;
	int dy;
	int xp;
	int yp;
	float time;
public:
	sf::CircleShape shape;
	static int ScreenHeight;
	static int ScreenWidth;
	bool isMove, isRot;
	static void setScreen(int w, int h)
	{
		ScreenHeight = h;
		ScreenWidth = w;
	}
	Point()
	{
	}
	Point(int xa, int ya, int a, int b, int c)
	{
		shape.setPosition(xa, ya);
		shape.setRadius(1);
		xp = 0;
		yp = 0;
		shape.setFillColor(sf::Color(a, b, c));
		shape.setOrigin(xp / 2, yp / 2);
		x = xa; y = ya;
		dx = 0;
		dy = 0;
		isMove = false;
		isRot = false;
	}
	void StopMove()
	{
		dy = 0; dx = 0;
	}
	void RandMove()
	{
		while (dx == 0)
			dx = rand() % 21 + (-10);
		cout << dx;
		while (dy == 0)
			dy = rand() % 21 + (-10);
		cout << dy;
	}
	void Rot()
	{
		shape.rotate(1);
		//shape.setOrigin(0, 0);
	}
	void Move(float time)
	{
		y += dy*time;
		x += dx*time;
		//cout << y << endl;
		//cout << x << endl;
		//cout << yp << endl;
		//cout << xp << endl;
		if (y + yp/2 >= ScreenHeight) dy -= (2 * dy);
		if (y <=0 + yp / 2) dy -=(2*dy) ;
		if (x + xp/2>= ScreenWidth) dx -= (2 * dx);
		if (x <= 0+ xp / 2) dx -= (2 * dx);
	}
	void reload()
	{
		shape.setPosition(x, y);
	}

};
class Circle : public Point
{
public:
	Circle()
	{}
	Circle(int xa, int ya, int r, int a, int b, int c)
	{
		shape.setPosition(xa, ya);
		shape.setRadius(r);
		xp = r*2;
		yp = r*2;
		shape.setFillColor(sf::Color(a, b, c));
		shape.setOrigin(xp / 2, yp / 2);
		x = xa; y = ya;
		dx = 0;
		dy = 0;
		isMove = false;
		isRot = false;
	}
};
class Rectangle : public Point
{
public:
	sf::RectangleShape shape;
	Rectangle()
	{ }
	Rectangle(int xa, int ya, int xl, int yl, int a, int b, int c)
	{
		shape.setPosition(xa, ya);
		shape.setSize(Vector2f(xl, yl));
		xp = xl;
		yp = yl;
		shape.setFillColor(sf::Color(a, b, c));
		shape.setOrigin(xp / 2, yp / 2);
		x = xa; y = ya;
		dx = 0;
		dy = 0;
		isMove = false;
		isRot = false;
	}
	void reload()
	{
		shape.setPosition(x, y);
	}
	void Rot()
	{
		shape.rotate(1);
	}
};
class Line : public Rectangle
{
public:
	Line(int xa, int ya, int l, int r, int a, int b, int c)
	{
		shape.setPosition(xa, ya);
		shape.setSize(Vector2f(1, l));
		xp = (int)(l*sin(r*Pi / 180));
		yp = (int)(l*cos(r*Pi / 180));
		shape.setOrigin(xp / 2, yp / 2);
		for (int i = 0; i < r; i++) Rot();
		x = xa; y = ya;
		cout << yp/2 << endl;
		cout << xp/2 << endl;
		shape.setFillColor(sf::Color(a, b, c));
		dx = 0;
		dy = 0;
		isMove = false;
		isRot = false;
	}
};
class Triangle : public Circle
{
public:
	Triangle(int xa, int ya, int r, int a, int b, int c)
	{
		shape.setPosition(xa, ya);
		shape.setRadius(r);
		shape.setPointCount(3);
		xp = r*2;
		yp = r*2;
		shape.setFillColor(sf::Color(a, b, c));
		shape.setOrigin(xp / 2, yp / 2);
		x = xa; y = ya;
		dx = 0;
		dy = 0;
		isMove = false;
		isRot = false;
	}
};
class Square : public Circle
{
public:
	Square(int xa, int ya, int r, int a, int b, int c)
	{
		shape.setPosition(xa, ya);
		shape.setRadius(r);
		shape.setPointCount(4);
		xp = r * 2;
		yp = r * 2;
		shape.setFillColor(sf::Color(a, b, c));
		shape.setOrigin(xp / 2, yp / 2);
		x = xa; y = ya;
		dx = 0;
		dy = 0;
		isMove = false;
		isRot = false;
	}
};
class Ellipse: public Point
{
	public:
	EllipseShape shape;
	Ellipse(int xa, int ya, int xl, int yl, int a, int b, int c)
	{
		shape.setPosition(xa, ya);
		shape.setRadius(Vector2f(xl, yl));
		xp = xl*2;
		yp = yl*2;
		shape.setFillColor(sf::Color(a, b, c));
		shape.setOrigin(xp / 2, yp / 2);
		x = xa; y = ya;
		dx = 0;
		dy = 0;
		isMove = false;
		isRot = false;
	}
	void Rot()
	{
		shape.rotate(1);
	}
	void reload()
	{
		shape.setPosition(x, y);
	}
};
