#include "List.h"
#include <iostream>
#include <string>
#include <memory>

List::List()
{
	count = 0;
	capacity = 10;
	array = std::make_unique<std::string[]>(capacity);
}

void List::Add(std::string item)
{
	if (count >= capacity)
	{
		capacity *= 2;
	}

	auto temp = std::make_unique<std::string[]>(capacity);
	for (int i = 0; i < count; i++)
	{
		temp[i] = array[i];
	}

	temp[count] = item;

	array = std::move(temp);
	count++;
}

bool List::Remove(std::string item)
{
	auto temp = std::make_unique<std::string[]>(capacity);
	int j{};
	bool exists = Contains(item);
	if (!exists)
	{
		return false;
	}
	for (int i = 0; i < count; i++)
	{
		if (array[i] != item)
		{
			temp[j] = array[i];
			j++;
		}
	}

	array = std::move(temp);
	count--;
	return true;
}

void List::View()
{
	std::cout << "Your shopping list is:" << std::endl;
	for (int i = 0; i < count; i++)
	{
		std::cout << array[i] << std::endl;
	}
	std::cout << "That is it!" << std::endl;
}

void List::Clear()
{
	array = nullptr;
}

bool List::Contains(std::string item)
{
	for (size_t i = 0; i < count; i++)
	{
		if (array[i] == item)
		{
			return true;
		}
	}
	return false;
}
