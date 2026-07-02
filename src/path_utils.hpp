#pragma once

#include <string>
#include <vector>
#include <optional>


std::string getPathEnv();

std::vector<std::string> getPathDirectories(std::string path);

std::optional<std::string> getExecutable(const std::string& cmd);
