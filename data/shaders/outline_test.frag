#version 120
uniform sampler2D texture;
uniform vec3 selected_color;
uniform float outline_scale;

vec4 outline(float target_percent, vec3 target_color){
    float max = 1.0f - target_percent;
    if(gl_TexCoord[0].x < target_percent){
        return vec4(target_color.rgb,1);
    }
    else if(gl_TexCoord[0].x > max){
        return vec4(target_color.rgb,1);
    }
    else if(gl_TexCoord[0].y < target_percent){
        return vec4(target_color.rgb,1);
    }
    else if(gl_TexCoord[0].y > max){
        return vec4(target_color.rgb,1);
    }
    else {
        vec3 target = texture2D(texture,gl_TexCoord[0].st).rgb;
        return vec4(target.xyz, 1.0);
    }
}
void main() {
    vec4 color = outline(outline_scale, selected_color);
    gl_FragColor = color;
}
