#include <iostream>
#include <functional>
#include <string>
#include <sstream>


std::pair<std::string, std::vector<std::string>> parseInput(std::string line) {
	std::stringstream ss;
	std::string cmd;
	std::vector<std::string> args;

	ss >> cmd;
	std::string word;

	while (ss >> word) {
		args.push_back(word);
	}

	return {cmd, args};
}

int main() {
  // Flush after every std::cout / std:cerr
  std::cout << std::unitbuf;
  std::cerr << std::unitbuf;

  std::unordered_map<std::string, std::function<void(std::vector<std::string>)>> cmds;

  cmds["exit"] = [](const std::vector<std::string>& args) {
	exit(0);	
  };


  while (true) {
	  std::string line;
	  std::cout << "$ ";

	  // read user's input
	  std::getline(std::cin, line);

	  if (line.empty()) continue;

	  auto [cmd, args] = parseInput(line);

	  // Print an error message in exactly this format: {command}: command not found
	  if (!cmds.count(cmd)) {
		  std::cerr << cmd << ": command not found\n";
		  continue;
	  }

	  cmds[cmd](args);
  }

}
