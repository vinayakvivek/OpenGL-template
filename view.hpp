#ifndef VIEW_HPP_
#define VIEW_HPP_

#include <vector>
#include <cmath>

#include "gl_framework.hpp"
#include "shader_util.hpp"

#include "glm/vec3.hpp"
#include "glm/vec4.hpp"
#include "glm/mat4x4.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"
#include "glm/gtx/string_cast.hpp"


#define BUFFER_OFFSET(offset) (reinterpret_cast<void *>(offset))

class View {
  // screen size
  GLfloat half_width;
  GLfloat half_height;
  GLfloat half_depth;

  // models setup
  std::vector<glm::vec4> points;
  std::vector<glm::vec4> colors;

  GLuint shaderProgram;
  GLuint *vbo, *vao;
  GLuint num_vao;
  GLuint num_vbo;

  GLuint v_position;
  GLuint v_color;
  GLuint u_model_view_matrix;

  glm::mat4 ortho_matrix;
  glm::mat4 model_view_matrix;

  void initShadersGL();
  void initBuffersGL();
 public:
  View(GLfloat h_width, GLfloat h_height, GLfloat h_depth);
  void renderGL();
  void addSampleCube();
};

#endif  // VIEW_HPP_
