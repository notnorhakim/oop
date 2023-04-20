#include <iostream>

int main()
{

    while(true)
    {
        std::cout << std::endl;

        std::cout << "================================" << std::endl;
        // 1 print help
        std::cout << "1: Print help" << std::endl;
        // 2 print exchange stats
        std::cout << "2: Print exchange stats" << std::endl;
        // 3 make an offer
        std::cout << "3: Make an offer" << std::endl;
        // 4 make a bid
        std::cout << "4: Make a bid" << std::endl;
        // 5 print wallet
        std::cout << "5: Print wallet" << std::endl;
        // 6 continue
        std::cout << "6: Continue" << std::endl;

        std::cout << "================================" << std::endl;
        std::cout << std::endl;

        std::cout << "Type in 1-6" << std::endl;

        int userOption;
        std::cin >> userOption;
        std::cout << std::endl;
        std::cout << "You chose: " << userOption << std::endl;

        if (userOption == 0) //not one of the choice
        {
            std::cout << "Invalid choice. Choose 1-6" << std::endl;
        }
        if (userOption == 1)
        {
            std::cout << "Help - your aim is to make money. Analyse the market and make bids and offers." << std::endl;
        }
        if (userOption == 2)
        {
            std::cout << "Market looks good" << std::endl;
        }
        if (userOption == 3)
        {
            std::cout << "Make an offer - enter the amount" << std::endl;
        }
        if (userOption == 4)
        {
            std::cout << "Make a bid - enter the amount" << std::endl;
        }
        if (userOption == 5)
        {
            std::cout << "Your wallet is empty" << std::endl;
        }
        if (userOption == 6)
        {
            std::cout << "Going to next time frame" << std::endl;
        }
    }

    return 0;
}