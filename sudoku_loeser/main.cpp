#pragma comment(lib, "Winmm.lib")
#include <iostream>
#include <conio.h>
#include "ic.hpp"
#include "resource.h"

using namespace ic;
using namespace ic::shorties;
using namespace std;

const unsigned char AE = static_cast<unsigned char>(142);
const unsigned char ae = static_cast<unsigned char>(132);
const unsigned char OE = static_cast<unsigned char>(153);
const unsigned char oe = static_cast<unsigned char>(148);
const unsigned char UE = static_cast<unsigned char>(154);
const unsigned char ue = static_cast<unsigned char>(129);
const unsigned char ss = static_cast<unsigned char>(225);

void wait();
void keyInput();
bool controlInput();
bool controlNumber(short x, short y);
void drawGamefield ();
void drawCursor ();
void drawNumbers ();
void drawNumber (short x, short y);
void clearNumbers ();
void clearCursor ();
void clearText1 ();
void clearText2 ();

const string titleText = "Sudoku L\x94ser";
const string versionText = "1.0.1";
short matrix[10][10][2] = {0};
short inputx = 1;
short inputy = 1;
short posx = 1;
short posy = 1;
short fieldx = 0;
short fieldy = 0;
bool start = false;
bool gameEnd = false;
bool rightInput = false;
bool finish = false;
bool failed = false;
DWORD startTime = 0;
int endTime = 0;
//int showTime = 0;

int main (int argc, char **argv)
{
	
	
	cursize(-1);

	title(TEXT(titleText));
	clrscr(BG_WHITE);
	drawGamefield();
	drawNumbers();
	drawCursor();
	clearText1();
	clearText2();
	bgcolor(BG_WHITE);
	textcolor(FG_BLACK);
	gotoxy(49,7);
	cout << "Bitte Sudoku eingeben.";
	while ( !gameEnd && !finish && !failed )
	{
		if ( !start )
		{
			keyInput();
		}
		else
		{
			/*showTime = timeGetTime() - startTime;
			bgcolor(BG_WHITE);
			textcolor(FG_BLACK);
			gotoxy(49,5);
			cout << (showTime/1000) << ",";
			cout.width(3); cout.fill('0'); cout << (showTime%1000) << " s";*/
			if ( matrix[posx][posy][1] == 0 )
			{
				if ( matrix[posx][posy][0] < 9 )
				{
					++matrix[posx][posy][0];
					if ( controlNumber(posx,posy) )
					{
						//drawNumber(posx,posy);
						do
						{
							if ( posx == 9 && posy == 9 )
							{
								endTime = timeGetTime() - startTime;
								finish = true;
							}
							else
							{
								if ( posx < 9 )
									++posx;
								else
								{
									posx = 1;
									++posy;
								}
							}
						}
						while ( matrix[posx][posy][1] != 0 && !finish);
					}
				}
				else
				{
					matrix[posx][posy][0] = 0;
					//drawNumber(posx,posy);
					do
					{
						if ( posx == 1 && posy == 1 )
						{
							endTime = timeGetTime() - startTime;
							failed = true;
						}
						else
						{
							if ( posx > 1 )
								--posx;
							else
							{
								posx = 9;
								--posy;
							}
						}
					}
					while ( matrix[posx][posy][1] != 0 && !failed );
				}
			}
			else
			{
				if ( posx < 9 )
					++posx;
				else
				{
					posx = 1;
					++posy;
				}
			}
		}
	}
	if ( !gameEnd )
	{
		clearText1();
		bgcolor(BG_WHITE);
		textcolor(FG_BLACK);
		drawNumbers();
		if ( finish )
		{
			gotoxy(49,7);
			cout << "Sudoku erfolgreich gel"<<oe<<"st!";
		}
		else if ( failed )
		{
			gotoxy(49,7);
			cout << "Sudoku ist nicht l"<<oe<<"sbar!";
		}
		gotoxy(49,8);
		cout << "Ben"<<oe<<"tigte Zeit: " << (endTime/1000) << ",";
		cout.width(3); cout.fill('0');
		cout << (endTime%1000) << " s"; 
		gotoxy(49,10);
		cout << "<ESC> dr"<<ue<<"cken zum beenden";
		rightInput = false;
		while(!rightInput)
		{
			int c = _getch();
			if ( c == 27 ) rightInput = true;
		}
	}
	return 0;
}



