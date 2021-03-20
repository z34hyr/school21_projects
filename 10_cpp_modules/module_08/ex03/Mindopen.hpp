
#ifndef MINDOPEN_HPP
# define MINDOPEN_HPP

# include <string>
# include <iostream>
# include <vector>
# include <fstream>
# include <algorithm>

# include "CommonRules.hpp"
# include "./commands/Commands.hpp"
# include "./commands/NextPositionComm.hpp"
# include "./commands/PrevPositionComm.hpp"
# include "./commands/IncremComm.hpp"
# include "./commands/DecremComm.hpp"
# include "./commands/PrintSymbComm.hpp"
# include "./commands/PutSymbComm.hpp"
# include "./commands/WhileStartComm.hpp"
# include "./commands/WhileEndComm.hpp"

class Commands;

class Mindopen
{
	public:
		Mindopen(const std::string filename, const std::string args);
		Mindopen(Mindopen const & obj);
		Mindopen& operator= (Mindopen const & obj);
		~Mindopen(void);

		void			readFile(); // reads file, creates instruction queue
		void			execute(); // executes commands one by one

		char*			getArray();
		unsigned int	getCurrPos();
		char			getValue(unsigned int pos);
		void			setValue(int value);
		void			incPos();
		void			decPos();
		void			incVal();
		void			decVal();
		void			setVal(char symb);

		char			getArgsSymb();
		unsigned int*	getArgsCurrPos();

		Commands*		getComm(unsigned int ind);
		unsigned int	getCurrCommNumber(void);
		void			setCurrCommNumber(unsigned int new_number);
		unsigned int	getVectorSize();


	private:
		std::vector<Commands*>	_comm_arr;
		unsigned int			_cur_comm;
		
		char					_array[ARR_SIZE];
		unsigned int			_cur_pos_arr;

		const std::string		_filename;
		const std::string		_args;
		unsigned int			_cur_pos_args;
		void					_check_braces(void);
		int						_braces_count;
};

#endif