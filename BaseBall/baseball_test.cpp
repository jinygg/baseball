#include <gmock/gmock.h>
#include "baseball.cpp"

class BaseballFixure : public ::testing::Test {
public:
	Baseball game;
	void assertIllegalArgument(std::string guess_num) {
		try {
			game.guess(std::string("12s"));
			FAIL();

		}
		catch (std::exception e) {
		}
	}
};

TEST_F(BaseballFixure, Invalidcase) {
	assertIllegalArgument(std::string("12"));
	assertIllegalArgument(std::string("12s"));
	assertIllegalArgument(std::string("121"));
}