void wait ()
{
    std::cin.clear();
    std::cin.ignore(std::cin.rdbuf()->in_avail());
    std::cin.get();
}

void keyInput ()
{
	int c = _getch();
	switch(c)
	{
	case 75: // Links
		{
			if ( inputx > 1 )
			{
				clearCursor();
				--inputx;
				drawCursor();
			}
		}
		break;
	case 77: // Rechts
		{
			if ( inputx < 9 )
			{
				clearCursor();
				++inputx;
				drawCursor();
			}
		}
		break;
	case 72: // Hoch
		{
			if ( inputy > 1 )
			{
				clearCursor();
				--inputy;
				drawCursor();
			}
		}
		break;
	case 80: // Runter
		{
			if ( inputy < 9 )
			{
				clearCursor();
				++inputy;
				drawCursor();
			}
		}
		break;
	case '0': case 8:
		{
			matrix[inputx][inputy][0] = 0;
			matrix[inputx][inputy][1] = 0;
			drawNumber(inputx,inputy);
			drawCursor();
		}
		break;
	case '1':
		{
			matrix[inputx][inputy][0] = 1;
			matrix[inputx][inputy][1] = 1;
			drawNumber(inputx,inputy);
			drawCursor();
		}
		break;
	case '2':
		{
			matrix[inputx][inputy][0] = 2;
			matrix[inputx][inputy][1] = 1;
			drawNumber(inputx,inputy);
			drawCursor();
		}
		break;
	case '3':
		{
			matrix[inputx][inputy][0] = 3;
			matrix[inputx][inputy][1] = 1;
			drawNumber(inputx,inputy);
			drawCursor();
		}
		break;
	case '4':
		{
			matrix[inputx][inputy][0] = 4;
			matrix[inputx][inputy][1] = 1;
			drawNumber(inputx,inputy);
			drawCursor();
		}
		break;
	case '5':
		{
			matrix[inputx][inputy][0] = 5;
			matrix[inputx][inputy][1] = 1;
			drawNumber(inputx,inputy);
			drawCursor();
		}
		break;
	case '6':
		{
			matrix[inputx][inputy][0] = 6;
			matrix[inputx][inputy][1] = 1;
			drawNumber(inputx,inputy);
			drawCursor();
		}
		break;
	case '7':
		{
			matrix[inputx][inputy][0] = 7;
			matrix[inputx][inputy][1] = 1;
			drawNumber(inputx,inputy);
			drawCursor();
		}
		break;
	case '8':
		{
			matrix[inputx][inputy][0] = 8;
			matrix[inputx][inputy][1] = 1;
			drawNumber(inputx,inputy);
			drawCursor();
		}
		break;
	case '9':
		{
			matrix[inputx][inputy][0] = 9;
			matrix[inputx][inputy][1] = 1;
			drawNumber(inputx,inputy);
			drawCursor();
		}
		break;
	case 27: gameEnd = true; break; // Ende
	case 13:
		{
			clearText1();
			bgcolor(BG_WHITE);
			textcolor(FG_BLACK);
			rightInput = false;
			while(!rightInput)
			{
				gotoxy(49,7);
				cout << "Eingabe fertig?";
				gotoxy(49,9);
				cout << "<J>a <N>ein";
				int f = _getch();
				switch(f)
				{
				case 'J': case 'j': case 13:
					{
						clearText1();
						rightInput = true;
						if ( controlInput() )
						{
							start = true;
							clearCursor();
							gotoxy(49,7);
							cout << "arbeite...";
							startTime = timeGetTime();
							
						}
						else
						{
							gotoxy(49,7);
							cout << "Fehler bei der Eingabe!";
						}
					}
					break;
				case 'N': case 'n':
					{
						rightInput = true;
						clearText1();
						//...
					}
				}
			}

		}
		break;
	/*
	case 0: case 224:
		{
			int c = _getch();
			switch(c)
			{
				case 75:
					{
						if ( input > 0 ) --input;
						clearCursor();
						drawCursor();
					}
					break;
			}
		}*/
	}
}

