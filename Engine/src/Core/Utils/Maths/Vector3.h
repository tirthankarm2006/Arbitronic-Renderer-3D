#pragma once

#ifndef _ARB_VECTOR3_H_
#define _ARB_VECTOR3_H_
#include "Precision.h"

namespace ARB {
	class Vector3
	{
	public:
		realf_t x, y, z;
		Vector3() 
			: x(0), y(0), z(0){}
		Vector3(const realf_t x, const realf_t y, const realf_t z)
			: x(x), y(y), z(z) {}

		//Basic Vector3 addition and substraction Operations
		void operator+=(const Vector3& v) {
			x += v.x;
			y += v.y;
			z += v.z;
		}
		Vector3 operator+(const Vector3& v) const {
			return Vector3(x + v.x, y + v.y, z + v.z);
		}

		void operator-=(const Vector3& v) {
			x -= v.x;
			y -= v.y;
			z -= v.z;
		}
		Vector3 operator-(const Vector3& v) const {
			return Vector3(x - v.x, y - v.y, z - v.z);
		}

		//Vector scaled by a floating point value s
		void operator*=(const realf_t s) {
			x *= s;
			y *= s;
			z *= s;
		}
		Vector3 operator*(const realf_t s) const {
			return Vector3(x * s, y * s, z * s);
		}
		void AddScaledVector(const Vector3& v, const realf_t s) {
			x += v.x * s;
			y += v.y * s;
			z += v.z * s;
		}

		//Vector3 Scalar Dot Product
		realf_t DotProduct(const Vector3& v) const {
			return x * v.x + y * v.y + z * v.z;
		}
		realf_t operator*(const Vector3& v) const {
			return x * v.x + y * v.y + z * v.z;
		}

		//Vector3 Vector Cross Product
		Vector3 CrossProduct(const Vector3& v) const {
			return Vector3(y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x);
		}
		Vector3 operator%(const Vector3& v) const {
			return Vector3(y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x);
		}
		void operator%=(const Vector3& v) {
			*this = CrossProduct(v);
		}

		//Vector3 magnitude
		realf_t GetMagnitude() const {
			return SQRT(x * x + y * y + z * z);
		}
		realf_t GetMagnitudeSquared() const{
			return x * x + y * y + z * z;
		}

		//Vector3 operations with the magnitude
		void Normalize() {
			realf_t s = GetMagnitude();
			if (s > 0)
				*this *= ((realf_t)1 / s);
		}
		void ChangeMagnitude(const realf_t s) {
			Normalize();
			x *= s;
			y *= s;
			z *= s;
		}
		void Trim(const realf_t s) {
			if (GetMagnitudeSquared() > s * s) {
			    Normalize();
				x *= s;
				y *= s;
				z *= s;
			}
		}
		Vector3 GetUnitVector() const {
			Vector3 v = *this;
			v.Normalize();
			return v;
		}

		//Checking Component by component
		bool operator==(const Vector3& v) const{
			return (x == v.x) && (y == v.y) && (z == v.z);
		}
		bool operator!=(const Vector3& v) const {
			return !(*this == v);
		}
		void SetToNullVector() {
			x = 0;
			y = 0;
			z = 0;
		}
		void Invert() {
			x = -x;
			y = -y;
			z = -z;
		}
	};
}

#endif // !_ARB_VECTOR3_H_

