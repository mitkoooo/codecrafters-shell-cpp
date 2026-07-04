#include "commands.hpp"
#include "../path_utils.hpp"

#include <iostream>
#include <filesystem>

void cdCommand (const std::vector<std::string>& args) {
    namespace fs = std::filesystem;

    // check if path is absolute
    if (args.size() != 1) {
      std::cout << "cd: incorrect usage\n";
      return;
		}

    const fs::path target = expandPath(args[0]);

    std::error_code error;
    fs::current_path(target, error);

    if (error) {
      std::cerr << "cd: " << target.string() << ": " << error.message() << '\n';
    }
};
