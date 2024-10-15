#include "pch.h"
#include "CppUnitTest.h"
#include "../6.4_it/6.4_it.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest64it
{
	TEST_CLASS(UnitTest64it)
	{
	public:

		TEST_METHOD(TestCountZeros)
		{
			double arr[] = { 1.0, 0.0, 3.0, 0.0, 5.0 };
			int size = sizeof(arr) / sizeof(arr[0]);
			int result = CountZeros(arr, size);
			Assert::AreEqual(2, result);  
		}

		TEST_METHOD(TestFindMinIndex)
		{
			double arr[] = { 1.0, -2.0, 3.0, -4.0, 5.0 };
			int size = sizeof(arr) / sizeof(arr[0]);
			int result = FindMinIndex(arr, size);
			Assert::AreEqual(3, result); 
		}

		TEST_METHOD(TestSumAfterMin)
		{
			double arr[] = { 1.0, 2.0, 3.0, -1.0, 5.0, 6.0 };
			int size = sizeof(arr) / sizeof(arr[0]);
			int minIndex = FindMinIndex(arr, size);
			double result = SumAfterMin(arr, size, minIndex);
			Assert::AreEqual(11.0, result); 
		}

		TEST_METHOD(TestSortOddElements)
		{
			double arr[] = { 1.0, -3.0, 4.0, 2.0, 5.0, -7.0 };
			int size = sizeof(arr) / sizeof(arr[0]);

			SortOddElements(arr, size);

			double expected[] = { 1.0, -3.0, 4.0, 2.0, 5.0, -7.0 };  
			for (int i = 0; i < size; i++) {
				Assert::AreEqual(expected[i], arr[i]);
			}
		}
	};
}