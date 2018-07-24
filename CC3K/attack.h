
enum Result {attack, death, miss};
enum Type {increaseATK, decreaseATK, increaseDEF, decreaseDEF, increaseHP, decreaseHP};

struct Attack {
    double dmg;
    double health;
    Result res; 
};

struct Potion {
    double before;
    double after;
    Type type;
};
