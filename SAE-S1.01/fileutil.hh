#pragma once

#include "fileio.hh"
#include "global.hh"
#include <fstream>



void outputset_f (std::string in_s);
void inputset_f (std::string in_s);

void resetstream_f (std::ifstream &in_f);
size_t width_f (std::ifstream &in_f);
size_t height_f (std::ifstream &in_f);
size_t filelen_f (std::ifstream &in_f);
