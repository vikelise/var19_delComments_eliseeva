#pragma once

#include <string>
#include<vector>
/**
namespace std
\brief Пространство имен std
*/
using namespace std;


/*! Удаление многострочных комментариев в тексте программы на языке Си
* \param[in\out] text - текст программы на языке Си
*/
void delComments(vector<string>& text);

/*! Нахождение начала многострочного комментария
* \param[in] text - текст программы на языке Си
* \param[in] numberRow - номер строки, с которой начинается поиск
* \param[in] numberPos - позиция начала многострочного комментария, который уже найден, в строке
* \param[in\out] indexRowBegin - индекс строки начала комментария
* \param[in\out] posBegin - позиция начала комментария в строке
* \param[in\out] countFindBegin - счетчик обращений к функции поиска 
*/
void findBeginComment(vector<string>& text, int numberRow, int numberPos, int* indexRowBegin, int* posBegin, int* countFindBegin);

/*! Нахождение конца многострочного комментария
* \param[in] text - текст программы на языке Си
* \param[in] numberRow - номер строки, с которой начинается поиск
* \param[in] numberPos - позиция конца многострочного комментария, который уже найден, в строке
* \param[in\out] indexRowEnd - индекс строки конца комментария
* \param[in\out] posEnd - позиция конца комментария в строке
* \param[in\out] countFindEnd - счетчик обращений к функции поиска 
*/
void findEndComment(vector<string>& text, int numberRow, int numberPos, int* indexRowEnd, int* posEnd, int* countFindEnd);

/*! Записть результата в файл
* \param[in] text - текст программы на языке Си
* \param[in] path - путь к файлу для записи результатов
*/
void saveResult(vector<string>& text, string & path);


