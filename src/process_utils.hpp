#pragma once

#include <string>
#include <vector>

std::vector<char*> makeArgv(
    std::string& command,
    std::vector<std::string>& args
);

void executeExternalCommand(std::string& command, std::vector<std::string>& args);
