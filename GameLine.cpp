#include "GameLine.hpp"

int GameLine::go_left() {
	if (currState == nullptr) return -1;
	currState = currState->left;
	return 0;
}

int GameLine::go_right() {
	if (currState == nullptr) return -1;
	currState = currState->right;
	return 0;
}

int GameLine::add_state(std::string state_name, GameState* state) {
	states.insert({state_name, state});
	return 0;
}

int GameLine::link_state(std::string state1, std::string state2, int right) {

	if (states.find(state1) == states.end() || states.find(state2) == states.end())
		return -1;
	GameState* state_1 = states[state1];
	GameState* state_2 = states[state2];
	if (state_1 == nullptr) return -1;
	if (right)
		state_1->right = state_2;
	else
		state_1->left = state_2;
	return 0;
}