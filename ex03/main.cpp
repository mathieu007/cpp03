#include <iostream>
#include <unistd.h>
#include <fstream>
#include "DiamondTrap.hpp"

static void DisableCout()
{
    std::cout.setstate(std::ios_base::failbit);
}

static void EnableCout()
{
    std::cout.clear();
}

static void CallConstructor(std::string &ctName)
{
    std::cout
        << "--Before calling Constructor " << ctName << ""
        << std::endl;
    DiamondTrap ct(ctName);
    std::cout
        << "--After calling Constructor " << ctName << std::endl
        << std::endl;
    std::cout
        << "--Before calling Destructor" << ctName << "" << std::endl;
}

static void CallConstructorCopy(std::string &ctName)
{
    DisableCout();
    DiamondTrap *ct2 = new DiamondTrap(ctName);
    EnableCout();
    std::cout
        << "--Before calling Copy Constructor " << ctName << "" << std::endl;
    DiamondTrap ct = DiamondTrap(*ct2);
    std::cout << "--After calling Copy Constructor " << ctName << "" << std::endl
              << std::endl;
    DisableCout();
    delete ct2;
    EnableCout();
    std::cout
        << "--Before calling Destructor" << ctName << "" << std::endl;
}

static void CallAssignCopyConstructor(std::string &ctName)
{
    DisableCout();
    DiamondTrap *ct = new DiamondTrap(ctName);
    DiamondTrap *ct2 = new DiamondTrap(ctName);
    EnableCout();
    std::cout
        << "--Before calling assign Copy operator "
        << "" << std::endl;
    *ct = *ct2;
    std::cout << "--After calling assign Copy operator "
              << "" << std::endl
              << std::endl;
    DisableCout();
    delete ct;
    delete ct2;
    EnableCout();
}

static void AttackTakeDamageRepair(std::string &ctName, std::string &other, uint32_t attackDamage, uint32_t takeDamage, uint32_t beRepaired)
{
    DiamondTrap *ct = new DiamondTrap(ctName);
    ct->setAttackDamage(attackDamage);
    std::cout << std::endl;
    ct->whoAmI();
    ct->guardGate();
    ct->highFivesGuys();

    std::cout << "hp: " << ct->getHitPoints() << ", energy: " << ct->getEnergyPoints() << std::endl;
    while (ct->getHitPoints() != 0 && ct->getEnergyPoints() != 0)
    {
        ct->attack(other);
        std::cout << "hp: " << ct->getHitPoints() << ", energy: " << ct->getEnergyPoints() << std::endl
                  << std::endl;
        ct->takeDamage(takeDamage);
        std::cout << "hp: " << ct->getHitPoints() << ", energy: " << ct->getEnergyPoints() << std::endl
                  << std::endl;
        ct->beRepaired(beRepaired);
        std::cout << "hp: " << ct->getHitPoints() << ", energy: " << ct->getEnergyPoints() << std::endl
                  << std::endl;
    }
    ct->highFivesGuys();
    ct->guardGate();
    ct->whoAmI();
    ct->attack(other);
    std::cout << "hp: " << ct->getHitPoints() << ", energy: " << ct->getEnergyPoints() << std::endl
              << std::endl;
    ct->takeDamage(takeDamage);
    std::cout << "hp: " << ct->getHitPoints() << ", energy: " << ct->getEnergyPoints() << std::endl
              << std::endl;
    ct->beRepaired(beRepaired);
    std::cout << "--hp: " << ct->getHitPoints() << ", energy: " << ct->getEnergyPoints() << std::endl
              << std::endl;
    delete ct;
}

int32_t main(void)
{
    std::string math = "Math";
    std::string bob = "Bob";
    {
        CallConstructor(math);
        std::cout
            << "--After calling Destructor " << math << "" << std::endl
            << std::endl;
        CallConstructorCopy(math);
        std::cout
            << "--After calling Destructor " << math << "" << std::endl
            << std::endl;
        CallAssignCopyConstructor(math);
    }
    {
        uint32_t attackDamage = 30;
        uint32_t takeDamage = 45;
        uint32_t beRepaired = 2;

        std::cout
            << std::endl
            << "Routine values: attackDamage:"
            << attackDamage
            << " takeDamage:"
            << takeDamage
            << " beRepaired:"
            << beRepaired << std::endl;
        AttackTakeDamageRepair(math, bob, attackDamage, takeDamage, beRepaired);
    }
    return 0;
}
