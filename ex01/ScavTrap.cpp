#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy)
{
    std::cout << "\033[35mScavTrap " << copy.getName() << " copy Constructor called\033[0m" << std::endl;
    *this = copy;
}

ScavTrap::ScavTrap(std::string &name) : ClapTrap(name), _guardGate(false)
{
    std::cout << "\033[35mScavTrap " << name << " constructor called\033[0m" << std::endl;
    this->_attackDamage = 20;
    this->_energyPoints = 50;
    this->_hitPoints = 100;
}

ScavTrap::~ScavTrap()
{
    std::cout << "\033[33mScavTrap " << _name << " destructor called\033[0m" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &assign)
{
    std::cout << "\033[33mScavTrap " << assign.getName() << " copy assignment operator called\033[0m" << std::endl;
    if (this != &assign)
    {
        this->_attackDamage = assign.getAttackDamage();
        this->_energyPoints = assign.getEnergyPoints();
        this->_hitPoints = assign.getHitPoints();
        this->_name = assign.getName();
        this->_guardGate = assign._guardGate;
    }
    return *this;
}

/// @brief need override keyword in cpp11++
/// @param target
void ScavTrap::attack(std::string const &target)
{
    if (_hitPoints == 0)
        std::cout << "ScavTrap " << _name << " cannot attack, is dead!" << std::endl;
    else if (_energyPoints > 0 && _hitPoints > 0)
    {
        std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
        _energyPoints--;
    }
    else if (_energyPoints == 0)
        std::cout << "ScavTrap " << _name << " does not have enough energy to attack!" << std::endl;
}

void ScavTrap::guardGate()
{
    if (_hitPoints == 0)
        std::cout << "ScavTrap " << _name << " cannot enter Gate keeper mode, is dead!" << std::endl;
    else if (_guardGate)
        std::cout << "ScavTrap " << _name << " cannot enter Gate keeper mode, is already in Gate keeper Mode!" << std::endl;
    else
        std::cout << "ScavTrap " << _name << " has entered Gate keeper mode!" << std::endl;
    _guardGate = true;
}
