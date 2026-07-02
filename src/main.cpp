#include <iostream>
#include <functional>
#include <string>
#include <sstream>


std::pair<std::string, std::vector<std::string>> parseInput(std::string line) {
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

int main() {
  // Flush after every std::cout / std:cerr
  std::cout << std::unitbuf;
  std::cerr << std::unitbuf;

  std::unordered_map<std::string, std::function<void(std::vector<std::string>)>> cmds;

  cmds["exit"] = [](const std::vector<std::string>& args) {
	exit(0);	
  };

  cmds["echo"] = [](const std::vector<std::string>& args) {
	int n = args.size();
	for (int i = 0; i < n; i++) {

		std::cout << args[i];
		i == n - 1 ? std::cout << '\n' : std::cout << ' ';
	}
  };

  cmds["type"] = [&cmds](const std::vector<std::string>& args) {
	if (args.size() != 1) std::cout << "incorrect usage";


	std::cout << args[0];

	std::cout << (cmds.count(args[0]) ? " is a shell builtin" : ": not found") << '\n';
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
