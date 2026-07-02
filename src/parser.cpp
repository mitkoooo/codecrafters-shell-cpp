#include "parser.hpp"

#include <sstream>

ParsedInput parseInput(const std::string& line) {
	std::stringstream ss(line);
	std::string cmd;
	std::vector<std::string> args;

	ss >> cmd;
	std::string word;

	while (ss >> word) {
		args.push_back(word);
	}

	return {cmd, args};
}
