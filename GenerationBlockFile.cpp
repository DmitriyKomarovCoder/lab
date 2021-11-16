#include "GenerationBlockFile.h"

void Generation_Block_File(const char* path_file, int n, int *key) {  //  Генерация блочного блокнота 
    setlocale(LC_ALL, "ru");
    int x; 
    char sim;
    srand(time(0));
    std::ofstream f;
    f.open(path_file);
    for (int i=0; i < n; i++) {
        x = rand() % LAST_ASCII_CHAR;
        key[i] = x;
        sim = (char)x;
        f << sim;
    }
    f.close();
}

void Generation_Coding_File(const char* path_file, const char* path_file_coding, const char* path_file_key, int *key) {//Кодирование файла и запись ключа
    setlocale(LC_ALL, "ru");
    char s; 
    int k = 0, simvol;
    int x;
    std::ifstream f;
    std::ofstream coding_file;
    std::ofstream key_file;
    coding_file.open(path_file_coding);
    f.open(path_file);
    key_file.open(path_file_key);
    while (f.get(s)) {  //  Кодирование сообщения
        x = (int) s;
        simvol = ((x + key[k % 30]) % 256);
        coding_file << (char)simvol;
        k ++;
    }
    for (int i = 0; i < 30; i ++) {  //  запись в ключа в файл
        key_file << key[i] <<std::endl;
    }
    f.close();
    coding_file.close();
    key_file.close();
}

void Decoding_File(const char* path_file_coding, const char* path_file_key) {  //  декодинг файла
    setlocale(LC_ALL, "ru");
    std::ifstream key_file;
    std::ifstream coding_file;
    int key[30];
    int k = 0, x;
    char s;
    key_file.open(path_file_key);  
    coding_file.open(path_file_coding);
    while (!key_file.eof()) {  //  создание массива ключей, принятых из файла
        key_file >> key[k]; 
        k ++;
    }
    k = 0;
    while (coding_file.get(s)) {  //  Декодинг файла
        x = ((int) s);
        x = ((x + 256 - key[k % 30] % 256) % 256);
        std::cout<<((char)x);
        k ++;
    }
    std::cout<<std::endl;
    key_file.close();
    coding_file.close();
}