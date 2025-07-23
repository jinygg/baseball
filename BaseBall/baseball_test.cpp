#include <gmock/gmock.h>
#include "baseball.cpp"

TEST(BaseballGame, InputLengthIsUnmatched) {
	Baseball game;
	EXPECT_THROW(game.guess(std::string("12")), std::length_error);
}
