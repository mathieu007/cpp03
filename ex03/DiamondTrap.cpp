#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(const DiamondTrap &copy) : ClapTrap(copy), FragTrap(copy), ScavTrap(copy)
{
    std::cout << "\033[35mDiamondTrap " << copy.getName() << " copy Constructor called\033[0m" << std::endl;
    *this = copy;
}

DiamondTrap::DiamondTrap(std::string &name) : ClapTrap(name), FragTrap(name), ScavTrap(name), _name(name)
{
    std::cout << "\033[35mDiamondTrap " << name << " constructor called\033[0m" << std::endl;
    ClapTrap::_name = name + "_clap_trap";
    this->_attackDamage = ScavTrap::_attackDamage;
    this->_energyPoints = ScavTrap::_energyPoints;
    this->_hitPoints = FragTrap::_hitPoints;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "\033[33mDiamondTrap " << _name << " destructor called\033[0m" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &assign)
{
    std::cout << "\033[33mDiamondTrap " << assign.getName() << " copy assignment operator called\033[0m" << std::endl;
    if (this != &assign)
    {
        this->_guardGate = assign._guardGate;
        this->_name = assign._name;
        this->_attackDamage = assign._attackDamage;
        this->_energyPoints = assign._energyPoints;
        this->_hitPoints = assign._hitPoints;
    }
    return *this;
}

void DiamondTrap::attack(std::string const &target)
{
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
    std::cout << "Hello, i am derived class DiamondTrap:" << _name << std::endl;
    std::cout << "And i am derived from the base class ClapTrap :" << ClapTrap::_name << std::endl;
}