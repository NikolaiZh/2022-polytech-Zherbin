#include <deque>
#include <iostream>

int main() {
  std::string expr;
  std::cout << " > ";

  std::getline(std::cin, expr);

  if (std::cin.fail() || expr == "exit") {
    std::cout << ITALIC << "\n Goodbye, desu\n" << RESET << std::endl;
    exit(0);
  }

  std::deque<Token> tokens = tokenize(expr);

  auto queue = shunting_yard(tokens);

  if (queue.first == -1) {
    std::cerr << RED << "\n  Error" << RESET << ": " << ITALIC
              << "Mismatched parentheses, desu\n"
              << RESET << std::endl;
    return main();
  }

  auto res = solve(queue.second);

  if (res.first == 136) {
    std::cerr << RED << "\n  Error" << RESET << ": " << ITALIC
              << "Division by zero, desu\n"
              << RESET << std::endl;
    return main();
  }

  std::cout << "\n    ";
  for (Token token : tokens) {
    if (token.type == Token::Type::Number) {
      std::cout << CYAN;
      if (token.num < 0)
        std::cout << RESET << "(" << CYAN << token.num << RESET << ") ";
      else
        std::cout << CYAN << token.num << " ";

    } else {
      std::cout << RESET;
      std::cout << token.str << " ";
    }
  }
  std::cout << RESET << "= " << GREEN << res.second << RESET << "\n"
            << std::endl;

  return main();
}