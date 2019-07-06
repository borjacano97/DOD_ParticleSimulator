#ifndef VECTOR2_H
#define VECTOR2_H

#include <cmath>

#define DEFINE_TO_STRING
#define USE_DOUBLE_PRECISSION true

#ifdef DEFINE_TO_STRING
#include <string>
#endif

#if USE_DOUBLE_PRECISSION
#define Real double
#else
#define Real float
#endif

class Vector2
{
	Real _x, _y;
public:
	Vector2() :_x(0), _y(0) {};
	Vector2(Real x, Real y) :_x(x), _y(y) {};
	Vector2(const Vector2& other) :_x(other._x), _y(other._y) {};
	Vector2(Vector2&& other) noexcept
	{
		_x = other._x;
		_y = other._y;
	};

	Real X() { return _x; };
	const Real X() const { return _x; };
	Real Y() { return _y; };
	const Real Y() const { return _y; };

	void X(Real x) { _x = x; };
	void Y(Real y) { _y = y; };

	Real getX() { return _x; };
	const Real getX() const { return _x; };
	Real getY() { return _y; };
	const Real getY() const { return _y; };

	void setX(Real x) { _x = x; };
	void setY(Real y) { _y = y; };

	void set(Real x, Real y) { _x = x; _y = y; };

	Vector2& operator+=(const Vector2& other) 
	{
		_x += other._x;
		_y += other._y;
		return *this;
	}

	Vector2 operator+(Vector2 other) 
	{
		other += (*this);
		return other;
	}

	const Vector2 operator+(Vector2 other) const 
	{
		other += (*this);
		return other;
	}

	Vector2& operator-=(const Vector2& other) 
	{
		_x -= other._x;
		_y -= other._y;
		return (*this);
	}

	Vector2 operator-(Vector2 other) 
	{
		other -= (*this);
		return other;
	}

	const Vector2 operator-(Vector2 other) const
	{
		other -= (*this);
		return other;
	}
	Vector2& operator*=(const Vector2& other) 
	{
		_x *= other._x;
		_y *= other._y;
		return (*this);
	}
	Vector2 operator*(Vector2 other)
	{
		other *= (*this);
		return other;
	}
	const Vector2 operator*(Vector2 other)const
	{
		other *= (*this);
		return other;
	}
	Vector2& operator/=(const Vector2& other) 
	{
		_x /= other._x;
		_y /= other._y;
		return (*this);
	}
	Vector2 operator/(const Vector2& other)
	{
		Vector2 aux = (*this);
		aux /= other;
		return aux;
	}
	const Vector2 operator/(const Vector2 other) const
	{
		Vector2 aux = (*this);
		aux /= other;
		return aux;
	}

	Vector2& operator*=(const Real scalar)
	{
		_x *= scalar;
		_y *= scalar;
	}

	Vector2 operator*(const Real scalar) 
	{
		Vector2 aux(*this);
		aux *= scalar;
		return aux;
	}
	const Vector2 operator*(const Real scalar) const
	{
		Vector2 aux(*this);
		aux *= scalar;
		return aux;
	}

	const bool operator==(const Vector2& other)const 
	{
		return _x == other._x && _y == other._y;
	}

	bool operator==(const Vector2& other) {
		return _x == other._x && _y == other._y;
	}

	const bool operator!=(const Vector2&other) const
	{
		return !(*this == other);
	}
	bool operator!=(const Vector2& other)
	{
		return !(*this == other);
	}
	void normalize() {
		const Real len = lenght();
		_x /= len;
		_y /= len;
	}
	Vector2 normalized()
	{
		Vector2 aux(*this);
		aux.normalize();
		return aux;
	}
	const Vector2 normalized() const
	{
		return normalized();
	}

	Real lenght()
	{
		return std::sqrt((_x*_x) + (_y*_y));
	}
	Real lenghtSquared()
	{
		return (_x*_x) + (_y*_y);
	}

	const Real lenght() const
	{
		return lenght();
	}
	const Real lenghtSquared() const
	{
		return lenghtSquared();
	}

	Real distanceSquared(const Vector2& other) const
	{
		return ((other._x - _x) * (other._x - _x)) + ((other._y - _y) * (other._y - _y));
	}

	Real distance(const Vector2& other) const
	{
		return std::sqrt(distanceSquared(other));
	}
	static Real distance(const Vector2& a, const Vector2& b) 
	{
		return a.distance(b);
	}
	static Real distanceSqrt(const Vector2& a, const Vector2& b) 
	{
		return a.distanceSquared(b);
	}

#ifdef DEFINE_TO_STRING
	std::string toString() const
	{
		return "(" + std::to_string(_x) + ", " + std::to_string(_y) + ")";
	}
#endif
};
#endif // VECTOR2_H
