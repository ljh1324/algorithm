#include <vector>
#include <iostream>

using namespace std;

const double PI = 2.0 * acos(0.0);

// 2���� ���͸� ǥ���Ѵ�.
struct MyVector {
	double x, y;
	// �����ڸ� explicit���� �����ϸ� vector2�� ���� ���� �߸��� �Ǽ��� ���� ���� �������ش�.
	explicit MyVector(double x_ = 0, double y_ = 0) : x(x_), y(y_) {}

	// �� ������ ��
	bool operator == (const MyVector rhs) const {
		return x == rhs.x && y == rhs.y;
	}

	bool operator < (const MyVector rhs) const {
		return x != rhs.x ? x < rhs.x : y < rhs.y;
	}

	MyVector operator + (const MyVector& rhs) const {
		return MyVector(x + rhs.x, y + rhs.y);
	}

	MyVector operator - (const MyVector& rhs) const {
		return MyVector(x - rhs.x, y - rhs.y);
	}


	MyVector operator * (double rhs) const {
		return MyVector(x * rhs, y * rhs);
	}

	// ������ ���̸� ��ȯ�Ѵ�.
	double norm() const { return hypot(x, y); }

	// ������ ���� ���� ���͸� ��ȯ�Ѵ�.
	MyVector normalize() const {
		return MyVector(x / norm(), y / norm());
	}

	// x���� ���� �������κ��� �� ���ͱ��� �ݻ�� �������� �� ����
	double polar() const { return fmod(atan2(y, x) + 2 * PI, 2 * PI); }

	// ���� ����
	double dot(const MyVector& rhs) const {
		return x * rhs.x + y * rhs.y;
	}

	// ���� ����
	double cross(const MyVector& rhs) const {
		return x * rhs.y - rhs.x * y;
	}

	// �� ���͸� rhs�� �翵�� ���
	MyVector project(const MyVector& rhs) const {
		MyVector r = rhs.normalize();
		return r * r.dot(*this);
	}
};

// (a, b)�� �����ϴ� ���� (c, d)�� �����ϴ� ���� ������ x�� ��ȯ�Ѵ�.
// �� ������ �����̸� (��ġ�� ��츦 ����) ������, �ƴϸ� ���� ��ȯ�Ѵ�.
bool lineIntersection(MyVector a, MyVector b, MyVector c, MyVector d, MyVector& x)
{
	double det = (b - a).cross(d - c);

	// �� ������ ������ ���
	if (fabs(det) < DBL_EPSILON) return false;
	x = a + (b - a) * ((c - a).cross(d - c) / det);
	return true;
}

bool lineIntersection2(MyVector a, MyVector b, MyVector c, MyVector d, MyVector& x)
{
	double p = (c - a).cross(d) / b.cross(d);

	x = a + b * p;
	return true;
}

int main()
{
	MyVector a = MyVector(1, 3);
	MyVector b = MyVector(2, 3);
	MyVector c = MyVector(4, 9);
	MyVector d = MyVector(1, 10);
	MyVector x;

	lineIntersection(a, b, c, d, x);

	cout << x.x << " " << x.y << endl;

	lineIntersection2(a, b, c, d, x);
	cout << x.x << " " << x.y << endl;
	return 0;
}