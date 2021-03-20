
#ifndef FIXED_CLASS_HPP
# define FIXED_CLASS_HPP

# include <iostream>
# include <string>

class Fixed
{
    public:
		Fixed(void);
		~Fixed(void);
		Fixed(const Fixed& obj);
		Fixed& operator = (const Fixed& obj);

		int 				getRawBits(void) const;
		void 				setRawBits(int const raw);
	
	private:
		int					_fp_value;
		static const int	_fb_number;
};

#endif