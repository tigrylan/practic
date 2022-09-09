#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<windows.h>
#include<set>
#include "conio.h"  

using namespace std;

string strGameOver = R"(
		  ________    _____      _____  ___________ ____________   _________________________ 
		 /  _____/   /  _  \    /     \ \_   _____/ \_____  \   \ /   /\_   _____/\______   \
		/   \  ___  /  /_\  \  /  \ /  \ |    __)_   /   |   \   Y   /  |    __)_  |       _/
		\    \_\  \/    |    \/    Y    \|        \ /    |    \     /   |        \ |    |   \
		 \______  /\____|__  /\____|__  /_______  / \_______  /\___/   /_______  / |____|_  /
				\/         \/         \/        \/          \/                 \/         \/ 
)";

string strGameStart = R"(		 _____      _____    _____   ______ 
		|  __ \    |_   _|  / ____| |  ____|
		| |  | |     | |   | |      | |__   
		| |  | |     | |   | |      |  __|  
		| |__| |    _| |_  | |____  | |____ 
		|_____/    |_____|  \_____| |______|)";
string strYouWin = R"(
		 _     _   _____   _     _    _  _  _  _____  ______   _ 
		| |   | | / ___ \ | |   | |  | || || |(_____)|  ___ \ | |
		| |___| || |   | || |   | |  | || || |   _   | |   | || |
		 \_____/ | |   | || |   | |  | ||_|| |  | |  | |   | ||_|
		   ___   | |___| || |___| |  | |___| | _| |_ | |   | | _ 
		  (___)   \_____/  \______|   \______|(_____)|_|   |_||_|
)";
string strMenu = R"(
		 _ __ ___     ___   _ __    _   _ 
		| '_ ` _ \   / _ \ | '_ \  | | | |
		| | | | | | |  __/ | | | | | |_| |
		|_| |_| |_|  \___| |_| |_|  \__,_|
		1 - ����� ����  
		2 - ������� 
		3 - �������
		4 - �����
)";
string artsDice = R"(
			   .-------.    ______
			  /   o   /|   /\     \
			 /_______/o|  /o \  o  \
			 | o     | | /   o\_____\
			 |   o   |o/ \o   /o    /
			 |     o |/   \ o/  o  /
			 '-------'     \/____o/)";
