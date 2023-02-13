typedef struct GameHistory GameHistory;

struct GameHistory {
    int bet;
    int nb_sticks;
    int total;
    GameHistory* next;
};

GameHistory* create_history(int bet, int nb_sticks, int total);

void update_history(GameHistory** head, GameHistory** tail, int bet, int nb_sticks, int total);

void free_list(GameHistory* head);
