#include <stdexcept>

class Baseball {
public:
	void guess(const std::string& str) {
		throw std::length_error("Must be 3 letter ");
	}
};