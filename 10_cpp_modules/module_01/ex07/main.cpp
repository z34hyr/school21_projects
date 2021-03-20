
#include <string>
#include <iostream>
#include <fstream>

int	err_write(std::string err_text)
{
	std::cerr << "Error: " << err_text << std::endl;
	return (1);
}

int main(int argc, char* argv[])
{
	if (argc != 4)
		return (err_write("Wrong # of arguments"));
	std::ifstream infile(argv[1]);
	if (!infile.good())
		return (err_write("Error while opening file!"));
	std::cout << argv[1] << " opened. processing..." << std::endl;
	std::string ofname = argv[1];//overload char[]	
	ofname = ofname + ".replace";

	std::string s1 = argv[2];
	std::string s2 = argv[3];
	std::string buff_str;
	std::ofstream outfile(ofname);
	if (!outfile.good())
	{
		infile.close();
		return (err_write("Error while opening .replace file!"));
	}
	std::cout << ofname << " file created" << std::endl;
	while (std::getline(infile, buff_str))
	{
		std::size_t found = 0;
		std::size_t start = 0;
		if (buff_str.find(s1) != std::string::npos)
		{
			while ((found = buff_str.find(s1, start)) != std::string::npos)
			{
				std::string p1 = buff_str.substr(0, found);
				std::string p2 = buff_str.substr(found + s1.length());
				buff_str = p1 + s2 + p2;
				start = found + s2.length();
			}
			outfile << buff_str << std::endl;
		}
		else
			outfile << buff_str << std::endl;
	}
	std::cout << "done!" << std::endl;
	outfile.close();
	infile.close();
	return (0);
}
