#include <iostream>
#include <vector>
#include "map.h"
#include "sprite.h"
#include <fstream>

Map::Map(int posX, int posY)
{
	std::ifstream inFile;
	inFile >> std::noskipws;
	char line;
	inFile.open("lvl1.txt");

	map_ = std::vector<std::vector<char> >(map_width, std::vector<char>(map_length));
	
	for (int i = 0; i < map_.size(); i++)
	{
		for (unsigned int j = 0; j < map_[i].size(); j++)
		{
			while (inFile >> line)
			{
				map_[i][j] = line;
				break;
			}
		}
	}

	inFile.close();
}

void Map::print_map()
{
	for (int i = 0; i < map_.size(); i++)
	{
		for (int j = 0; j < map_[i].size(); j++)
		{
			std::cout << map_[i][j];
		}
		std::cout << "\n";
	}
}

int Map::check_obstacle(int newPosX, int newPosY)
{
	switch (map_[newPosY][newPosX])
	{
		case Sprite::ground:
		{
			return 1;
		}

		case Sprite::potion:
		{
			return 2;
		}

		case Sprite::invisibleTrap:
		{
			return 3;
		}

		case Sprite::trap:
		{
			return 3;
		}

		case Sprite::portal:
		{
			level_2();
			return 4;
		}

		case Sprite::key:
		{
			collectedKeys_ += 1;
			openDoor();
			return 5;
		}

		case Sprite::princess:
		{
			return 6;
		}
		
		default:
		{
			return 7;
		}
	}
}

void Map::set_new_player_pos(int obstacle, int posX, int posY, int newPosX, int newPosY)
{
	system("cls");
	switch (obstacle)
	{
		case 1:
		{
			map_[posY][posX] = Sprite::ground;
			map_[newPosY][newPosX] = Sprite::player;
			break;
		}

		case 2:
		{
			map_[posY][posX] = Sprite::ground;
			map_[newPosY][newPosX] = Sprite::player;
			break;
		}

		case 3:
		{
			map_[posY][posX] = Sprite::ground;
			map_[newPosY][newPosX] = Sprite::player;
			break;
		}

		case 5:
		{
			map_[posY][posX] = Sprite::ground;
			map_[newPosY][newPosX] = Sprite::player;
			break;
		}
	}
}

void Map::visible_trap(int showTrap)
{
	if (showTrap == 1)
	{
		for (int i = 0; i < map_.size(); i++)
		{
			for (unsigned int j = 0; j < map_[i].size(); j++)
			{
				if (map_[i][j] == Sprite::invisibleTrap)
				{
					map_[i][j] = Sprite::trap;
				}
			}
		}
		
		system("cls");
	}
}

void Map::level_2()
{
	std::ifstream inFile;
	inFile >> std::noskipws;
	char line;
	inFile.open("lvl2.txt");
	
	map_length = 26;
	map_width = 26;
	map_ = std::vector<std::vector<char> >(map_width, std::vector<char>(map_length));

	for (int i = 0; i < map_.size(); i++)
	{
		for (unsigned int j = 0; j < map_[i].size(); j++)
		{
			while (inFile >> line)
			{
				map_[i][j] = line;
				break;
			}
		}
	}

	inFile.close();
	
}

void Map::openDoor()
{
	if(collectedKeys_ == 4)
	{
		system("cls");
		std::cout << "Congratulation hero (" << Sprite::player << "), you took the 4 keys and the passage leading to the princess opened.\n\n";
		system("pause");
		system("cls");
		map_[13][12] = Sprite::ground;
	}
}