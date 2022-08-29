#include "pch.h"
#include "CppUnitTest.h"
#include"../var19_delComments_eliseeva/var19_delComments_eliseeva.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestdelComments
{
	TEST_CLASS(UnitTestdelComments)
	{
	public:
		
		TEST_METHOD(beginMultilineCommSingleLine)
		{
			vector<string>text = { "void main()","{","int a;//int t/*int k;","/*a=10;","a=2;*/","}" };
			vector<string>exptext = { "void main()", "{" ,"int a;//int t/*int k;","}" };
			delComments(text);
			Assert::AreEqual( exptext, text);
		}

		TEST_METHOD(endMultilineCommSingleLine)
		{
			vector<string>text = { "void main()","{","int a;//int t*/int k;","/*a=10;","a=2;*/","}" };
			vector<string>exptext = { "void main()", "{" ,"int a;//int t/*int k;","}" };
			delComments(text);
			Assert::AreEqual(exptext, text);
		}

		TEST_METHOD(singleLineCommInMultiline)
		{
			vector<string>text = { "void main()","{","int a;","/*a=10;","//int k;","a=2;*/","}" };
			vector<string>exptext = { "void main()", "{" ,"int a;","}" };
			delComments(text);
			Assert::AreEqual(exptext, text);
		}

		TEST_METHOD(multilineCommInSingleLine)
		{
			vector<string>text = { "void main()","{","int a;","//int k;/*90*/","}" };
			vector<string>exptext = { "void main()", "{" ,"int a;","//int k;/*90*/","}" };
			delComments(text);
			Assert::AreEqual(exptext, text);
		}

		TEST_METHOD(multilineCommInConst)
		{
			vector<string>text = { "void main()","{","char a= '/*12;","6890 * / '","a = 10;","}" };
			vector<string>exptext = { "void main()", "{" ,"char a= '/*12;","6890 * / '","a = 10;","}" };
			delComments(text);
			Assert::AreEqual(exptext, text);
		}
		
		TEST_METHOD(multilineCommLikeSingleLineInConst)
		{
			vector<string>text = { "void main()","{","char a= '/*12;*/ '","a = 10;","}" };
			vector<string>exptext = { "void main()", "{" ,"char a= '/*12;*/ '","a = 10;","}" };
			delComments(text);
			Assert::AreEqual(exptext, text);
		}
	};
}
