#include <gmock/gmock.h>
#include "baseball.cpp"

class BaseballFixure : public ::testing::Test {
public:
	Baseball game = {"123"};
	void assertIllegalArgument(std::string guess_num) {
		try {
			game.guess(guess_num);
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


TEST_F(BaseballFixure, MatchedNumber) {
	GuessResult result = game.guess("123");

	EXPECT_TRUE(result.solved);
	EXPECT_EQ(result.strike, 3);
	EXPECT_EQ(result.ball, 0);

}

TEST_F(BaseballFixure, twostike0ball) {
	GuessResult result = game.guess("124");

	EXPECT_FALSE(result.solved);
	EXPECT_EQ(result.strike, 2);
	EXPECT_EQ(result.ball, 0);
}

TEST_F(BaseballFixure, onestrike2ball) {
	GuessResult result = game.guess("132");

	EXPECT_FALSE(result.solved);
	EXPECT_EQ(result.strike, 1);
	EXPECT_EQ(result.ball, 2);

}
