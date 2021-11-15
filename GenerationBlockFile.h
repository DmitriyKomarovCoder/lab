#ifndef PROJECT_GENERATIONBLOCKFILE_H_
#define PROJECT_GENERATIONBLOCKFILE_H_
#define FIRST_ASCII_CHAR 0
#define LAST_ASCII_CHAR 128
#include <math.h>
#include <stdio.h>
#include <cstdio>
#include <cstdlib>
#include <ostream>
#include <ctime>
#include <iostream>
#include <fstream>

void Generation_Block_File(const char* path_file, int n, int *key);
void Generation_Coding_File(const char* path_file, const char* path_file_coding, const char* path_file_key, int *key);
void Decoding_File(const char* path_file_coding, const char* path_file_key);

#endif  //  PROJECT_INCLUDE_GENERATIONBLOCKFILE_H_

