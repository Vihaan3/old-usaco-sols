#include <iostream>
#include <vector>
#define string std:: string
string original, censored;


int main()
{
	std::cin >> original >> censored;
	string holder;
	int counter = 0;
	for (char letter : original)
	{
		holder.push_back(letter);
		if (counter >= (censored.length()))
		{
			if (holder.substr(counter - (censored.length()+1), censored.length()) == censored)
			{
				holder.erase(counter - (censored.length()+1), censored.length());
			}
		}
		counter++;
	}
	std::cout << holder;
}
