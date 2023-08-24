#ifndef DIAMONDTRAP
#define DIAMONDTRAP

#include <iostream>
#include <string>
#include <stdint.h>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
public:
    DiamondTrap(std::string &name);
    DiamondTrap(const DiamondTrap &copy);
    virtual ~DiamondTrap();
    DiamondTrap &operator=(const DiamondTrap &assign);
    void attack(std::string const &target);
    void whoAmI();

private:
    std::string _name;
    DiamondTrap();
};

#endif