#include <iostream>

static const int MAX_KEY_VALUE_LEN = 100;
static const int MAX_PAIRS = 1024;

struct KeyValuePair {
    char key[MAX_KEY_VALUE_LEN+1];
    char value[MAX_KEY_VALUE_LEN+1];
};

struct DataMap {
    KeyValuePair pairs[MAX_PAIRS];
    int count;
};

static void initDataMap(DataMap &map) {
    map.count = 0;
    for (int i = 0; i < MAX_PAIRS; ++i) {
        map.pairs[i].key[0] = '\0';
        map.pairs[i].value[0] = '\0';
    }
}

static bool isSpace(char c) {
    return c == ' ' || c == '\t' || c == '\n' || c == '\r'; // проверка на пробельный символ
}

static void trim(char *str) { // удаление пробелов в начале и конце строки
    int len = 0;

    while (str[len] != '\0') ++len; // вычисление длины строки

    int start = 0; // пропуск пробелов в начале
    while (start < len && isSpace(str[start])) ++start; // пропуск пробелов в начале

    int end = len - 1;
    while (end >= start && isSpace(str[end])) --end;

    int newLen = end - start + 1;// вычисление новой длины строки
    if (newLen <= 0) { // если строка пустая
        str[0] = '\0'; // установка пустой строки
        return;
    }
    for (int i = 0; i < newLen; ++i) {// копирование символов
        str[i] = str[start + i]; // сдвиг символов в начало строки
    }
    str[newLen] = '\0';// добавление завершающего нуля
}

static bool isValidIdetifierChar(char c) { // проверка на допустимый символ ключа
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9') || c == '_';
}

static bool isSingleWordValid(const char *str) { // проверка на допустимость ключа
    if (str[0] == '\0') return false; // пустая строка невалидна
    for (int i = 0; str[i] != '\0'; ++i) {
        if (!isValidIdetifierChar(str[i])) return false; // если найден недопустимый символ, возвращаем false
    }
    return true; // все символы допустимы
}



int main() {
    DataMap map;
    initDataMap(map);
    // Пример использования trim
    char exampleStr[] = "   Hello, World!   ";
    std::cout << "Before trim: '" << exampleStr << "'" << std::endl;
    trim(exampleStr);
    std::cout << "After trim: '" << exampleStr << "'" << std::endl;

    return 0;
}

