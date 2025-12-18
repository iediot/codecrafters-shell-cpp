#include <iostream>
#include <string>

int main()
{
  std::cout << std::unitbuf;
  std::cerr << std::unitbuf;
  std::string command;

  while (1) {
    std::cout << "$ ";
    std::cin >> command;
    if (command == "echo")
    {
      std::string echo;
      std::cin >> echo;
      std::cout << echo << std::endl;
    }
    else if (command == "exit")
      break;
    else
      std::cout << command << ": command not found\n";
  }
}
