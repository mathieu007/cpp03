#include <iostream>
#include "ScavTrap.hpp"

static void AttackTakeDamageRepair(std::string &ctName, std::string &other, uint32_t attackDamage, uint32_t takeDamage, uint32_t beRepaired)
{
    std::cout << "\033[34m--Before calling Cosntructor ScavTrap " << ctName << ":\033[0m" << std::endl;
    ScavTrap ct(ctName);
    std::cout << "--After calling Cosntructor ScavTrap " << ctName << "\033[0m" << std::endl
              << std::endl;
    std::string ctName2 = ctName + "2";

    std::cout << "\033[34m--Before calling Cosntructor ScavTrap " << ctName2 << ":\033[0m" << std::endl;
    ScavTrap ct2 = ScavTrap(ctName2);
    std::cout << "--After calling Cosntructor ScavTrap " << ctName2 << "\033[0m" << std::endl
              << std::endl;

    std::cout << "\033[34m--Before calling Copy Cosntructor ScavTrap " << ctName2 << ":\033[0m" << std::endl;
    ScavTrap ct3 = ScavTrap(ct2);
    std::cout << "--After calling Copy Cosntructor ScavTrap " << ctName2 << "\033[0m" << std::endl
              << std::endl;

    std::cout << "\033[34m--Before calling assign Copy operator ScavTrap " << ctName << " to " << ctName2 << " :\033[0m" << std::endl;
    ct = ct2;
    std::cout << "--After calling assign Copy operator ScavTrap " << ctName << " to " << ctName2 << "\033[0m" << std::endl
              << std::endl;

    ct.setAttackDamage(attackDamage);
    std::cout << std::endl;
    ct.guardGate();
    ct.guardGate();
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
    ct.guardGate();
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
    // std::string julia = "Julia";
    // std::string mark = "Mark";
    // std::string simon = "Simon";
    // std::string clark = "Clark";

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
