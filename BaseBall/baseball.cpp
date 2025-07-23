#include <stdexcept>

class Baseball {
public:
	void guess(const std::string& str) {
		if(str.length() != 3)
			throw std::length_error("Must be 3 letter ");

		for (auto ch : str) {
			if (ch < '0' || ch > '9')
				throw std::invalid_argument("Must be number");
		}
	}
};