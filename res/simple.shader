#shader vertex
#version 400

layout (location = 0) in vec4 pos;
layout (location = 1) in vec4 color;

out vec4 frag_color;

void main()
{
    frag_color=color;
    gl_Position=pos;
}

#shader fragment
#version 400
in vec4 frag_color;
out vec4 color;

void main()
{
    color = frag_color;
}
