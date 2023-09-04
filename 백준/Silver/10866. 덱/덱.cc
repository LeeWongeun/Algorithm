#include <iostream>
#include <vector>
#include <string>

std::vector<int> vec;

void push_front(int num);
void push_back(int num);
void pop_front();
void pop_back();
void size();
void empty();
void front();
void back();

int main() {
	int n, num;
	std::string cmd;
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::cin >> cmd;
		if (!cmd.compare("push_front")) {
			std::cin >> num;
			push_front(num);
		}
		else if (!cmd.compare("push_back")) {
			std::cin >> num;
			push_back(num);
		}
		else if (!cmd.compare("pop_front")) {
			pop_front();
		}
		else if (!cmd.compare("pop_back")) {
			pop_back();
		}
		else if (!cmd.compare("size")) {
			size();
		}
		else if (!cmd.compare("empty")) {
			empty();
		}
		else if (!cmd.compare("front")) {
			front();
		}
		else if (!cmd.compare("back")) {
			back();
		}
	}
}

void push_front(int num)
{
	vec.insert(vec.begin(), num);
}
void push_back(int num)
{
	vec.push_back(num);
}
void pop_front()
{
	if (vec.empty())
	{
		std::cout << "-1\n";
		return;
	}
	std::cout << vec.front() << std::endl;
	vec.erase(vec.begin());
}
void pop_back()
{
	if (vec.empty())
	{
		std::cout << "-1\n";
		return;
	}
	std::cout << vec.back() << std::endl;
	vec.erase(vec.begin() + vec.size() - 1);
}
void size()
{
	std::cout << vec.size() << std::endl;
}
void empty()
{
	if (vec.empty())
	{
		std::cout << "1\n";
	}
	else
	{
		std::cout << "0\n";
	}
}
void front()
{
	if (vec.empty())
	{
		std::cout << "-1\n";
		return;
	}
	std::cout << vec.front()<< std::endl;
}
void back()
{
	if (vec.empty())
	{
		std::cout << "-1\n";
		return;
	}
	std::cout << vec.back()<< std::endl;
}