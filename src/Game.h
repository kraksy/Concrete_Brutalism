
#ifndef SMOLGAME_GAME_H
#define SMOLGAME_GAME_H

class Game {
public:
    Game();
    ~Game();
    static bool init();
    static void run();
    static void exit();
};

#endif //SMOLGAME_GAME_H