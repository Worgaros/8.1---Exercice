#pragma once

#include <iostream>

class Player
{
	public:
		int posX = 1;
		int posY = 2;
		int newPosX = posX;
		int newPosY = posY;
		std::string userInput;
		Player();
		void take_damages(int damage);
		void take_heal(int heal);
		void set_new_position(int obstacle, int heal, int damage);
		int calc_new_pos();
		void print_player_stats();
		void death(bool& isRunning);
		bool ask_take_potion(int heal);
		void win(bool& isRunning, int obstacle);
	
	private:
		int healthPoints_ = 3;
		const int maxHealthPoints_ = 1000;
		int keys_ = 0;
};
