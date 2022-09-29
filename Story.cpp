#include "GameLine.hpp"
#include "Story.hpp"
#include <iostream>
void create_story(GameLine* game_line) {
	GameLine::GameState* currState = game_line->currState;
	game_line->add_state("start", currState);
	currState->text = "												STUPID GAME";
	currState->choice_left = "start"; 
	currState->choice_right = "exit";
	
	GameLine::GameState* s1 = new GameLine::GameState();
	game_line->add_state("s1", s1);
	s1->text = "On a dark and windy night, you are walking home alone. Suddenly, a wild monster appears on your back. ";
	game_line->link_state("start", "s1", 0);
	s1->choice_left = "Fight him with your butt";
	s1->choice_right = "Pee on your pants";

	GameLine::GameState* s2 = new GameLine::GameState();
	game_line->add_state("s2", s2);
	s2->text = "The monster is not hurt but enraged.";
	game_line->link_state("s1", "s2", 0);
	s2->choice_left = "Continue fighting him with your butt .";
	s2->choice_right = "Run!!";

	GameLine::GameState* s3 = new GameLine::GameState();
	game_line->add_state("s3", s3);
	s3->text = "Your butt does no damage to monster and he killed you in 1 hit. Game Over.";
	game_line->link_state("s2", "s3", 0);
	s3->choice_left = "";
	s3->choice_right = "";

	GameLine::GameState* s4 = new GameLine::GameState();
	game_line->add_state("s4", s4);
	s4->text = "The monster runs much faster than you and he killed you in 1 hit. Game Over.";
	game_line->link_state("s2", "s4", 1);
	s4->choice_left = "";
	s4->choice_right = "";

	GameLine::GameState* s5 = new GameLine::GameState();
	game_line->add_state("s5", s5);
	s5->text = "You disgusted the monster and he runs away. You are save!";
	game_line->link_state("s1", "s5", 1);
	s5->choice_left = "";
	s5->choice_right = "";
}