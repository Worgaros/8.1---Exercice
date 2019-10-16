#pragma once

class Potion
{
	public:
		Potion();
		int heal_player();
		
	private:
		int healing_points_ = 5;
};