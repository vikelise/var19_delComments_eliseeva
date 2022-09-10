#include "pch.h"
#include "CppUnitTest.h"
#include"../var19_delComments_eliseeva/var19_delComments_eliseeva.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestfindEndComment
{
	TEST_CLASS(UnitTestfindEndComment)
	{
	public:
		
		TEST_METHOD(findFromBegin)
		{
			vector<string>text = { "void main ()", "{", "int a = 9;/*int", "k;*/", "a = 10;", "}" };
			int numberRow = 0;
			int numberPos = -1;
			int indexRowEnd = 0;
			int posEnd = -1;
			int countFindEnd = 0;
			int expcountFindEnd = 1;
			int expindexRowEnd = 3;
			int expposEnd = 2;

			findEndComment(text, numberRow, numberPos, &indexRowEnd, &posEnd, &countFindEnd);

			Assert::AreEqual(expcountFindEnd, countFindEnd);
			Assert::AreEqual(expindexRowEnd, indexRowEnd);
			Assert::AreEqual(expposEnd, posEnd);
		}

		TEST_METHOD(findFromFoundComment)
		{
			vector<string>text = { "void main ()", "{", "    int a=9;/*int", "k;*/", "a = 10;", "/*68", "int", "char f;*/", "}" };
			int numberRow = 3;
			int numberPos = 2;
			int indexRowEnd = 3;
			int posEnd = 2;
			int countFindEnd = 0;
			int expcountFindEnd = 1;
			int expindexRowEnd = 7;
			int expposEnd = 7;

			findEndComment(text, numberRow, numberPos, &indexRowEnd, &posEnd, &countFindEnd);

			Assert::AreEqual(expcountFindEnd, countFindEnd);
			Assert::AreEqual(expindexRowEnd, indexRowEnd);
			Assert::AreEqual(expposEnd, posEnd);
		}

		TEST_METHOD(beginMultilineCommSingleLine)
		{
			vector<string>text = { "void main()","{","int a;//int t/*int k;","}" };
			int numberRow = 0;
			int numberPos = -1;
			int indexRowEnd = 0;
			int posEnd = -1;
			int countFindEnd = 0;
			int expcountFindEnd = 1;
			int expindexRowEnd = 0;
			int expposEnd = -1;

			findEndComment(text, numberRow, numberPos, &indexRowEnd, &posEnd, &countFindEnd);

			Assert::AreEqual(expcountFindEnd, countFindEnd);
			Assert::AreEqual(expindexRowEnd, indexRowEnd);
			Assert::AreEqual(expposEnd, posEnd);
		}

		TEST_METHOD(beginMultilineCommInConst)
		{
			vector<string>text = { "void main()","{","char a= '/*12;","6890 * / '","a = 10;","}" };
			int numberRow = 0;
			int numberPos = -1;
			int indexRowEnd = 0;
			int posEnd = -1;
			int countFindEnd = 0;
			int expcountFindEnd = 1;
			int expindexRowEnd = 0;
			int expposEnd = -1;

			findEndComment(text, numberRow, numberPos, &indexRowEnd, &posEnd, &countFindEnd);

			Assert::AreEqual(expcountFindEnd, countFindEnd);
			Assert::AreEqual(expindexRowEnd, indexRowEnd);
			Assert::AreEqual(expposEnd, posEnd);
		}
	};
}
