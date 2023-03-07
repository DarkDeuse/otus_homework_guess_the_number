#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "random_value.h"
#include "file_worker.h"
#include "game_back.h"

int main(int argc, char** argv) {
	std::string high_scores_filename = "high_scores.txt";
	int upper_limit = 0;
	if (argc >= 2) {
	std::string arg1_value{ argv[1] };
	if (arg1_value == "-max"){
	if (argc < 3) {
	std::cout << "Wrong usage! The argument '-max' requires some value!" << std::endl;
	return -1;
	}
	
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
	write_in_file(score, user_name, high_scores_filename);
	read_the_file(high_scores_filename);
	
	return 0;
	
}

