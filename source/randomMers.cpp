#include "randomMers.h"

int randomMers(int down_range, int up_range) {
	
	std::random_device rd{};
	std::mt19937 engine{ rd() };
	std::uniform_int_distribution<int> dist{ down_range, up_range };

	int random{};
	random = dist(engine);

	return random;
}