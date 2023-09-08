#ifndef HEAT_EXCHANGE_GLFW_SEEDERS_H
#define HEAT_EXCHANGE_GLFW_SEEDERS_H
#include "Arrays.h"
#include "Environment.h"

class Seeder {
public:
  virtual void seed(Environment *env) = 0;
};

class HotWaterDryColdAirSeeder : public Seeder {
public:
  void seed(Environment *env) override;
};






#endif //HEAT_EXCHANGE_GLFW_SEEDERS_H
