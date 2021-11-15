#include "GenerationBlockFile.h"
int main() {
    int key[30];
    Generation_Block_File("block.txt", 30, key);
    Generation_Coding_File("file.txt", "coding_file.txt", "key.txt" ,key);
    Decoding_File("coding_file.txt", "key.txt");
    return 0;
}