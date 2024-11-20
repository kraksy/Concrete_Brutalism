
#include <Core.h>

class Player
{
public:
    int posX;
    int posY;
    
    int health;

    Player(int hp, int x, int y);
    ~Player();

    void AddHP(int health);
};

Player::Player(
    int hp,
    int x, 
    int y)
{
    health = hp;
    posX = x;
    posY = y;
}

Player::~Player()
{
}
