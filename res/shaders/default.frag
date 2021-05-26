#version 460 core

in vec4 vertexColour;
in vec2 textureCoord;
out vec4 fragColour;
uniform sampler2D ourTexture;

void main(){
	if (texture(ourTexture, textureCoord).a < 1.0f){
		fragColour = texture(ourTexture, textureCoord) + vertexColour;
	}
	else{
		fragColour = texture(ourTexture, textureCoord);
	}
}