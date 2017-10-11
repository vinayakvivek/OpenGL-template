#include "view.hpp"

#include <string>

View::View(GLfloat h_width, GLfloat h_height, GLfloat h_depth) {
  half_width = h_width;
  half_height = h_height;
  half_depth = h_depth;

  initShadersGL();
  initBuffersGL();

  ortho_matrix = glm::ortho(-half_width, half_width,
                            -half_height, half_height,
                            -half_depth, half_depth);
  model_view_matrix = ortho_matrix;
}

void View::initShadersGL() {
  std::string vertex_shader_file("shaders/vshader.glsl");
  std::string fragment_shader_file("shaders/fshader.glsl");

  std::vector<GLuint> shaderList;
  shaderList.push_back(mynamespace::loadShaderGL(GL_VERTEX_SHADER, vertex_shader_file));
  shaderList.push_back(mynamespace::loadShaderGL(GL_FRAGMENT_SHADER, fragment_shader_file));

  shaderProgram = mynamespace::createProgramGL(shaderList);
  glUseProgram(shaderProgram);
}

void View::initBuffersGL() {
  v_position = glGetAttribLocation(shaderProgram, "vPosition");
  v_color = glGetAttribLocation(shaderProgram, "vColor");
  u_model_view_matrix = glGetUniformLocation(shaderProgram, "uModelViewMatrix");

  num_vao = 1;
  num_vbo = 1;
  vao = new GLuint[num_vao];
  vbo = new GLuint[num_vbo];

  glGenVertexArrays(num_vao, vao);
  glGenBuffers(num_vbo, vbo);

  glEnable(GL_PROGRAM_POINT_SIZE);
}

void View::renderGL() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glBindVertexArray(vao[0]);
  glUniformMatrix4fv(u_model_view_matrix, 1, GL_FALSE, glm::value_ptr(model_view_matrix));
  glDrawArrays(GL_TRIANGLES, 0, points.size());
}

void View::addSampleTriangle() {
  points = std::vector<glm::vec4>({
    glm::vec4(0.0, 0.0, 0.0, 1.0),
    glm::vec4(-200.0, 0.0, 0.0, 1.0),
    glm::vec4(0.0, 200.0, 0.0, 1.0)
  });

  colors = std::vector<glm::vec4>({
    glm::vec4(0.2, 0.4, 0.6, 1.0),
    glm::vec4(0.5, 0.1, 0.4, 1.0),
    glm::vec4(0.7, 0.9, 0.1, 1.0),
  });

  assert(points.size() == colors.size());

  GLuint buffer_len = points.size() * sizeof(glm::vec4);

  glBindVertexArray(vao[0]);
  glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);

  glEnableVertexAttribArray(v_position);
  glVertexAttribPointer(v_position, 4, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));
  glEnableVertexAttribArray(v_color);
  glVertexAttribPointer(v_color, 4, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(buffer_len));

  glBufferData(GL_ARRAY_BUFFER, 2 * buffer_len, NULL, GL_STATIC_DRAW);
  glBufferSubData(GL_ARRAY_BUFFER, 0, buffer_len, &points[0]);
  glBufferSubData(GL_ARRAY_BUFFER, buffer_len, buffer_len, &colors[0]);
}
