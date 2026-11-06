#include "gun.h"
#include <iostream>

Gun::Gun() : ammo(5) {}

Gun::Gun(int ammo) : ammo(ammo) {}

void Gun::shoot() {
    if (ammo > 0) {
        std::cout << "Бах!\n";
        --ammo;
    } else {
        std::cout << "Клац!\n";
    }
}

void Gun::print() const {
    std::cout << "Остаток патронов: " << ammo << "\n";
}