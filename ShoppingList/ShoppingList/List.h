#pragma once
#include<iostream>
#include<string>
#include<memory>
class List
{
public:
	List();
	void Add(std::string item);
	bool Remove(std::string item);
	void View();
	void Clear();
	bool Contains(std::string item);
	int count{};
	int capacity{};

private:
	std::unique_ptr<std::string[]> array;
};

