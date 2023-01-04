#pragma once

#include <array>
#include <vector>
#include <cstddef>
#include <string>
#include <fstream>



using screen_t = std::vector <std::vector <char>>;

const size_t headersize_i = 9;

extern size_t width_i;
extern size_t height_i;

extern std::ifstream input_f;
extern std::ofstream output_f;

extern std::vector<char> palet_v;
