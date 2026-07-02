#include "commands.hpp"
#include "path_utils.hpp"

#include <cstdlib>
#include <iostream>

void registerCommands(CommandMap &cmds) {
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
		if (args.size() != 1) {
			std::cout << "type: incorrect usage\n";
			return;
		}

		const std::string& cmd = args[0];


	    	if (cmds.count(cmd)) {
			std::cout << cmd << " is a shell builtin\n";
			return;
	    	}

	    	auto executable = getExecutable(cmd);

	    	if (executable) {
			std::cout << cmd << " is " << *executable << '\n';
		} else {
			std::cout << cmd << ": not found\n";
	    	}
	  };
}
