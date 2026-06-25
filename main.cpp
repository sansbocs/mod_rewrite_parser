#include <iostream>
//#include <string>
#include <fstream>
#include <filesystem>
#include <vector>

struct Lexer{
	std::string::iterator source;
	std::vector<std::string> tokens;
};

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
		std::cout << *si << std::endl;
		si++;
	}

//	std::cout << "first char?? first line??: " << *si << std::endl;
//	std::cout << "every new dereference of the operator gives a new char??: " << *si << std::endl;
//	std::cout << "do you need to increment the iterator as an array subscript??" << std::endl;
//	si++;
//	std::cout << "what about now??: " << *si << std::endl;
//	std::cout << "you can also use the array subscript operator with iterator, checking the [0] element should return the element currently pointed by si, so let's print si[1]: " << si[1] << std::endl;
//	std::cout << "is it safe to assume that if file is 1384 bytes then we can subscript si[1381]??: " << si[1381] << std::endl;
//	std::cout << "you should check safely that the next character si[1] is not the end of the string" << std::endl;
//	if(si + 1383 == s.end()){
//		std::cout << "end of string reached" << std::endl;
//	}else{
//		std::cout << "si[1382] is not the end string" << std::endl;
//	}
	//std::getline(file_reading_stream, s);
	//while(std::getline(file_reading_stream, s)){
		//std::cout << "line [ " << i << "]: " << s << std::endl;
		//i++;
	//}
	//std::string s;
	//std::getline(file_reading_stream, s);
	//std::cin >> s;
	return 0;
}
