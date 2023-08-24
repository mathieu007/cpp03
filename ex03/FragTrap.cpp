#include "FragTrap.hpp"

FragTrap::FragTrap(const FragTrap &copy) : ClapTrap(copy)
{
    std::cout << "\033[35mFragTrap " << copy.getName() << " copy Constructor called\033[0m" << std::endl;
    *this = copy;
}

FragTrap::FragTrap(std::string &name) : ClapTrap(name)
{
    std::cout << "\033[35mFragTrap " << name << " constructor called\033[0m" << std::endl;
    this->_attackDamage = 20;
    this->_energyPoints = 50;
    this->_hitPoints = 100;
}

FragTrap::~FragTrap()
{
    std::cout << "\033[33mFragTrap " << _name << " destructor called\033[0m" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &assign)
{
    std::cout << "\033[33mFragTrap " << assign.getName() << " copy assignment operator called\033[0m" << std::endl;
    if (this != &assign)
    {
        this->_attackDamage = assign.getAttackDamage();
        this->_energyPoints = assign.getEnergyPoints();
        this->_hitPoints = assign.getHitPoints();
        this->_name = assign.getName();
    }
    return *this;
}

void FragTrap::highFivesGuys()
{
    std::cout << "FragTrap " << _name << ": Let's make a high five guys!" << std::endl;
}
