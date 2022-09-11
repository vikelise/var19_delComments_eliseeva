#include "pch.h"
#include "CppUnitTest.h"
#include"../var19_delComments_eliseeva/var19_delComments_eliseeva.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestfindBeginComment
{
	TEST_CLASS(UnitTestfindBeginComment)
	{
	public:
		
		TEST_METHOD(findFromBegin)
		{
			vector<string>text = { "void main ()", "{", "int a = 9;/*int", "k;*/", "a = 10;", "}" };
			int numberRow = 0;
			int numberPos = -1;
			int indexRowBegin = 0;
			int posBegin = -1;
			int countFindBegin = 0;
			int expcountFindBegin = 1;
			int expindexRowBegin = 2;
			int expposBegin = 10;

			findBeginComment(text, numberRow, numberPos, &indexRowBegin, &posBegin, &countFindBegin);
			Assert::AreEqual(expcountFindBegin, countFindBegin);
			Assert::AreEqual(expindexRowBegin, indexRowBegin);
			Assert::AreEqual(expposBegin, posBegin);
		}

		TEST_METHOD(findFromFoundComment)
		{
			vector<string>text = { "void main ()", "{", "int a=9;/*int", "k;*/", "a = 10;", "/*68", "int", "char f;*/", "}" };
			int numberRow = 2;
			int numberPos = 8;
			int indexRowBegin = 2;
			int posBegin = 8;
			int countFindBegin = 0;
			int expcountFindBegin = 1;
			int expindexRowBegin = 5;
			int expposBegin = 0;

			findBeginComment(text, numberRow, numberPos, &indexRowBegin, &posBegin, &countFindBegin);
			Assert::AreEqual(expcountFindBegin, countFindBegin);
			Assert::AreEqual(expindexRowBegin, indexRowBegin);
			Assert::AreEqual(expposBegin, posBegin);
		}

		TEST_METHOD(beginMultilineCommSingleLine)
		{
			vector<string>text = { "void main()","{","int a;//int t/*int k;","}" };
			int numberRow = 0;
			int numberPos = -1;
			int indexRowBegin = 0;
			int posBegin = -1;
			int countFindBegin = 0;
			int expcountFindBegin = 1;
			int expindexRowBegin = 0;
			int expposBegin = -1;

			findBeginComment(text, numberRow, numberPos, &indexRowBegin, &posBegin, &countFindBegin);
			Assert::AreEqual(expcountFindBegin, countFindBegin);
			Assert::AreEqual(expindexRowBegin, indexRowBegin);
			Assert::AreEqual(expposBegin, posBegin);
		}

		
	};
}
