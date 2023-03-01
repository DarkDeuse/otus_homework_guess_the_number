#include <iostream>

#include <cstdlib>
#include <ctime>

int imagine_number(int upper_limit = 0) {
	if (upper_limit == 0)
	upper_limit = 100;

	std::srand(static_cast<unsigned int>(std::time(nullptr))); // use current time as seed for random generator

	const int random_value = std::rand() % upper_limit;

	return random_value;
}
