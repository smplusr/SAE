#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "fileutil.hh"
#include "strutil.hh"


typedef struct lookup_t {
	std::string ref_s;
	void (*ptr_f) (std::string in_s);
} lookup_t;


using lookup_v = std::vector<lookup_t>;
extern lookup_v intlookup_v;

bool lookexist_f (lookup_v &in_v, std::string in_s);
void (*lookget_f (lookup_v &in_v, std::string in_s)) (std::string in_s);
void manual_f ();
