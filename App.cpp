#include "App.h"

const char *vertexShaderSource = "#version 330 core\n"
                                 "layout (location = 0) in vec3 aPos;\n"
                                  "void main()\n"
                                  "{\n"
                                  "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
                                  "}\0";
const char *fragmentShaderSource = "#version 330 core\n"
                                   "out vec4 FragColor;\n"
                                   "void main()\n"
                                   "{\n"
                                   "   FragColor = vec4(0.8f, 0.3f, 0.2f, 1.0f);\n"
                                   "}\n\0";

App *App::instance_ = nullptr;
std::mutex App::mutex_;

App::App(const std::string &title, int width, int height) {
  title_ = title;
  width_ = width;
  height_ = height;
  window = nullptr;
  running = false;
}

App *App::GetInstance(const std::string &title, int width, int height) {
  std::lock_guard<std::mutex> lock(mutex_);
  if (instance_ == nullptr) {
    instance_ = new App(title, width, height);
  }
  return instance_;
}

void App::errorCallback(int error, const char *description) {
  fprintf(stderr, "Error: %s\n", description);
}

bool App::OnInit() {
  if(this->running) {
    return true;
  }
  glfwInit();
  glfwSetErrorCallback(errorCallback);
  
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
  
  window = glfwCreateWindow(width_, height_, title_.c_str(), nullptr, nullptr);
  if (window == nullptr) {
    std::cerr << "Failed to create GLFW window" << std::endl;
    glfwTerminate();
    return false;
  }
  glfwMakeContextCurrent(window);
  
  gladLoadGL();
  glViewport(0, 0, width_, height_);
  
  
  
  running = true;
  return true;
}

void App::OnEvent() {
}

void App::OnLoop() {
  while(!glfwWindowShouldClose(window)) {
    glfwPollEvents();
    OnRender();
    glfwSwapBuffers(window);
  }
}

void App::OnRender() {
  glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT);
}

void App::OnCleanup() {
  running = false;
  glfwDestroyWindow(window);
  glfwTerminate();
}

