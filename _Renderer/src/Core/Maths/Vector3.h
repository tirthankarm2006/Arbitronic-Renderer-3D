#pragma once

#ifndef _ARB_VECTOR3_H_
#define _ARB_VECTOR3_H_
#include "Precision.h"
#include "SysDefines.h"

namespace ARB {
	template<typename T>
	class Vector3
	{
	public:
		T x, y, z;
		ARB_INLINE Vector3()
			: x(0), y(0), z(0){}
		ARB_INLINE Vector3(const T x, const T y, const T z)
			: x(x), y(y), z(z) {}

		ARB_INLINE T& operator[](const int index) {
			if (!(index >= 0 && index <= 3)) {
				ARB_ERROR("Index out of range!");
				return;
			}
			return (&x)[index];
		}

		ARB_INLINE T operator[](const int index) const {
			if (!(index >= 0 && index <= 3)) {
				ARB_ERROR("Index out of range!");
				return;
			}
			return (&x)[index];
		}

		//Basic Vector3 addition and substraction Operations
		ARB_INLINE void operator+=(const Vector3& v) {
			x += v.x;
			y += v.y;
			z += v.z;
		}
		ARB_INLINE Vector3 operator+(const Vector3& v) const {
			return Vector3(x + v.x, y + v.y, z + v.z);
		}

		ARB_INLINE void operator-=(const Vector3& v) {
			x -= v.x;
			y -= v.y;
			z -= v.z;
		}
		ARB_INLINE Vector3 operator-(const Vector3& v) const {
			return Vector3(x - v.x, y - v.y, z - v.z);
		}

		//Vector scaled by a floating point value s
		ARB_INLINE void operator*=(const T s) {
			x *= s;
			y *= s;
			z *= s;
		}
		ARB_INLINE Vector3 operator*(const T s) const {
			return Vector3(x * s, y * s, z * s);
		}
		ARB_INLINE void AddScaledVector(const Vector3& v, const T s) {
			x += v.x * s;
			y += v.y * s;
			z += v.z * s;
		}

		//Vector3 Scalar Dot Product
		ARB_INLINE T DotProduct(const Vector3& v) const {
			return x * v.x + y * v.y + z * v.z;
		}
		ARB_INLINE T operator*(const Vector3& v) const {
			return x * v.x + y * v.y + z * v.z;
		}

		//Vector3 Vector Cross Product
		ARB_INLINE Vector3 CrossProduct(const Vector3& v) const {
			return Vector3(y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x);
		}
		ARB_INLINE Vector3 operator%(const Vector3& v) const {
			return Vector3(y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x);
		}
		ARB_INLINE void operator%=(const Vector3& v) {
			*this = CrossProduct(v);
		}

		//Vector3 magnitude
		ARB_INLINE T GetMagnitude() const {
			return SQRT(x * x + y * y + z * z);
		}
		ARB_INLINE T GetMagnitudeSquared() const{
			return x * x + y * y + z * z;
		}

		//Vector3 operations with the magnitude
		ARB_INLINE void Normalize() {
			T s = GetMagnitude();
			if (s > 0)
				*this *= ((T)1 / s);
		}
		ARB_INLINE void ChangeMagnitude(const T s) {
			Normalize();
			x *= s;
			y *= s;
			z *= s;
		}
		ARB_INLINE void Trim(const T s) {
			if (GetMagnitudeSquared() > s * s) {
			    Normalize();
				x *= s;
				y *= s;
				z *= s;
			}
		}
		ARB_INLINE Vector3 GetUnitVector() const {
			Vector3 v = *this;
			v.Normalize();
			return v;
		}

		//Checking Component by component
		ARB_INLINE bool operator==(const Vector3& v) const{
			return (x == v.x) && (y == v.y) && (z == v.z);
		}
		ARB_INLINE bool operator!=(const Vector3& v) const {
			return !(*this == v);
		}
		ARB_INLINE void SetToNullVector() {
			x = 0;
			y = 0;
			z = 0;
		}
		ARB_INLINE void Invert() {
			x = -x;
			y = -y;
			z = -z;
		}
	};
}

#endif // !_ARB_VECTOR3_H_