void printText(string& m)
{
	for (int i = 0; i < m.size(); i++)
	{
		cout << m[i];
		Sleep(1);
	}
}
string rollDice = R"(               
                               (( _______
                     _______     /\O    O\
                    /O     /\   /  \      \
                   /   O  /O \ / O  \O____O\ ))
                ((/_____O/    \\    /O     /
                  \O    O\    / \  /   O  /
                   \O    O\ O/   \/_____O/
                    \O____O\/ ))          ))
                  ((
)";
string getWord(ifstream& fin, int& number)
{
	string wordGuess;
	while (true)
	{
		fin >> wordGuess;
		number--;
		if (number <= 0)break;
	}
	return wordGuess;
}
void infoError(set <char>& st)
{
	cout << R"(		 ____________________________
		|�����, ������� ��� � �����  |
		|____________________________| )";
	for (auto& i : st)
		cout << i << " ";
	cout << endl;
}
int getInputMenu()
{
	int number;
	while (true) // ����������� ����, ������� ������ ����������� �� �������
	{
		cin >> number;   // ���� �������� �������������
		if (!cin.fail()) // ���� ����� �����, � ������ ����� �� � ��������� ������, �� ��������� ����
		{
			if (number <= 4 && number >= 1)break;
		}
		cout << "		syntax error!" << endl;
		cin.clear(); // ���������� ��������� ������
		cin.ignore((numeric_limits<std::streamsize>::max)(), '\n');
	}
	return number; // ���������� �� ������� ��������� � ����� ������ �������
}
int getInputNumber()
{
	int number;
	while (true) // ����������� ����, ������� ������ ����������� �� �������
	{
		cin >> number;   // ���� �������� �������������
		if (!cin.fail()) // ���� ����� �����, � ������ ����� �� � ��������� ������, �� ��������� ����
		{
			if (number <= 12 && number > 1)break;
		}
		cout << "		syntax error!" << endl;
		cin.clear(); // ���������� ��������� ������
		cin.ignore((numeric_limits<std::streamsize>::max)(), '\n');
	}
	return number; // ���������� �� ������� ��������� � ����� ������ �������
}
int getPlayerBet(int& score)
{
	int number;
	while (true) // ����������� ����, ������� ������ ����������� �� �������
	{
		cin >> number;   // ���� �������� �������������
		if (!cin.fail()) // ���� ����� �����, � ������ ����� �� � ��������� ������, �� ��������� ����
		{
			if (number > 0 && score >= number)break;
		}
		cout << "		syntax error!" << endl;
		cin.clear(); // ���������� ��������� ������
		cin.ignore((numeric_limits<std::streamsize>::max)(), '\n');
	}
	return number; // ���������� �� ������� ��������� � ����� ������ �������
}
void infoScore(int& score)
{
	cout << R"(		 ______________________________
		| ���������� ��������� �����   |         
		|______________________________| )";
	cout << score;
}
int main() {
	SetConsoleCP(1251);
	setlocale(LC_ALL, "Rus");
	srand(time(0));
	/*AudioDevicePtr device = OpenDevice();
	OutputStreamPtr sound = OpenSound(device, "zhu.mp3", false);
	sound->play();
	sound->setVolume(0.5f);*/
	cout << strGameStart << endl << artsDice;
	Sleep(3000);
	system("cls");
	printText(strMenu);
	while (true)
	{
		system("cls");
		cout << strMenu;
		int n = getInputMenu();

		if (n == 1)
		{
			int scorePlayer = 100;
			while (true)
			{
				system("cls");
				cout << artsDice << endl;
				int numberRand = rand() % 12 + 1;
				infoScore(scorePlayer);

				cout << R"(
		 _________________
		| �������� ������ |
		|_________________|)";
				int playersBet = getPlayerBet(scorePlayer);
				cout << R"(		 ____________________________
		| ��������� ����� �� 2 �� 12 |
		|____________________________|)";
				int numberInputPlayer = getInputNumber();
				cout << rollDice << endl;
				Sleep(1000);
				if (numberRand == numberInputPlayer)
				{
					scorePlayer += playersBet * 4;
					cout << strYouWin;
					Sleep(2500);
				}
				else if (numberRand >= 7 && 7 <= numberInputPlayer)
				{
					scorePlayer += playersBet * 2;
					cout << "�� �������� " << playersBet * 2 << endl;
					Sleep(2500);
				}
				else {
					scorePlayer -= playersBet;
					cout << R"(                                                         _           _   
         ___  ___  _ __ _ __ _   _   _   _  ___  _   _  | | ___  ___| |_ 
        / __|/ _ \| '__| '__| | | | | | | |/ _ \| | | | | |/ _ \/ __| __|
        \__ \ (_) | |  | |  | |_| | | |_| | (_) | |_| | | | (_) \__ \ |_ 
        |___/\___/|_|  |_|   \__, |  \__, |\___/ \__,_| |_|\___/|___/\__|
                             |___/   |___/                               )";
					Sleep(2500);
				}
				if (scorePlayer <= 0)
				{
					cout << strGameOver;
					system("pause");
					break;
				}
			}
		}
		if (n == 2)
		{
			system("cls");
			cout << R"(		
 ______________________________________________________________________________________________________________________
|                                              ���� "�����"                                                             |
| ����� �������� ����� ����� �� 2 �� 12. ������ ��������, ���� ���������� ����� �������� � ��� �� ��������(2-6, 7-12),  |
| ��� � �������� ������� ������. � ���� ������ ����� �������� ���������� ����� ������ � 2 ����.                         |
| ���� ��������� ����� ����� ������� � ������� �� ������, �� ����� �������� ���������� ����� ������ � 4 ����.           |
|_______________________________________________________________________________________________________________________|
)";
			system("pause");
			system("cls");
			continue;
		}
		if (n == 3)
		{
			system("cls");
			cout << R"(
		���� ���� ����������� �� ����� ������ ������� ��������.
		�� ����� ����� ���� ����� ������������, ��� ���������, ��� � �������� �����.
		���� ������ ������ ��������� ����, �� ������� ����� ������.
		
		?\_(**)_/?)";
			system("pause");
			system("cls");
			continue;
		}
		if (n == 4)
		{
			exit(0);
		}
	}

	return 0;
}





