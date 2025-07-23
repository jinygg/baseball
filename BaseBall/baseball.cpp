#include <stdexcept>

struct GuessResult {
	bool solved;
	int strike;
	int ball;
};

class Baseball {
public:
	Baseball(const std::string ans) : answer(ans) {

	}

	GuessResult guess(const std::string& guessnum) {
		return assertIllegalArgument(guessnum);
	}

	int CountStrike(std::string question) {
		int strike = 0;

		for (int i = 0; i < 3; i++) {
			if (answer[i] == question[i]) {
				strike++;
			}
		}

		return strike;
	}

	int CountBall(std::string question) {
		int ball = 0;

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (i == j) continue;
				if (question[i] == answer[j]) ball++;
			}
		}

		return ball;
	}

	GuessResult assertIllegalArgument(const std::string& guessnum)
	{
		GuessResult result = { true, 3, 0 };

		if (guessnum == answer) {
			return result;
		}

		if (guessnum.length() != 3)
			throw std::length_error("Must be 3 letter ");

		for (auto ch : guessnum) {
			if (ch <= '0' || ch <= '9') continue;
			throw std::invalid_argument("Must be number");
		}

		if (isDuplicatedNum(guessnum)) {
			throw std::invalid_argument("Must not have the same number");
		}

		result.strike = CountStrike(guessnum);
		result.ball = CountBall(guessnum);
		result.solved = false;

		return result;
	}
	bool isDuplicatedNum(const std::string& guessnum)
	{
		return guessnum[0] == guessnum[1]
			|| guessnum[1] == guessnum[2]
			|| guessnum[0] == guessnum[2];
	}

private:
	std::string answer;
};