#include <iostream>
#include <fstream>
#include <string>

int the_game(int number_to_guess){
	int current_value = 0;
	int tries = 0;
	std::string printed_string = "Enter your guess:";
	std::cout << printed_string << std::endl;

	do {
		std::cin >> current_value;

		if (current_value > number_to_guess) {
			printed_string = "less than ";
			tries += 1;
		}
		else if (current_value < number_to_guess) {
			printed_string = "greater than ";
			tries += 1;
		}
		else {
			std::cout << "you win!" << std::endl;
			break;
		}
		std::cout << printed_string << current_value <<std::endl;

	} while(true);

	return tries;

}