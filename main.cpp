#include <iostream>
//#include <string>
#include <fstream>
#include <filesystem>

int main(){
	std::filesystem::path file_path = "rules.rules";
	if(!std::filesystem::exists(file_path)){
		std::cout << "file " << file_path << " doesn't exist" << std::endl;
	}
	std::string s;
	std::cin >> s;
	std::cout << "input: " << s << std::endl;
	return 0;
}
