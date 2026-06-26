#include <iostream>
//#include <string>
#include <fstream>
#include <filesystem>
#include <vector>
#include <cctype>

struct Lexer{
	std::string::iterator source;
	std::vector<std::string> tokens;
};

//skipping all lines that start with '#' character
//meaning that after encountering '#' every other character will be ignored
//until a new line character is encountered the the function returns
void skip_commented_line(std::string& s, std::string::iterator& si){
	std::cout << "entered skip_commented_line function" << std::endl;
	while(si != s.end()){
		if(*si == '\n'){
			return;
		}
		si++;
	}
}

void skip_whitespace(std::string& s, std::string::iterator& si){
	std::cout << "entered skip_whitespace function" << std::endl;
	while(si != s.end()){
		if(std::isspace(*si)){
			return;
		}
		si++;
	}
}

std::string tokenize(std::string& s, std::string::iterator& si){
//void tokenize(){
	std::string temp;
	temp.reserve(200);
	while(si != s.end()){
		if(*si == '#'){
			std::cout << "how does temp look?: " << temp << std::endl;
			return temp;	
		}
		if(std::isspace(*si)){
			std::cout << "how does temp look?: " << temp << std::endl;
			return temp;	
		}
		temp.push_back(*si);
		si++;
	}
	return s;
}

int main(){
	std::filesystem::path file_path = "rules.rules";
	if(!std::filesystem::exists(file_path)){
		std::cout << "file " << file_path << " doesn't exist" << std::endl;
	}
	std::uintmax_t file_size = std::filesystem::file_size(file_path);
	std::cout << "the file you are trying to read is " << file_size << " bytes" << std::endl;
	std::ifstream file_reading_stream(file_path);
	if(!file_reading_stream.is_open()){
		std::cout << "Error: file " << file_path << " could not be opened" << std::endl;
	}
	//int i{1};
	std::string s(file_size, '\0');
	file_reading_stream.read(s.data(), file_size);
	std::string::iterator si = std::begin(s);
	//printing and incrementing the string iterator until it reaches the end of string
	while(si != s.end()){
		if(*si == '#'){
			skip_commented_line(s, si);
		}else if(std::isspace(*si)){
			skip_whitespace(s, si);
		}else{
			tokenize(s, si);
		}
		si++;
	}
	return 0;
}
