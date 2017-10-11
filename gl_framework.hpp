#ifndef GL_FRAMEWORK_HPP_
#define GL_FRAMEWORK_HPP_

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>

namespace mynamespace {
  void initGL(void);
  void error_callback(int error, const char* description);
  void framebuffer_size_callback(GLFWwindow* window, int width, int height);
  void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
};  // namespace mynamespace

#endif  GL_FRAMEWORK_HPP_
