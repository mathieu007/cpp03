#include "ClapTrap.hpp"

// Constructors
// ClapTrap::ClapTrap()
// {
//     std::cout << "Default Constructor called" << std::endl;
// }

ClapTrap::ClapTrap(const ClapTrap &copy)
{
    std::cout << "\033[32mClapTrap " << copy._name << " copy constructor called\033[0m" << std::endl;
    *this = copy;
}

ClapTrap::ClapTrap(std::string &name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "\033[32mClapTrap " << _name << " constructor called\033[0m" << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "\033[31mClapTrap " << _name << " destructor called\033[0m" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &assign)
{
    std::cout << "\033[33mClapTrap " << assign.getName() << " copy assignment operator called\033[0m" << std::endl;
    if (this != &assign)
    {
        this->_attackDamage = assign.getAttackDamage();
        this->_energyPoints = assign.getEnergyPoints();
        this->_hitPoints = assign.getHitPoints();
        this->_name = assign.getName();
    }
    return *this;
}

const std::string &ClapTrap::getName() const
{
    return (_name);
}

const uint32_t &ClapTrap::getHitPoints() const
{
    return (_hitPoints);
}

const uint32_t &ClapTrap::getEnergyPoints() const
{
    return (_energyPoints);
}

const uint32_t &ClapTrap::getAttackDamage() const
{
    return (_attackDamage);
}

void ClapTrap::setHitPoints(uint32_t hitPoints)
{
    _hitPoints = hitPoints;
}

void ClapTrap::setEnergyPoints(uint32_t energyPoints)
{
    _energyPoints = energyPoints;
}

void ClapTrap::setAttackDamage(uint32_t attackDamage)
{
    _attackDamage = attackDamage;
}

void ClapTrap::attack(std::string const &target)
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

void ClapTrap::takeDamage(uint32_t amout)
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

void ClapTrap::beRepaired(uint32_t amout)
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
