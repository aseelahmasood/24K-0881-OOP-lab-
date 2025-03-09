#include <iostream>
using namespace std;

class Level {
private:
    string name;
    int difficulty;
public:
    Level(string lvlName, int lvlDifficulty) : name(lvlName), difficulty(lvlDifficulty) {}
    void display() {
        cout << "Level: " << name << ", Difficulty: " << difficulty << endl;
    }
};

class VideoGame {
private:
    string title;
    string genre;
    Level* levels[10];
    int levelCount;
public:
    VideoGame(string gameTitle, string gameGenre) : title(gameTitle), genre(gameGenre), levelCount(0) {}
    ~VideoGame() {
        for (int i = 0; i < levelCount; i++) delete levels[i];
    }
    void addLevel(string lvlName, int lvlDifficulty) {
        if (levelCount < 10) {
            levels[levelCount++] = new Level(lvlName, lvlDifficulty);
        }
    }
    void display() {
        cout << "Game: " << title << " (" << genre << ")" << endl;
        for (int i = 0; i < levelCount; i++) levels[i]->display();
    }
};

int main() {
    VideoGame game("Adventure Quest", "RPG");
    game.addLevel("Forest", 2);
    game.addLevel("Dungeon", 5);
    game.display();
    return 0;
}
