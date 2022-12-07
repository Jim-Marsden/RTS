#version 120
uniform sampler2D texture;
uniform float selected_color;

vec4 fun(float selected_color_in){
    vec3 t = texture2D(texture,gl_TexCoord[0].st).rgb;
    vec4 color;
    if(t == vec3(selected_color_in, selected_color_in, selected_color_in))
        color = vec4(t.xyz, 1.0);
    else
        color = vec4(t.xyz, 0.5);
    return color;
}
void main() {
    vec4 color = fun(selected_color);
    gl_FragColor = color;
}
