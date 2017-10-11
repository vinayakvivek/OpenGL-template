#version 400

in vec4 vPosition;
in vec4 vColor;

uniform mat4 uModelViewMatrix;

void main () {
	gl_Position = vPosition;
}
