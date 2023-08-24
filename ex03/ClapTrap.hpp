#ifndef CLAPTRAP
#define CLAPTRAP

#include <iostream>
#include <string>
#include <stdint.h>

class ClapTrap
{
public:
    // Constructors
    ClapTrap(std::string &name);
    ClapTrap(const ClapTrap &copy);
    virtual ~ClapTrap();
    ClapTrap &operator=(const ClapTrap &assign);
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
    ClapTrap();

protected:
    std::string _name;
    uint32_t _hitPoints;
    uint32_t _energyPoints;
    uint32_t _attackDamage;
};

std::ostream &operator<<(std::ostream &stream, const ClapTrap &obj);

#endif