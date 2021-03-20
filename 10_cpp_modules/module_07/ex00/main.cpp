
#include "whatever.hpp"

int main()
{
	int i1 = 50;
	int i2 = 12;
	float f1 = 12.0f;
	float f2 = 1111.0f;
	double d1 = 1.0;
	double d2 = 1.1;
	std::string str1 = "hello";
	std::string str2 = "hell";
	std::cout.precision(1);

	std::cout << "values int:	" << i1 << ", " << i2 << std::endl;
	std::cout << "max int:	" << ::max<int>(i1, i2) << std::endl;
	std::cout << "min int:	" << ::min<int>(i1, i2) << std::endl;
	std::cout << "values before swap:	" << i1 << ", " << i2 << std::endl;
	::swap<int>(i1, i2);
	std::cout << "values after swap:	" << i1 << ", " << i2 << std::endl;

	std::cout << "values float:	"<< std::fixed << f1 << ", " << f2 << std::endl;
	std::cout << "max float:	" << ::max<float>(f1, f2) << std::endl;
	std::cout << "min float:	" << ::min<float>(f1, f2) << std::endl;
	std::cout << "values before swap:	" << f1 << ", " << f2 << std::endl;
	::swap<float>(f1, f2);
	std::cout << "values after swap:	" << f1 << ", " << f2 << std::endl;

	std::cout << "values double:	" << d1 << ", " << d2 << std::endl;
	std::cout << "max double:	" << ::max<double>(d1, d2) << std::endl;
	std::cout << "min double:	" << ::min<double>(d1, d2) << std::endl;
	std::cout << "values before swap:	" << d1 << ", " << d2 << std::endl;
	::swap<double>(d1, d2);
	std::cout << "values after swap:	" << d1 << ", " << d2 << std::endl;

	std::cout << "values string:	" << str1 << ", " << str2 << std::endl;
	std::cout << "max string:	" << ::max(str1, str2) << std::endl;
	std::cout << "min string:	" << ::min(str1, str2) << std::endl;
	std::cout << "values before swap:	" << str1 << ", " << str2 << std::endl;
	::swap(str1, str2);
	std::cout << "values after swap:	" << str1 << ", " << str2 << std::endl;
}

// int main( void ) {
// 	int a = 2;
// 	int b = 3;
// 	::swap( a, b);
// 	std::cout << "a = " << a << ", b = " << b << std::endl;
// 	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
// 	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
// 	std::string c = "chaine1";
// 	std::string d = "chaine2";
// 	::swap(c, d);
// 	std::cout << "c = " << c << ", d = " << d << std::endl;
// 	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
// 	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
// 	return 0;
// }