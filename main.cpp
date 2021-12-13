#include <iostream>
#include <random>

int getUserGuess()
{
    while(true)
    {
       static int guessNum{ 1 };
       std::cout << "Guess #" << guessNum <<": ";
       int userNum{};
       std::cin >> userNum;
       std::cin.ignore(pow(2,16), '\n');
       if (userNum >= 1 && userNum <= 100)
            return userNum;
    }
}

int main()
{
   std::cout<<"Let's play a game. I'm thinking of a number. You have 7 tries to guess what it is.\n";
   std::random_device rd; 
   std::mt19937 mersenne(rd());
   auto randomNum{mersenne() % 99 + 1};
   std::cout << randomNum << '\n';

   int userGuess{ getUserGuess() };
   std::cout << userGuess;

   return 0;
}