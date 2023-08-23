#ifndef SCAVTRAP
#define SCAVTRAP

#include <iostream>
#include <string>
#include <stdint.h>
#include "ClapTrap.hpp"

class ScavTrap
public:
    // Constructors
    ScavTrap(std::string name);
    ScavTrap(const ScavTrap &copy);
    ~ScavTrap();
    ScavTrap &operator=(const ScavTrap &assign);
    void attack(std::string const &target);
    void takeDamage(uint32_t amout);
    void beRepaired(uint32_t amout);

    const std::string &getName() const;
    const uint32_t &getHitPoints() const;
    const uint32_t &getEnergyPoints() const;
    const uint32_t &getAttackDamage() const;

    void setName(std::string &name);
    void setHitPoints(uint32_t hitPoints);
    void setEnergyPoints(uint32_t energyPoints);
    void setAttackDamage(uint32_t attackDamage);

private:
    ScavTrap();
    std::string _name;
    uint32_t _hitPoints;
    uint32_t _energyPoints;
    uint32_t _attackDamage;
};

#endif