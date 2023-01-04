#include "fileio.hh"
#include "fileutil.hh"
#include "strutil.hh"
#include "console.hh"


using namespace std;

bool strequ_f (char in0_s[], char in1_s[]) {
	for (; *in0_s && *in1_s; *in0_s++, +in1_s++)
		if (*in0_s != *in1_s)
			return false;
	return true;
}



size_t argmanage_f (int argc, char *argv[]) {
	if (argc <= 1) {
		manual_f ();
		std::cerr << "Please specify at least one argument.\n";
		return EXIT_FAILURE;
	}

	for (size_t tmp_i = 1; tmp_i < argc; tmp_i += 2) {
		if (lookexist_f (intlookup_v, argv[tmp_i])) {
			lookget_f (intlookup_v, argv[tmp_i]) (argv[tmp_i + 1]);
		}
		else {
			manual_f ();
			if (!strequ_f (argv[tmp_i], (char*) "--help")) {
				std::cerr << "The argument \"" << argv[tmp_i] << "\" does not exist\n";
				return EXIT_FAILURE;
			}
		}
	}


	if (!input_f.is_open ()) {
		manual_f ();
		std::cerr << "An input file needs to be specified\n";
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}


int main(int argc, char *argv[]) {

	size_t ret_i = argmanage_f (argc, argv);
	if (ret_i) return ret_i;

	size_t width_i = width_f (input_f),
	       height_i = height_f (input_f),
	       size_i = width_i * height_i;


	{
		skipline_f (input_f, 3);
		readbuf_f (input_f, 4);
	}

	std::cout << width_i << ' ' << height_i << '\n';


	write_f (readbuf_f (input_f, size_i), output_f, width_i, height_i);

	return EXIT_SUCCESS;
}
