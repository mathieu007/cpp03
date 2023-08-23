#include "ScavTrap.hpp"

// ClapTrap::ClapTrap()
// {

//     std::cout << "Default Constructor called" << std::endl;
// }

ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy)
{
    std::cout << "ClapTrap Copy Constructor called" << std::endl;
    *this = copy;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(copy), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    _name = name;
    std::cout << "ClapTrap name Constructor called" << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ClapTrap Destructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &assign)
{
    std::cout << "Copy assignment operator called" << std::endl;
    this->_attackDamage = assign.getAttackDamage();
    this->_energyPoints = assign.getEnergyPoints();
    this->_hitPoints = assign.getHitPoints();
    this->_name = assign.getName();
    return *this;
}

const std::string &ScavTrap::getName() const
{
    return (_name);
}

const uint32_t &ScavTrap::getHitPoints() const
{
    return (_hitPoints);
}

const uint32_t &ScavTrap::getEnergyPoints() const
{
    return (_energyPoints);
}

const uint32_t &ScavTrap::getAttackDamage() const
{
    return (_attackDamage);
}

void ScavTrap::setHitPoints(uint32_t hitPoints)
{
    _hitPoints = hitPoints;
}

void ScavTrap::setEnergyPoints(uint32_t energyPoints)
{
    _energyPoints = energyPoints;
}

void ScavTrap::setAttackDamage(uint32_t attackDamage)
{
    _attackDamage = attackDamage;
}

void ScavTrap::attack(std::string const &target)
{
    if (_hitPoints == 0)
        std::cout << "ClapTrap " << _name << " cannot attack, is dead!" << std::endl;
    else if (_energyPoints > 0 && _hitPoints > 0)
    {
        std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
        _energyPoints--;
    }
    else if (_energyPoints == 0)
        std::cout << "ClapTrap " << _name << " does not have enough energy to attack!" << std::endl;
}

void ScavTrap::takeDamage(uint32_t amout)
{
    if (_hitPoints == 0)
    {
        std::cout << "ClapTrap " << _name << " cannot take anymore damage, is dead!" << std::endl;
        return;
    }
    int32_t damageTaken = 0;
    if (amout > _hitPoints)
        damageTaken = _hitPoints;
    else
        damageTaken = amout;
    _hitPoints -= damageTaken;
    std::cout << "ClapTrap " << _name << " has taken " << damageTaken << " points of damage!" << std::endl;
    if (_hitPoints == 0)
        std::cout << "ClapTrap " << _name << " just die!" << std::endl;
}

void ScavTrap::beRepaired(uint32_t amout)
{
    if (_hitPoints == 0)
    {
        std::cout << "ClapTrap " << _name << " cannot be repaired, is dead!" << std::endl;
        return;
    }
    else if (_energyPoints == 0)
        std::cout << "ClapTrap " << _name << " cannot be repaired, do not have enough energy points!" << std::endl;
    else
    {
        std::cout << "ClapTrap " << _name << " have gain " << amout << " hit points!" << std::endl;
        _hitPoints += amout;
        _energyPoints--;
    }
}
