
#include <sstream>
#include <string>
#include <iostream>
#include <limits>

#define IMPOSS "impossible"
#define UNDISPL "Non displayable"
#define CHAR "char: "
#define INTEGER "int: "
#define FLOAT "float: "
#define DOUBLE "double: "

int		errorParams(void)
{
	std::cout << "Wrong number of parameters" << std::endl;
	return 0;
}

void	specResult(std::string charRes, std::string intRes, std::string floatRes, std::string doubleRes)
{
	std::cout << CHAR << charRes << std::endl;
	std::cout << INTEGER << intRes << std::endl;
	std::cout << FLOAT << floatRes << std::endl;
	std::cout << DOUBLE << doubleRes << std::endl;
}

bool	isDigit(char symb)
{
	if (symb >= '0' && symb <= '9')
		return 1;
	return 0;
}

int     main(int argc, char* argv[])
{
	if (argc != 2)
		return errorParams();
	std::stringstream ss_i;
	std::stringstream ss_f;
	std::stringstream ss_d;
	std::stringstream ss;
	std::string str;
	char c;
	int integer;
	float f;
	double d;

	ss << argv[1];
	str = ss.str();
	//std::cout << "string in std::string: " << str << std::endl;
	//////////////////
	//overview string for nan/nanf/-inf/+inf
	//////////////////;
	if (str == "nan" || str == "nanf" || str == "")
	{
		f = 0.0/0.0;
		d = 0.0/0.0;
		specResult(IMPOSS, IMPOSS, "nanf", "nan");
		return 0;
	}
	if (str == "-inff" || str == "-inf")
	{
		f = 1.0/-0.0;
		d = 1.0/-0.0;
		specResult(IMPOSS, IMPOSS, "-inff", "-inf");
		return 0;
	}
	if (str == "+inff" || str == "+inf")
	{
		f = 1.0/+0.0;
		d = 1.0/+0.0;
		specResult(IMPOSS, IMPOSS, "+inff", "+inf");
		return 0;
	}
	//////////////////
	// HANDLE CHAR LITERAL
	//////////////////
	if (str.length() == 1 && ((str[0] >= 32 && str[0] <= 47) || (str[0] >= 58 && str[0] <= 126)))
	{
		c = str[0];
		integer = c;//static_cast<int>(c); upcast - static isn't necessary
		f = c;//static_cast<float>(c);
		d = c;//static_cast<double>(c);
		std::cout << CHAR << "'" << c << "'" << std::endl;
		std::cout << INTEGER << integer << std::endl;
		std::cout << FLOAT << f << ".0f" << std::endl;
		std::cout << DOUBLE << d << ".0" << std::endl;
		return 0;
	}
	//////////////////
	//overview string for other types:
	//////////////////
	int point_count = 0;
	int f_count = 0;
	for (unsigned long i = 0; i < str.length(); i++)
	{
		//std::cout << "watch symbol: " << str[i] << std::endl;
		if (str[i] == '.' && (i == 0 || point_count > 0 || (i + 3 != str.length() && i + 2 != str.length())))
		{
			specResult(IMPOSS, IMPOSS, IMPOSS, IMPOSS);
			return 0;
		}
		else if (str[i] == '.' && point_count == 0)
		{
			point_count += 1;
			continue;
		}
		if (str[i] == 'f' && i + 1 != str.length())
		{
			specResult(IMPOSS, IMPOSS, IMPOSS, IMPOSS);
			return 0;
		}
		else if (str[i] == 'f')
		{
			f_count += 1;
			continue;
		}
		if (str[i] == '-' && i == 0)
			continue;
		else if (str[i] == '-' && i > 0)
		{
			specResult(IMPOSS, IMPOSS, IMPOSS, IMPOSS);
			return 0;
		}
		if (!isDigit(str[i]))
		{
			specResult(IMPOSS, IMPOSS, IMPOSS, IMPOSS);
			return 0;
		}
	}
	//////////////////
	// configuring int limits strings
	//////////////////
	int int_min = std::numeric_limits<int>::min();
	int int_max = std::numeric_limits<int>::max();
	std::stringstream int_ss_max;
	std::stringstream int_ss_min;
	std::string	int_str_max;
	std::string int_str_min;
	int_ss_max << int_max;
	int_ss_min << int_min;
	int_str_max = int_ss_max.str();
	int_str_min = int_ss_min.str();
	//std::cout << "int min: " << int_str_min << std::endl;
	//std::cout << "int max: " << int_str_max << std::endl;
	//////////////////
	// configuring float limits strings
	//////////////////
	float float_max = std::numeric_limits<float>::max();
	//float float_min = float_max * -1.0;
	std::stringstream float_ss_max;
	std::string	float_str_max;
	std::string	float_str_min;
	float_ss_max.precision(1);

	float_ss_max << std::fixed << float_max;
	float_str_max = float_ss_max.str();
	float_str_min = "-" + float_str_max;
	//std::cout << "float min: " << float_str_min << std::endl;
	//std::cout << "float max: " << float_str_max << std::endl;

	//////////////////
	// configuring double limits strings
	//////////////////
	double double_max = std::numeric_limits<double>::max();
	//double double_min = double_max * -1.0;
	std::stringstream double_ss_max;
	std::string	double_str_max;
	std::string	double_str_min;
	double_ss_max.precision(1);

	double_ss_max << std::fixed << double_max;
	double_str_max = double_ss_max.str();
	double_str_min = "-" + double_str_max;
	//std::cout << "double min: " << double_str_min << std::endl;
	//std::cout << "double max: " << double_str_max << std::endl;

	std::cout.precision(1);

	if (point_count == 0 && f_count == 0)
		str = str + ".0";
	else if (point_count == 1 && f_count == 1)
		str = str.substr(0, str.length() - 1);
	if (str[str.length() - 2] != '.')
	{
		specResult(IMPOSS, IMPOSS, IMPOSS, IMPOSS);
		return 0;
	}
	///////
	// check limits of double
	///////
	std::string str_whole;
	char char_fract;
	str_whole = str.substr(0, str.length() - 2);
	char_fract = str.at(str.length() - 1);	
	if ((isDigit(str[0]) && \
			(str.length() > double_str_max.length() || (str.length() == double_str_max.length() && str.compare(double_str_max) > 0))) || \
		(!isDigit(str[0]) && \
			(str.length() > double_str_min.length() || (str.length() == double_str_min.length() && str.compare(double_str_min) > 0))))
	{
		specResult(IMPOSS, IMPOSS, IMPOSS, IMPOSS);
		return 0;
	}
	///////
	// if limits are OK -> convert
	///////
	ss_d << argv[1];
	ss_d >> d;
	//std::cout << "what I get: " << d << std::endl;
	if (d >= 32.0 && d < 127.0)
	{
		c = static_cast<char>(d);
		std::cout << CHAR << "'" << c << "'" << std::endl;
	}
	else if ((d >= -128.0 && d < 32.0) || (d >= 127.0 && d < 128.0))
		std::cout << CHAR << UNDISPL << std::endl;
	else
		std::cout << CHAR << IMPOSS << std::endl;
	if ((isDigit(str[0]) && (str_whole.length() > int_str_max.length() ||\
							(str_whole.length() == int_str_max.length() && \
							(str_whole > int_str_max || (str_whole == int_str_max && char_fract != '0'))))) || \
		(str[0] == '-' && (str_whole.length() > int_str_min.length() || \
							(str_whole.length() == int_str_min.length() && (str_whole > int_str_min || \
							(str_whole == int_str_min && char_fract != '0'))))))
		std::cout << INTEGER << IMPOSS << std::endl;
	else
	{
		integer = static_cast<int>(d);
		std::cout << INTEGER << integer << std::endl;
	}
	if ((isDigit(str[0]) && \
			(str.length() > float_str_max.length() || (str.length() == float_str_max.length() && str.compare(float_str_max) > 0))) || \
		(!isDigit(str[0]) && \
			(str.length() > float_str_min.length() || (str.length() == float_str_min.length() && str.compare(float_str_min) > 0))))
		std::cout << FLOAT << IMPOSS << std::endl;
	else
	{
		f = static_cast<float>(d);
		std::cout << FLOAT << std::fixed << f << "f" << std::endl;
	}
	std::cout << DOUBLE << std::fixed << d << std::endl;
	return 0;
}
