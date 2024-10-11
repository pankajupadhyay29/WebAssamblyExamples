#include <emscripten.h>

EMSCRIPTEN_KEEPALIVE
// Function to convert RGB to Grayscale
void convertToGrayscale(unsigned int length, unsigned int *data, float rRatio, float gRatio, float bRatio) {
    // printf("hello, world!\n");
    // printf("length: %d; rRatio: %f;\n", length, rRatio);
    for (unsigned int i = 0; i < length; i += 4) {
        if (i + 2 < length) {
            unsigned int r = data[i];
            unsigned int g = data[i + 1];
            unsigned int b = data[i + 2];
            unsigned int gray = (unsigned int)(r*rRatio + g*gRatio + b*bRatio);
            data[i] = gray;
            data[i + 1] = gray;
            data[i + 2] = gray;
        }

        // data[i] = (unsigned char)(r*rRatio);
        // data[i + 1] = (unsigned char)(g*gRatio);
        // data[i + 2] = (unsigned char)(b*bRatio);
    }
}
