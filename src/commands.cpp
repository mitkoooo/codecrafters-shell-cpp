#include "commands.hpp"
#include "path_utils.hpp"

#include <cstdlib>
#include <filesystem>
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

  cmds["pwd"] = [](const std::vector<std::string>& args) {
    namespace fs = std::filesystem;

    try {
      std::cout << fs::current_path().string() << '\n';
    } catch (const fs::filesystem_error& error) {
      std::cerr << "pwd: " << error.what() << '\n';
    }
  };

  cmds["cd"] = [](const std::vector<std::string>& args) {
    namespace fs = std::filesystem;

    // check if path is absolute
    if (args.size() != 1) {
      std::cout << "cd: incorrect usage\n";
      return;
		}

    std::string rawPath = args[0];
    
    if (rawPath.at(0) == '/') {
      // Convert string to path 
      fs::path path = fs::path(rawPath);

      // check if path exists
      if (!fs::exists(path)) {
        std::cerr << "cd: " << path.string() << ": No such file or directory\n";
        return;
      }

      fs::current_path(path);
    }
  };
}
