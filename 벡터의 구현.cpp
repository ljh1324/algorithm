#include <vector>
#include <iostream>

using namespace std;

const double PI = 2.0 * acos(0.0);

// 2차원 벡터를 표현한다.
struct MyVector {
	double x, y;
	// 생성자를 explicit으로 지정하면 vector2를 넣을 곳에 잘못해 실수가 들어가는 일을 방지해준다.
	explicit MyVector(double x_ = 0, double y_ = 0) : x(x_), y(y_) {}

	// 두 벡터의 비교
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

	// 벡터의 길이를 반환한다.
	double norm() const { return hypot(x, y); }

	// 방향이 같은 단위 벡터를 반환한다.
	MyVector normalize() const {
		return MyVector(x / norm(), y / norm());
	}

	// x축의 양의 방향으로부터 이 벡터까지 반사계 방향으로 잰 각도
	double polar() const { return fmod(atan2(y, x) + 2 * PI, 2 * PI); }

	// 내적 구현
	double dot(const MyVector& rhs) const {
		return x * rhs.x + y * rhs.y;
	}

	// 외적 구현
	double cross(const MyVector& rhs) const {
		return x * rhs.y - rhs.x * y;
	}

	// 이 벡터를 rhs에 사영한 결과
	MyVector project(const MyVector& rhs) const {
		MyVector r = rhs.normalize();
		return r * r.dot(*this);
	}
};

// (a, b)를 포함하는 선과 (c, d)를 포함하는 선의 교점을 x에 반환한다.
// 두 직선이 평행이면 (겹치는 경우를 포함) 거짓을, 아니면 참을 반환한다.
bool lineIntersection(MyVector a, MyVector b, MyVector c, MyVector d, MyVector& x)
{
	double det = (b - a).cross(d - c);

	// 두 직선이 평행인 경우
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