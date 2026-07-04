#include "commands.hpp"

#include <iostream>
#include <filesystem>

void pwdCommand(const CommandArgs& args) {
    namespace fs = std::filesystem;

    try {
      std::cout << fs::current_path().string() << '\n';
    } catch (const fs::filesystem_error& error) {
      std::cerr << "pwd: " << error.what() << '\n';
    }
  };

