
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

		int 				getRawBits(void) const;
		void 				setRawBits(int const raw);
		float				toFloat(void) const;
		int					toInt(void) const;

	private:
		int					_value;
		static const int	_frac_bits;
};

		std::ostream& operator << (std::ostream& z, const Fixed& obj);

#endif