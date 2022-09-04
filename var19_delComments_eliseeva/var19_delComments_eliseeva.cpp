// var19_delComments_eliseeva.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include<vector>
#include"var19_delComments_eliseeva.h"

using namespace std;

int main(const int argc, char** argv)
{
    setlocale(LC_ALL, "rus");

    //Выдать ошибку, если входной файл не указанив аргументах командной строки
    if (argc == 1)
    {
        cout << "Входной файл не указан." << endl;
        return 0;
    }

    //Выдать ошибку, если входной файл невозможно открыть 
    string path = argv[1];//путь ко входному файлу 

    fstream fin;//объект типа ifstream (содержание входного файла)
    fin.open(path);

    if (!fin.is_open())
    {
        cout << "Входной файл" << path << "Невозможно открыть." << endl;
        return 0;
    }

    string line;
    vector<string>text;

    while (!fin.eof())
    {
        getline(fin, line);
        text.push_back(line);//считывание из файла
    }
    fin.close();

    delComments(text);//удаление многострочных комментариев
    saveResult(text);//запись результатов в файл


}

void delComments(vector<string>& text)
{
    int indexRowBegin = 0;//индекс строки начала многострочного комментария
    int indexRowEnd = 0;//индекс строки конца многострочного комментария
    int posBegin = -1;//позииция начала многострочного комментария в строке
    int posEnd = -1;//позиция конца многострочного комментария в строке
    int countFindBegin = 0;//счетчик обращений к функции поиска начала
    int countFindEnd = 0;//счетчик обращений к функции поиска конца 

    try {
        do {
            findBeginComment(text, indexRowBegin, posBegin, &indexRowBegin, &posBegin, &countFindBegin);//поиск начала многострочного комментария 
            findEndComment(text, indexRowEnd, posEnd, &indexRowEnd, &posEnd, &countFindEnd);//поиск конца многострочного комментария
            if (posBegin != -1 && posEnd != -1)
            {
                if (indexRowBegin != indexRowEnd)
                {
                    if (indexRowBegin < indexRowEnd)
                    {
                        //удаление наччала многострочного комментария
                        text[indexRowBegin].erase(text[indexRowBegin].begin() + posBegin, text[indexRowBegin].begin() + text[indexRowBegin].size());
                        //если после удаления осталась пустая строка, записываем в нее 0
                        if (text[indexRowBegin].empty() == 1)
                            text[indexRowBegin].insert(text[indexRowBegin].begin(), '0');

                        //удаление тела многострочного комментария с заменой пустых строк 0
                        for (int i = indexRowBegin + 1; i < indexRowEnd; i++)
                        {
                            text[i].erase(text[i].begin(), text[i].end());
                            text[i].insert(text[i].begin(), '0');
                        }

                        //удаление конца многострочного комментария 
                        text[indexRowEnd].erase(text[indexRowEnd].begin(), text[indexRowEnd].begin() + posEnd + 2);
                        //если после удаления осталась пустая строка, записываем в нее 0
                        if (text[indexRowEnd].empty() == 1)
                            text[indexRowEnd].insert(text[indexRowEnd].begin(), '0');
                    }
                    else throw 1;// неправильно обозначенные комментарии
                }
                else
                {
                    posBegin = posEnd;
                }
            }
            else if (posBegin == -1 && posEnd == -1 && countFindBegin == 1 && countFindEnd==1)
                throw 2;//нет комментариев многострочных;
            else if (posBegin == -1 && posEnd != -1 || posBegin != -1 && posEnd == -1)
                throw 1;// неправильно обозначены комментарии

        } while (posBegin != -1 || posEnd != -1);//повторять пока комментарии находятся 
    }
    catch (int& exception)
    {
        if (exception == 1)
            cout << "Некорректно обозначены многострочные комментарии" << endl;
        else
            cout << "Нет многострочных комментариев" << endl;
    }
}

void findBeginComment(vector<string>& text, int numberRow, int numberPos, int* indexRowBegin, int* posBegin, int* count)
{
    *posBegin = -1;//считаем позицию начала многострочного комментария в строке не найденной 
    int status = 0;//переменная, отвечающая за текущее положение(0-в тексте, 1-в строковой константе, 2- в однострочном комментарии)
    for (int i = numberRow; i < text.size(); i++)
    {
        for (int j = 0; j < text[i].size(); j++)
        {
            if (text[i][j] == '"' && status == 0)
                status = 1; //в строковой константе
            else if (text[i][j] == '"' && status == 1)
                status = 0;//в тексте
            if (j != (text[i].size() - 1))
                if (text[i][j] == '/' && text[i][j + 1] == '/' && status == 0)
                    status = 2;//в однострочном комментарии
            if (j != (text[i].size() - 1))//если текущий элемент не последний 
            {

                if (text[i][j] == '/' && text[i][j + 1] == '*' && status == 0 && *posBegin == -1)
                {
                    if (i != numberRow)
                    {
                        *indexRowBegin = i;
                        *posBegin = j;
                    }
                    else if (j != numberPos)
                    {
                        *indexRowBegin = i;
                        *posBegin = j;
                    }
                }

            }
        }
        if (status == 2)//если были в однострочном комментарии, то при переходе к следующей строке попадаем в текст
            status = 0;
    }
    *count = *count + 1;//счетчик обращений к функции увеличиваем на 1
}

void findEndComment(vector<string>& text, int numberRow, int numberPos, int* indexRowEnd, int* posEnd)
{
    *posEnd = -1;
    int status = 0;
    for (int i = numberRow; i < text.size(); i++)
    {
        for (int j = 0; j < text[i].size(); j++)
        {
            if (text[i][j] == '"' && status == 0)
                status = 1; //в строковой константе
            else if (text[i][j] == '"' && status == 1)
                status = 0;//в тексте
            if (j != (text[i].size() - 1))
                if (text[i][j] == '/' && text[i][j + 1] == '/' && status == 0)
                    status = 2;//в однострочном комментарии
            if (j != (text[i].size() - 1))//если текущий элемент не последний 
            {
                if (text[i][j] == '*' && text[i][j + 1] == '/' && status == 0 && *posEnd == -1)
                {
                    if (i != numberRow)
                    {
                        *indexRowEnd = i;
                        *posEnd = j;
                    }
                    else if (j != numberPos)
                    {
                        *indexRowEnd = i;
                        *posEnd = j;
                    }
                }
            }
        }
        if (status == 2)//если находились в однострочном коммкентарии то при преходе к следуещей строке меняфем сосотояние на в тексте
            status = 0;
    }
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
