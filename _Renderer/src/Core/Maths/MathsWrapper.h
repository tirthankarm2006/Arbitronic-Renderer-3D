#pragma once
#include "ARBpch.h"
#include "Vector3.h"

#ifndef _ARB_UTILSMATHWRAPPER_H_
#define _ARB_UTILSMATHWRAPPER_H_

namespace ARB {

#define ARB_VEC2 glm::vec2
#define ARB_IVEC2 glm::ivec2
#define ARB_UVEC2 glm::uvec2
//#define ARB_VEC3 glm::vec3
//#define ARB_IVEC3 glm::ivec3
//#define ARB_UVEC3 glm::uvec3
#define ARB_VEC4 glm::vec4
#define ARB_IVEC4 glm::ivec4
#define ARB_UVEC4 glm::uvec4
#define ARB_MATRIX3 glm::mat3
#define ARB_MATRIX4 glm::mat4

    typedef Vector3<float> Vector3f_32t;//Vector with 32 bit floating point numbers
    typedef Vector3<double> Vector3f_64t;//Vector with 64 bit floating point numbers
    typedef Vector3<uint8_t> Vector3ui_8t;//Vector with 8 unsigned bit integer numbers
    typedef Vector3<char> Vector3i_8t;//Vector with 8 bit integer numbers
    typedef Vector3<uint16_t> Vector3ui_16t;//Vector with 16 unsigned bit integer numbers
    typedef Vector3<short> Vector3i_16t;//Vector with 16 bit integer numbers
    typedef Vector3<int> Vector3i_32t;//Vector with 32 bit integer numbers
    typedef Vector3<uint32_t> Vector3ui_32t;//Vector with 32 bit usigned integer numbers
    typedef Vector3<uint64_t> Vector3ui_64t;//Vector with 32 bit usigned integer numbers
    typedef Vector3<long long> Vector3i_64t;//Vector with 64 bit integer numbers
}

#endif // !_ARB_UTILSMATHWRAPPER_H_