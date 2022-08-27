#pragma once
#include <string>
#include<vector>
using namespace std;


/*!
* \�������� ������������� ������������ � ������ ��������� �� ����� ��
* \param[in\out] text - ����� ��������� �� ����� ��
* \throw - (����������� ���������� � ������ ������ � �������� ������)
*/
void delComments(vector<string>& text);

/*!
* \���������� ������ �������������� �����������
* \param[in] text - ����� ��������� �� ����� ��
* \param[in] numberRow - ����� ������, � ������� ���������� �����
* \param[in] numberPos - ������� ������ �������������� �����������, ������� ��� ������, � ������
* \param[in\out] indexRowBegin - ������ ������ ������ �����������
* \param[in\out] posBegin - ������� ������ ����������� � ������
* \param[in\out] countFindBegin - ������� ��������� � ������� ������ 
*/
void findBeginComment(vector<string>& text, int numberRow, int numberPos, int* indexRowBegin, int* posBegin, int* countFindBegin);

/*!
* \���������� ����� �������������� �����������
* \param[in] text - ����� ��������� �� ����� ��
* \param[in] numberRow - ����� ������, � ������� ���������� �����
* \param[in] numberPos - ������� ����� �������������� �����������, ������� ��� ������, � ������
* \param[in\out] indexRowEnd - ������ ������ ����� �����������
* \param[in\out] posEnd - ������� ����� ����������� � ������
* \param[in\out] countFindEnd - ������� ��������� � ������� ������ 
*/
void findEndComment(vector<string>& text, int numberRow, int numberPos, int* indexRowEnd, int* posEnd, int* countFindEnd);

/*!
* \������� ���������� � ����
* \param[in] text - ����� ��������� �� ����� ��
*/
void saveResult(vector<string>& text);


