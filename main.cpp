#include <iostream>
#include <random>

int main()
{
   std::cout<<"Let's play a game. I'm thinking of a number. You have 7 tries to guess what it is.\n";
   std::random_device rd; 
   std::mt19937 mersenne(rd());
   auto randomNum{mersenne() % 99 + 1};
   std::cout << randomNum << '\n';
   
   return 0;
}