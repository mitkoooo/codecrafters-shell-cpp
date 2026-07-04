#pragma once

#include <string>
#include <vector>
#include <optional>

#include <filesystem>


std::string getPathEnv();

std::filesystem::path expandPath(const std::string& rawPath);

std::vector<std::string> getPathDirectories(std::string path);

std::optional<std::string> getExecutable(const std::string& cmd);
