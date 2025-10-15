 #ifndef MOMENTUM_METER_SYSTEM_H
#define MOMENTUM_METER_SYSTEM_H

#include <string>
#include <vector>
using namespace std;

// ---------------- GAME CLASS ----------------
class MomentumMeter;
class Team;
class GameEvent;

class Game {
private:
    int gameTime;
    vector<Team> teams;
    MomentumMeter* momentumMeter;

public:
    Game();
    void startGame();
    void updateGameState();
    void endGame();

    int getGameTime() const;
    vector<Team> getTeams() const;
    MomentumMeter* getMomentumMeter() const;
};

// ---------------- TEAM CLASS ----------------
class Player;

class Team {
private:
    string teamName;
    vector<Player> players;
    int score;
    double momentumLevel;

public:
    Team(string name);
    void updateScore(int points);
    void updateMomentum(double change);
    void resetMomentum();

    string getTeamName() const;
    int getScore() const;
    double getMomentumLevel() const;
    vector<Player> getPlayers() const;
};

// ---------------- PLAYER CLASS ----------------
class Player {
private:
    string playerName;
    string position;
    double performanceRating;

public:
    Player(string name, string pos);
    void updatePerformance(double newRating);
    void applyBoost(double boostValue);

    string getPlayerName() const;
    string getPosition() const;
    double getPerformanceRating() const;
};

// ---------------- MOMENTUM METER CLASS ----------------
class MomentumMeter {
private:
    double momentumValue;
    double thresholds[3];
    Team* activeTeam;

public:
    MomentumMeter();
    void increaseMomentum(string eventType);
    void decreaseMomentum(string eventType);
    void applyBoost(Team* team);

    double getMomentumValue() const;
    Team* getActiveTeam() const;
};

// ---------------- GAME EVENT CLASS ----------------
class GameEvent {
private:
    string eventType;
    Team* teamInvolved;
    double impactScore;
    double timestamp;

public:
    GameEvent(string type, Team* team, double time);
    double calculateImpact();
    void notifyMomentumMeter(MomentumMeter* meter);
};

// ---------------- CROWD REACTION CLASS ----------------
class CrowdReaction {
private:
    double crowdNoiseLevel;
    string emotionState;

public:
    CrowdReaction();
    void updateCrowdSound(double momentumValue);
    void displayVisualFeedback();
};

// ---------------- COMMENTARY SYSTEM CLASS ----------------
class CommentarySystem {
private:
    string currentTone;
    vector<string> scriptPool;

public:
    CommentarySystem();
    void triggerCommentary(string eventType, double momentumValue);
};

// ---------------- UI MANAGER CLASS ----------------
class UIManager {
private:
    string colorScheme;
    double animationState;

public:
    UIManager();
    void updateUI(double momentumValue);
    void animateTransition();
};

#endif
