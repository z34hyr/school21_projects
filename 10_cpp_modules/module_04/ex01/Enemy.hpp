
#ifndef ENEMY_HPP
# define ENEMY_HPP

# include <string>
# include <iostream>

class Enemy
{
	public:
		Enemy(void);
		Enemy(int hp, std::string const & type);
		virtual ~Enemy();
		Enemy(const Enemy& obj);
		Enemy& operator = (const Enemy& obj);

		std::string getType() const;
		int getHP() const;
		virtual void takeDamage(int damage);

	protected:
		std::string		_type;
		int				_hp;
};

#endif
