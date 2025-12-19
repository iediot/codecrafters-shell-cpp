#include <complex>
#include <iostream>
#include <ranges>
#include <string>
#include <sstream>
#include <unistd.h>
#include <vector>
#include <sys/types.h>
#include <sys/wait.h>
#include <filesystem>
#include <cstdlib>

int main() {
  std::cout << std::unitbuf;
  std::cerr << std::unitbuf;
  std::string line;
  std::string command;

  while (true) {
    std::cout << "$ ";
    std::getline(std::cin, line);
    std::stringstream ss(line);
    ss >> command;
    if (command == "echo") {
      std::string word;
      while (ss >> word)
        std::cout << word << " ";
      std::cout << std::endl;
    }

    else if (command == "exit") {
      return 0;
    }

    else if (command == "type") {
      bool found = false;
      std::string builtin[100] = {"echo", "exit", "type", "pwd"};
      std::string command_to_know;
      ss >> command_to_know;

      for (const auto& b : builtin)

        if (b == command_to_know) {
          std::cout << command_to_know << " is a shell builtin\n";
          found = true;
        }

      if (!found) {
        std::string path_env = std::getenv("PATH");
        std::stringstream ss_path(path_env);
        std::string path;
        while (std::getline(ss_path, path, ':')) {
          std::string full_path = path + '/' + command_to_know;
          if (access(full_path.c_str(), X_OK) == 0) {
            std::cout << command_to_know << " is " << full_path << std::endl;
            found = true;
            break;
          }
        }
      }

      if (!found)
        std::cout << command_to_know << ": not found\n";
    }

    else if (command == "pwd") {
      std::cout << std::filesystem::current_path().string() << std::endl;
    }

    else if (command == "cd")
    {
      const char* target = nullptr;
      std::vector<std::string> args;
      std::string arg;

      while (ss >> arg)
        args.push_back(arg);
      if (args.size() == 0) {
        target = std::getenv("HOME");
        if (!target)
          target = "/";
      } else {
        target = args[0].c_str();
      }
      if (chdir(target) != 0) {
        std::cout << "cd: " << target << ": No such file or directory\n";
      }

    } else {
      std::vector<std::string> args;
      args.push_back(command);
      std::string arg;

      while (ss >> arg)
        args.push_back(arg);
      std::vector<char*> c_args;

      for (auto &a : args)
        c_args.push_back(&a[0]);
      c_args.push_back(nullptr);
      pid_t pid = fork();

      if (pid == 0) {
        execvp(command.c_str(), c_args.data());
        std::cout << command << ": command not found\n";
        exit(1);
      } else {
        wait(nullptr);
      }
    }
  }
}