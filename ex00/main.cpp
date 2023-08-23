#include <iostream>
#include "ClapTrap.hpp"

static void AttackTakeDamageRepair(std::string &ctName, std::string &other, uint32_t attackDamage, uint32_t takeDamage, uint32_t beRepaired)
{
    ClapTrap ct(ctName);
    ct.setAttackDamage(attackDamage);
    std::cout << std::endl;
    std::cout << "--hitPoints: " << ct.getHitPoints() << " energyPoints: " << ct.getEnergyPoints() << std::endl;
    while (ct.getHitPoints() != 0 && ct.getEnergyPoints() != 0)
    {
        ct.attack(other);
        std::cout << "--hitPoints: " << ct.getHitPoints() << " energyPoints: " << ct.getEnergyPoints() << std::endl;
        ct.takeDamage(takeDamage);
        std::cout << "--hitPoints: " << ct.getHitPoints() << " energyPoints: " << ct.getEnergyPoints() << std::endl;
        ct.beRepaired(beRepaired);
        std::cout << "--hitPoints: " << ct.getHitPoints() << " energyPoints: " << ct.getEnergyPoints() << std::endl;
    }
    ct.attack(other);
    std::cout << "--hitPoints: " << ct.getHitPoints() << " energyPoints: " << ct.getEnergyPoints() << std::endl;
    ct.takeDamage(takeDamage);
    std::cout << "--hitPoints: " << ct.getHitPoints() << " energyPoints: " << ct.getEnergyPoints() << std::endl;
    ct.beRepaired(beRepaired);
    std::cout << "--hitPoints: " << ct.getHitPoints() << " energyPoints: " << ct.getEnergyPoints() << std::endl;
}

int32_t main(void)
{
    std::string math = "Math";
    std::string bob = "Bob";
    std::string julia = "Julia";
    std::string mark = "Mark";
    std::string simon = "Simon";
    std::string clark = "Clark";

    {
        uint32_t attackDamage = 1;
        uint32_t takeDamage = 9;
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
        uint32_t attackDamage = 1;
        uint32_t takeDamage = 1;
        uint32_t beRepaired = 10;

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
        uint32_t takeDamage = 6;
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
        uint32_t attackDamage = 10;
        uint32_t takeDamage = 7;
        uint32_t beRepaired = 4;

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
