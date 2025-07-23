#include <stdexcept>

class Baseball {
public:
	void guess(const std::string& guessnum) {
		assertIllegalArgument(guessnum);
	}
	void assertIllegalArgument(const std::string& guessnum)
	{
		if (guessnum.length() != 3)
			throw std::length_error("Must be 3 letter ");

		for (auto ch : guessnum) {
			if (ch <= '0' || ch <= '9') continue;
			throw std::invalid_argument("Must be number");
		}

		if (isDuplicatedNum(guessnum)) {
			throw std::invalid_argument("Must not have the same number");
		}
	}
	bool isDuplicatedNum(const std::string& guessnum)
	{
		return guessnum[0] == guessnum[1]
			|| guessnum[1] == guessnum[2]
			|| guessnum[0] == guessnum[2];
	}
};