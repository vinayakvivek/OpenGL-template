#ifndef _TEXTURE_UTIL_HPP_
#define _TEXTURE_UTIL_HPP_

GLuint LoadTexture(const char *filename, int width, int height);
void FreeTexture(GLuint texture);

#endif  // _TEXTURE_UTIL_HPP_
