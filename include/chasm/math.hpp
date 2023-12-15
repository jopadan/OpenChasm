#pragma once
#include <GL/glcorearb.h>
namespace sca
{
	using f32    = GLfloat;
	using f64    = GLdouble;
	using c8     = GLchar;
	using i8     = GLbyte;
	using u8     = GLubyte;
	using i16    = GLshort;
	using u16    = GLushort;
	using i32    = GLint;
	using u32    = GLuint;
	using i64    = GLint64;
	using u64    = GLuint64;
	using ssz    = khronos_ssize_t;
	using usz    = khronos_usize_t;
	using iptr   = khronos_intptr_t;
	using uptr   = khronos_uintptr_t;
	using stime  = khronos_stime_nanoseconds_t;
	using utime  = khronos_utime_nanoseconds_t;
	using idx    = GLuint;
};

namespace vec
{
	template<typename T, size_t N>
	struct type : std::array<T, N>
	{
	};

	template<size_t N>
	using  i8 = std::conditional_t<N == 1,  int8_t, type< int8_t,N>>;
	template<size_t N>
	using  u8 = std::conditional_t<N == 1, uint8_t, type<uint8_t,N>>;
	template<size_t N>
	using i16 = std::conditional_t<N == 1,  int16_t, type< int16_t,N>>;
	template<size_t N>
	using u16 = std::conditional_t<N == 1, uint16_t, type<uint16_t,N>>;
	template<size_t N>
	using i32 = std::conditional_t<N == 1,  int32_t, type< int32_t,N>>;
	template<size_t N>
	using u32 = std::conditional_t<N == 1, uint32_t, type<uint32_t,N>>;
	template<size_t N>
	using f32 = std::conditional_t<N == 1, float, type<float,N>>;
	template<size_t N>
	using f64 = std::conditional_t<N == 1, double, type<double,N>>;

};
namespace mat
{
	template<typename T, size_t COLS, size_t ROWS>
		struct type : std::array<vec::type<T,COLS>, ROWS>
	{
	};

	template<size_t COLS, size_t ROWS>
	using  i8 = type<sca:: i8, COLS, ROWS>;
	template<size_t COLS, size_t ROWS>
	using  u8 = type<sca:: u8, COLS, ROWS>;
	template<size_t COLS, size_t ROWS>
	using i16 = type<sca::i16, COLS, ROWS>;
	template<size_t COLS, size_t ROWS>
	using u16 = type<sca::u16, COLS, ROWS>;
	template<size_t COLS, size_t ROWS>
	using i32 = type<sca::i32, COLS, ROWS>;
	template<size_t COLS, size_t ROWS>
	using u32 = type<sca::u32, COLS, ROWS>;
	template<size_t COLS, size_t ROWS>
	using i64 = type<sca::i64, COLS, ROWS>;
	template<size_t COLS, size_t ROWS>
	using u64 = type<sca::u64, COLS, ROWS>;
	template<size_t COLS, size_t ROWS>
	using f32 = type<sca::f32, COLS, ROWS>;
	template<size_t COLS, size_t ROWS>
	using f64 = type<sca::f64, COLS, ROWS>;
};

