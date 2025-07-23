#include <stdexcept>

class Baseball {
public:
	void guess(const std::string& guessnum) {
		if(guessnum.length() != 3)
			throw std::length_error("Must be 3 letter ");

		for (auto ch : guessnum) {
			if (ch < '0' || ch > '9')
				throw std::invalid_argument("Must be number");
		}
	}
};