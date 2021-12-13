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
   int tryCounter{ 1 };

   while (true)
   {
      std::cout<<"Let's play a game. I'm thinking of a number. You have 7 tries to guess what it is.\n";
      std::random_device rd; 
      std::mt19937 mersenne(rd());
      auto randomNum{mersenne() % 99 + 1};

      int userGuess{ getUserGuess() };

      if (userGuess != randomNum)
      {
         if (userGuess < randomNum)
         {
            std::cout << "Your guess is too low.\n";
         }
         else if (userGuess > randomNum)
         {
            std::cout << "Your guess is too high.\n";
         }
         ++tryCounter;
      }
      else
      {
         if (tryCounter <= 7)
         {
            std::cout << "Correct! You win!\n";
         }
         else
         {
            std::cout << "Sorry, you lose. The correct number was " << randomNum << ".\n";
         }
         
         bool isUserInputCorrect{};
         do
         {
            std::cout << "Would you like to play again (y/n)? ";
            char userAnswer{};
            std::cin >> userAnswer;
            if (userAnswer == 'y')
            {
               tryCounter = 1;
               isUserInputCorrect = true;
               continue;
            }
            else if (userAnswer == 'n')
            {
               std::cout << "Thank you for playing.\n";
               isUserInputCorrect = true;
               break;
            }
            else
            {
               isUserInputCorrect = false;
            }
         } while (!isUserInputCorrect);
      }
   }

   return 0;
}