bool controlInput ()
{
	for(int x=1;x<=9;++x)
	{
		for(int y=1;y<=9;++y)
		{
			if ( matrix[x][y][1] == 1 )
			{
				for(int xx=1;xx<=9;++xx)
					if ( xx != x)
						if ( matrix[xx][y][0] == matrix[x][y][0] )
							return false;
				for(int yy=1;yy<=9;++yy)
					if ( yy != y)
						if ( matrix[x][yy][0] == matrix[x][y][0] )
							return false;
				if ( x <= 9 ) fieldx = 2;
				if ( x <= 6 ) fieldx = 1;
				if ( x <= 3 ) fieldx = 0;
				if ( y <= 9 ) fieldy = 2;
				if ( y <= 6 ) fieldy = 1;
				if ( y <= 3 ) fieldy = 0;
				for(int xx=1;xx<=3;++xx)
					for(int yy=1;yy<=3;++yy)
						if ( fieldx*3+xx != x && fieldy*3+yy != y)
							if ( matrix[fieldx*3+xx][fieldy*3+yy][0] == matrix[x][y][0] )
								return false;
			}
			
		}
	}
	return true;
}

bool controlNumber (short x, short y)
{
	for(int xx=1;xx<=9;++xx)
		if ( xx != x)
			if ( matrix[xx][y][0] == matrix[x][y][0] )
				return false;
	for(int yy=1;yy<=9;++yy)
		if ( yy != y)
			if ( matrix[x][yy][0] == matrix[x][y][0] )
				return false;
	if ( x <= 9 ) fieldx = 2;
	if ( x <= 6 ) fieldx = 1;
	if ( x <= 3 ) fieldx = 0;
	if ( y <= 9 ) fieldy = 2;
	if ( y <= 6 ) fieldy = 1;
	if ( y <= 3 ) fieldy = 0;
	for(int xx=1;xx<=3;++xx)
		for(int yy=1;yy<=3;++yy)
			if ( fieldx*3+xx != x && fieldy*3+yy != y)
				if ( matrix[fieldx*3+xx][fieldy*3+yy][0] == matrix[x][y][0] )
					return false;
	return true;
}

