#include<fstream>
#include<iostream>

void FindGametes(int pairs, int dpairs)
{
	std::ifstream ralelles{ "alelles.txt" };
	std::ofstream out{ "Gametes.txt" };
	std::string temp;
	bool isOne;
	for (long long comb = (1ULL << dpairs) - 1; comb >= 0; comb--)
	{
		int j = 0;
		for (int i = 0; i < pairs; i++)
		{
			ralelles >> temp;
			if (temp.length() == 1)
				out << temp;
			else
			{
				isOne = comb & (1ULL << j);
				out << temp[isOne];
				j++;
			}
		}
		out << "\n";
		ralelles.seekg(std::ios::beg);
	}
	ralelles.close();
	out.close();
}
int main()
{
	std::string genotype;
	std::cout << "Enter a Genotype: ";
	std::cin >> genotype;
	std::ofstream out{ "alelles.txt" };
	int p = 0;
	for (int i = 0; i < genotype.size(); i += 2)
	{
		if (genotype[i] == genotype[i + 1])
			out << genotype[i] << "\n";
		else
		{
			out << genotype[i] << genotype[i + 1] << "\n";
			p++;
		}
	}
	out.close();
	FindGametes(genotype.length() / 2, p);
}