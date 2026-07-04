#include "commands.hpp"
#include "../path_utils.hpp"

#include <iostream>

void typeCommand(const CommandArgs &args, const CommandMap &cmds) {
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
