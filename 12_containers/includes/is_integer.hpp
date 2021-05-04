
#pragma once

namespace ft
{
	struct true_type { };
	struct false_type { };
	// Integer types //

	template<typename _Tp> 
	struct is_integer
	{
		enum { value = 0 };
		typedef false_type __type;
	};

	template<>
		struct is_integer<bool>
		{
			enum { value = 1 };
			typedef true_type __type;
		};

	template<>
		struct is_integer<char>
		{
			enum { value = 1 };
			typedef true_type __type;
		};

	template<>
		struct is_integer<signed char>
		{
			enum { value = 1 };
			typedef true_type __type;
		};

	template<>
		struct is_integer<unsigned char>
		{
			enum { value = 1 };
			typedef true_type __type;
		};

	template<>
		struct is_integer<short>
		{
			enum { value = 1 };
			typedef true_type __type;
		};

	template<>
		struct is_integer<unsigned short>
		{
			enum { value = 1 };
			typedef true_type __type;
		};

	template<>
		struct is_integer<int>
		{
			enum { value = 1 };
			typedef true_type __type;
		};

	template<>
		struct is_integer<unsigned int>
		{
			enum { value = 1 };
			typedef true_type __type;
		};

	template<>
		struct is_integer<unsigned long>
		{
			enum { value = 1 };
			typedef true_type __type;
		};

	template<> 
		struct is_integer<long>
		{
			enum { value = 1 };
			typedef true_type __type;
		};

	template<>
		struct is_integer<long long>
		{
			enum { value = 1 };
			typedef true_type __type;
		};
	template<>
    	struct is_integer<unsigned long long>
		{
			enum { value = 1 };
			typedef true_type __type;
		};
}