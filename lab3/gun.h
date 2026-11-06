#ifndef GUN_H
#define GUN_H

class Gun {
public:
    Gun();
    explicit Gun(int ammo);

    void shoot();
    void print() const;

private:
    int ammo;
};

#endif