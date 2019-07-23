#include "pch.h"
#include "CppUnitTest.h"

#include "../ntl/vector"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ntltest {
	TEST_CLASS(vector) {
	public:
		TEST_METHOD(empty_constructor) {
            ntl::vector<int> v;
		}
        TEST_METHOD(count_constructor) {
            size_t size = 16;
            ntl::vector<int> v(size);
            Assert::AreEqual(v.size(), size);
            Assert::AreEqual(v.capacity(), size);
            for (auto e : v) {
                Assert::AreEqual(0, e);
            }
        }
        TEST_METHOD(count_value_constructor) {
            int value = 2;
            size_t size = 16;
            ntl::vector<int> v(size, value);
            Assert::AreEqual(v.size(), size);
            Assert::AreEqual(v.capacity(), size);
            for (auto e : v) {
                Assert::AreEqual(value, e);
            }
        }
        TEST_METHOD(range_constructor) {
            int a[] = { 0, 1, 2, 3, 4, 5, 6, 7 };
            ntl::vector<int> w(a, a + 8);
            for (int i = 0; i != 8; i++) {
                Assert::AreEqual(i, w[i]);
            }
        }
        TEST_METHOD(copy_constructor) {
            int a[] = { 0, 1, 2, 3, 4, 5, 6, 7 };
            ntl::vector<int> w(a, a + 8);
            ntl::vector<int> v(w);
            for (int i = 0; i != 8; i++) {
                Assert::AreEqual(i, w[i]);
            }
        }
        TEST_METHOD(move_constructor) {
            size_t size = 16;
            ntl::vector<int> v(size);
            ntl::vector<int> w(ntl::move(v));
            Assert::AreEqual(size, w.size());
            Assert::AreEqual((size_t)0, v.size());
        }
        TEST_METHOD(assignment_copy) {
            int a[] = { 0, 1, 2, 3, 4, 5, 6, 7 };
            ntl::vector<int> v(a, a + 8);
            ntl::vector<int> w;
            w = v;
            Assert::AreEqual(v.size(), w.size());
            for (size_t i = 0; i != v.size(); i++) {
                Assert::AreEqual(v[i], w[i]);
            }
        }
        TEST_METHOD(assignment_move) {
            int a[] = { 0, 1, 2, 3, 4, 5, 6, 7 };
            ntl::vector<int> v(a, a + 8);
            ntl::vector<int> w;
            w = ntl::move(v);
            Assert::AreEqual((size_t)0, v.size());
            for (size_t i = 0; i != 8; i++) {
                Assert::AreEqual(a[i], w[i]);
            }
        }
        TEST_METHOD(assign_count_value) {
            size_t size = 16;
            int value = 1;
            ntl::vector<int> v;
            v.assign(size, value);
            for (size_t i = 0; i != size; i++) {
                Assert::AreEqual(value, v[i]);
            }
        }
        TEST_METHOD(assign_range) {
            int a[] = { 0, 1, 2, 3, 4, 5, 6, 7 };
            ntl::vector<int> v;
            v.assign(a, a + 8);
            for (int i = 0; i != 8; i++) {
                Assert::AreEqual(a[i], v[i]);
            }
        }
        TEST_METHOD(at) {
            int a[] = { 0, 1, 2, 3, 4, 5, 6, 7 };
            ntl::vector<int> v(a, a + 8);
            for (int i = 0; i != 8; i++) {
                Assert::AreEqual(a[i], v.at(i));
            }
            try {
                v.at(8);
                Assert::Fail(L"exception was expected");
            } catch (ntl::out_of_range const&) {
            }
        }
        TEST_METHOD(empty_and_clear) {
            ntl::vector<int> v((size_t)1, 1);
            Assert::IsFalse(v.empty());
            v.clear();
            Assert::IsTrue(v.empty());
        }
        TEST_METHOD(size) {
            size_t size = 16;
            ntl::vector<int> v(size, 1);
            Assert::AreEqual(size, v.size());
        }
        TEST_METHOD(reserve) {
            size_t initial_size = 5;
            size_t new_capacity = 16;
            ntl::vector<int> v(initial_size, 1);
            Assert::AreEqual(initial_size, v.size());
            Assert::AreEqual(initial_size, v.capacity());
            v.reserve(new_capacity);
            Assert::AreEqual(initial_size, v.size());
            Assert::AreEqual(new_capacity, v.capacity());
            for (size_t i = 0; i != initial_size; i++) {
                Assert::AreEqual(1, v[i]);
            }
        }
        TEST_METHOD(shrink_to_fit) {
            size_t size = 16;
            ntl::vector<int> v;
            v.reserve(size);
            Assert::AreEqual(size, v.capacity());
            v.shrink_to_fit();
            Assert::AreEqual((size_t)0, v.capacity());
        }
        TEST_METHOD(clear) {
            size_t size = 16;
            ntl::vector<int> v(size, 1);
            Assert::AreEqual(size, v.size());
            v.clear();
            Assert::IsTrue(v.empty());
        }
        TEST_METHOD(resize) {
            int value = 1;
            size_t initial_size = 5;
            size_t new_size = 16;
            ntl::vector<int> v(initial_size, value);
            Assert::AreEqual(initial_size, v.size());
            for (size_t i = 0; i != v.size(); i++) {
                Assert::AreEqual(value, v[i]);
            }
            v.resize(new_size);
            Assert::AreEqual(new_size, v.size());
            for (size_t i = 0; i != initial_size; i++) {
                Assert::AreEqual(value, v[i]);
            }
            for (size_t i = initial_size; i != new_size; i++) {
                Assert::AreEqual(0, v[i]);
            }
            v.resize(initial_size);
            for (size_t i = 0; i != initial_size; i++) {
                Assert::AreEqual(value, v[i]);
            }
        }
        TEST_METHOD(swap) {
            int a[] = { 0, 1, 2, 3, 4, 5, 6, 7 };
            int b[] = { 7, 6, 5, 4, 3, 2, 1, 0 };
            ntl::vector<int> v(a, a + 8);
            ntl::vector<int> w(b, b + 8);
            for (size_t i = 0; i != 8; i++) {
                Assert::AreEqual(a[i], v[i]);
                Assert::AreEqual(b[i], w[i]);
            }
            v.swap(w);
            for (size_t i = 0; i != 8; i++) {
                Assert::AreEqual(b[i], v[i]);
                Assert::AreEqual(a[i], w[i]);
            }
        }
        TEST_METHOD(insert) {
            int a[] = { 0, 1, 2, 3, 4, 5, 6, 7 };
            ntl::vector<int> v(a, a + 8);
            for (size_t i = 0; i != 8; i++) {
                Assert::AreEqual(a[i], v[i]);
            }
            v.insert(v.begin() + 4, 8);
            for (size_t i = 0; i != 9; i++) {
                if (i < 4) {
                    Assert::AreEqual(a[i], v[i]);
                } else if (i == 4) {
                    Assert::AreEqual(8, v[i]);
                } else /*if (i > 4)*/ {
                    Assert::AreEqual(a[i - 1], v[i]);
                }
            }
        }
        TEST_METHOD(insert_move) {
            size_t count = 16;
            size_t value = 3;
            ntl::vector<ntl::vector<size_t>> v;
            ntl::vector<size_t> w(count, value);
            v.resize(2);
            for (size_t i = 0; i != v.size(); i++) {
                v[i].assign(count, i + 1);
            }
            for (size_t i = 0; i != v.size(); i++) {
                for (size_t j = 0; j != count; j++) {
                    Assert::AreEqual(i + 1, v[i][j]);
                }
            }
            for (size_t i = 0; i != w.size(); i++) {
                Assert::AreEqual(value, w[i]);
            }
            v.insert(v.begin() + 1, ntl::move(w));
            Assert::AreEqual((size_t)3, v.size());
            for (size_t i = 0; i != count; i++) {
                Assert::AreEqual((size_t)1, v[0][i]);
                Assert::AreEqual((size_t)3, v[1][i]);
                Assert::AreEqual((size_t)2, v[2][i]);
            }
            Assert::IsTrue(w.empty());
        }
        TEST_METHOD(insert_count) {
            int a[] = { 0, 1, 2, 3, 12, 13, 14, 15 };
            ntl::vector<int> v(a, a + 8);
            for (size_t i = 0; i != 8; i++) {
                Assert::AreEqual(a[i], v[i]);
            }
            v.insert(v.begin() + 4, (size_t)8, 8);
            Assert::AreEqual((size_t)16, v.size());
            for (size_t i = 0; i != v.size(); i++) {
                if (i < 4) {
                    Assert::AreEqual(a[i], v[i]);
                } else if (i < 12) {
                    Assert::AreEqual(8, v[i]);
                } else /*if (i < 16)*/ {
                    Assert::AreEqual(a[i - 8], v[i]);
                }
            }
        }
        TEST_METHOD(insert_range) {
            int a[] = { 0, 1, 2, 3, 3, 2, 1, 0 };
            ntl::vector<int> v(a, a + 8);
            v.insert(v.begin() + 4, a, a + 4);
            v.insert(v.begin() + 8, a + 4, a + 8);
            Assert::AreEqual((size_t)16, v.size());
            for (size_t i = 0; i != 8; i++) {
                if (i < 4) {
                    Assert::AreEqual(a[i], v[i]);
                } else /*if (i < 8)*/ {
                    Assert::AreEqual(a[i - 4], v[i]);
                }
            }
            for (size_t i = 8; i != 16; i++) {
                if (i < 12) {
                    Assert::AreEqual(a[i - 4], v[i]);
                } else /*if (i < 8)*/ {
                    Assert::AreEqual(a[i - 8], v[i]);
                }
            }
        }
        TEST_METHOD(emplace) {
            size_t count = 16;
            ntl::vector<ntl::vector<size_t>> v;
            v.resize(2);
            v[0].assign(count, (size_t)1);
            v[1].assign(count, (size_t)3);
            for (size_t i = 0; i != count; i++) {
                Assert::AreEqual((size_t)1, v[0][i]);
                Assert::AreEqual((size_t)3, v[1][i]);
            }
            v.emplace(v.begin() + 1, count, (size_t)2);
            Assert::AreEqual((size_t)3, v.size());
            for (size_t i = 0; i != v.size(); i++) {
                for (size_t j = 0; j != count; j++) {
                    Assert::AreEqual(i + 1, v[i][j]);
                }
            }
        }
        TEST_METHOD(erase) {
            int a[] = { 0, 1, 2, 3, 4, 5, 6, 7 };
            ntl::vector<int> v(a, a + 8);
            for (size_t i = 0; i != 8; i++) {
                Assert::AreEqual(a[i], v[i]);
            }
            v.erase(v.begin() + 4);
            Assert::AreEqual((size_t)7, v.size());
            for (size_t i = 0; i != v.size(); i++) {
                if (i < 4) {
                    Assert::AreEqual(a[i], v[i]);
                } else /*if (i >= 4)*/ {
                    Assert::AreEqual(a[i + 1], v[i]);
                }
            }
        }
        TEST_METHOD(erase_range) {
            int a[] = { 0, 1, 2, 3, 4, 5, 6, 7 };
            ntl::vector<int> v(a, a + 8);
            for (size_t i = 0; i != 8; i++) {
                Assert::AreEqual(a[i], v[i]);
            }
            v.erase(v.begin() + 3, v.begin() + 5);
            Assert::AreEqual((size_t)6, v.size());
            for (size_t i = 0; i != v.size(); i++) {
                if (i < 3) {
                    Assert::AreEqual(a[i], v[i]);
                } else /*if (i >= 4)*/ {
                    Assert::AreEqual(a[i + 2], v[i]);
                }
            }
            v.erase(v.begin() + 3, v.end());
            Assert::AreEqual((size_t)3, v.size());
            for (size_t i = 0; i != v.size(); i++) {
                Assert::AreEqual(a[i], v[i]);
            }
        }
	};
}
