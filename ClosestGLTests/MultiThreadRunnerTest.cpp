#include "stdafx.h"
#include "CppUnitTest.h"

#include <MultiThreadRunner.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace ClosestGL::ParallelStrategy;

namespace ClosestGLTests::ParallelStrategyTest
{
	TEST_CLASS(MultiThreadRunnerTest)
	{
	public:
		TEST_METHOD(TestMultiThreadFor)
		{
			MultiThreadRunner runner(30);
			std::mutex t;
			std::vector<std::tuple<int, size_t>> mark;

			int i = 0;
			for (int j = 0; j < 5; ++j)
			{
				
				struct ForAction
				{
					int* i;
					std::mutex* t;
					std::vector<std::tuple<int, size_t>>* mark;

					void operator()(size_t index, size_t threadID) const
					{
						t->lock();
						(*i)++;
						std::tuple<int, size_t> tup{ *i,threadID };
						mark->push_back(tup);
						t->unlock();
					}
				};
			}

			runner.Wait();
		}
	};
}