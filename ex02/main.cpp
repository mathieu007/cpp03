#include <iostream>
#include "FragTrap.hpp"
#include <unistd.h>

static void CallConstructor(std::string &ctName)
{
    std::cout
        << "--Before calling Constructor FragTrap " << ctName << ""
        << std::endl;
    FragTrap ct(ctName);
    std::cout
        << "--After calling Constructor FragTrap " << ctName << std::endl
        << std::endl;
}

static void CallConstructorCopy(std::string &ctName)
{
    FragTrap ct2 = FragTrap(ctName);
    std::cout << "--Before calling Copy Constructor FragTrap " << ctName << "" << std::endl;
    FragTrap ct = FragTrap(ct2);
    std::cout << "--After calling Copy Constructor FragTrap " << ctName << "" << std::endl
              << std::endl;
}

static void CallAssignCopyConstructor(std::string &ctName)
{
    FragTrap ct = FragTrap(ctName);
    FragTrap ct2 = FragTrap(ctName);

    std::cout
        << "--Before calling assign Copy operator FragTrap "
        << "" << std::endl;
    ct = ct2;
    std::cout << "--After calling assign Copy operator FragTrap "
              << "" << std::endl
              << std::endl;
}

static void AttackTakeDamageRepair(std::string &ctName, std::string &other, uint32_t attackDamage, uint32_t takeDamage, uint32_t beRepaired)
{
    FragTrap ct(ctName);

    ct.setAttackDamage(attackDamage);
    std::cout << std::endl;
    ct.highFivesGuys();

    std::cout << "hp: " << ct.getHitPoints() << ", energy: " << ct.getEnergyPoints() << std::endl;
    while (ct.getHitPoints() != 0 && ct.getEnergyPoints() != 0)
    {
        ct.attack(other);
        std::cout << "hp: " << ct.getHitPoints() << ", energy: " << ct.getEnergyPoints() << std::endl
                  << std::endl;
        ct.takeDamage(takeDamage);
        std::cout << "hp: " << ct.getHitPoints() << ", energy: " << ct.getEnergyPoints() << std::endl
                  << std::endl;
        ct.beRepaired(beRepaired);
        std::cout << "hp: " << ct.getHitPoints() << ", energy: " << ct.getEnergyPoints() << std::endl
                  << std::endl;
    }
    ct.highFivesGuys();
    ct.attack(other);
    std::cout << "hp: " << ct.getHitPoints() << ", energy: " << ct.getEnergyPoints() << std::endl
              << std::endl;
    ct.takeDamage(takeDamage);
    std::cout << "hp: " << ct.getHitPoints() << ", energy: " << ct.getEnergyPoints() << std::endl
              << std::endl;
    ct.beRepaired(beRepaired);
    std::cout << "--hp: " << ct.getHitPoints() << ", energy: " << ct.getEnergyPoints() << std::endl
              << std::endl;
}

int32_t main(void)
{
    std::string math = "Math";
    std::string bob = "Bob";
    {
        CallConstructor(math);
        usleep(500);
        CallConstructorCopy(math);
        usleep(500);
        CallAssignCopyConstructor(math);
        usleep(500);
    }
    {
        uint32_t attackDamage = 20;
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
    {
        uint32_t attackDamage = 25;
        uint32_t takeDamage = 43;
        uint32_t beRepaired = 50;

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
    {
        uint32_t attackDamage = 10;
        uint32_t takeDamage = 30;
        uint32_t beRepaired = 5;

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
    {
        uint32_t attackDamage = 15;
        uint32_t takeDamage = 35;
        uint32_t beRepaired = 12;

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
