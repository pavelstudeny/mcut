/**@mainpage
 Micro C++ Unit Tester
 @author Pavel Studeny

 Example:
 @code{.cpp}

 TEST_CASE(Example, {
   int i = static_cast<int>(2.5);
   CHECK(i == 2);
 });

 @endcode

 See test.cpp for more examples.
 */

#include <vector>
#include <functional>
#include <assert.h>
#include <iostream>


/**
 Hold a list of tests and run them
 */
class MCUT {

public:
	/** Current instance */
	static MCUT *instance;


	/** Update instance when constructed */
	MCUT();

	/** Return instance back tuo previous status */
	virtual ~MCUT();


	/** Name and body of a test */
	struct TestCase {
		/**
		 Called by TEST_CASE
		 @param n test name
		 @param t test body
		 */
		TestCase(const std::string &n, std::function < void(bool & rv) > t);

		/** test body */
		std::function < void(bool & rv) > test;

		/** test name, comes from TEST_CASE identifier */
		const std::string name;
	};

	/**
	 Run all tests
	 @param description test result, one result per line
	 @return number of failed tests
	*/
	int run(std::ostream &description) const;


protected:
	/** List pf tests added to the current instance */
	std::vector<TestCase> tests;

private:
	static MCUT defaultInstance;
	MCUT *previousInstance;
};

/**
 Verify a condition
 @param x expression returning a bool value
*/
#define CHECK(x) if (!(x)) { rv = false; }

/**
 Define a test
 @param f identifier
 @param ... test body
*/
#define TEST_CASE(f, ...) MCUT::TestCase MCUT_TEST_CASE_ ## f(#f, [] (bool & rv) __VA_ARGS__)

