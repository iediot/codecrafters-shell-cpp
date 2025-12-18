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

  while (true) {
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
    else if (command == "type")
    {
      bool found = false;
      std::string builtin[3] = {"echo", "exit", "type"};
      std::string command_to_know;
      ss >> command_to_know;
      for (int i = 0; i <= builtin->length(); i++)
        if (builtin[i] == command_to_know)
        {
          std::cout << command_to_know << " is a shell builtin\n";
          found = true;
        }
      if (found == false)
        std::cout << command_to_know << ": command not found\n";
    }
    else
      std::cout << command << ": command not found\n";
  }
}
