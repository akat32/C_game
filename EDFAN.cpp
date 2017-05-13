#include<stdio.h>
#pragma warning(disable:4996)
#include<Windows.h>
#include<time.h>
#include<conio.h>>
#include<stdlib.h>
#include<time.h>

int mainmap[50][80];
int i, j;
void gotoxy(int x, int y)
{
	COORD Pos = { x , y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
void hos();
void fff()
{
	HANDLE hConsole; // 콘솔 핸들
	CONSOLE_CURSOR_INFO ConsoleCursor; // 콘솔커서 정보 구조체

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // 핸들을 구하고

	ConsoleCursor.bVisible = false; // true 보임 , false 안보임
	ConsoleCursor.dwSize = 1; // 커서 사이즈

	SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}
void mainmapset()
{

	mainmap[0][1] = 999;
	mainmap[0][68] = 999;
	mainmap[39][1] = 999;
	mainmap[39][68] = 999;
	for (i = 0; i <= 5; i++)
	{
		mainmap[8][14 + i] = 999;
		mainmap[12][14 + i] = 999;
		mainmap[16][14 + i] = 999;
		mainmap[8][32 + i] = 999;
		mainmap[12][32 + i] = 999;
		mainmap[12][41 + i] = 999;
		mainmap[11 + i][41] = 999;
		mainmap[11 + i][46] = 999;
	}
	for (i = 0; i < 9; i++)
	{
		mainmap[8 + i][14] = 999;
		mainmap[8 + i][23] = 999;
		mainmap[8 + i][32] = 999;
		mainmap[8 + i][50] = 999;
		mainmap[8 + i][55] = 999;
	}
	for (i = 0; i < 3; i++)
	{
		mainmap[8][24 + i] = 999;
		mainmap[16][24 + i] = 999;
		mainmap[10 + i][28] = 999;

	}
	mainmap[9][27] = 999;
	mainmap[15][27] = 999;
	mainmap[14][28] = 999;
	mainmap[13][28] = 999;
	mainmap[10][41] = 999;
	mainmap[10][46] = 999;
	mainmap[9][41] = 999;
	mainmap[9][46] = 999;
	mainmap[8][45] = 999;
	mainmap[8][42] = 999;
	mainmap[8][43] = 999;
	mainmap[8][44] = 999;

	mainmap[9][51] = 999;
	mainmap[10][52] = 999;
	mainmap[11][52] = 999;
	mainmap[14][53] = 999;
	mainmap[12][52] = 999;
	mainmap[13][53] = 999;
	mainmap[15][54] = 999;
}
void mainmapset2()
{
	for (j = 0; j < 69; j++)
	{
		mainmap[0][j] = 999;
		mainmap[38][j] = 888;
		mainmap[1][j] = 888;
		mainmap[39][j] = 999;
	}
	for (i = 0; i < 40; i++)
	{
		mainmap[i][68] = 888;
		mainmap[i][1] = 888;
		mainmap[i][0] = 999;
		mainmap[i][69] = 999;
	}
}
void mainmapprt()
{
	for (i = 0; i < 40; i++)
	{
		for (j = 0; j < 70; j++)
		{
			if (mainmap[i][j] == 999)
				printf("■");
			else if (mainmap[i][j] == 888)
				printf("□");
			else
				printf("  ");
		}
		printf("\n");
	}
}
void welcome()
{
	gotoxy(61, 25);
	printf("[Push the any key]");
	while (1)
		if (kbhit())
		{
			fff();
			hos();
			system("cls");
			break;
		}
}
void hos()
{
	int x = 2, y = 1;
	int n = 37, m = 67;
	int chk = 1;
	// 138 , 38
	while (1)
	{
		if (n == 0 || m == 0)
			break;
		for (i = 0; i < m; i++)
		{
			gotoxy(x, y);
			printf("■");
			x += 2;
			Sleep(1);
		}
		if (chk != 1)
			m--;
		else
			chk--;
		for (i = 0; i < n; i++)
		{
			gotoxy(x, y);
			printf("■");
			y++;
			Sleep(1);
		}
		n--;
		for (i = 0; i < m; i++)
		{
			gotoxy(x, y);
			printf("■");
			x -= 2;
			Sleep(1);
		}
		m--;
		if (n == 0 || m == 0)
			break;
		for (i = 0; i < n; i++)
		{
			gotoxy(x, y);
			printf("■");
			y--;
			Sleep(1);
		}
		n--;
	}
}
int map[50][80];
void menuset()
{
	for (j = 0; j < 69; j++)
	{
		map[0][j] = 999;
		map[38][j] = 888;
		map[1][j] = 888;
		map[39][j] = 999;
	}
	for (i = 0; i < 40; i++)
	{
		map[i][68] = 888;
		map[i][1] = 888;
		map[i][0] = 999;
		map[i][69] = 999;
	}
	map[0][1] = 999;
	map[0][68] = 999;
	map[39][1] = 999;
	map[39][68] = 999;
}
void mapprt()
{
	for (i = 0; i < 40; i++)
	{
		for (j = 0; j < 70; j++)
		{
			if (map[i][j] == 999)
				printf("■");
			else if (map[i][j] == 888)
				printf("□");
			else
				printf("  ");
		}
		printf("\n");
	}
}
void pr()
{
	gotoxy(4, 2);
	printf(" 조작법을 설명하겠습니다.");
	gotoxy(4, 4);
	printf(" 1p : w d 이동 , g = 공격");
	gotoxy(4, 6);
	printf(" 2p : 방향키 이동 , p = 공격");
	gotoxy(4, 8);
	gotoxy(4, 12);
	printf(" 공격 사거리에 있다면 공격이 적중, 아니라면 맞지 않습니다.");
	gotoxy(4, 16);
	printf(" 그럼 프롤로그를 종료합니다.");
	for (i = 5; i >= 0; i--)
	{
		gotoxy(4, 18);
		printf("%d 초 뒤에 시작합니다", i);
		Sleep(1000);
	}
	system("cls");
}
int a[200][200];
void aset()
{
	for (i = 0; i < 69; i++)
	{
		a[0][i] = 999;
		a[24][i] = 999;
	}
	for (i = 0; i < 25; i++)
	{
		a[i][0] = 999;
		a[i][69] = 999;
	}
}
void aprt()
{
	for (i = 0; i < 25; i++)
	{
		for (j = 0; j < 70; j++)
		{
			if (a[i][j] == 999)
				printf("▣");
			else
				printf("  ");
		}
		printf("\n");
	}
}
int p1hp = 10, p2hp = 10;
int p1[20][15];
int p2[20][15];
int p1a[20][20];
int p2a[20][20];
int p1x = 11, p1y = 1;
int p2x = 58, p2y = 69;
void p1aset()
{
	for (i = 0; i < 3; i++)
	{
		p1a[0][4 + i] = 888;
		p1a[1][4 + i] = 888;
		p1a[7][4 + i] = 888;
		p1a[8][3 + i] = 888;
		p1a[9][2 + i] = 888;
	}
	p1a[1][12] = 888;
	for (i = 0; i < 4; i++)
		p1a[2][2 + i] = 888;
	p1a[2][11] = 888;
	for (i = 0; i < 6; i++)
		p1a[3][1 + i] = 888;
	p1a[3][9] = p1a[3][10] = 888;
	p1a[4][0] = p1a[4][1] = 888;
	for (i = 0; i < 8; i++)
		p1a[4][3 + i] = 888;
	p1a[5][0] = p1a[6][0] = 888;
	for (i = 0; i < 7; i++)
		p1a[5][3 + i] = 888;
	for (i = 0; i < 5; i++)
		p1a[6][4 + i] = 888;
	p1a[7][1] = p1a[7][9] = 888;
	for (i = 0; i < 2; i++)
	{
		p1a[10][2] = 888;
		p1a[11][2] = 888;
		p1a[12][3] = 888;
		p1a[14][3] = 888;
	}
	p1a[13][4] = 888;
	p1a[0][13] = 888;
	p1a[1][13] = 888;

}
void p2aset()
{
	for (i = 0; i < 15; i++)
		for (j = 0; j < 14; j++)
			p2a[i][13 - j] = p1a[i][j];
}
void p1set()
{
	p1[0][6] = 888;
	p1[0][7] = 888;
	p1[0][5] = 888;
	p1[1][6] = 888;
	p1[1][7] = 888;
	p1[1][5] = 888;
	for (i = 0; i < 4; i++)
		p1[2][3 + i] = 888;
	p1[3][2] = 888;
	for (i = 0; i < 4; i++)
		p1[3][4 + i] = 888;
	for (i = 0; i < 2; i++)
		p1[4][1 + i] = 888;
	for (i = 0; i < 5; i++)
		p1[4][4 + i] = 888;
	p1[5][1] = 888;
	for (i = 0; i < 6; i++)
		p1[5][4 + i] = 888;
	p1[6][0] = 888;
	p1[6][9] = 888;
	for (i = 0; i < 3; i++)
		p1[6][4 + i] = 888;
	p1[7][1] = 888;
	p1[7][10] = 888;
	for (i = 0; i < 3; i++)
		p1[7][4 + i] = 888;
	for (i = 0; i < 5; i++)
		p1[8][3 + i] = 888;
	p1[9][3] = p1[9][4] = 888;
	for (i = 0; i < 3; i++)
		p1[9][6 + i] = 888;
	for (i = 0; i < 2; i++)
	{
		p1[10][2 + i] = 888;
		p1[10][7 + i] = 888;
	}
	for (i = 0; i < 2; i++)
	{
		p1[11][2 + i] = 888;
		p1[11][7 + i] = 888;
	}
	for (i = 0; i < 2; i++)
	{
		p1[12][1 + i] = 888;
		p1[12][6 + i] = 888;
	}
	p1[13][0] = p1[13][5] = 888;
	for (i = 0; i < 2; i++)
	{
		p1[14][i] = 888;
		p1[14][5 + i] = 888;
	}
}
void p2set()
{
	for (i = 0; i < 15; i++)
		for (j = 0; j < 11; j++)
			p2[i][10 - j] = p1[i][j];
}
int n = 11;
void p1prt(int p1y1)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0004);
	for (i = 0; i < 15; i++)
	{
		for (j = 0; j < n; j++)
		{
			gotoxy((p1y1 * 2) + (j * 2), 9 + i);
			if (p1[i][j] == 888)
				printf("■");
			else
				printf("  ");
		}
		gotoxy(p1y1 * 2, 9 + i);
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0007);
}
void p1aprt(int p1y1)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x000d);
	for (i = 0; i < 15; i++)
	{
		for (j = 0; j < 14; j++)
		{
			gotoxy((p1y1 * 2) + (j * 2), 9 + i);
			if (p1a[i][j] == 888)
				printf("■");
			else
				printf("  ");
		}
		gotoxy(p1y1 * 2, 9 + i);
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0007);
}
void p2aprt(int p2x2)
{

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x000b);
	for (i = 0; i < 15; i++)
	{
		for (j = 0; j < 14; j++)
		{
			gotoxy((p2x2 * 2) + (j * 2), 9 + i);
			if (p2a[i][j] == 888)
				printf("■");
			else
				printf("  ");
		}
		gotoxy(p2x2 * 2, 9 + i);
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0007);
}
void p2prt(int p2x2)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0009);
	for (i = 0; i < 15; i++)
	{
		for (j = 0; j < 11; j++)
		{
			gotoxy((p2x2 * 2) + (j * 2), 9 + i);
			if (p2[i][j] == 888)
				printf("■");
			else
				printf("  ");
		}
		gotoxy(p2x2 * 2, 9 + i);
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0007);
}
void p1del(int p1y1)
{
	for (i = 0; i < 15; i++)
	{
		for (j = 0; j < 11; j++)
		{
			gotoxy((p1y1 * 2) + (j * 2), 9 + i);
			printf("  ");
		}
		gotoxy(p1y1 * 2, 9 + i);
	}
}
void p2del(int p2x2)
{
	for (i = 0; i < 15; i++)
	{
		for (j = 0; j < 11; j++)
		{
			gotoxy((p2x2 * 2) + (j * 2), 9 + i);
			printf("  ");
		}
		gotoxy(p2x2 * 2, 9 + i);
	}
}
int p2atk()
{
	if (p2x - 2 <= p1x)
	{
		p1hp -= 1;
		return 1;
	}
	else return 0;
}
int p1atk(int p1y1)
{
	if (p1x + 2 >= p2x)
	{
		p2hp -= 1;
		return 1;
	}
	else return 0;
}
int inputchk(char c)
{
	if ((c == 'A' || c == 'a') && p1y - 1 > 0)
	{
		p1del(p1y);
		p1x -= 2;
		p1y -= 2;
		p1prt(p1y);
		return 0;
	}
	else if ((c == 'd' || c == 'D') && p1x + 1 != p2x)
	{
		p1del(p1y);
		p1x += 2;
		p1y += 2;
		p1prt(p1y);
		return 0;
	}
	else if (c == 'g' || c == 'G')
	{
		char ssdasada;
		p1atk(p1y);
		p1del(p1y);
		p1aprt(p1y);
		for (int z = 0; z < 20; z++)
		{
			Sleep(10);
			if (kbhit())
				ssdasada = getch();
		}
		p1prt(p1y);
		p2prt(p2x);
	}
	else if ((c == 'k' || c == 'K') && p2x - 1 != p1x)
	{
		p2del(p2x);
		p2x -= 2;
		p2y -= 2;
		p2prt(p2x);
		return 0;
	}
	else if ((c == 'm' || c == 'M') && p2y + 1 < 69)
	{
		p2del(p2x);
		p2x += 2;
		p2y += 2;
		p2prt(p2x);
		return 0;
	}
	else if (c == 'P' || c == 'p')
	{
		char ssdasada;
		p2atk();
		p2del(p2x);
		p2aprt(p2x - 3);
		for (int z = 0; z < 20; z++)
		{
			Sleep(10);
			if (kbhit())
				ssdasada = getch();
		}
		p2prt(p2x);
		p1prt(p1y);
	}
}
char c; // 입력받은 방향키
int main()
{
	fff();
	system("mode con:cols=142 lines=45");
	mainmapset2();
	mainmapset();
	mainmapprt();
	//welcome();
	system("cls");
	menuset();
	mapprt();
	pr(); // 프롤로그
	system("cls");
	aset();
	aprt();
	p1set();
	p2set();
	p1aset();
	p2aset();
	p1prt(1);
	p2prt(58);
	gotoxy(0, 25);
	printf("엔터키를 누르세요!                                                ");
	char aaa;
	scanf("%c", &aaa);
	gotoxy(0, 25);
	printf("                                                                       ");
	int ii, jj;
	while (1)
	{
		if (p1hp == 0 || p2hp == 0)
			break;

		if (kbhit())
		{
			c = getch();
			inputchk(c);
			gotoxy(2, 1);
			printf("                   ");
			gotoxy(2, 1);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x000d);
			for (ii = 0; ii < p1hp; ii++)
				printf("♥");
			gotoxy(118, 1);
			printf("                   ");
			gotoxy(118, 1);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x000b);
			for (ii = 0; ii < p2hp; ii++)
				printf("♥");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0007);
		}
	}
	gotoxy(0, 25);
	if (p1hp > p2hp)
		printf("P1 승리! \n");
	else
		printf("P2 승리! \n");
	Sleep(4000);
}