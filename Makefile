CC = g++

OS := $(shell uname)
ifeq ($(OS), Darwin)
  # MacOS
  OPENGLLIB = -framework OpenGL
  LDFLAGS = -L/opt/local/lib
else
  # Linux
  OPENGLLIB = -lGL
  LDFLAGS = -L/usr/local/lib
endif

GLEWLIB = -lGLEW
GLFWLIB = -lglfw
LIBS = $(OPENGLLIB) $(GLEWLIB) $(GLFWLIB)
CPPFLAGS = -std=c++11 -I/usr/local/include -I./

BIN = out
SRCS = main.cpp gl_framework.cpp shader_util.cpp
INCLUDES = gl_framework.hpp shader_util.hpp

all: $(BIN)

$(BIN): $(SRCS) $(INCLUDES)
	g++ $(CPPFLAGS) $(SRCS) -o $(BIN) $(LDFLAGS) $(LIBS)

clean:
	rm -f *~ *.o $(BIN)
