
#include <iostream>
#include <string>
#include <cstdlib>
#include <limits>
//#include <experimental/random>

struct Data 
{
	std::string	s1;
	int			n;
	std::string s2; 
};

int	randUpper(void)
{
	return std::rand() % 26 + 65; // (65, 90)
}

int	randLower(void)
{
	return std::rand() % 26 + 97; //(97, 122)
}

int	randDigits(void)
{
	return std::rand() % 10 + 48; //(48, 57)
}

void * serialize(void)
{
	char* seria = new char[22];
	void* void_seria = reinterpret_cast<void *>(seria);
	char* seq1 = reinterpret_cast<char *>(seria);
	int*  int2 = reinterpret_cast<int *>(&seria[9]);
	char* seq3 = reinterpret_cast<char *>(&seria[13]);

	int (*randAlphaNumerical[3]) (void) = { &randUpper, &randLower, &randDigits};
	for (int i = 0; i < 8; i++)
	{
		//seq1[i] = randAlphaNumerical[std::experimental::randint(0, 2)]();
		seq1[i] = randAlphaNumerical[std::rand() % 3]();
		seq3[i] = randAlphaNumerical[std::rand() % 3]();
	}
	seq1[8] = '\0';
	seq3[8] = '\0';
	*int2 = std::rand();
	//*int2 = std::experimental::randint(std::numeric_limits<int>::min(), std::numeric_limits<int>::max());
	std::cout << "SEQ1 (serialized):	";
	std::cout << seq1 << std::endl;
	std::cout << "INT (serialized):	" << *int2 << std::endl;
	std::cout << "SEQ2 (serialized):	";
	std::cout << seq3 << std::endl;
	return void_seria;
}

Data * deserialize(void * raw)
{
	Data* data = new Data;
	char* deseria = reinterpret_cast<char *>(raw);
	//data->s1 = std::string(deseria, 8); //from sequence (5)	string (const char* s, size_t n);
	//data->s1 = *(new std::string(reinterpret_cast<char const *>(&deseria[0])));
	//data->s2 = *(new std::string(reinterpret_cast<char const *>(&deseria[13])));

	data->s1 = std::string(reinterpret_cast<char const *>(deseria));
	data->n = *reinterpret_cast<int *>(&deseria[9]);
	data->s2 = std::string(reinterpret_cast<char const *>(&deseria[13]));

	std::cout << "STR1 (deserialized):	" << data->s1 << std::endl;
	std::cout << "INT (deserialized):	" << data->n << std::endl;
	std::cout << "STR2 (deserialized):	" << data->s2 << std::endl;
	delete[] deseria;
	deseria = NULL;
	return data;
}

int main(void)
{
	void* seria;
	Data* deserialized;
	for (int i = 0; i < 3; i++)
	{
		std::cout << std::endl << "---result # " << i + 1 << "---" << std::endl;
		seria = serialize();
		std::cout << "=============" << std::endl;
		deserialized = deserialize(seria);
		delete deserialized;
	}
	return 0;
}
