#include "../mcut.h"

MCUT *MCUT::currentInstance = nullptr;


MCUT *MCUT::instance()
{
	static MCUT defaultInstance;

	return currentInstance;
}

MCUT::MCUT()
{
	previousInstance = currentInstance;
	currentInstance = this;
}

MCUT::~MCUT()
{
	currentInstance = previousInstance;
}

MCUT::TestCase::TestCase(const std::string &n, std::function < void(bool & rv) > t) : name(n), test(t)
{
	MCUT::instance()->tests.push_back(*this);
}

int MCUT::run(std::ostream &description) const
{
	int failures = 0;
	bool test_result;

	for (const TestCase &t : tests)
	{
		test_result = true;
		try {
			t.test(test_result);
		}
		catch (...) {
			test_result = false;
		}

		if (test_result)
		{
			description << t.name.c_str() << ": passed" << std::endl;
		}
		else {
			++failures;
			description << t.name.c_str() << ": failed" << std::endl;
		}
	}
	return failures;
}



int main(int argc, char* argv[])
{
	return MCUT::instance()->run(std::cout);
}
