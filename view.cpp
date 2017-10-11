#include "view.hpp"

#include <string>

View::View(GLfloat h_width, GLfloat h_height, GLfloat h_depth) {
  half_width = h_width;
  half_height = h_height;
  half_depth = h_depth;

  initShadersGL();
  initBuffersGL();
}

void View::initShadersGL() {
  std::string vertex_shader_file("shaders/vshader.glsl");
  std::string fragment_shader_file("shaders/fshader.glsl");

  std::vector<GLuint> shaderList;
  shaderList.push_back(viewing::loadShaderGL(GL_VERTEX_SHADER, vertex_shader_file));
  shaderList.push_back(viewing::loadShaderGL(GL_FRAGMENT_SHADER, fragment_shader_file));

  shaderProgram = viewing::createProgramGL(shaderList);
  glUseProgram(shaderProgram);
}

void View::initBuffersGL() {
  vPosition = glGetAttribLocation(shaderProgram, "vPosition");
  vColor = glGetAttribLocation(shaderProgram, "vColor");
  uModelViewMatrix = glGetUniformLocation(shaderProgram, "uModelViewMatrix");

  num_vao = 1;
  num_vbo = 1;
  vao = new GLuint[num_vao];
  vbo = new GLuint[num_vbo];

  glGenVertexArrays(num_vao, vao);
  glGenBuffers(num_vbo, vbo);
  glGenBuffers(num_eab, veo);

  glEnable(GL_PROGRAM_POINT_SIZE);
}

void View::renderGL() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glUseProgram(shaderProgram);

  glBindVertexArray(vao[0]);
  glDrawArrays(GL_TRIANGLES, 0, 3);
}

void View::addSampleCube() {

}