#pragma once
#include <iostream>

int read_the_file(std::string high_scores_filename);
int write_in_file(std::string user_name, int score, std::string high_scores_filename);
