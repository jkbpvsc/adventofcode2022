#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum move
{
    ROCK,
    PAPER,
    SCISSORS
} Move_t;

typedef enum outcome
{
    WIN,
    LOSE,
    DRAW
} Outcome_t;

/// @brief Returns the score outcome for a game of RPS
/// @param opp Opponents move
/// @param our Our move
/// @return Result (0 Loss, 3 Draw, 6 Win)
int get_score_for_game_outcome(Move_t opp, Move_t our)
{
    if (opp == our)
    {
        return 3;
    }

    if (opp == ROCK && our == PAPER || opp == PAPER && our == SCISSORS || opp == SCISSORS && our == ROCK)
    {
        return 6;
    }
    else
    {
        return 0;
    }
}

int get_score_for_move(Move_t move)
{
    switch (move)
    {
    case ROCK:
        return 1;
    case PAPER:
        return 2;
    case SCISSORS:
        return 3;
    }
}

int calc_score_for_game(Move_t opp, Move_t our)
{
    unsigned int score = 0;

    score += get_score_for_move(our);
    score += get_score_for_game_outcome(opp, our);

    return score;
}

Move_t get_move_for_outcome(Move_t opp, Outcome_t outcome)
{
    switch (outcome)
    {
    case DRAW:
        return opp;

    case WIN:
        switch (opp)
        {
        case ROCK:
            return PAPER;
        case PAPER:
            return SCISSORS;
        case SCISSORS:
            return ROCK;
        }
    case LOSE:
        switch (opp)
        {
        case ROCK:
            return SCISSORS;
        case PAPER:
            return ROCK;
        case SCISSORS:
            return PAPER;
        }
    }
}

Move_t parse_move(char move)
{
    switch (move)
    {
    case 'A':
        return ROCK;
    case 'B':
        return PAPER;
    case 'C':
        return SCISSORS;
    default:
        printf("Cannot parse move %c", move);
        exit(1);
    }
}

/// @brief Returns outcome type for a char (X - lose, Y - draw, Z - win)
/// @param outcome
/// @return
Outcome_t parse_outcome(char outcome)
{
    switch (outcome)
    {
    case 'X':
        return LOSE;
    case 'Y':
        return DRAW;
    case 'Z':
        return WIN;
    default:
        printf("Cannot parse outcome %c", outcome);
        exit(1);
    }
}

int parse_and_calc_score_for_game(char opp_move, char outcome)
{
    Move_t opp = parse_move(opp_move);
    Outcome_t out = parse_outcome(outcome);

    Move_t our = get_move_for_outcome(opp, out);

    return calc_score_for_game(opp, our);
}

int main()
{
    FILE *file_ptr;
    char line[10];

    file_ptr = fopen("input.txt", "r");

    if (file_ptr == NULL)
    {
        printf("Error opening file");
        return 1;
    }

    unsigned int score = 0;

    while (fgets(line, 10, file_ptr) != NULL)
    {
        char op_move = line[0];
        char your_move = line[2];

        score += parse_and_calc_score_for_game(op_move, your_move);
    }

    printf("Final score: %u\n", score);
}