#include "Environment.h"

Environment::Environment(int width, int height, int depth, float cellDimension, float timeStep)
  : width{width}, height{height}, depth{depth},
    cellDimension{cellDimension}, cellVolume{cellDimension * cellDimension * cellDimension},
    isReady{false}, timeStep{timeStep},
    cellTypes(boost::extents[width][height][depth]),
    density(boost::extents[width][height][depth]),
    mass(boost::extents[width][height][depth]),
    temperature(boost::extents[width][height][depth]),
    heatCapacity(boost::extents[width][height][depth]),
    heatConductivity(boost::extents[width][height][depth]),
    saturation(boost::extents[width][height][depth])
    {
}

void Environment::seed(Seeder *seeder) {
  seeder->seed(this);
}

float dryAirDensity(float temperature, float pressure){
  constexpr float R = 287.058f;
  return pressure / (R * temperature);
}

float getHumiditySaturation(float temperature){

}

