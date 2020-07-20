#include <iostream>
#include <fstream>

std::string StringToHex(std::string str)
{
  static const char hex[] = "0123456789abcdef";
  
  std::string output;
  output.resize(str.length() * 2);
  for(unsigned char c : str)
  {
    output.push_back(hex[c >> 4]);
    output.push_back(hex[c & 15]);
    output.push_back(' ');
  }
  return output;
}

int main(int argc, char** argv)
{
 if(argc == 2)
 {
  std::fstream stream = std::fstream(argv[1], std::ios::binary | std::ios::in);
  std::string str((std::istreambuf_iterator<char>(stream)), std::istreambuf_iterator<char>());
  stream.close();
  
  std::cout << StringToHex(str) << std::endl;
 }
}
