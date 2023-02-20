#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <map>



int imagine_number(int upper_limit = 0) {
	if (upper_limit == 0)
	upper_limit = 100;

	std::srand(std::time(nullptr)); // use current time as seed for random generator

	const int random_value = std::rand() % upper_limit;

	return random_value;
}

int read_the_file(std::string high_scores_filename){
	std::ifstream in_file{high_scores_filename};
	if (!in_file.is_open()) {
		std::cout << "Failed to open file for read: " << high_scores_filename << "!" << std::endl;
		return -1;
	}

	std::cout << "High scores table:" << std::endl;

	std::string username;
	int high_score = 0;
	while (true) {
		// Read the username first
		in_file >> username;
		// Read the high score next
		in_file >> high_score;
		// Ignore the end of line symbol
		in_file.ignore();

		if (in_file.fail()) {
			break;
		}

		// Print the information to the screen
		std::cout << username << '\t' << high_score << std::endl;
	}

	return 0;
}


int write_in_file(std::string user_name, int score, std::string high_scores_filename){
		// We should open the output file in the append mode - we don't want
		// to erase previous results.
		std::ofstream out_file{high_scores_filename, std::ios_base::app};
		if (!out_file.is_open()) {
			std::cout << "Failed to open file for write: " << high_scores_filename << "!" << std::endl;
			return -1;
		}

		// Append new results to the table:
		out_file << user_name << ' ';
		out_file << score;
		out_file << std::endl;
	return 0;
}

int the_game(int number_to_guess){
	int current_value = 0;
	bool not_win = true;
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
		std::cout << printed_string << std::endl;

	} while(true);

	return tries;

}

int main(int argc, char** argv) {
	std::string high_scores_filename = "high_scores.txt";
	int upper_limit = 0;
	if (argc >= 2){
		std::string arg1_value{ argv[1] };
		if (arg1_value == "-max"){
			upper_limit = std::stoi(argv[2]);
		}
		if (arg1_value == "-table"){
			read_the_file(high_scores_filename);
			return 0;
		}
	}
	int riddled_number = imagine_number(upper_limit);
	std::cout << "Hi! Enter your name, please:" << std::endl;
	std::string user_name;
	std::cin >> user_name;
	int score = the_game(riddled_number);
	write_in_file(user_name, score, high_scores_filename);
	read_the_file(high_scores_filename);
	
	return 0;	
}
