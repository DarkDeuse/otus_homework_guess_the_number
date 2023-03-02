#pragma once
#include <iostream>

int read_the_file(const std::string &high_scores_filename);
int write_in_file(int score,const std::string &user_name,const std::string &high_scores_filename);
