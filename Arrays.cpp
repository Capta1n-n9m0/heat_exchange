#include "Arrays.h"

void add3DArray(Float3DArray &arr1, Float3DArray &arr2, Float3DArray &result) {
  auto shape = arr1.shape();
  for(int i = 0; i < shape[0]; i++)
    for(int j = 0; j < shape[1]; j++)
      for(int k = 0; k < shape[2]; k++)
        result[i][j][k] = arr1[i][j][k] + arr2[i][j][k];
}

void sub3DArray(Float3DArray &arr1, Float3DArray &arr2, Float3DArray &result) {
  auto shape = arr1.shape();
  for(int i = 0; i < shape[0]; i++)
    for(int j = 0; j < shape[1]; j++)
      for(int k = 0; k < shape[2]; k++)
        result[i][j][k] = arr1[i][j][k] - arr2[i][j][k];
}