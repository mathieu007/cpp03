#ifndef FRAGTRAP
#define FRAGTRAP

#include <iostream>
#include <string>
#include <stdint.h>
#include "ClapTrap.hpp"

class FragTrap : public virtual ClapTrap
{
public:
    // Constructors
    FragTrap(std::string &name);
    FragTrap(const FragTrap &copy);
    virtual ~FragTrap();
    FragTrap &operator=(const FragTrap &assign);
    void highFivesGuys(void);

private:
    FragTrap();
};

#endif