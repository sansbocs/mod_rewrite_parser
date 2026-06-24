#include <iostream>
//#include <string>
#include <fstream>
#include <filesystem>

int main(){
	std::filesystem::path file_path = "rules.rules";
	if(!std::filesystem::exists(file_path)){
		std::cout << "file " << file_path << " doesn't exist" << std::endl;
	}
	std::ifstream file_reading_stream(file_path);
	if(!file_reading_stream.is_open()){
		std::cout << "Error: file " << file_path << " could not be opened" << std::endl;
	}
	int i{1};
	std::string s;
	std::getline(file_reading_stream, s);
	while(std::getline(file_reading_stream, s)){
		std::cout << "line [ " << i << "]: " << s << std::endl;
		i++;
	}
	//std::string s;
	//std::getline(file_reading_stream, s);
	//std::cin >> s;
	return 0;
}
