#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "strutil.hh"
#include "fileutil.hh"
#include "global.hh"


std::string readline_f (std::ifstream &in_f, size_t in_i);
void skipline_f (std::ifstream &in_f, size_t in_i);
std::vector <char> readbuf_f (std::ifstream &in_f, size_t in_i);
screen_t screenfmt_f (std::vector <char> in_v, size_t width_i, size_t height_i);
void write_f (std::vector <char> in_v, std::ofstream &out_f, size_t inwidth_i, size_t inheight_i);
void draw_f (std::vector <char> in_v, size_t inwidth_i, size_t inheight_i);
