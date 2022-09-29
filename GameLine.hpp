#include <string>
#include <map>
using std::string;
class GameLine {
public:
	
	struct GameState{
		int end;
		GameState* left;
		GameState* right;
		std::string text;
		std::string choice_left;
		std::string choice_right; 
	}*currState;
	std::map<std::string, GameState*>states;
	GameLine(){}
	~GameLine(){}
	int go_left();
	int go_right();
	int add_state(std::string, GameState*);
	int link_state(std::string state1, std::string state2, int right);
};