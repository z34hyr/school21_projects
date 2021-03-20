
#ifndef FIXED_CLASS_HPP
# define FIXED_CLASS_HPP

# include <iostream>
# include <string>

class Fixed
{
    public:
		Fixed(void);
		Fixed(const int param);
		Fixed(const float param);
		~Fixed(void);
		Fixed(const Fixed& obj);
		Fixed& operator = (const Fixed& obj);

		bool				operator < (const Fixed& other) const;
		bool				operator > (const Fixed& other) const;
		bool				operator <= (const Fixed& other) const;
		bool				operator >= (const Fixed& other) const;
		bool				operator == (const Fixed& other) const;
		bool				operator != (const Fixed& other) const;
		Fixed				operator + (const Fixed& other) const;
		Fixed				operator - (const Fixed& other) const;
		Fixed				operator * (const Fixed& other) const;
		Fixed				operator / (const Fixed& other) const;

		Fixed&				operator ++();
		Fixed				operator ++(int);
		Fixed&				operator --();
		Fixed				operator --(int);

		int 				getRawBits(void) const;
		void 				setRawBits(int const raw);
		float				toFloat(void) const;
		int					toInt(void) const;

		static Fixed&		min(Fixed& value1, Fixed& value2);
		const static Fixed&	min(const Fixed& value1, const Fixed& value2);
		static Fixed&		max(Fixed& value1, Fixed& value2);
		const static Fixed&	max(const Fixed& value1, const Fixed& value2);

	private:
		int					_value;
		static const int	_frac_bits;
};
		std::ostream& operator << (std::ostream& z, const Fixed& obj);

#endif