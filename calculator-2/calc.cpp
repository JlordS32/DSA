#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <queue>
#include "calc.hpp"

std::ostream &Calc::operator<<(std::ostream &out, const Calc::Token &t)
{
   out << "{'" << t.type << "', " << t.val << '}';
   return out;
}

bool Calc::operator==(const Calc::Token &a, const Calc::Token &b)
{
   if (a.type != b.type)
   {
      return false;
   }
   if (a.type == 'n')
   {
      return a.val == b.val;
   }
   return true;
}

// This is the function for you to write
std::vector<Calc::Token> Calc::infixToPostfix(const std::vector<Token> &input)
{
   std::vector<Token> output;
   std::vector<Token> opStack;

   for (Token t : input)
   {
      if (t.type == 'n')
      {
         output.push_back(t);
      }
      else if (t.type == '(')
      {
         opStack.push_back(t);
      }
      else if (t.type == ')')
      {
         while (!opStack.empty() && opStack.back().type != '(')
         {
            output.push_back(opStack.back());
            opStack.pop_back();
         }

         // Handle case when back is '('
         if (!opStack.empty())
         {
            opStack.pop_back();
         }
      }
      else
      {
         while (!opStack.empty() && precedence(t.type) <= precedence(opStack.back().type))
         {
            output.push_back(opStack.back());
            opStack.pop_back();
         }
         opStack.push_back(t);
      }
   }

   // Cleanup
   while (!opStack.empty())
   {
      output.push_back(opStack.back());
      opStack.pop_back();
   }

   return output;
}

// Additional helper function
int Calc::precedence(char c)
{
   switch (c)
   {
   case '+':
   case '-':
      return 1;
   case '*':
   case '/':
      return 2;
   default:
      return 0;
   }
}

// evalPostfix evaluates a vector of tokens in postfix notation
// This function was done in tutorial Week 10
int Calc::evalPostfix(const std::vector<Token> &tokens)
{
   if (tokens.empty())
   {
      return 0;
   }

   std::vector<int> stack;

   for (Token t : tokens)
   {
      if (t.type == 'n')
      {
         stack.push_back(t.val);
      }
      else
      {
         int val = 0;

         switch (t.type)
         {
         case '+':
            val = stack.back() + *(stack.end() - 2);
            break;
         case '*':
            val = stack.back() * *(stack.end() - 2);
            break;
         case '-':
            val = *(stack.end() - 2) - stack.back();
            break;
         case '/':
            if (stack.back() == 0)
            {
               throw std::runtime_error("divide by zero");
            }
            val = *(stack.end() - 2) / stack.back();
            break;
         default:
            std::cout << "invalid token\n";
            break;
         }

         stack.pop_back();
         stack.pop_back();
         stack.push_back(val);
      }
   }
   return stack.back();
}

// tokenise takes a string and parses it into a vector of tokens
std::vector<Calc::Token> Calc::tokenise(const std::string &expression)
{
   const std::vector<char> symbols = {'+', '-', '*', '/', '(', ')'};
   std::vector<Token> tokens{};

   for (std::size_t i = 0; i < expression.size(); ++i)
   {
      const char c = expression[i];
      // check if c is one of '+', '-', '*', '/', '(', ')'
      if (std::find(symbols.begin(), symbols.end(), c) != symbols.end())
      {
         tokens.push_back({c});
      }
      else if (isdigit(c))
      {
         // process multiple digit integers
         std::string num{c};
         while (i + 1 < expression.size() && isdigit(expression[i + 1]))
         {
            ++i;
            num.push_back(expression[i]);
         }
         tokens.push_back({'n', std::stoi(num)});
      }
   }
   return tokens;
}

// eval puts the pieces together to take a string with an
// arithmetic expression and output its evaluation
int Calc::eval(const std::string &expression)
{
   std::vector<Token> tokens = tokenise(expression);
   std::vector<Token> postfix = infixToPostfix(tokens);
   return evalPostfix(postfix);
}
