#include <iostream>

#include <cstdlib>
#include <ctime>

int main() {

	const int max_value = 10;

	std::srand(std::time(nullptr)); // use current time as seed for random generator

	const int random_value = std::rand() % max_value;

	std::cout << random_value << std::endl;

	return 0;
}