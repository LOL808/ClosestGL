#include "stdafx.h"
#include <vector>
#include <PrimitiveStripReader.h>
#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace ClosestGL::Primitive;


namespace ClosestGLTests::PrimitiveTest
{
	TEST_CLASS(PrimitiveStripReaderTest)
	{
	public:
		TEST_METHOD(TestStripReader)
		{
			std::vector<size_t> ibo =
			{
				1,2,3,4,5,6,7,8,9
			};

			PrimitiveStripReader<3> reader(ibo.data(), ibo.size());

			while (reader.CanRead())
			{
				auto pri = reader.Read();

				std::string msg = "Triangle:" +
					std::to_string(pri[0]) + "," +
					std::to_string(pri[1]) + "," +
					std::to_string(pri[2]) + '\n';

				Logger::WriteMessage(msg.c_str());
			}
		}
	};
}
