#ifndef SCAVTRAP
#define SCAVTRAP

#include <iostream>
#include <string>
#include <stdint.h>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
public:
    // Constructors
    ScavTrap(std::string &name);
    ScavTrap(const ScavTrap &copy);
    virtual ~ScavTrap();
    ScavTrap &operator=(const ScavTrap &assign);
    // cpp11++ need override keyword
    //  void attack(std::string const &target) override;
    virtual void attack(std::string const &target);
    void guardGate();

private:
    bool _guardGate;
    ScavTrap();
};

#endif