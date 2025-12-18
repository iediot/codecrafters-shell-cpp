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
    if (command == "exit")
      break;
    std::cout << command << ": command not found\n";
  }
}
