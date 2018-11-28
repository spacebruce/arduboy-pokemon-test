#pragma once

template<typename T> T * pgm_read_pointer(T * const * pointer)
{
	return reinterpret_cast<T *>(pgm_read_ptr(pointer));
}

template<typename T> T * pgm_read_pointer(T * const pointer)
{
	return reinterpret_cast<T *>(pgm_read_ptr(pointer));
}