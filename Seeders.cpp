#include "Seeders.h"

void HotWaterDryColdAirSeeder::seed(Environment *env){
  for(int x = 0; x < env->width; x++){
    for(int y = 0; y < env->height; y++){
      for(int z = 0; z < env->depth; z++){
        if(y < 5){
          env->cellTypes[x][y][z] = CellType::WATER;
          env->density[x][y][z] = 1000.0f;
          env->temperature[x][y][z] = 90.0f;
          env->heatCapacity[x][y][z] = 4186.0f;
          env->heatConductivity[x][y][z] = 0.6f;
          env->saturation[x][y][z] = 1.0f;
        } else {
          env->cellTypes[x][y][z] = CellType::AIR;
          env->density[x][y][z] = 1.225f;
          env->temperature[x][y][z] = 0.0f;
          env->heatCapacity[x][y][z] = 1005.0f;
          env->heatConductivity[x][y][z] = 0.025f;
          env->saturation[x][y][z] = 1.0f;
        }
        env->mass[x][y][z] = env->density[x][y][z] * env->cellVolume;
      }
    }
  }
}