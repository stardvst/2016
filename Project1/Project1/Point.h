#ifndef POINT_H
#define POINT_H

class Point {
public:
	Point(int = 0, int = 0);
	void setX(int);
	void setY(int);
	int getX() const;
	int getY() const;
private:
	int x;
	int y;
};

#endif // !POINT_H
