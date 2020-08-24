#include <iostream>
#include <iterator>
#include <cstring>
using namespace std;
/**
 * Returns the neighbours of a game state.
 * @param state: the game state
 * @return: Array of all neighbours
 */
int** getNeighbours(int* state);

/**
 * Helper function which prints a game state to the command line.
 * @param state: the game state
 */
void printGameState(int * state);

/**
 * Returns the index of the empty tile of a game state .
 * @param state: the game state
 * @return: The index of the empty tile/0
 */
int findZero (int* state);

/**
 * Helper function that finds the neighbour of a game state, where the empty tile is moved to the left.
 * @param state: the game state
 * @return: the left neighbour
 */
int * getLeftNeighbour(int* state);

/**
 * Helper function that finds the neighbour of a game state, where the empty tile is moved to the right.
 * @param state: the game state
 * @return: the right neighbour
 */
int * getRightNeighbour(int* state);

/**
 * Helper function that finds the neighbour of a game state, where the empty tile is moved up.
 * @param state: the game state
 * @return: the upper neighbour
 */
int * getUpNeighbour(int* state);

/**
 * Helper function that finds the neighbour of a game state, where the empty tile is moved down.
 * @param state: the game state
 * @return: the lower neighbour
 */
int * getDownNeighbour(int* state);

/**
 * Finds the scores for all game states in an array.
 * @param arr: the Array of game states
 * @return: an array of all scores
 */
int * getNeighbourScores(int **arr);

/**
 * Finds the score for a game state.
 * @param state: the game state
 * @return: the score
 */
int getScore(int *state);

/**
 * Starting from a given game state, this function loops through the neighbours in a greedy local search until no neigh-
 * bour with a better score is found.
 * @return: return code
 */
int main() {
    int curr[16] = {0, 13, 15, 7, 11, 12, 9, 5, 6, 14, 2, 1, 4, 8, 10, 3};
    int curr_score = getScore(curr);
    while (true) {
        printGameState(curr);
        int** neighbours = getNeighbours(curr);
        int * neighbour_scores = getNeighbourScores(neighbours);
        int index = -1;
        for (int i = 0; i < 4; i++){
            if (neighbour_scores[i] > curr_score){
                curr_score = neighbour_scores[i];
                index = i;
            }
            printGameState(neighbours[i]);
            cout << "\nScore: " << neighbour_scores[i] << "\n";
        }
        if (index == -1){
            break;
        }
        for (int i = 0; i<16; i++){
            curr[i] = neighbours[index][i];
        }
    }
    return 0;
}

int** getNeighbours(int* state) {
    int** r = new int*[4];
    r[0] = getLeftNeighbour(state);
    r[1] = getRightNeighbour(state);
    r[2] = getUpNeighbour(state);
    r[3] = getDownNeighbour(state);
    return r ;
}
int * getLeftNeighbour(int* state) {
    int * r = new int[16];
    memcpy(r, state, 16* sizeof(int));
    int pos = findZero(r);
    if (pos % 4 == 0){
        return nullptr;
    }
    r[pos] = r[pos -1];
    r[pos - 1] = 0;
    return r;

}
int * getRightNeighbour(int* state) {
    int * r = new int[16];
    memcpy(r, state, 16* sizeof(int));
    int pos = findZero(r);
    if (pos % 4 == 3){
        return nullptr;
    }
    r[pos] = r[pos + 1];
    r[pos + 1] = 0;
    return r;

}
int * getUpNeighbour(int* state) {
    int * r = new int[16];
    memcpy(r, state, 16* sizeof(int));
    int pos = findZero(r);
    if (pos < 4){
        return nullptr;
    }
    r[pos] = r[pos -4];
    r[pos - 4] = 0;
    return r;
}
int * getDownNeighbour(int* state) {
    int * r = new int[16];
    memcpy(r, state, 16* sizeof(int));
    int pos = findZero(r);
    if (pos > 11) {
        return nullptr;
    }
    r[pos] = r[pos + 4];
    r[pos + 4] = 0;
    return r;
}


int findZero (int* state) {
    int r = 0;
    for (int i = 0; i < 16; i++){
        if (state[i] == 0){
            r = i;
            break;
        }
    }
    return r;
}
int * getNeighbourScores(int **arr) {
    int* r = new int[4];
    for (int i = 0; i <4; i++){
        r[i] = getScore(arr[i]);
    }
    return r;
}
int getScore(int *state) {
    //This method is where we will measure the time the solver needs for a neighbour.
    if (state == nullptr){
        return -1;
    }
    return (rand()%100) + 1;
}

void printGameState(int* state) {
    if (state == nullptr){
        return;
    }
    cout << '\n';
    for (int i = 0; i < 4; i++){
        cout << '|';
        for (int j = 0; j <4; j++){
            cout << state[i*4 + j];
            cout << " ";
        }
        cout << "|\n";
    }
}
