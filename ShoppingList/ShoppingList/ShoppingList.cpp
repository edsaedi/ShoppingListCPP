// ShoppingList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "List.h"

int main()
{
	bool done = false;
	List shoppingList;
	do
	{
		std::cout << "Would you like to view (1), see if an item is contained (2), add (3), or remove (4) from your shopping list." << std::endl;
		int response{};
		std::cin >> response;
		if (response == 1)
		{
			shoppingList.View();
		}
		else if (response == 2)
		{
			std::cout << "Name the item you want to see." << std::endl;
			std::string container;
			std::cin >> container;
			bool contained = shoppingList.Contains(container);
			if (contained)
			{
				std::cout << "It exists." << std::endl;
			}
			else
			{
				std::cout << "It does not exist." << std::endl;
			}
		}
		else if (response == 3)
		{
			std::cout << "Name the item you want to add." << std::endl;
			std::string adder;
			std::cin >> adder;
			shoppingList.Add(adder);
		}
		else if (response == 4)
		{
			std::cout << "Name the item you want to remove" << std::endl;
			std::string remover;
			std::cin >> remover;
			bool removed = shoppingList.Remove(remover);
			if (removed)
			{
				std::cout << "It has been successfully removed.";
			}
			else
			{
				std::cout << "Unsecussful attempt. Item does not exist.";
			}
		}
		std::cout << "Are you done? (1) Yes. (2). No" << std::endl;
		int donner;
		std::cin >> donner;
		if (donner == 1)
		{
			done = true;
		}

	} while (!done);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
