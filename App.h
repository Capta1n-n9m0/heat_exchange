#ifndef HEAT_EXCHANGE_GLFW_APP_H
#define HEAT_EXCHANGE_GLFW_APP_H

#include <iostream>
#include <mutex>
#include "glad/glad.h"
#include "GLFW/glfw3.h"


class App {
private:
  static App *instance_;
  static std::mutex mutex_;

protected:
  std::string title_;
  int width_;
  int height_;
  GLFWwindow *window;

public:
  bool running;


protected:
  App(const std::string& title, int width, int height);
  ~App()= default;

public:
  App(const App&) = delete;
  void operator=(const App&) = delete;
  
  static App *GetInstance(const std::string& title, int width, int height);
  static void errorCallback(int error, const char* description);

public:
  bool OnInit();
  void OnEvent();
  void OnLoop();
  void OnRender();
  void OnCleanup();
};


#endif //HEAT_EXCHANGE_GLFW_APP_H
