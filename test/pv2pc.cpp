#include "emp-ag2pc/pv2pc.h"
#include "voleith-lib/vole.h"

int main() {

    uint8_t iv[16] = {0};
    uint8_t sd[32] = {0};
    
    // Generate some random data for testing
    for(int i = 0; i < 16; i++) {
        iv[i] = rand() % 256;
    }
    for(int i = 0; i < 32; i++) {
        sd[i] = rand() % 256; 
    }

    // Call AES with random input
    unsigned int lambda = 128;
    unsigned int depth = 4;
    unsigned int outLenBytes = 16;
    uint8_t* u = (uint8_t*)malloc(outLenBytes);
    uint8_t* v = (uint8_t*)malloc(depth * outLenBytes);

    ConvertToVole(iv, sd, false, lambda, depth, outLenBytes, u, v);

    free(u);
    free(v);
    
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
