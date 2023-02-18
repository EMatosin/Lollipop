typedef struct GameHistory GameHistory;

struct GameHistory {
    int bet;
    int nb_sticks;
    float total;
    GameHistory* next;
};

GameHistory* create_history(int bet, int nb_sticks, float total);

void update_history(GameHistory** head, GameHistory** tail, int bet, int nb_sticks, float total);

void SaveGames(GameHistory* head, const char *filename);

void free_list(GameHistory* head);
