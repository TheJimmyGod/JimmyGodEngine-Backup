#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace JimmyGod::Core;


namespace CoreTest
{
	TEST_CLASS(TypedAllocatorTest)
	{
	public:
		class Bar // Used to verify the correct constructor being called
		{
		public:
			static int counter;
			Bar() { counter = 0; }
			Bar(const Bar&) { counter = 1; }
			Bar(Bar&&) { counter = 2; }
		};

		class Foo
		{
		public:
			int a,b;
			Foo() : a(42), b(7) {}
			Foo(int i, int j) : a(i), b(j) {}
			Foo(Bar b) : a(12), b(34) {}
			Foo(std::string str) : a(12), b(34) {}
			~Foo() { a = 0xfeeefeee, b = 0xdeadbeef; }
		};

	public:

		TEST_METHOD(OneBlockTest)
		{
			TypedAllocator<Foo> typedAllocator(1);

			Foo* ptr = typedAllocator.New();
			Assert::IsNotNull(ptr);
			Assert::IsTrue(ptr->a == 42);
			Assert::IsTrue(ptr->b == 7);

			Foo* ptr2 = typedAllocator.New();
			Assert::IsNull(ptr2);

			//// Run some logic, if Bar is moved
			//Assert::IsTrue(Bar::counter == 2);
		}

		TEST_METHOD(TestDelete)
		{
			TypedAllocator<Foo> typedAllocator(1);
			Foo* ptr = typedAllocator.New();
			Assert::IsNotNull(ptr);

			typedAllocator.Delete(ptr);

			Assert::AreEqual((uint32_t)ptr->a, 0xfeeefeee);
			Assert::AreEqual((uint32_t)ptr->b, 0xdeadbeef);
		}

		TEST_METHOD(TestRecycling)
		{
			TypedAllocator<Foo> typedAllocator(1);
			Foo* ptr = typedAllocator.New();
			Assert::IsNotNull(ptr);

			typedAllocator.Delete(ptr);

			Foo* ptr2 = typedAllocator.New();
			Assert::IsNotNull(ptr2);
			Assert::IsTrue(ptr == ptr2);
		}

		TEST_METHOD(TestOverloadedNew)
		{
			TypedAllocator<Foo> typedAllocator(1);
			Foo* ptr = typedAllocator.New(36, 48);
			Assert::IsNotNull(ptr);
			Assert::AreEqual(ptr->a, 36);
			Assert::AreEqual(ptr->b, 48);

			Foo* ptr2 = typedAllocator.New();
			Assert::IsNull(ptr2);
		}

		TEST_METHOD(TestForwardingNew)
		{
			TypedAllocator<Foo> typedAllocator(1);
			Foo* ptr = typedAllocator.New(Bar());
			Assert::IsNotNull(ptr);
			Assert::AreEqual(Bar::counter, 2);
		}

	};

	int TypedAllocatorTest::Bar::counter = 0;
}
