#include "fileio.hh"


std::string readline_f (std::ifstream &in_f, size_t in_i) {

	if (filelen_f (in_f) < in_i) {
		std::cerr << "Index out of file range : "
			  << filelen_f (in_f)
			  << " < "
			  << in_i
			  << '\n';
		return nullptr;
	}

	std::string line_s;
	for (; in_i; in_i--)
		getline (in_f, line_s);

	resetstream_f (in_f);

	return line_s;
}

void skipline_f (std::ifstream &in_f, size_t in_i) {
	std::string tmp_s;
	for (; in_i; in_i--)
		getline (in_f, tmp_s);
}

std::vector <char> readbuf_f (std::ifstream &in_f, size_t in_i) {
	std::vector<char> data_v (in_i);
	in_f.read (data_v.data (), in_i);

	return data_v;
}

void write_f (std::vector <char> in_v, std::ofstream &out_f, size_t width_i, size_t height_i) {
	for (size_t i = 0; i < height_i; i++) {
		for (size_t j = 0; j < width_i; j++)
			out_f << palet_v[(unsigned char) in_v[j + (i * width_i)] / (256 / palet_v.size ())];
		out_f << "\n";
	}
}


void draw_f (std::vector <char> in_v, size_t inwidth_i, size_t inheight_i) {
	std::ofstream out_f ("/dev/tty0");
	write_f (in_v, out_f, inwidth_i, inheight_i);
}
