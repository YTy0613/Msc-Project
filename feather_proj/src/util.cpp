#include "util.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"


GLuint Util::LoadTexture(const char* filename, int& w, int& h, int& k, int& k1, int* Xvalue, int* Xvalue2)
{
    k = 0;
    k1 = 0;
    GLuint texture_id;
    //int w, h;
    int comp;
    unsigned char* image =
        stbi_load(filename, &w, &h, &comp, STBI_default);
    if (!image) {
        std::cerr << "Unable to load texture: " << filename
            << std::endl;
        exit(1);
    }

    glGenTextures(1, &texture_id);
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    glBindTexture(GL_TEXTURE_2D, texture_id);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);
    //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    if (comp == 3) {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, w, h, 0, GL_RGB,
            GL_UNSIGNED_BYTE, image);
    }
    else if (comp == 4) {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_RGBA,
            GL_UNSIGNED_BYTE, image);
    }
    else {
        assert(0);
    }

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if ((image[3 * i * w + 3 * j] < 250)
                && (image[3 * i * w + 3 * j + 1] < 250)
                && (image[3 * i * w + 3 * j + 2] < 250)) {
                Xvalue[k] = j;
                k++;
                break;
            }
        }
    }
    for (int i1 = 0; i1 < h; i1++) {
        for (int j1 = w - 1; j1 >= 0; j1--) {
            if ((image[3 * i1 * w + 3 * j1] < 250)
                && (image[3 * i1 * w + 3 * j1 + 1] < 250)
                && (image[3 * i1 * w + 3 * j1 + 2] < 250)) {
                Xvalue2[k1] = j1;
                k1++;
                break;
            }
        }
    }


    glBindTexture(GL_TEXTURE_2D, 0);
    stbi_image_free(image);
    return texture_id;
}

void Util::Invert(GLfloat in[16], GLfloat out[16])
{
    // Transpose rotation
    out[0] = in[0]; out[1] = in[4]; out[2] = in[8];
    out[4] = in[1]; out[5] = in[5]; out[6] = in[9];
    out[8] = in[2]; out[9] = in[6]; out[10] = in[10];

    // clear shearing terms
    out[3] = 0.0f; out[7] = 0.0f; out[11] = 0.0f; out[15] = 1.0f;

    // Translation is minus the dot of translation and rotations
    out[12] = -(in[12] * in[0]) - (in[13] * in[1]) - (in[14] * in[2]);
    out[13] = -(in[12] * in[4]) - (in[13] * in[5]) - (in[14] * in[6]);
    out[14] = -(in[12] * in[8]) - (in[13] * in[9]) - (in[14] * in[10]);
}

void Util::Multiply(GLfloat vecIn[3], GLfloat m[16], GLfloat vecOut[3])
{
    vecOut[0] = (vecIn[0] * m[0]) + (vecIn[1] * m[4]) + (vecIn[2] * m[8]) + m[12];
    vecOut[1] = (vecIn[0] * m[1]) + (vecIn[1] * m[5]) + (vecIn[2] * m[9]) + m[13];
    vecOut[2] = (vecIn[0] * m[2]) + (vecIn[1] * m[6]) + (vecIn[2] * m[10]) + m[14];
}