#include <iostream>
#include "App.h"
#include "Environment.h"
#include "Seeders.h"

constexpr bool DEBUG = true;

int run();
int test();

int main() {
  if(DEBUG){
    return test();
  } else {
    return run();
  }
}

int run() {
  App *app = App::GetInstance("Heat Exchange", 800, 800);
  if (app == nullptr) {
    return -1;
  }
  if(!app->OnInit()) {
    return -1;
  }
  app->OnLoop();
  app->OnCleanup();
  return 0;
}

int test(){
  Environment env = Environment(10, 10, 10, 0.1f, 1.0f);
  env.seed(new HotWaterDryColdAirSeeder());
  
  return 0;
}