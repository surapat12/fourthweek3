#include<stdio.h>
#include<windows.h>
#include<conio.h>
void draw_ship(int x, int y)
{
	COORD c = { x, y };
	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE), c);
	printf(" <-0-> ");
}
void erase_ship(int x, int y)
{
	COORD c = { x, y };
	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE), c);
	printf("       ");
}
int main()
{
	char ch = ' ';
	int x = 56, y = 14;
	draw_ship(x, y);

	do {
		if (_kbhit()) {
			ch = _getch();
			if (ch == 'a')
			{

				if (x == 0)
				{
					draw_ship(++x, y);
				}

				draw_ship(--x, y);
			}
			if (ch == 'd')
			{

				if (x >= 113)
				{

					draw_ship(x--, y);
				}
				draw_ship(++x, y);
			}
			if (ch == 'w')
			{
				if (y == 0)
				{
					erase_ship(x, y);
					draw_ship(x, ++y);
				}
				erase_ship(x, y);
				draw_ship(x, --y);

			}
			if (ch == 's')
			{

				if (y >= 29)
				{
					erase_ship(x, y);
					draw_ship(x, --y);
				}
				erase_ship(x, y);
				draw_ship(x, ++y);
			}
			fflush(stdin);
		}
		Sleep(100);
	} while (ch != 'x');


	return 0;
}