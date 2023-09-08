#ifndef HEAT_EXCHANGE_GLFW_ENVIRONMENT_H
#define HEAT_EXCHANGE_GLFW_ENVIRONMENT_H
#include <iostream>
#include <vector>
#include <boost/multi_array.hpp>
#include "Seeders.h"

enum class CellType {
  AIR,
  WATER,
};

/**
 * @brief The Environment class
 *
 * The environment is a 3D grid of cells. Each cell has a type, density, mass, temperature, heat capacity, heat conductivity, and saturation.
 *
 * @param width The width of the environment in meters
 * @param height The height of the environment in meters
 * @param depth The depth of the environment in meters
 * @param cellDimension The width, height, and depth of each cell in meters
 * @param timeStep The time step in milliseconds
 * @param cellTypes The type of each cell
 * @param density The density of each cell in kg/m^3
 * @param mass The mass of each cell in kg
 * @param temperature The temperature of each cell in degrees Celsius
 * @param heatCapacity The heat capacity of each cell in J/(kg*K)
 * @param heatConductivity The heat conductivity of each cell in W/(m*K)
 * @param saturation The humidity of each cell in portion of 1.0
 * @param isReady Whether the environment is ready to be simulated
 * @param cellVolume The volume of each cell in m^3
 * */
class Environment {
public:
  //! meters
  int width;
  //! meters
  int depth;
  //! meters
  int height;
  //! meters
  float cellDimension;
  //! cubic meters
  float cellVolume;
  //! milliseconds
  float timeStep;
  bool isReady;
  //! width, height, depth
  boost::multi_array<CellType, 3> cellTypes;
  boost::multi_array<float, 3> density;
  boost::multi_array<float, 3> mass;
  boost::multi_array<float, 3> temperature;
  boost::multi_array<float, 3> heatCapacity;
  boost::multi_array<float, 3> heatConductivity;
  boost::multi_array<float, 3> saturation;
  
  
public:
  Environment(int width, int height, int depth, float cellDimension, float timeStep);
  void seed(Seeder *seeder);

};

float dryAirDensity(float temperature, float pressure = 101325.0f);

float getHumiditySaturation(float temperature);

#endif //HEAT_EXCHANGE_GLFW_ENVIRONMENT_H