void drawGamefield ()
{
	//Hintergrund		
	bgcolor(BG_WHITE);
	textcolor(FG_BLUE);		
	gotoxy(0,0); for(int i=0;i<80;i++) cout << "\xb1";

	gotoxy(0,1); cout << "\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1       ";
	textcolor(FG_BLACK); cout << titleText; textcolor(FG_BLUE);
	cout << "        \xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1    ";
	textcolor(FG_BLACK); cout << "V " << versionText ; textcolor(FG_BLUE);
	cout << "   \xb1\xb1\n";

	gotoxy(0,2); for(int i=0;i<80;i++) cout << "\xb1";
	for(int i=0;i<22;i++)
	{
		gotoxy(0,i+3);
		cout << "\xb1\xb1";
	}
	for(int i=0;i<22;i++)
	{
		gotoxy(46,i+3);
		for(int i=46;i<80;i++) cout << "\xb1";
	}
	gotoxy(0,23); for(int i=0;i<80;i++) cout << "\xb1";
	gotoxy(0,24); for(int i=0;i<80;i++) cout << "\xb1";
	clearText1 ();
	textcolor(FG_BLACK);
	gotoxy(17,24);
	cout << " \xb8 2008 Oliver K"<<ae<<"dtler   http://www.ok-city.de ";
	// Feld zeichnen
	textcolor(FG_BLACK);
	gotoxy(9, 3); cout << "\xc9\xcd\xcd\xcd\xcd\xcd\xcb\xcd\xcd\xcd\xcd\xcd\xcb\xcd\xcd\xcd\xcd\xcd\xbb";
	gotoxy(9, 4); cout << "\xba \xb3 \xb3 \xba \xb3 \xb3 \xba \xb3 \xb3 \xba";
	gotoxy(9, 5); cout << "\xba\xc4\xc5\xc4\xc5\xc4\xba\xc4\xc5\xc4\xc5\xc4\xba\xc4\xc5\xc4\xc5\xc4\xba";
	gotoxy(9, 6); cout << "\xba \xb3 \xb3 \xba \xb3 \xb3 \xba \xb3 \xb3 \xba";
	gotoxy(9, 7); cout << "\xba\xc4\xc5\xc4\xc5\xc4\xba\xc4\xc5\xc4\xc5\xc4\xba\xc4\xc5\xc4\xc5\xc4\xba";
	gotoxy(9, 8); cout << "\xba \xb3 \xb3 \xba \xb3 \xb3 \xba \xb3 \xb3 \xba";
	gotoxy(9, 9); cout << "\xcc\xcd\xcd\xcd\xcd\xcd\xce\xcd\xcd\xcd\xcd\xcd\xce\xcd\xcd\xcd\xcd\xcd\xb9";
	gotoxy(9,10); cout << "\xba \xb3 \xb3 \xba \xb3 \xb3 \xba \xb3 \xb3 \xba";
	gotoxy(9,11); cout << "\xba\xc4\xc5\xc4\xc5\xc4\xba\xc4\xc5\xc4\xc5\xc4\xba\xc4\xc5\xc4\xc5\xc4\xba";
	gotoxy(9,12); cout << "\xba \xb3 \xb3 \xba \xb3 \xb3 \xba \xb3 \xb3 \xba";
	gotoxy(9,13); cout << "\xba\xc4\xc5\xc4\xc5\xc4\xba\xc4\xc5\xc4\xc5\xc4\xba\xc4\xc5\xc4\xc5\xc4\xba";
	gotoxy(9,14); cout << "\xba \xb3 \xb3 \xba \xb3 \xb3 \xba \xb3 \xb3 \xba";
	gotoxy(9,15); cout << "\xcc\xcd\xcd\xcd\xcd\xcd\xce\xcd\xcd\xcd\xcd\xcd\xce\xcd\xcd\xcd\xcd\xcd\xb9";
	gotoxy(9,16); cout << "\xba \xb3 \xb3 \xba \xb3 \xb3 \xba \xb3 \xb3 \xba";
	gotoxy(9,17); cout << "\xba\xc4\xc5\xc4\xc5\xc4\xba\xc4\xc5\xc4\xc5\xc4\xba\xc4\xc5\xc4\xc5\xc4\xba";
	gotoxy(9,18); cout << "\xba \xb3 \xb3 \xba \xb3 \xb3 \xba \xb3 \xb3 \xba";
	gotoxy(9,19); cout << "\xba\xc4\xc5\xc4\xc5\xc4\xba\xc4\xc5\xc4\xc5\xc4\xba\xc4\xc5\xc4\xc5\xc4\xba";
	gotoxy(9,20); cout << "\xba \xb3 \xb3 \xba \xb3 \xb3 \xba \xb3 \xb3 \xba";
	gotoxy(9,21); cout << "\xc8\xcd\xcd\xcd\xcd\xcd\xca\xcd\xcd\xcd\xcd\xcd\xca\xcd\xcd\xcd\xcd\xcd\xbc";

}

void drawCursor ()
{
	bgcolor(BG_BLACK);
	textcolor(FG_WHITE);
	gotoxy(inputx*2+8,inputy*2+2);
	if ( matrix[inputx][inputy][0] > 0 )
		cout << matrix[inputx][inputy][0];
	else
		cout << " ";

}

void drawNumbers ()
{
	bgcolor(BG_WHITE);
	textcolor(FG_BLACK);
	for(int x=1;x<=9;++x)
	{
		for(int y=1;y<=9;++y)
		{
			if ( matrix[x][y][0] > 0 )
			{
				gotoxy(x*2+8,y*2+2);
				cout << matrix[x][y][0];
			}
			
		}
	}
}
void drawNumber (short x, short y)
{
	bgcolor(BG_WHITE);
	textcolor(FG_BLACK);
	if ( matrix[x][y][0] > 0 )
	{
		gotoxy(x*2+8,y*2+2);
		cout << matrix[x][y][0];
	}
}

void clearNumbers ()
{
	//..
}

void clearCursor ()
{
	bgcolor(BG_WHITE);
	textcolor(FG_BLACK);
	gotoxy(inputx*2+8,inputy*2+2);
	if ( matrix[inputx][inputy][0] > 0 )
		cout << matrix[inputx][inputy][0];
	else
		cout << " ";
}

void clearText1 ()
{
	bgcolor(BG_WHITE);
	textcolor(FG_BLACK);
	for(int i=0;i<5;i++)
	{
		gotoxy(48,i+7);
		for(int i=48;i<78;i++) cout << " ";
	}
}

void clearText2 ()
{
	bgcolor(BG_WHITE);
	textcolor(FG_BLACK);
	gotoxy(48,5);
	for(int i=48;i<59;i++) cout << " ";
}