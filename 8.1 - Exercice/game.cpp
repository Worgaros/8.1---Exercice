#include "game.h"
#include "map.h"
#include "player.h"
#include "potion.h"
#include "trap.h"
#include "sprite.h"

void run()
{
	bool isRunning = true;
	Player playerStats = Player();
	Map map = Map(playerStats.posX, playerStats.posY);
	Potion potionStats = Potion();
	Trap trapStats = Trap();
	int heal = potionStats.heal_player();
	int damage = trapStats.make_damages();

	introduction_text();
	
	while (isRunning)
	{
		map.print_map();
		playerStats.print_player_stats();
		int showTrap = playerStats.calc_new_pos();
		map.visible_trap(showTrap);
		int obstacle = map.check_obstacle(playerStats.newPosX, playerStats.newPosY);
		map.set_new_player_pos(obstacle, playerStats.posX, playerStats.posY, playerStats.newPosX, playerStats.newPosY);
		playerStats.set_new_position(obstacle, heal, damage);
		playerStats.death(isRunning);
		playerStats.win(isRunning, obstacle);
	}
}

void introduction_text()
{
	system("Color 08");
	
	std::cout << "Welcome hero (" << Sprite::player <<"), make your way to the teleportation portal (" << Sprite::portal <<").\n\n";
	system("pause");
	system("cls");
	std::cout << "Your quest will be scattered with pitfalls.\nYou must avoid invisible traps and heal yourself with potions (" << Sprite::potion << ").\n\n";
	system("pause");
	system("cls");
}

void lvl2_text()
{
	std::cout << "Congratulation hero (" << Sprite::player << "), you crossed the path leading to the cave where the princess is held captive.\n\n";
	system("pause");
	system("cls");
	std::cout << "Now you have to recover the 4 keys ("<< Sprite::key <<") to open the cell where the princess (" << Sprite::princess <<") is.\n\n";
	system("pause");
	system("cls");
}