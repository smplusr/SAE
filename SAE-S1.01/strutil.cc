#include "strutil.hh"


std::array <std::string, 2> stringsplit_f (std::string in_s, char in_c) {	
	std::array<std::string, 2> res_a;
	bool tmp_b = false;
	for (size_t i = 0; i < in_s.size (); i++) {
		if (in_s[i] == in_c) tmp_b = true;
		(!tmp_b) ? res_a[0].push_back (in_s[i])
			 : res_a[1].push_back (in_s[i]); 
	}
	return res_a;
}

void paletset_f (std::string in_s) {
	std::string tmp_s;
	std::ifstream tmp_f (in_s);

	for (; !palet_v.empty (); palet_v.pop_back ());

	for (; getline (tmp_f, tmp_s); )
		palet_v.push_back (*tmp_s.data ());
}
