#include "path_utils.hpp"

#include <cstdlib>
#include <filesystem>
#include <sstream>
#include <unistd.h>

std::string getPathEnv() {
	const char* path = getenv("PATH");

	return path ? std::string{path} : "";
}

std::vector<std::string> getPathDirectories(std::string path) {
	if (path.empty()) return {};

	std::stringstream ss(path);
	std::vector<std::string> directories;
	std::string directory;
	
	while (std::getline(ss, directory, ':')) {
			directories.push_back(directory.empty() ? "." : directory);
	}

	return directories;
}

std::optional<std::string> getExecutable(const std::string& cmd) {
	namespace fs = std::filesystem;

	std::string path = getPathEnv();

	for (const std::string& directory : getPathDirectories(path)) {
		fs::path candidate = fs::path(directory) / cmd;

		if (fs::is_regular_file(candidate) && access(candidate.c_str(), X_OK) == 0) {
			return std::string{candidate};
		}
	}

	return std::nullopt;
}
