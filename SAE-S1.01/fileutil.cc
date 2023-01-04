#include "fileutil.hh"


void outputset_f (std::string in_s) { output_f = std::ofstream (in_s); }
void inputset_f (std::string in_s) { input_f = std::ifstream (in_s, std::ios_base::binary); }

void resetstream_f (std::ifstream &in_f) { in_f.clear (); in_f.seekg (0); }
size_t width_f (std::ifstream &in_f) { return stoi (stringsplit_f (readline_f (in_f, 3), ' ')[0]); }
size_t height_f (std::ifstream &in_f) { return stoi (stringsplit_f (readline_f (in_f, 3), ' ')[1]); }
size_t filelen_f (std::ifstream &in_f) {
	std::string tmp_s;
	size_t ret_i = 0;
	while (getline (in_f, tmp_s))
		ret_i++;

	resetstream_f (in_f);

	return ret_i;
}
