
#include "ZombieEvent.hpp"

ZombieEvent::ZombieEvent(void)
{
    return;
}

ZombieEvent::~ZombieEvent(void)
{
    return;
}

void	ZombieEvent::setZombieType(std::string type, Zombie* zombie)
{
    ZombieEvent::_type = type;
    zombie->set_type(type);
}

Zombie* ZombieEvent::newZombie(std::string name)
{
    Zombie* newWarrior = new Zombie(name);
    this->setZombieType("random", newWarrior);
    return (newWarrior);
}
