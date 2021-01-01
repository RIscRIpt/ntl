#include "pch.h"
#include "CppUnitTest.h"

#include "../ntl/algorithm"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ntltest {
	TEST_CLASS(algorithm) {
	public:
		TEST_METHOD(lower_bound) {
            int a[] = { 1, 3, 5, 7, 9 };
			for (int i = 0; i < 10; i++) {
                auto it = ntl::lower_bound(a, a + 5, i);
				Assert::IsTrue(*it - i <= 1);
			}
			auto it = ntl::lower_bound(a, a + 5, 10);
			Assert::AreEqual(it, a + 5);
		}

		TEST_METHOD(lower_bound_predicate) {
            int a[] = { 1, 3, 5, 7, 9 };
			for (int i = 0; i < 10; i++) {
                auto it = ntl::lower_bound(a, a + 5, i, [](int a, int b) { return a < b; });
				Assert::IsTrue(*it - i <= 1);
			}
            auto it = ntl::lower_bound(a, a + 5, 10, [](int a, int b) { return a < b; });
			Assert::AreEqual(it, a + 5);
		}

		TEST_METHOD(upper_bound) {
            int a[] = { 1, 3, 5, 7, 9 };
			for (int i = 0; i < 9; i++) {
                auto it = ntl::upper_bound(a, a + 5, i);
				Assert::IsTrue(*it - i == 1 || *it - i == 2);
			}
			auto it = ntl::upper_bound(a, a + 5, 9);
			Assert::AreEqual(it, a + 5);
		}

		TEST_METHOD(upper_bound_predicate) {
            int a[] = { 1, 3, 5, 7, 9 };
			for (int i = 0; i < 9; i++) {
                auto it = ntl::upper_bound(a, a + 5, i, [](int a, int b) { return a < b; });
				Assert::IsTrue(*it - i == 1 || *it - i == 2);
			}
            auto it = ntl::upper_bound(a, a + 5, 9, [](int a, int b) { return a < b; });
			Assert::AreEqual(it, a + 5);
		}
	};
}
