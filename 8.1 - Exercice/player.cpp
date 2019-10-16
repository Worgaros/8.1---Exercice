#include <iostream>
#include "player.h"
#include "game.h"

Player::Player()
{}

void Player::take_damages(int damage)
{
	healthPoints_ -= damage;
}

void Player::take_heal(int heal)
{
	healthPoints_ += heal;
	if (healthPoints_ > maxHealthPoints_)
	{
		healthPoints_ = maxHealthPoints_;
		system("cls");
		std::cout << "MAX LIFE !\n\n";
		system("pause");
	}
}

void Player::set_new_position(int obstacle, int heal, int damage)
{
	if(userInput == "w" || userInput == "s")
	{
		bool askAgain = true;
		switch (obstacle)
		{
			case 1:
			{		
				posY = newPosY;
				break;
			}

			case 2:
			{
				posY = newPosY;
				while (askAgain)
				{
					askAgain = ask_take_potion(heal);
				}
				break;
			}

			case 3:
			{
				posY = newPosY;
				take_damages(damage);
				break;
			}
			
			case 4:
			{
				posX = 12;
				posY = 15;
				newPosX = 12;
				newPosY = 15;
				break;
			}

			case 5:
			{
				posY = newPosY;
				keys_ += 1;
			}

			default:
			{
				newPosY = posY;
			}
		}
	}

	else if (userInput == "a" || userInput == "d")
	{
		bool askAgain = true;
		switch (obstacle)
		{
			case 1:
			{
				posX = newPosX;
				break;
			}

			case 2:
			{
				posX = newPosX;
				while (askAgain)
				{
					askAgain = ask_take_potion(heal);
				}
				break;
			}

			case 3:
			{
				posX = newPosX;
				take_damages(damage);
				break;
			}

			case 4:
			{
				posX = 12;
				posY = 15;
				newPosX = 12;
				newPosY = 15;
				lvl2_text();
				break;
			}

			case 5:
			{
				posX = newPosX;
				keys_ += 1;
			}

			default:
			{
				newPosX = posX;
			}
		}
	}
}

int Player::calc_new_pos()
{
	std::cin >> userInput;
	
	if (userInput == "w")
	{
		newPosY -= 1;
		return false;
	}

	else if (userInput == "s")
	{
		newPosY += 1;
		return false;
	}
	
	else if (userInput == "d")
	{
		newPosX += 1;
		return false;
	}
	
	else if (userInput == "a")
	{
		newPosX -= 1;
		return false;
	}

	else if (userInput == "lumos")
	{
		system("cls");
		std::cout << "CHEAT CODE ACTIVATED !\n\n";
		system("pause");
		return true;
	}

	else if (userInput == "kebab")
	{
		system("cls");
		std::cout << "CHEAT CODE ACTIVATED !\n\n";
		system("pause");
		healthPoints_ = 1000;
		return false;
	}

	else
	{
		std::cout << "Invalid choice !\n\n";
		system("pause");
		return false;
	}
}

void Player::print_player_stats()
{
	std::cout << "\nHealth: " << healthPoints_ << "\n";
	std::cout << "Keys: " << keys_ << "\n\n";
}

void Player::death(bool& isRunning)
{
	if (healthPoints_ <= 0)
	{
		system("cls");
		std::cout << "Game Over !\n\n";
		isRunning = false;
	}
}

void Player::win(bool& isRunning, int obstacle)
{
	if (obstacle == 6)
	{
		system("cls");
		std::cout << "Would you save the princess ? y = Yes, n = No, other = ?\n\n";
		
		char userInput;
		std::cin >> userInput;
		switch (userInput)
		{
			case 'y':
			{
				system("cls");
				std::cout << "Congratulation you saved the princess !\n\n";
				break;
			}

			case 'n':
			{
				system("cls");
				std::cout << "Congratulation you're a piece of shit! You killed the princess ...\n\n";
				break;
			}

			default:
			{
				system("cls");
				std::cout << "You killed yourself ...";
			}
		}
		
		isRunning = false;
	}
}

bool Player::ask_take_potion(int heal)
{
	char userInput;
	std::cout << "Would you take the potion ? y = Yes n = No\n";

	std::cin >> userInput;
	switch (userInput)
	{
		case 'y':
		{
			take_heal(heal);
			system("cls");
			return false;
		}

		case 'n':
		{
			system("cls");
			std::cout << "The potion disappears\n\n";
			system("pause");
			system("cls");
			return false;
		}

		default:
		{
			std::cout << "Invalid choice !\n\n";
			system("pause");
			system("cls");
			return true;
		}
	}
}
