#include "condense.h"

std::string usg = " [inputFile] [optional-outputDir]";
std::string ttl = 	"\n\n8\"\"\"\"8    8\"\"\"88    8\"\"\"8    8\"\"\"\"8    8\"\"\"\"    8\"\"\"8    8\"\"\"\"8    8\"\"\"\" \n"\
					"8    \"    8    8    8   8    8    8    8        8   8    8         8     \n"\
					"8e        8    8    8e  8    8e   8    8eeee    8e  8    8eeeee    8eeee \n"\
					"88        8    8    88  8    88   8    88       88  8        88    88    \n"\
					"88   e    8    8    88  8    88   8    88       88  8    e   88    88    \n"\
					"88eee8    8eeee8    88  8    88eee8    88eee    88  8    8eee88    88eee \n\n";

std::string author = "  [+] Nicholas V. Giamblanco, 2018\n";
std::string bugrpt = "  [!] Report bugs to gdev.engineering@gmail.com OR make an issue at https://github.com/ngiambla/condense\n";


std::string ver_string(int a, int b, int c) {
  std::ostringstream ss;
  ss << a << '.' << b << '.' << c;
  return ss.str();
}

int main(int argc, char const *argv[]) {
	std::string exeName 	= argv[0];
	std::string usage 		= "Usage "+exeName+usg;
	std::string outDir 		= "";

	std::string inputFile;
	size_t bspos = 0;

	switch(argc) {
		case 2:
			inputFile = argv[1];
			if( (bspos = inputFile.rfind("/")) != std::string::npos)
				outDir = inputFile.erase(bspos+1, std::string::npos);
			break;
		case 3:
			outDir = argv[2];
			break;
		default:
			std::cout << usage << "\n";
			exit(-1);		
	}

	std::string true_cxx = "  [+] Compiled with ";
	true_cxx +=
	#ifdef __clang__
	   "clang++ ";
	#else
	   "g++ ";
	#endif

	  std::string true_cxx_ver =
	#ifdef __clang__
	    ver_string(__clang_major__, __clang_minor__, __clang_patchlevel__);
	#else
	    ver_string(__GNUC__, __GNUC_MINOR__, __GNUC_PATCHLEVEL__);
	#endif

	std::cout << ttl << true_cxx << true_cxx_ver << "\n" << author << bugrpt << "\n";

	Parser * parser = new Parser();		

	return 0;
}