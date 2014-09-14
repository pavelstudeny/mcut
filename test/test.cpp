#include "../mcut.h"
#include <sstream>

TEST_CASE(Empty, {

});

TEST_CASE(Valid_CHECK,
{
	CHECK(true == true);
});

TEST_CASE(Failing_CHECK,
{
	MCUT tester;

	TEST_CASE(Non_Equals, 
	{
		CHECK(false == true);
	});

	std::ostringstream os;

	CHECK(tester.run(os) == 1);
});

TEST_CASE(Single_Argument_Template, {
	std::tuple<int> t(1);

	CHECK(std::get<0>(t) == 1);
});

// this is the reason why TEST_CASE is a variadic macro
TEST_CASE(Multiple_Argument_Template, {
	std::tuple<int, int> t(1, 2);

	CHECK(std::get<1>(t) == 2);
});

