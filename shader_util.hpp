#ifndef SHADER_UTIL_HPP_
#define SHADER_UTIL_HPP_

#include <GL/glew.h>

#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>

namespace mynamespace {
  GLuint loadShaderGL(GLenum eShaderType, const std::string &strFilename);
  GLuint createShaderGL(GLenum eShaderType, const std::string &strShaderFile);
  GLuint createProgramGL(const std::vector<GLuint> &shaderList);
};

#endif  // SHADER_UTIL_HPP_
