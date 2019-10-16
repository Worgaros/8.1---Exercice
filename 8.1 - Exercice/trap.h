#pragma once

class Trap
{
	public:
		Trap();
		int make_damages();
	
	private:
		int damage_points_ = 1;
};