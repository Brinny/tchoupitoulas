/* Shader code initially written by Joe Groff.
 * Modified slightly by Brittany Allesandro.
 */
#include "Utilities.h"

using namespace std;

/*********************Texture Loading******************************************/
void loadTexture(const char* fileName, int count, GLuint* textures) {

    ILuint imageID;
	ILboolean success;					
	ilGenImages(1, &imageID);
	ilBindImage(imageID);
	success = ilLoadImage(fileName);
 
	if (success)
	{
		success = ilConvertImage(IL_RGB, IL_UNSIGNED_BYTE);
 
		if (!success)
		{
			cout << "Could not convert file." << endl;
			exit(-1);
		}

		glBindTexture(GL_TEXTURE_2D, textures[count]);
 
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
 
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
 
		glTexImage2D(GL_TEXTURE_2D, 				// Type of texture
					 0,				                // Pyramid level
					 GL_RGB,	                    // Image colour depth
					 ilGetInteger(IL_IMAGE_WIDTH),	// Image width
					 ilGetInteger(IL_IMAGE_HEIGHT),	// Image height
					 0,				                // Border width in pixels
					 ilGetInteger(IL_IMAGE_FORMAT),	// Image format
					 GL_UNSIGNED_BYTE,		        // Image data type
					 ilGetData());			        // The data
 	}
  	else
  	{
		cout << "Could not load image." << endl;
		exit(-1);
  	}
 
 	ilDeleteImages(1, &imageID);
}

/*********************Shader Loading*******************************************/
static char* file_contents(const char *filename) {
    FILE* file = fopen(filename, "r");
    if(!file) {
        fprintf(stderr, "Unable to open %s for reading\n", filename);
        return NULL;
    }

    fseek(file, 0L, SEEK_END);
    long size = ftell(file);

    fseek(file, 0L, SEEK_SET);
    char* buffer = new char[size + 1];
    fread(buffer, 1, size, file);

    buffer[size] = '\0';
    fclose(file);

    return buffer;
}

GLuint get_shader(GLenum type, const char *filename) {
    GLchar *source = file_contents(filename);
    GLuint shader;
    GLint shader_ok;
    
    if(!source) {
        return 0;
    }
    
    shader = glCreateShader(type);
    glShaderSource(shader, 1, (const GLchar**)&source, NULL);
    free(source);
    glCompileShader(shader);

    glGetShaderiv(shader, GL_COMPILE_STATUS, &shader_ok);
    if(!shader_ok) {
        fprintf(stderr, "Failed to compile %s:\n", filename);
        glDeleteShader(shader);
        return 0;
    }
    return shader;
}

GLuint get_program(GLuint vertex_shader, GLuint fragment_shader) {
    GLint program_ok;
    GLuint program = glCreateProgram();
    
    glAttachShader(program, vertex_shader);
    glAttachShader(program, fragment_shader);
    glLinkProgram(program);
    
    glGetProgramiv(program, GL_LINK_STATUS, &program_ok);
    if(!program_ok) {
        fprintf(stderr, "Failed to link shader program\n");
        glDeleteProgram(program);
        return 0;
    }
    return program;
}

GLuint init_shaders(const char* vertex_shader, const char* fragment_shader) {
    GLuint vertex, fragment;
    vertex = get_shader(GL_VERTEX_SHADER, vertex_shader);
    fragment = get_shader(GL_FRAGMENT_SHADER, fragment_shader);
    
    GLuint program = get_program(vertex, fragment);
    
    return program;
}
