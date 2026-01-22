#pragma once

#ifndef _ARB_MATRIX3_H_
#define _ARB_MATRIX3_H_
#include "Vector3.h"
#include "SysDefines.h"

namespace ARB {
	template<typename T>
	class Matrix3 {
	private:
		typedef Vector3<T> Vector3_t;
		Vector3_t mat[3];//Row-wise, [0] is row 1, [1] is row 2, [2] is row 3
	public:
		//Row-wise input, row1, row2, row3
		ARB_INLINE Matrix3(const Vector3_t& r1, const Vector3_t& r2, const Vector3_t& r3) {
			mat[0].x = r1.x; mat[0].y = r1.y; mat[0].z = r1.z;
			mat[1].x = r2.x; mat[1].y = r2.y; mat[1].z = r2.z;
			mat[2].x = r3.x; mat[2].y = r3.y; mat[2].z = r3.z;
		}

		//m[0] should be Row 1, m[1] should be Row 2, m[2] should be Row 3
		ARB_INLINE Matrix3(const T m[3][3]) {
			mat[0].x = m[0][0]; mat[0].y = m[0][1]; mat[0].z = m[0][2];
			mat[1].x = m[1][0]; mat[1].y = m[1][1]; mat[1].z = m[1][2];
			mat[2].x = m[2][0]; mat[2].y = m[2][1]; mat[2].z = m[2][2];
		}

		//Get the ith row of the matrix
		ARB_INLINE const Vector3_t &operator[](const int index) const {
			if (!(index >= 0 && index <= 3)) {
				ARB_ERROR("Index out of range!");
				return;
			}
			return mat[index];
		}

		ARB_INLINE Vector3_t& operator[](const int index) {
			if (!(index >= 0 && index <= 3)) {
				ARB_ERROR("Index out of range!");
				return;
			}
			return mat[index];
		}

		ARB_INLINE Matrix3 GetInvertedMatrix() const {
			return Matrix3( Vector3_t(-mat[0][0], -mat[0][1], -mat[0][2]),
				            Vector3_t(-mat[1][0], -mat[1][1], -mat[1][2]),
				            Vector3_t(-mat[2][0], -mat[2][1], -mat[2][2]) );
		}
	};
}

#endif // !_ARB_MATRIX3_H_
