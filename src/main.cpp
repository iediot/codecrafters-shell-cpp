#include <iostream>
#include <ranges>
#include <string>
#include <sstream>

int main()
{
  std::cout << std::unitbuf;
  std::cerr << std::unitbuf;
  std::string line;
  std::string command;

  while (1) {
    std::cout << "$ ";
    std::getline(std::cin, line);
    std::stringstream ss(line);
    ss >> command;
    if (command == "echo")
    {
      std::string word;
      while (ss >> word)
        std::cout << word << " ";
      std::cout << std::endl;
    }
    else if (command == "exit")
      break;
    else
      std::cout << command << ": command not found\n";
  }
}
