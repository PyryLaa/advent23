#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
#include <fstream>
#include <vector>

std::string search_nums(std::string& s);

int main(){
  std::string fname = "input.txt";
  std::string line;
  std::ifstream in_file;
  std::vector<std::string> s_vec;
  int sum = 0;
  
  in_file.open("input.txt", std::ios::in);
  
  if(!in_file.is_open()){
    std::cerr << "File does not exist or could not be opened" << std::endl;
    return -1;
  }else{
    while(std::getline(in_file, line)){
      //s_vec.push_back(search_nums(line));
      sum += stoi(search_nums(line));
    }
  }
  std::cout << "Sum: " << sum << std::endl;
  for(std::string s : s_vec){
    std::cout << s << std::endl;
  }
  in_file.close();
  return 0;
}

std::string search_nums(std::string& s){
  std::string num_s = "";
  bool first_found = false;
  for(const auto& c : s){
    if(isdigit(c) && first_found == false){
      num_s.push_back(c);
      first_found = true;
    }else if(isdigit(c) && first_found == true && num_s.length() < 2){
      num_s.push_back(c);
    }else if(isdigit(c) && first_found == true && num_s.length() == 2){
      num_s.at(1) = c;
    }
  }
  if(num_s.length() == 1){
    num_s.push_back(num_s.at(0));
  }else if(num_s.empty()){
    num_s.push_back('0');
  }
  return num_s;
}
