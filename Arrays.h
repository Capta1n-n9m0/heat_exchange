#ifndef HEAT_EXCHANGE_GLFW_ARRAYS_H
#define HEAT_EXCHANGE_GLFW_ARRAYS_H
#include <boost/multi_array.hpp>

template<typename type>
class Array3D: public boost::multi_array<type, 3> {};

typedef Array3D<float> Float3DArray;

/// arr1 + arr2 = result
void add3DArray(Float3DArray &arr1, Float3DArray &arr2, Float3DArray &result);

/// arr1 - arr2 = result
void sub3DArray(Float3DArray &arr1, Float3DArray &arr2, Float3DArray &result);


#endif //HEAT_EXCHANGE_GLFW_ARRAYS_H
