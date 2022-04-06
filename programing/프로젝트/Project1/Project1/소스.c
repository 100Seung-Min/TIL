#pragma warning(disable:4996)
#pragma comment (lib,"ws2_32.lib")
#pragma comment(lib,"winmm.lib")
#include <winsock2.h>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include <mmsystem.h>  

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define GOOD "C:\\Users\\user\\Downloads\\clap.wav"
#define BAD "C:\\Users\\user\\Downloads\\disa.wav"

int bad1[7][20] = {
	{0,1,1,1,0,0,0,0,0,1,1,1,0,0,1,1,1,1,0,0},
	{0,1,0,0,1,0,0,0,1,0,0,1,0,0,1,0,0,0,1,0},
	{0,1,0,0,1,0,0,1,0,0,0,1,0,0,1,0,0,0,1,0},
	{0,1,1,1,0,0,0,1,0,0,0,1,0,0,1,0,0,0,1,0},
	{0,1,0,0,1,0,0,1,1,1,1,1,0,0,1,0,0,0,1,0},
	{0,1,0,0,1,0,0,1,0,0,0,1,0,0,1,0,0,0,1,0},
	{0,1,1,1,0,0,0,1,0,0,0,1,0,0,1,1,1,1,0,0}
};
int down[7][5] = {
	{0,1,1,1,0},
	{0,1,1,1,0},
	{0,1,1,1,0},
	{0,1,1,1,0},
	{1,1,1,1,1},
	{0,1,1,1,0},
	{0,0,1,0,0}
};
int draw[7][20] = {
	{0,1,1,1,0,1,1,1,1,0,0,0,1,1,1,1,0,0,0,1},
	{0,1,0,0,1,1,0,0,0,1,0,1,0,0,1,1,0,0,0,1},
	{0,1,0,0,1,1,0,0,0,1,1,0,0,0,1,1,0,0,0,1},
	{0,1,0,0,1,1,1,1,1,0,1,0,0,0,1,1,0,0,0,1},
	{0,1,0,0,1,1,0,1,0,0,1,1,1,1,1,1,0,1,0,1},
	{0,1,0,0,1,1,0,0,1,0,1,0,0,0,1,1,0,1,0,1},
	{0,1,1,1,0,1,0,0,0,1,1,0,0,0,1,0,1,0,1,0}
};
int good1[7][20] = {
	{0,0,1,1,0,0,0,1,1,0,0,0,1,1,0,0,1,1,1,0},
	{0,1,0,0,1,0,1,0,0,1,0,1,0,0,1,0,1,0,0,1},
	{0,1,0,0,0,0,1,0,0,1,0,1,0,0,1,0,1,0,0,1},
	{0,1,0,0,0,0,1,0,0,1,0,1,0,0,1,0,1,0,0,1},
	{0,1,0,1,1,0,1,0,0,1,0,1,0,0,1,0,1,0,0,1},
	{0,1,0,0,1,0,1,0,0,1,0,1,0,0,1,0,1,0,0,1},
	{0,0,1,1,0,0,0,1,1,0,0,0,1,1,0,0,1,1,1,0}
};
int lose[7][20] = {
	{0,1,0,0,0,0,1,1,1,0,0,1,1,1,0,1,1,1,1,0},
	{0,1,0,0,0,1,0,0,0,1,1,0,0,0,1,1,0,0,0,0},
	{0,1,0,0,0,1,0,0,0,1,1,0,0,0,0,1,0,0,0,0},
	{0,1,0,0,0,1,0,0,0,1,0,1,1,1,0,1,1,1,1,0},
	{0,1,0,0,0,1,0,0,0,1,0,0,0,0,1,1,0,0,0,0},
	{0,1,0,0,0,1,0,0,0,1,1,0,0,0,1,1,0,0,0,0},
	{0,1,1,1,1,0,1,1,1,0,0,1,1,1,0,1,1,1,1,0}
};
int map[4][20][20] = {
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
		2,0,1,1,0,1,1,1,0,0,0,0,0,0,0,1,0,1,1,1,
		1,0,0,0,0,1,1,1,1,1,1,0,0,0,0,1,0,0,0,1,
		1,0,1,1,0,1,1,1,1,1,1,1,1,1,0,1,0,0,0,1,
		1,0,1,1,0,1,1,1,0,0,0,1,0,0,0,1,0,1,0,1,
		1,0,1,1,0,0,0,0,0,0,0,1,0,1,0,1,0,1,0,1,
		1,0,0,0,0,1,0,1,1,1,1,1,0,0,0,0,0,1,0,1,
		1,1,1,1,0,1,0,1,0,0,0,0,0,0,0,0,0,1,0,1,
		1,0,0,0,0,1,0,1,0,1,0,1,1,1,1,0,0,1,0,1,
		1,0,0,0,0,1,0,1,0,1,0,0,1,0,0,0,1,1,0,1,
		1,1,1,1,0,0,1,0,0,1,0,1,1,0,0,0,1,1,0,1,
		1,1,1,1,0,0,1,0,1,1,0,1,1,0,1,0,1,1,1,1,
		1,1,1,1,0,1,0,0,0,1,0,1,1,1,0,0,0,0,0,1,
		1,1,1,0,0,1,0,1,0,1,0,0,1,0,0,0,0,0,0,1,
		1,1,1,1,0,1,0,0,0,0,0,0,0,0,0,0,1,0,1,1,
		1,0,1,0,0,1,0,1,0,0,1,0,1,1,1,1,1,0,1,1,
		1,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,1,0,1,1,
		1,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,0,1,1,
		1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,3,
		1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1
	},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	   2,0,0,0,0,1,1,1,0,0,0,1,1,1,0,1,1,1,1,1,
	   1,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,1,1,1,
	   1,0,0,0,1,0,0,1,0,0,1,1,1,0,1,1,0,1,1,1,
	   1,0,1,0,0,1,0,1,1,1,1,1,0,0,1,1,0,1,1,1,
	   1,1,1,1,0,0,0,1,1,1,0,1,1,1,1,1,1,1,1,1,
	   1,0,1,1,1,1,0,1,0,0,0,0,1,1,1,1,1,1,0,3,
	   1,0,1,0,0,0,0,1,1,1,1,0,0,0,1,0,0,0,0,1,
	   1,0,0,0,1,1,1,0,0,0,0,1,1,0,0,0,1,1,1,1,
	   1,0,1,0,0,1,0,0,1,1,1,1,1,1,0,1,1,1,1,1,
	   1,1,1,1,0,0,0,1,1,1,0,0,1,1,0,1,1,1,0,1,
	   1,0,1,1,1,1,0,0,0,0,0,1,1,1,0,1,0,0,0,1,
	   1,0,0,0,0,0,1,0,1,1,0,0,0,0,0,1,0,1,1,1,
	   1,1,0,1,1,0,0,0,0,1,1,1,1,1,1,1,0,1,1,1,
	   1,0,0,1,1,0,1,1,1,0,0,0,0,1,1,0,0,1,1,1,
	   1,0,1,1,1,0,0,1,1,1,0,1,0,0,1,0,1,1,1,1,
	   1,1,1,1,1,1,0,1,1,1,0,0,1,0,0,0,0,0,0,1,
	   1,0,1,0,0,0,0,0,0,0,0,1,1,1,1,0,1,1,0,1,
	   1,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,1,1,0,1,
	   1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1
	  },
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	   2,0,0,0,0,0,1,1,0,0,0,1,1,0,0,0,1,1,1,1,
	   1,1,0,1,1,0,0,0,0,1,0,1,1,0,1,0,0,0,1,1,
	   1,1,0,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,
	   1,0,0,1,0,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,
	   1,1,0,0,0,1,1,1,1,1,0,1,0,1,1,0,0,0,1,1,
	   1,1,1,1,0,1,1,1,1,1,0,1,0,0,1,0,1,1,1,1,
	   1,1,1,1,0,0,0,0,0,0,0,1,1,1,1,0,1,1,1,1,
	   1,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,1,1,1,
	   1,1,1,0,1,1,1,1,1,1,1,1,0,1,1,1,0,0,1,1,
	   1,1,1,0,1,0,0,0,0,0,0,1,1,1,1,1,1,0,1,1,
	   1,1,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,1,1,
	   1,0,0,1,1,0,0,0,0,0,0,1,1,1,1,1,0,1,1,1,
	   1,0,1,1,1,0,1,1,0,1,0,1,1,1,1,1,0,1,1,1,
	   1,1,1,1,1,1,1,0,0,1,1,1,0,0,0,0,0,1,1,1,
	   1,1,1,1,1,1,0,0,1,0,1,1,0,1,1,1,0,0,0,3,
	   1,0,0,1,1,1,1,0,1,0,1,1,0,1,1,1,1,1,0,1,
	   1,1,1,1,1,1,1,0,1,0,1,0,0,0,0,0,0,0,0,1,
	   1,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,
	   1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1
	  },
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	   2,0,1,1,1,1,1,0,0,1,1,1,0,0,0,0,0,0,1,1,
	   1,0,1,1,1,0,0,0,1,1,1,1,0,1,0,1,1,1,1,1,
	   1,0,0,0,0,0,1,0,0,0,0,1,0,1,0,0,0,0,0,3,
	   1,1,0,1,1,1,1,1,0,1,0,1,0,1,0,1,0,1,1,1,
	   1,1,0,1,0,0,1,1,0,1,1,1,0,0,0,1,1,1,1,1,
	   1,0,0,0,0,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,
	   1,0,1,1,1,1,1,1,1,1,0,1,1,1,1,0,0,0,1,1,
	   1,0,0,0,0,1,1,1,1,1,0,1,1,1,1,1,0,1,1,1,
	   1,0,1,1,0,1,1,1,0,0,0,0,0,1,1,1,0,1,1,1,
	   1,1,1,0,0,0,0,1,1,0,1,1,0,0,0,1,0,1,1,1,
	   1,1,1,1,0,1,1,1,1,0,1,1,1,1,0,0,0,1,1,1,
	   1,1,0,0,0,1,0,0,0,0,0,0,1,1,0,1,1,1,1,1,
	   1,1,1,1,0,1,0,1,1,1,0,1,0,0,0,1,1,1,1,1,
	   1,1,1,1,0,0,0,0,1,1,0,1,1,0,1,0,0,0,1,1,
	   1,1,1,1,0,1,1,0,1,1,1,0,0,1,1,0,1,1,1,1,
	   1,1,0,0,0,0,1,1,0,1,1,0,1,0,1,0,0,1,1,1,
	   1,1,0,1,1,0,1,1,0,0,0,0,0,0,0,1,0,1,1,1,
	   1,1,1,1,1,0,0,0,0,1,1,0,1,1,0,0,0,0,1,1,
	   1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1
	}
};
int map2[3][15][15] = {
	{0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
   0,1,1,1,1,1,1,1,1,0,0,0,0,0,1,
   0,1,0,0,1,0,0,0,0,0,0,0,0,0,1,
   0,1,0,0,1,0,1,0,1,1,1,1,1,0,1,
   0,1,0,0,0,0,1,0,1,3,0,0,0,0,1,
   0,1,1,1,1,1,1,0,1,1,1,1,1,1,1,
   0,1,0,0,0,0,0,0,0,0,0,0,0,0,4,
   0,1,0,0,0,0,0,0,0,0,0,0,0,0,4,
   0,1,0,0,0,0,0,0,0,0,0,0,0,0,4,
   0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,
   0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,
   0,1,1,1,1,1,1,1,1,1,1,1,1,0,1,
   0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,
   0,1,2,2,0,0,0,0,0,0,0,0,0,0,1,
   0,1,1,1,1,1,1,1,1,1,1,1,1,1,1

},
  {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
   0,1,2,2,1,0,0,0,0,0,0,0,0,1,1,
   0,1,0,0,1,0,1,1,1,1,0,0,0,1,1,
   0,1,0,1,1,1,1,0,0,1,1,1,0,1,1,
   0,1,0,0,0,0,0,0,0,0,0,1,0,0,1,
   0,1,1,1,1,1,1,1,1,1,0,1,1,0,1,
   0,0,0,0,0,0,0,0,0,1,0,0,0,0,4,
   0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,
   0,0,0,0,0,0,0,0,0,1,0,1,1,0,4,
   0,1,1,1,1,1,1,1,1,1,0,0,1,0,1,
   0,1,3,1,0,0,0,0,0,0,0,0,1,0,1,
   0,1,0,1,0,0,1,1,1,1,1,0,1,0,1,
   0,1,0,1,1,1,1,0,0,0,1,1,1,0,1,
   0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,
   0,1,1,1,1,1,1,1,1,1,1,1,1,1,1

},
  {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
   0,1,0,3,0,0,0,0,0,0,0,0,0,0,1,
   0,1,1,1,1,1,1,1,1,1,1,1,0,1,1,
   0,1,0,0,1,0,0,0,0,0,0,0,0,1,1,
   0,1,0,0,1,0,1,0,0,0,0,0,0,0,1,
   0,1,0,1,1,0,1,0,0,0,0,0,0,0,1,
   0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,
   0,0,0,0,0,0,1,0,0,0,0,0,0,0,4,
   0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,
   0,1,0,0,0,0,1,0,0,0,0,0,0,0,1,
   0,1,0,0,0,0,1,0,0,0,0,0,0,0,1,
   0,1,0,0,0,0,1,1,1,1,1,1,1,1,1,
   0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,
   0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,
   0,1,1,1,1,1,1,1,1,1,1,1,1,1,1
}
};
int num[10][8][5] = {
	{1,1,1,1,1,
	1,0,0,0,1,
	1,0,0,0,1,
	1,0,0,0,1,
	1,0,0,0,1,
	1,1,1,1,1
	},
	{0,0,1,0,0,
	0,1,1,0,0,
	1,0,1,0,0,
	0,0,1,0,0,
	0,0,1,0,0,
	1,1,1,1,1,
	} ,
	{0,1,1,1,0,
	1,0,0,0,1,
	0,0,0,0,1,
	0,0,0,1,0,
	0,0,1,0,0,
	0,1,0,0,0,
	1,1,1,1,1,
	} ,
	{0,1,1,1,0,
	1,0,0,0,1,
	0,0,0,0,1,
	0,0,1,1,0,
	0,0,0,0,1,
	1,0,0,0,1,
	0,1,1,1,0
	},
	{0,0,0,1,0,
	0,0,1,1,0,
	0,1,0,1,0,
	1,0,0,1,0,
	1,1,1,1,1,
	0,0,0,1,0,
	0,0,0,1,0
	},
	{1,1,1,1,1,
	 1,0,0,0,0,
	1,1,1,1,0,
	0,0,0,0,1,
	0,0,0,0,1,
	1,0,0,0,1,
	0,1,1,1,0
	},
	{0,1,1,1,0,
	 1,0,0,0,1,
	 1,0,0,0,0,
	 1,1,1,1,0,
	1,0,0,0,1,
	 1,0,0,0,1,
	0,1,1,1,0
	},
	{1,1,1,1,1,
	 0,0,0,0,1,
	0,0,0,1,0,
	0,0,1,0,0,
	0,1,0,0,0,
	0,1,0,0,0,
	0,1,0,0,0
	},
	{0,1,1,1,0,
	1,0,0,0,1,
	1,0,0,0,1,
	0,1,1,1,0,
	1,0,0,0,1,
	1,0,0,0,1,
	0,1,1,1,0
	},
	{0,1,1,1,0,
	 1,0,0,0,1,
	 1,0,0,0,1,
	 0,1,1,1,1,
	 0,0,0,0,1,
	 1,0,0,0,1,
	0,1,1,1,0
	}
};
int paper[16][13] = {
		{0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,1,0,0,0,0,0,0},
		{0,0,0,0,1,1,0,1,1,0,0,0,0},
		{0,0,0,1,0,1,0,1,0,1,0,0,0},
		{0,0,0,1,0,1,0,1,0,1,1,0,0},
		{0,0,1,1,0,1,0,1,0,1,0,1,0},
		{0,1,0,1,0,1,0,1,0,1,0,1,0},
		{0,1,0,1,0,1,0,1,0,1,0,1,0},
		{0,1,0,1,0,1,0,1,0,1,0,1,0},
		{0,1,0,0,0,0,0,0,0,0,0,1,0},
		{0,1,0,0,0,0,0,0,0,0,0,1,0},
		{0,1,0,0,0,0,0,0,0,0,0,1,0},
		{0,0,1,0,0,0,0,0,0,0,1,0,0},
		{0,0,0,1,0,0,0,0,0,1,0,0,0},
		{0,0,0,0,1,1,1,1,1,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0}
};
int rock[16][13] = {
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,1,0,1,0,0,0,0,0,0 },
		{ 0,0,0,1,0,1,0,1,1,0,0,0,0 },
		{ 0,0,0,1,0,1,0,1,0,1,0,0,0 },
		{ 0,0,0,1,0,1,0,1,0,1,1,0,0 },
		{ 0,0,1,1,0,1,0,1,0,1,0,1,0 },
		{ 0,1,0,1,0,1,0,1,0,1,0,1,0 },
		{ 0,1,0,1,1,1,1,0,1,1,0,1,0 },
		{ 0,1,0,0,0,0,0,1,0,1,0,1,0 },
		{ 0,1,0,0,1,1,1,0,0,0,1,0,0 },
		{ 0,0,1,0,0,0,0,0,0,0,1,0,0 },
		{ 0,0,0,1,0,0,0,0,0,1,0,0,0 },
		{ 0,0,0,0,1,1,1,1,1,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0 }
};
int scissors[16][13] = {
		{0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,1,0,0,0,0,0,0},
		{0,1,0,0,0,1,0,1,0,0,0,0,0},
		{1,0,1,0,0,1,0,1,0,0,0,0,0},
		{1,0,0,1,0,1,0,1,0,0,0,0,0},
		{0,1,0,1,0,1,0,1,1,0,0,0,0},
		{0,1,0,0,1,1,0,1,0,1,0,0,0},
		{0,0,1,0,1,1,0,1,0,1,1,0,0},
		{0,0,1,1,0,1,0,1,0,1,0,1,0},
		{0,1,0,1,1,1,1,0,1,1,0,1,0},
		{0,1,0,0,0,0,0,1,0,1,0,1,0},
		{0,1,0,0,1,1,1,0,0,0,1,0,0},
		{0,0,1,0,0,0,0,0,0,0,1,0,0},
		{0,0,0,1,0,0,0,0,0,1,0,0,0},
		{0,0,0,0,1,1,1,1,1,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0}
};
int up[7][5] = {
	{0, 0, 1, 0, 0},
	{0, 1, 1, 1, 0},
	{1, 1, 1, 1, 1},
	{0, 1, 1, 1, 0},
	{0, 1, 1, 1, 0},
	{0, 1, 1, 1, 0},
	{0, 1, 1, 1, 0}
};
int win[7][19] = {
	   {0,1,0,0,0,1,0,0,1,1,1,0,0,1,0,0,0,1,0},
	   {0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0},
	   {0,1,0,0,0,1,0,0,0,1,0,0,0,1,1,0,0,1,0},
	   {0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,1,0,1,0},
	   {0,1,0,1,0,1,0,0,0,1,0,0,0,1,0,0,1,1,0},
	   {0,1,0,1,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0},
	   {0,0,1,0,1,0,0,0,1,1,1,0,0,1,0,0,0,1,0}
};
int wow[7][20] = {
	{0,1,0,0,0,1,0,0,0,1,1,0,0,0,1,0,0,0,1,0},
	{0,1,0,0,0,1,0,0,1,0,0,1,0,0,1,0,0,0,1,0},
	{0,1,0,0,0,1,0,0,1,0,0,1,0,0,1,0,0,0,1,0},
	{0,1,0,0,0,1,0,0,1,0,0,1,0,0,1,0,0,0,1,0},
	{0,1,0,1,0,1,0,0,1,0,0,1,0,0,1,0,1,0,1,0},
	{0,1,0,1,0,1,0,0,1,0,0,1,0,0,1,0,1,0,1,0},
	{0,0,1,0,1,0,0,0,0,1,1,0,0,0,0,1,0,1,0,0}
};
int Score;
int I;
int Color;
int Color1 = 15;
int First;
int Count;
int X = 15;
int Y = 16;
int Z = 0;
int J = 0;

void 곱하기(char n, int c, int d);
void 나누기(char n, int c, int g);
void 더하기(char n, int c, int g);
void 빼기(char n, int c, int g);
void alphabet();
void attitude();
void attitude_quize(char quize[20][100], char answer[20][100], char wrong[20][100]);
void attribute();
void bad();
void ch_move(int a[10]);
void clock1();
void coding();
void color(int a);
void cursorView();
void delete_diary();
void diary();
void draw_box();
void exit_EBS();
void game();
void good();
void gotoxy(int, int);
void introduce();
void light(int x, int y);
void maze();
void move(int x, int y, int k);
void numbase();
void open_diary();
void print_light(int z, int x, int y);
void print_map();
void print_num(int k, int x, int y);
void print_result(int x);
void print_result_slot(int x);
void print_rps(int x);
void print_time(int h, int m, int s);
void print_updown(int x);
void rps();
void setcolor(unsigned char _BgColor, unsigned char _TextColor);
void sever();
void slot();
void taza();
void taza_krl(char p[5][5][40]);
void taza_krs(char p[20][40]);
void taza_kwo(char p[90][20]);
void timegame();
void update_diary();
void updown();
int choice(int x, int y, int a, int b, int c, int d);
int choice2(int x, int y, int a, int b, int c, int d);
int choice3(int x, int y, int a, int b, int c, int d);
int end();
int keyControl();
int number();

int main()
{
	cursorView();
	system("title 어린이 종합 교육 프로그램");
	int cnt = 0, x = 7, y = 7, sum;
	time_t before = time(0);
	system("mode con cols=40 lines=30");
	if (First == 0)
	{
		First++;
		printf("\n\n\n\n\n\t┌───────────────────────┐\n");
		printf("\t│\t\t\t│\n");
		printf("\t│  화면을 키시겠습니까?\t│\n");
		printf("\t│\t\t\t│\n");
		printf("\t└───────────────────────┘\n\n\n\n");
		printf("\t   아무 버튼이나 클릭");
		while (1)
		{
			if (kbhit())
			{
				FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
				break;
			}
			cnt++;
			Sleep(10);
			if (cnt >= 500)
				return;
		}
	}
	system("cls");
	printf("\n\n\n   ┌──────────────────────────────┐\n");
	printf("   │                              │\n");
	printf("   │                              │\n");
	printf("   │                              │\n");
	printf("   │                              │\n");
	printf("   │                              │\n");
	printf("   │                              │\n");
	printf("   │                              │\n");
	printf("   │                              │\n");
	printf("   │                              │\n");
	printf("   │                              │\n");
	printf("   │                              │\n");
	printf("   └──────────────────────────────┘");
	gotoxy(15, 4);
	printf("MAIN MENU");
	gotoxy(5, 7);
	printf("> ");
	while (1)
	{
		clock1(before);
		gotoxy(7, 7);
		printf("설정");
		gotoxy(23, 7);
		printf("알파벳게임");
		gotoxy(7, 8);
		printf("숫자게임");
		gotoxy(23, 8);
		printf("예절공부");
		gotoxy(7, 9);
		printf("타자연습");
		gotoxy(23, 9);
		printf("코딩하기");
		gotoxy(7, 10);
		printf("일기장");
		gotoxy(23, 10);
		printf("미니게임");
		gotoxy(7, 11);
		printf("끝말잇기");
		gotoxy(23, 11);
		printf("종료하기");
		sum = choice2(x, y, 7, 11, 7, 23);
		if (sum == 7 || sum == 8 || sum == 9 || sum == 10 || sum == 11)
			y = sum;
		else if (sum == 28 || sum == 12)
			x = sum - 5;
		switch (sum)
		{
		case 14:
			attribute();
			system("cls");
			break;
		case 30:
			alphabet();
			system("cls");
			break;
		case 15:
			number();
			system("cls");
			break;
		case 31:
			attitude();
			system("cls");
			break;
		case 16:
			taza();
			system("cls");
			break;
		case 32:
			coding();
			system("cls");
			break;
		case 17:
			diary();
			system("cls");
			break;
		case 33:
			game();
			system("cls");
			break;
		case 18:
			sever();
			system("cls");
			break;
		case 34:
			exit_EBS();
		}
	}
}

void 곱하기(char n, int c, int d)
{
	system("cls");
	int cnt = 0, a, b, temp, 답;
	a = rand() % c + 1;
	b = rand() % d + 1;
	temp = a * b;
	printf("\t\t\t score: %d / %d\n\n\n\n\n\n\n\n\n\t   ", I, Score);
	printf("답을 입력하시오\n\n\t   ");
	printf("%d %c %d = ? \n\n", a, n, b);
	printf("\t   답 : _\b");
	scanf(" %d", &답);
	if (답 == temp)
	{
		gotoxy(11, 15);
		good();
		Score++;
	}
	else
	{
		gotoxy(11, 15);
		bad();
		Sleep(800);
		printf("\n\t   정답은 %d입니다.", temp);
	}
	Sleep(1000);
	PlaySound(NULL, 0, 0);
}

void 나누기(char n, int c, int g)
{
	system("cls");
	int cnt = 0, a, b, d, 답, temp;
	a = rand() % c;
	b = rand() % g;
	d = a;
	if (a < b)
	{
		a = b;
		b = d;
	}
	temp = a / b;
	printf("\t\t\t score: %d / %d\n\n\n\n\n\n\n\n\n\t   ", I, Score);
	printf("답을 입력하시오\n\n\t   ");
	printf("%d %c %d = ? \n\n", a, n, b);
	printf("\t   답 : _\b");
	scanf(" %d", &답);
	if (답 == temp)
	{
		gotoxy(11, 15);
		good();
		Score++;
	}
	else
	{
		gotoxy(11, 15);
		bad();
		Sleep(800);
		printf("\n\t   정답은 %d입니다.", temp);
	}
	Sleep(1000);
	PlaySound(NULL, 0, 0);
}

void 더하기(char n, int c, int g)
{
	system("cls");
	int cnt = 0, a, b, temp, 답, d;
	a = rand() % c;
	b = rand() % g;
	d = b;
	a = a < b ? d : a;
	temp = a + b;
	printf("\t\t\t score: %d / %d\n\n\n\n\n\n\n\n\n\t   ", I, Score);
	printf("답을 입력하시오\n\n\t   ");
	printf("%d %c %d = ? \n\n", a, n, b);
	printf("\t   답 : _\b");
	scanf(" %d", &답);
	if (답 == temp)
	{
		gotoxy(11, 15);
		good();
		Score++;
	}
	else
	{
		gotoxy(11, 15);
		bad();
		Sleep(800);
		printf("\n\t   정답은 %d입니다.", temp);
	}
	Sleep(1000);
	PlaySound(NULL, 0, 0);
}

void 빼기(char n, int c, int g)
{
	system("cls");
	int cnt = 0, a, b, temp, 답, d;
	a = rand() % c;
	b = rand() % g;
	d = b;
	a = a < b ? d : a;
	temp = a - b;
	printf("\t\t\t score: %d / %d\n\n\n\n\n\n\n\n\n\t   ", I, Score);
	printf("답을 입력하시오\n\n\t   ");
	printf("%d %c %d = ? \n\n", a, n, b);
	printf("\t   답 : _\b");
	scanf(" %d", &답);
	if (답 == temp)
	{
		gotoxy(11, 15);
		good();
		Score++;
	}
	else
	{
		gotoxy(11, 15);
		bad();
		Sleep(800);
		printf("\n\t   정답은 %d입니다.", temp);
	}
	Sleep(1000);
	PlaySound(NULL, 0, 0);
}

void alphabet()
{
	system("title 알파벳게임");
	int ran, j = 0, x = 7, y = 6, sum;
	char en[26], EN[26], answer;
	srand(time(NULL));
	for (int i = 0; i < 26; i++)
	{
		en[i] = i + 97;
		EN[i] = i + 65;
	}
	while (1)
	{
		Score = 0;
		system("cls");
		printf("\n\n\n   ┌────────────────────────────────┐\n");
		printf("   │                                │\n");
		printf("   │                                │\n");
		printf("   │                                │\n");
		printf("   │                                │\n");
		printf("   │                                │\n");
		printf("   │                                │\n");
		printf("   │                                │\n");
		printf("   └────────────────────────────────┘");
		gotoxy(x - 2, y);
		printf("> 소문자 쉬움");
		gotoxy(x + 16, y);
		printf("대문자 쉬움");
		gotoxy(x, y + 1);
		printf("소문자 어려움");
		gotoxy(x + 16, y + 1);
		printf("대문자 어려움");
		gotoxy(x, y + 2);
		printf("뒤로가기");
		gotoxy(x + 16, y + 2);
		printf("종료하기");
		sum = choice(7, 6, 6, 8, 7, 23);
		if (sum == 14 || sum == 30)
		{
			printf("\n\n\n\n\n\n\n     원하는 문제 수를 입력해주세요\n");
			printf("     입력 : _\b");
			scanf_s(" %d", &j);
		}
		system("cls");
		switch (sum)
		{
		case 13:
			for (int i = 0; i < 26; i++)
			{
				do
				{
					printf("\t\t\t  score: 26 / %d\n\n\n\n\n\n\n\n", Score);
					printf("\t   %d번째의 알파벳은 ?\n\n\n", i + 1);
					printf("\t   입력 : _\b");
					scanf(" %c", &answer);
					if (!islower(answer))
					{
						printf("\n\n\t   소문자가 아닙니다.\n");
						printf("\t   다시 입력 하세요\n");
						Sleep(800);
						system("cls");
					}
					else
						break;
				} while (!islower(answer));
				if (answer == en[i])
				{
					gotoxy(11, 14);
					good();
					Score++;
					Sleep(1000);
					system("cls");
					PlaySound(NULL, 0, 0);
				}
				else
				{
					gotoxy(11, 14);
					bad();
					Sleep(800);
					printf("\n\t   정답은 %c였습니다\n", en[i]);
					Sleep(1000);
					system("cls");
					PlaySound(NULL, 0, 0);
				}
			}
			printf("\n\n\n\n\n\n\n\n\n\n\n\t 26개 중에 %d개 맞췄습니다", Score);
			Sleep(800);
			break;
		case 29:
			for (int i = 0; i < 26; i++)
			{
				do
				{
					printf("\t\t\t  score: 26 / %d\n\n\n\n\n\n\n\n", Score);
					printf("\t   %d번째의 알파벳은 ?\n\n\n", i + 1);
					printf("\t   입력 : _\b");
					scanf(" %c", &answer);
					if (!isupper(answer))
					{
						printf("\n\n\t   대문자가 아닙니다.\n");
						printf("\t   다시 입력 하세요\n");
						Sleep(800);
						system("cls");
					}
					else
						break;
				} while (!isupper(answer));
				if (answer == EN[i])
				{
					gotoxy(11, 14);
					good();
					Score++;
					Sleep(1000);
					system("cls");
					PlaySound(NULL, 0, 0);
				}
				else
				{
					gotoxy(11, 14);
					bad();
					Sleep(800);
					printf("\n\t   정답은 %c였습니다\n", EN[i]);
					Sleep(1000);
					system("cls");
					PlaySound(NULL, 0, 0);
				}
			}
			printf("\n\n\n\n\n\n\n\n\n\n\n\t 26개 중에 %d개 맞췄습니다", Score);
			Sleep(800);
			break;
		case 14:
			for (int i = 0; i < j; i++)
			{
				ran = rand() % 25;
				do
				{
					printf("\t\t\t  score: %d / %d\n\n\n\n\n\n\n\n", j, Score);
					printf("\t   %c 다음 알파벳은 ?\n\n\n", en[ran]);
					printf("\t   입력 : _\b");
					scanf(" %c", &answer);
					if (!islower(answer))
					{
						printf("\n\n\t   소문자가 아닙니다.\n");
						printf("\t   다시 입력 하세요\n");
						Sleep(800);
						system("cls");
					}
					else
						break;
				} while (!islower(answer));
				if (answer == en[ran + 1])
				{
					gotoxy(11, 14);
					good();
					Score++;
					Sleep(1000);
					system("cls");
					PlaySound(NULL, 0, 0);
				}
				else
				{
					gotoxy(11, 14);
					bad();
					Sleep(800);
					printf("\n\t   정답은 %c였습니다\n", en[ran + 1]);
					Sleep(1000);
					system("cls");
					PlaySound(NULL, 0, 0);
				}
			}
			printf("\n\n\n\n\n\n\n\n\n\n\n\t %d개 중에 %d개 맞췄습니다", j, Score);
			Sleep(800);
			break;
		case 30:
			for (int i = 0; i < j; i++)
			{
				ran = rand() % 25;
				do
				{
					printf("\t\t\t  score: %d / %d\n\n\n\n\n\n\n\n", j, Score);
					printf("\t   %c 다음 알파벳은 ?\n\n\n", EN[ran]);
					printf("\t   입력 : _\b");
					scanf(" %c", &answer);
					if (!isupper(answer))
					{
						printf("\n\n\t   대문자가 아닙니다.\n");
						printf("\t   다시 입력 하세요\n");
						Sleep(800);
						system("cls");
					}
					else
						break;
				} while (!isupper(answer));
				if (answer == EN[ran + 1])
				{
					gotoxy(11, 14);
					good();
					Score++;
					Sleep(1000);
					system("cls");
					PlaySound(NULL, 0, 0);
				}
				else
				{
					gotoxy(11, 14);
					bad();
					Sleep(800);
					printf("\n\t   정답은 %c였습니다\n", EN[ran + 1]);
					Sleep(1000);
					system("cls");
				}
			}
			printf("\n\n\n\n\n\n\n\n\n\n\n\t %d개 중에 %d개 맞췄습니다", j, Score);
			Sleep(800);
			break;
		case 15:
			return main();
		case 31:
			exit_EBS();
		}
	}
}

void attitude()
{
	system("title 예절공부");
	int num, answer, a, b, x = 7, y = 6, sum;
	char key1[100];
	char quize1[20][100] = {
		"처음보는 웃어른에게는?",
		"아침에 일어났을 때 웃어른에게는?",
		"밤에 잘때 웃어른에게는?",
		"웃어른과 밥을 먹을 때는?",
		"다같이 밥을먹을때는?",
		"누군가에게 부탁할 때는",
		"친구가 대회에서 상을탔을때는?",
		"친구랑 같은주제로 토론할때는?",
		"친한 친구를 만났을때는?",
		"친구가 싫다한 행동을 했을때는?",
		"문화가 다른 친구와 대화할때는?",
		"다른 선생님들을 만났을때는?",
		"어딘가 불편하신분에겐?",
		"사람들과 함께 있을땐?",
		"집에 들어갈 때는?",
		"물건을 주고 받을때는?",
		"밥을 먹을때는?",
		"음식을 먹는 속도는?",
		"공공장소에선?",
		"늦은 시간엔?"
	};
	char quize2[20][100] = {
		"처음보는 사람에게는?",
		"오랜만에 보는 사람에게는?",
		"친구들을 만났을 때에는?",
		"이웃을 만났을때는?",
		"선생님을 만났을 때에는?",
		"선생님께 여쭤볼 것이 있을때는?",
		"어른들께 하기싫다고 말할때는?",
		"친척들이 오랜만에 오셨을떈?",
		"게임을 할때는?",
		"도서관에서 공부할때는?",
		"잘모르는사람에겐?",
		"나가는데 뒤에 사람이 오는걸 보면?",
		"엘리베이터를 탈라는데 다른 사람이 보이면?",
		"친구와 대화를 하고 있을땐?",
		"길가다 지갑이나 돈을 줍게된다면?",
		"친구와 놀던 중 조금 늦게된다면?",
		"나로 인해 친구가 다치게 되면?",
		"바닥에 쓰레기가 떨어져있으면?",
		"누군가의 발을 실수로 밟으면?",
		"먹고 나서 나온 쓰레기는?"
	};
	char quize3[20][100] = {
		"음식이 입속 에 있을 때는?",
		"웃어른이 식사를 끝내지 않았다면?",
		"밥이나 반찬을 먹을 때는?",
		"국물을 마실때는?",
		"어른들이 무엇을 물어볼떼는?",
		"어른들이 불렀을때는?",
		"친구들과 싸움이 났을때는?",
		"형,누나들이 무엇을 물어볼떼는?",
		"밥을 먹을때는?",
		"부모님의 심부름을 부탁받으면?",
		"부모님이 밥먹으라고 하시면?",
		"친구들과의 약속에 늦었을때는?",
		"실수로 어깨를 부딫쳤을때는?",
		"잘못을 했을때는?",
		"약속을 지키지 못했을때는?",
		"친구에게 무엇을 빌릴때는?",
		"부모님에게 무엇이 필요할때 말씀드릴때는?",
		"저녁을 먹기전 할 행동은?",
		"선생님에게 연락드릴때는?",
		"인사를할때는?"
	};
	char quize4[20][100] = {
		"웃어른에게는?",
		"친구에게는?",
		"형, 누나들에게는?",
		"동생들에게는?",
		"어른들한테 용돈받을때는?",
		"가게에서 밥먹을때는",
		"장난감을 가지고 논 뒤엔?",
		"부모님과 놀러갔을때는?",
		"과일을 먹을때는?",
		"영화관에서는?"
		"친구 부모님을 만났을 때는?",
		"친구들과 애기할때는?",
		"전화가 왔을때는?",
		"공부할때는?",
		"밖에 나갔다 왔을때는?",
		"옷을 벗고나서는?",
		"책상은 항상?",
		"신발은 항상?",
		"전화할 때는?",
		"화장실을 사용하고 난뒤에는?"
	};
	char answer1[20][100] = {
		"공손히 인사한다.",
		"아침인사를 드린다.",
		"저녁인사를 드린다.",
		"식사예절을 지키며 먹는다.",
		"가까운 반찬을 가져가서 먹는다.",
		"'제발'이라는 말을 사용하여 부탁한다.",
		"친구에게 긍정적인 말을 한다.",
		"내 의견만 말하지 말고 상대 의견을 존중한다.",
		"너무 친근하다고 쉽게 말을 하지 않는다.",
		"친구에게 미안하다는 말을 하고 앞으로는 하지않도록 한다.",
		"친구의 문화를 이해하고 존중하면서 애기한다.",
		"공손히 인사한다.",
		"괜찮으시냐고 물어보고 도와드린다.",
		"모든 사람들에게 친절히 대한다.",
		"조용히 들어간다.",
		"상대방에게 고마운 마음을 표현한다.",
		"쩝쩝거리는 소리가 안나게 먹는다.",
		"어른들이 다 드시기 전에 일어나지않는다.",
		"조용히 주변사람들을 생각하면서 활동한다.",
		"다른 이웃들이 자고 있을수도 있으니 조용한다."
	};
	char answer2[20][100] = {
		"공손히 인사한다.",
		"반갑게 인사한다.",
		"즐겁게 인사한다.",
		"가볍게 인사한다.",
		"예의바르게 인사한다.",
		"조심스럽게 연락드린다.",
		"하기 싫은 이유를 말하면서 거부한다.",
		"모두에게 공손히 인사한다.",
		"상대방에게 욕을 하지 않는다.",
		"조용히 떠들지 않고 공부한다.",
		"공손하게 친절히 인사한다.",
		"상대방이 나올때까지 문을 잡고 있는다.",
		"엘리베이터 문을 닫지 않는다.",
		"친구의 말을 끊지 않고 들어준다.",
		"부모님이나 근처 경비실에 말한다.",
		"늦은 이유를 설명하고 사과한다.",
		"친구에게 사과하고 어른들에게 말을 한다.",
		"주워서 근처 쓰레기통에 버린다.",
		"누가됬던지 진심을 다해 사과한다.",
		"가지고 있다가 쓰레기통에 버린다."
	};
	char answer3[20][100] = {
		"말하지 않는다.",
		"자리에서 일어나지 않는다.",
		"조용히 먹는다.",
		"소리내며 마시지 않는다.",
		"예의바르게 질문에 답한다.",
		"하고있던일을 잠시 멈추고 애기한다.",
		"서로 잘못했다 하지않고 서로 사과한다.",
		"에의바르게 답한다.",
		"쩝쩝거리지 않고 조용히 먹는다.",
		"할수있는 심부름이면 해본다.",
		"하고있는 일을 멈추고 먹으러 간다.",
		"우선 사과를 하고 이유를 설명한다.",
		"상대가 누구든 사과를한다.",
		"'제발'이라는 말등을 이용하여 빌리고 다쓴뒤엔 고마워를 항상 붙인다.",
		"내가 필요한것이 무엇인지 뭐땜에 필요한지를 설명드리면서 부탁한다.",
		"밥상을 차릴때 도와서 차린다.",
		"늦지 않은시간에 조심히 보낸다",
		"하는 대상이 누구냐에 따라 맞는 인사를 한다"
	};
	char answer4[20][100] = {
		"존대말 써",
		"친하게 말하지만, 상대를 존중한다.",
		"예의바르게 말한다.",
		"다정하게 말한다.",
		"허리를 숙이며 감사합니다를 한다.",
		"다른 테이블에 피해가 안가도록 조용히 먹는다.",
		"장난감 상자에 다시 정리해논다.",
		"부모님 손을 꼭 잡고 조용히 다닌다.",
		"어른들에게 먼저 가져다드린뒤 먹는다.",
		"조용히 소리를 내지 않는다.",
		"공손히 인사한다.",
		"친구들을 존중하면서 얘기한다.",
		"받은뒤 존댓말로 누구세요라고 한다.",
		"남에게 방해안되게 조용히 공부한다.",
		"'다녀왔습니다'라고 한다.",
		"빨래통에 넣어논다.",
		"깨끗히 정리해논다.",
		"신발장에 정리해논다.",
		"자신이 누군지 밝힌다.",
		"사용한뒤 변기 커버를 내리고 물을내린다."
	};
	char wrong1[20][100] = {
	   "안녕",
	   "손으로만 인사한다.",
	   "잘자라고 한다.",
	   "시끄럽게 먹는다.",
	   "흘리면서 먹는다.",
	   "부탁하지 않고 명령조로 말한다.",
	   "친구에게 그런건 쉽다는 듯이 말한다.",
	   "친구의 의견을 무시하고 내할말만 한다.",
	   "친하다고 함부로 말한다.",
	   "상관없다는 듯이 계속한다.",
	   "문화가 다르다고 놀린다.",
	   "무시하고 지나간다.",
	   "이상하다고 하고 지나간다.",
	   "시끄럽게 소리지르면서 다닌다.",
	   "시끄럽게 들어간다.",
	   "던져서준다.",
	   "쩝쩝거리면서 먹는다,",
	   "뛰어다닌다.",
	   "큰소리가 나게 다닌다."

	};
	char wrong2[20][100] = {
		"안녕",
		"핸드폰만 하고있는다.",
		"내 할말만 한다.",
		"인사하지 않고 지나간다.",
		"시간이 늦어도 연락을 한다.",
		"싫다고만 한다.",
		"방에서 나오지 않는다.",
		"시끄럽게 화내면서 한다.",
		"소리를 크게 내면서 한다.",
		"무시한다.",
		"무시하고 문을 닫는다.",
		"엘리베이터 문을 닫고 올라간다.",
		"할말만 한다.",
		"내가 가지고간다.",
		"아무말없이 들어온다.",
		"친구의 잘못이라고 우긴다",
		"무시하고 지나간다.",
		"아무렇지 않게 지나간다.",
		"바닥에 버린다."
	};
	char wrong3[20][100] = {
		"떠든다.",
		"신경쓰지 않고 일어난다.",
		"편식하며 먹는다.",
		"소리내면서 마신다.",
		"대충 대답한다.",
		"늦게 부름에 답한다.",
		"더욱 싸운다.",
		"흘리면서 먹는다.",
		"할수있는일이여도 하지않는다.",
		"하고 있던일던일을 하다가 늦게 먹는다.",
		"아무말없이 그냥 논다.",
		"무시하고 지나간다.",
		"내잘못이 아니라는듯이 애기한다.",
		"변명을 대면서 안혼날라고한다.",
		"말도없이 가져간다음 돌려준다.",
		"필요하다고만 한다.",
		"침대에 누워있다 나온다.",
		"시간이 늦어도 연락한다.",
		"손인사만 건넨다."
	};
	char wrong4[20][100] = {
		"안녕",
		"싫어하는 행동을 한다.",
		"반말을 한다.",
		"앞에서 비속어를 사용한다.",
		"한손으로 받는다.",
		"뛰어다닌다.",
		"치우지 않는다.",
		"혼자 막 다닌다.",
		"먼저먹는다.",
		"시끄럽게 뛰어다닌다.",
		"대충 인사한다.",
		"내 할말만 한다.",
		"반말로 대화한다.",
		"산만하게 공부한다.",
		"그대로 침대나 소파에 눕는다.",
		"아무곳에나 던져놓는다.",
		"짐을 쌓아논다.",
		"신발장에 정리한다.",
		"시끄럽게 내 할말만 하고 끊는다.",
		"변기 뚜껑을 열어놓고 나온다."
	};
	while (1)
	{
		system("cls");
		printf("\n\n\n   ┌──────────────────────────────┐\n");
		printf("   │                              │\n");
		printf("   │                              │\n");
		printf("   │                              │\n");
		printf("   │                              │\n");
		printf("   │                              │\n");
		printf("   │                              │\n");
		printf("   │                              │\n");
		printf("   └──────────────────────────────┘");
		gotoxy(x - 2, y);
		printf("> 웃어른예절");
		gotoxy(x + 16, y);
		printf("인사예절");
		gotoxy(x, y + 1);
		printf("식사예절");
		gotoxy(x + 16, y + 1);
		printf("언어예절");
		gotoxy(x, y + 2);
		printf("뒤로가기");
		gotoxy(x + 16, y + 2);
		printf("종료하기");
		sum = choice(7, 6, 6, 8, 7, 23);
		if (sum != 15 && sum != 31)
		{
			gotoxy(7, 14);
			printf("문제입력");
			scanf(" %d", &num);
		}
		system("cls");
		switch (sum)
		{
		case 13:
			for (int i = 0; i < num; i++)
				attitude_quize(quize1, answer1, wrong1, i);
			break;
		case 29:
			for (int i = 0; i < num; i++)
				attitude_quize(quize2, answer2, wrong2, i);
			break;
		case 14:
			for (int i = 0; i < num; i++)
				attitude_quize(quize3, answer3, wrong3, i);
			break;
		case 30:
			for (int i = 0; i < num; i++)
				attitude_quize(quize4, answer4, wrong4, i);
			break;
		case 15:
			return main();
		case 31:
			exit_EBS();
		}
	}
}

void attitude_quize(char quize[20][100], char answer[20][100], char wrong[20][100], int num)
{
	srand(time(NULL));
	int a, b, c[4], x = 4, y = 10, sum;
	a = rand() % 20;
	b = rand() % 4;
	for (int i = 0; i < 4; i++)
	{
		c[i] = rand() % 20;
		if (c[i] == c[i - 1] && i != 0)
			i--;
		else if (c[i] == c[i - 2] && i == 2)
			i--;
		else if (c[i] == c[i - 3] && i == 3)
			i--;
	}
	gotoxy(2, 5);
	printf("%d. %s\n\n", num + 1, quize[a]);
	for (int j = 0; j < 4; j++)
	{
		{
			gotoxy(x - 2, y);
			printf("> ");
		}
		if (b == j)
		{
			gotoxy(x, y + b);
			printf("%d : %s\n", j + 1, answer[a]);
		}
		else
		{
			gotoxy(x, y + j);
			printf("%d : %s\n", j + 1, wrong[c[j]]);
		}

	}
	sum = choice(4, 10, 10, 13, 4, 4) - 14;
	if (sum == b)
	{
		gotoxy(11, 15);
		good();
		Sleep(1000);
		system("cls");
		PlaySound(NULL, 0, 0);
	}
	else
	{
		gotoxy(11, 15);
		bad();
		Sleep(800);
		gotoxy(11, 16);
		printf("정답은 %d번입니다.\n", b + 1);
		Sleep(1000);
		system("cls");
	}
}

void attribute()
{
	system("title 설정");
	int x = 15, y = 8, sum;
	system("cls");
	for (;;)
	{
		printf("\n\n\n\n\n        ┌────────────────────┐\n");
		printf("        │                    │\n");
		printf("        │                    │\n");
		printf("        │                    │\n");
		printf("        │                    │\n");
		printf("        │                    │\n");
		printf("        │                    │\n");
		printf("        │                    │\n");
		printf("        │                    │\n");
		printf("        │                    │\n");
		printf("        └────────────────────┘\n");
		gotoxy(x - 2, y++);
		printf("> 색깔 바꾸기");
		gotoxy(x, y++);
		printf("기능 설명");
		gotoxy(x, y++);
		printf("뒤로가기");
		gotoxy(x, y);
		printf("종료하기");
		sum = choice(15, 8, 8, 11, 15, 15);
		switch (sum)
		{
		case 23:
			color(0);
			break;
		case 24:
			introduce();
			break;
		case 25:
			return main();
		case 26:
			exit_EBS();
		}
	}
}

void bad()
{
	srand(time(NULL));
	char bad_word[20][40] =
	{
		"아쉽습니다.",
		"조금 더 노력해봅시다.",
		"다음엔 꼭 맞춰봅시다.",
		"틀렸습니다.",
		"아깝습니다.",
		"NOT BAD",
		"포기하지 마세요",
		"FIGHTING!!",
		"다음 기화에"
	};
	int a = rand() % 9;
	printf("%s", bad_word[a]);
	PlaySound(TEXT(BAD), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
}

void ch_move(int a[10])
{
	int x, y;
	for (int i = 0; i < 10; i++)
	{
		if (a[i] == 0)
			break;
		if (map2[J][Y - 3][X / 2] == 5)
		{
			if (J == 2)
			{
				system("cls");
				gotoxy(10, 20);
				printf("CLEAR");
				Sleep(800);
				return main();
			}
			else if (J != 2)
			{
				J++;
				if (X == 29)
					X = 3;
				else if (Y == 4)
					Y = 16;
			}
			break;
		}
		if (a[i] == 1)
		{
			if (Z == 0 && map2[J][(Y - 3) - 1][X / 2] != 1 && map2[J][(Y - 3) - 1][X / 2] != 4)
			{
				if (Y >= 4)
				{
					gotoxy(X, Y);
					printf("  ");
					gotoxy(X, --Y);
					printf("◎");
					Sleep(200);
				}
			}
			else if (Z == 1 && map2[J][(Y - 3)][X / 2 + 1] != 1 && map2[J][(Y - 3)][X / 2 + 1] != 4)
			{
				if (X <= 28)
				{
					gotoxy(X, Y);
					printf("  ");
					X += 2;
					gotoxy(X, Y);
					printf("◎");
					Sleep(200);
				}
			}
			else if (Z == 2 && map2[J][(Y - 3) + 1][X / 2] != 1 && map2[J][(Y - 3) + 1][X / 2] != 4)
			{
				if (Y <= 16)
				{
					gotoxy(X, Y);
					printf("  ");
					gotoxy(X, ++Y);
					printf("◎");
					Sleep(200);
				}
			}
			else if (Z == 3 && map2[J][(Y - 3)][X / 2 - 1] != 1 && map2[J][(Y - 3)][X / 2 - 1] != 4)
			{
				if (X >= 3)
				{
					gotoxy(X, Y);
					printf("  ");
					X -= 2;
					gotoxy(X, Y);
					printf("◎");
					Sleep(200);
				}
			}
		}
		else if (a[i] == 2)
		{
			if (Z == 3)
				Z = 0;
			else
				Z++;
			Sleep(100);
		}
		else if (a[i] == 3)
		{
			if (Z == 0)
				Z = 3;
			else
				Z--;
			Sleep(100);
		}
		else if (a[i] == 4)
		{
			if (map2[J][Y - 3][X / 2] == 2)
			{
				map2[J][Y - 3][X / 2] = 0;
			}
			else if (map2[J][Y - 3][X / 2] == 3)
			{
				map2[J][Y - 3][X / 2] = 0;
				for (int i = 0; i < 15; i++)
					for (int j = 0; j < 15; j++)
						if (map2[J][i][j] == 4)
							map2[J][i][j] = 5;
			}
		}
	}
	x = 4, y = 23;
	for (int i = 0; i < 10; i++)
	{
		gotoxy(x, y);
		printf("  ");
		if (x == 4 || x == 27)
			x += 7;
		else x += 8;
		if (x >= 40)
		{
			y += 2;
			x = 4;
		}
	}
	for (int i = 0; i < 10; i++)
		a[i] = 0;
}

void clock1(time_t before)
{
	time_t now;
	struct tm nt;
	now = time(0);
	if (now == before) {
		localtime_s(&nt, &now);
		gotoxy(14, 2);
		print_time(nt.tm_hour, nt.tm_min, nt.tm_sec);
	}
	if (now != before)
	{
		gotoxy(14, 2);
		before = now;
		localtime_s(&nt, &now);
		print_time(nt.tm_hour, nt.tm_min, nt.tm_sec);
	}
	return before;
}

void coding()
{
	int sum, x = 4, y = 23, a = 35, b = 3, move[10] = { 0, }, i = 0;
	system("mode con cols=40 lines=30");
	gotoxy(0, 0);
	printf("\n\n┌──────────────────────────────┯──────┐\n");
	printf("│                              │      │\n");
	printf("│                              │      │\n");
	printf("│                              │      │\n");
	printf("│                              │      │\n");
	printf("│                              │      │\n");
	printf("│                              │      │\n");
	printf("│                              │      │\n");
	printf("│                              │      │\n");
	printf("│                              │      │\n");
	printf("│                              │      │\n");
	printf("│                              │      │\n");
	printf("│                              │      │\n");
	printf("│                              │      │\n");
	printf("│                              │      │\n");
	printf("│                              │      │\n");
	printf("└──────────────────────────────┷──────┘");
	gotoxy(33, 3);
	printf("> ↑");
	gotoxy(35, 5);
	printf("→");
	gotoxy(35, 7);
	printf("←");
	gotoxy(35, 9);
	printf("☏");
	gotoxy(35, 11);
	printf("◈");
	gotoxy(35, 13);
	printf("■");
	gotoxy(35, 15);
	printf("▲");
	gotoxy(0, 22);
	printf("┌──────┯───────┯───────┯───────┯──────┐\n");
	printf("│      │       │       │       │      │\n");
	printf("┣──────┿───────┿───────┿───────┿──────┫\n");
	printf("│      │       │       │       │      │\n");
	printf("└──────┷───────┷───────┷───────┷──────┘\n");
	while (1)
	{
		print_map();
		gotoxy(X, Y);
		printf("◎");
		sum = choice3(a, b, 3, 15, 35, 35);
		switch (sum)
		{
		case 38:
			if (y == 23 || y == 25)
			{
				gotoxy(x, y);
				if (x == 4 || x == 27)
					x += 7;
				else
					x += 8;
				printf("↑");
				move[i] = 1;
				i++;
			}
			b = 3;
			break;
		case 40:
			if (y == 23 || y == 25)
			{
				gotoxy(x, y);
				if (x == 4 || x == 27)
					x += 7;
				else
					x += 8;
				printf("→");
				move[i] = 2;
				i++;
			}
			b = 5;
			break;
		case 42:
			if (y == 23 || y == 25)
			{
				gotoxy(x, y);
				if (x == 4 || x == 27)
					x += 7;
				else
					x += 8;
				printf("←");
				move[i] = 3;
				i++;
			}
			b = 7;
			break;
		case 44:
			if (y == 23 || y == 25)
			{
				gotoxy(x, y);
				if (x == 4 || x == 27)
					x += 7;
				else
					x += 8;
				printf("☏");
				move[i] = 4;
				i++;
			}
			b = 9;
			break;
		case 46:
			ch_move(move);
			x = 4, y = 23;
			b = 11;
			i = 0;
			break;
		case 48:
			return main();
			b = 13;
			break;
		case 50:
			exit_EBS();
			break;
		}
		if (x >= 40)
		{
			y += 2;
			x = 4;
		}
	}
}

void color(int a)
{
	if (a == 0)
		system("title 배경 색");
	else if (a == 1)
		system("title 글자색");
	int x = 7, y = 6, sum;
	while (1)
	{
		system("cls");
		printf("\n\n\n   ┌────────────────────────────────┐\n");
		printf("   │                                │\n");
		printf("   │                                │\n");
		printf("   │                                │\n");
		printf("   │                                │\n");
		printf("   │                                │\n");
		printf("   │                                │\n");
		printf("   │                                │\n");
		printf("   │                                │\n");
		printf("   │                                │\n");
		printf("   │                                │\n");
		printf("   │                                │\n");
		printf("   │                                │\n");
		printf("   │                                │\n");
		printf("   │                                │\n");
		printf("   └────────────────────────────────┘");
		gotoxy(x - 2, y);
		printf("> 검은색");
		gotoxy(x + 16, y);
		printf("회색");
		gotoxy(x, y + 1);
		printf("파란색");
		gotoxy(x + 16, y + 1);
		printf("연한 파란색");
		gotoxy(x, y + 2);
		printf("녹색");
		gotoxy(x + 16, y + 2);
		printf("연한 녹색");
		gotoxy(x, y + 3);
		printf("청록색");
		gotoxy(x + 16, y + 3);
		printf("연한 청록색");
		gotoxy(x, y + 4);
		printf("빨간색");
		gotoxy(x + 16, y + 4);
		printf("연한 빨간색");
		gotoxy(x, y + 5);
		printf("자주색");
		gotoxy(x + 16, y + 5);
		printf("연한 자주색");
		gotoxy(x, y + 6);
		printf("노란색");
		gotoxy(x + 16, y + 6);
		printf("연한 노란색");
		gotoxy(x, y + 7);
		printf("흰색");
		gotoxy(x + 16, y + 7);
		printf("밝은 흰색");
		gotoxy(x, y + 8);
		printf("뒤로가기");
		gotoxy(x + 16, y + 8);
		printf("종료하기");
		sum = choice(7, 6, 6, 14, 7, 23);
		switch (sum)
		{
		case 13:
			if (a == 0)
			{
				system("color 00");
				Color = 0;
			}
			else if (a == 1)
			{
				setcolor(Color, 0);
				Color1 = 0;
			}
			system("cls");
			break;
		case 29:
			if (a == 0)
			{
				system("color 80");
				Color = 8;
			}
			else if (a == 1)
			{
				setcolor(Color, 8);
				Color1 = 8;
			}
			system("cls");
			break;
		case 14:
			if (a == 0)
			{
				system("color 10");
				Color = 1;
			}
			else if (a == 1)
			{
				setcolor(Color, 1);
				Color1 = 1;
			}
			system("cls");
			break;
		case 30:
			if (a == 0)
			{
				system("color 90");
				Color = 9;
			}
			else if (a == 1)
			{
				setcolor(Color, 9);
				Color1 = 9;
			}
			system("cls");
			break;
		case 15:
			if (a == 0)
			{
				system("color 20");
				Color = 2;
			}
			else if (a == 1)
			{
				setcolor(Color, 2);
				Color1 = 2;
			}
			system("cls");
			break;
		case 31:
			if (a == 0)
			{
				system("color A0");
				Color = 10;
			}
			else if (a == 1)
			{
				setcolor(Color, 10);
				Color1 = 10;
			}
			system("cls");
			break;
		case 16:
			if (a == 0)
			{
				system("color 30");
				Color = 3;
			}
			else if (a == 1)
			{
				setcolor(Color, 3);
				Color1 = 3;
			}
			system("cls");
			break;
		case 32:
			if (a == 0)
			{
				system("color B0");
				Color = 11;
			}
			else if (a == 1)
			{
				setcolor(Color, 11);
				Color1 = 11;
			}
			system("cls");
			break;
		case 17:
			if (a == 0)
			{
				system("color 40");
				Color = 4;
			}
			else if (a == 1)
			{
				setcolor(Color, 4);
				Color1 = 4;
			}
			system("cls");
			break;
		case 33:
			if (a == 0)
			{
				system("color C0");
				Color = 12;
			}
			else if (a == 1)
			{
				setcolor(Color, 12);
				Color1 = 12;
			}
			system("cls");
			break;
		case 18:
			if (a == 0)
			{
				system("color 50");
				Color = 5;
			}
			else if (a == 1)
			{
				setcolor(Color, 5);
				Color1 = 5;
			}
			system("cls");
			break;
		case 34:
			if (a == 0)
			{
				system("color D0");
				Color = 13;
			}
			else if (a == 1)
			{
				setcolor(Color, 13);
				Color1 = 13;
			}
			system("cls");
			break;
		case 19:
			if (a == 0)
			{
				system("color 60");
				Color = 6;
			}
			else if (a == 1)
			{
				setcolor(Color, 6);
				Color1 = 6;
			}
			system("cls");
			break;
		case 35:
			if (a == 0)
			{
				system("color E0");
				Color = 14;
			}
			else if (a == 1)
			{
				setcolor(Color, 14);
				Color1 = 14;
			}
			system("cls");
			break;
		case 20:
			if (a == 0)
			{
				system("color 70");
				Color = 7;
			}
			else if (a == 1)
			{
				setcolor(Color, 7);
				Color1 = 7;
			}
			system("cls");
			break;
		case 36:
			if (a == 0)
			{
				system("color F0");
				Color = 15;
			}
			else if (a == 1)
			{
				setcolor(Color, 15);
				Color1 = 15;
			}
			system("cls");
			break;
		case 21:
			return attribute();
		case 37:
			exit_EBS();
		}
		if (a == 0)
			return color(1);
		else if (a == 1)
			return color(0);
	}
}

void cursorView()
{
	CONSOLE_CURSOR_INFO cursorInfo = { 0, };
	cursorInfo.dwSize = 1;
	cursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

void delete_diary()
{
	int x = 7, y = 10, sum;
	system("cls");
	gotoxy(5, 8);
	printf("정말로 일기를 지우시겠습니까?");
	gotoxy(x - 2, y);
	printf("> 예");
	gotoxy(x + 16, y);
	printf("아니요");
	sum = choice(7, 10, 10, 10, 7, 23);
	if (sum == 17)
	{
		FILE* fout;
		char day[20], did[1000];

		if ((fout = fopen("diary.txt", "wt")) == NULL)
		{
			puts("diary.txt - 파일을 삭제할 수 없습니다.");
			return -1;
			fclose(fout);
		}
	}
	else return;
}

void diary()
{
	system("title 일기장");
	int num, x = 15, y = 8, sum;
	for (;;)
	{
		system("cls");
		printf("\n\n\n\n\n        ┌────────────────────┐\n");
		printf("        │                    │\n");
		printf("        │                    │\n");
		printf("        │                    │\n");
		printf("        │                    │\n");
		printf("        │                    │\n");
		printf("        │                    │\n");
		printf("        │                    │\n");
		printf("        │                    │\n");
		printf("        │                    │\n");
		printf("        └────────────────────┘\n");
		gotoxy(x - 2, y);
		printf("> 일기쓰기");
		gotoxy(x, y + 1);
		printf("일기보기");
		gotoxy(x, y + 2);
		printf("일기삭제");
		gotoxy(x, y + 3);
		printf("뒤로가기");
		gotoxy(x, y + 4);
		printf("종료하기");
		sum = choice(15, 8, 8, 12, 15, 15);
		switch (sum)
		{
		case 23:
			update_diary();
			system("cls");
			break;
		case 24:
			open_diary();
			system("cls");
			break;
		case 25:
			delete_diary();
			system("cls");
			break;
		case 26:
			return main();
		case 27:
			exit_EBS();
		}
	}
}

void draw_box()
{
	printf("\n\n\n   ┌──────────────────────────────┐\n");
	printf("   │                              │\n");
	printf("   │                              │\n");
	printf("   │                              │\n");
	printf("   │                              │\n");
	printf("   │                              │\n");
	printf("   │                              │\n");
	printf("   │                              │\n");
	printf("   │                              │\n");
	printf("   │                              │\n");
	printf("   │                              │\n");
	printf("   │                              │\n");
	printf("   └──────────────────────────────┘");
}

void exit_EBS()
{
	system("cls");
	system("color 01");
	setcolor(0, 0);
	exit(1);
}

void game()
{
	system("title 미니게임");
	int x = 7, y = 6, sum;
	while (1)
	{
		if (Count == 10)
		{
			system("cls");
			gotoxy(8, 12);
			printf("게임을 너무 많이 했습니다.");
			gotoxy(8, 13);
			printf("내일 만나요^^");
			Sleep(800);
			break;
		}
		system("cls");
		printf("\n\n\n   ┌──────────────────────────────┐\n");
		printf("   │                              │\n");
		printf("   │                              │\n");
		printf("   │                              │\n");
		printf("   │                              │\n");
		printf("   │                              │\n");
		printf("   │                              │\n");
		printf("   │                              │\n");
		printf("   │                              │\n");
		printf("   └──────────────────────────────┘");
		gotoxy(x - 2, y);
		printf("> 가위바위보");
		gotoxy(x + 16, y);
		printf("시간맞추기");
		gotoxy(x, y + 1);
		printf("업다운");
		gotoxy(x + 16, y + 1);
		printf("미로게임");
		gotoxy(x, y + 2);
		printf("숫자야구");
		gotoxy(x + 16, y + 2);
		printf("슬롯머신");
		gotoxy(x, y + 3);
		printf("뒤로가기");
		gotoxy(x + 16, y + 3);
		printf("종료하기");
		sum = choice(7, 6, 6, 9, 7, 23);
		switch (sum)
		{
		case 13:
			rps();
			Count++;
			break;
		case 29:
			timegame();
			Count++;
			break;
		case 14:
			updown();
			Count++;
			break;
		case 30:
			maze();
			Count++;
			break;
		case 15:
			numbase();
			Count++;
			break;
		case 31:
			slot();
			Count++;
			break;
		case 16:
			return main();
		case 32:
			exit_EBS();
		}
	}
}

void good()
{
	srand(time(NULL));
	char good_word[20][40] =
	{
		"정답입니다.",
		"천재입니다.",
		"축하합니다.",
		"머리가 좋으시네요.",
		"최고입니다.",
		"참 잘했습니다.",
		"멋집니다.",
		"GOOD",
		"WONDERFUL",
		"NICE",
		"COOL",
		"AMAZING",
		"FANTASTIC",
		"GREAT",
		"똑똑하시네요",
		"엄지 척"
	};
	int a = rand() % 16;
	printf("%s", good_word[a]);
	PlaySound(TEXT(GOOD), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
}

void gotoxy(int x, int y)
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(consoleHandle, pos);
}

void introduce()
{
	system("title 기능설명");
	system("cls");
	int sum;
	for (;;)
	{
		printf("\n\n\n   ┌──────────────────────────────┐\n");
		printf("   │                              │\n");
		printf("   │                              │\n");
		printf("   │                              │\n");
		printf("   │                              │\n");
		printf("   │                              │\n");
		printf("   │                              │\n");
		printf("   │                              │\n");
		printf("   │                              │\n");
		printf("   │                              │\n");
		printf("   │                              │\n");
		printf("   │                              │\n");
		printf("   │                              │\n");
		printf("   │                              │\n");
		printf("   └──────────────────────────────┘");
		gotoxy(5, 7);
		printf("> 숫자게임");
		gotoxy(23, 7);
		printf("타자연습");
		gotoxy(7, 8);
		printf("알파벳 게임");
		gotoxy(23, 8);
		printf("코딩게임");
		gotoxy(7, 9);
		printf("일기장");
		gotoxy(23, 9);
		printf("예절공부");
		gotoxy(7, 10);
		printf("슬롯머신");
		gotoxy(23, 10);
		printf("가위바위보");
		gotoxy(7, 11);
		printf("업다운 게임");
		gotoxy(23, 11);
		printf("미로게임");
		gotoxy(7, 12);
		printf("숫자야구");
		gotoxy(23, 12);
		printf("시간 맞추기");
		gotoxy(7, 13);
		printf("뒤로가기");
		gotoxy(23, 13);
		printf("종료하기");
		sum = choice(7, 7, 7, 13, 7, 23);
		system("cls");
		draw_box();
		switch (sum)
		{
		case 14:
			while (1)
			{
				gotoxy(5, 7);
				printf("1. 난이도를 선택한다");
				gotoxy(5, 8);
				printf("2. 문제 수를 선택한다");
				gotoxy(5, 9);
				printf("3. 계산한 값을 입력에 적는다");
				gotoxy(5, 11);
				printf("* 숫자만 입력해주세요");
				gotoxy(5, 12);
				printf("* 나눗셈은 몫을 적어주세요");
				if (kbhit())
				{
					FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
					break;
				}
			}
			break;
		case 30:
			while (1)
			{
				gotoxy(5, 7);
				printf("1. 원하는 기능을 선택한다");
				gotoxy(5, 8);
				printf("2. 열심히 타자를 친다");
				gotoxy(5, 10);
				printf("* 한글로만 입력을 해주세요");
				if (kbhit())
				{
					FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
					break;
				}
			}
			break;
		case 15:
			while (1)
			{
				gotoxy(5, 7);
				printf("1. 원하는 난이도를 선택하세요");
				gotoxy(5, 8);
				printf("2. 문제수를 입력하세요");
				gotoxy(5, 10);
				printf("* 쉬움은 순서대로");
				gotoxy(5, 11);
				printf("* 어려움은 다음 알파벳");
				gotoxy(5, 12);
				printf("* 한글은 입력하지 말아주세요");
				if (kbhit())
				{
					FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
					break;
				}
			}
			break;
		case 31:
			while (1)
			{
				gotoxy(5, 7);
				printf("1. 원하는 방향을 선택하세요");
				gotoxy(5, 8);
				printf("2. 열쇠를 얻으러 가세요");
				gotoxy(5, 9);
				printf("3. 문이 열리면 탈출을 하세요");
				gotoxy(5, 11);
				printf("→ -> 우회전     ← -> 좌회전");
				gotoxy(5, 12);
				printf("☏ -> 줍기       ◈ -> 시작");
				gotoxy(5, 13);
				printf("■ -> 그만하기   ▲ -> 종료");
				if (kbhit())
				{
					FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
					break;
				}
			}
			break;
		case 16:
			while (1)
			{
				gotoxy(5, 7);
				printf("1. 일기를 적어주세요");
				gotoxy(5, 8);
				printf("2. 무조건 4문장을 적어주세요");
				gotoxy(5, 10);
				printf("* 모든 내용이 삭제됩니다");
				gotoxy(5, 11);
				printf("* 짧은 문장으로 적어주세요");
				if (kbhit())
				{
					FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
					break;
				}
			}
			break;
		case 32:
			while (1)
			{
				gotoxy(5, 7);
				printf("1. 예절 문제를 선택하세요");
				gotoxy(5, 8);
				printf("2. 문제수를 선택하세요");
				gotoxy(5, 9);
				printf("3. 정답을 골라주세요");
				if (kbhit())
				{
					FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
					break;
				}
			}
			break;
		case 17:
			while (1)
			{
				gotoxy(5, 9);
				printf("1. 아무키나 눌러주세요");
				gotoxy(5, 10);
				printf("2. 모두 같은 수로 맞춰주세요");
				if (kbhit())
				{
					FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
					break;
				}
			}
			break;
		case 33:
			while (1)
			{
				gotoxy(5, 7);
				printf("1. 판 수를 입력 해주세요");
				gotoxy(5, 8);
				printf("2. 원하는 것을 선택해주세요");
				gotoxy(5, 10);
				printf("* 키를 입력후 기다려주세요");
				if (kbhit())
				{
					FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
					break;
				}
			}
			break;
		case 18:
			while (1)
			{
				gotoxy(5, 7);
				printf("1. 숫자를 입력합니다");
				gotoxy(5, 8);
				printf("2. ↑는 입력보다 작습니다");
				gotoxy(5, 9);
				printf("3. ↓는 입력보다 큽니다");
				if (kbhit())
				{
					FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
					break;
				}
			}
			break;
		case 34:
			while (1)
			{
				gotoxy(5, 9);
				printf("1. 방향키로 이동합니다");
				gotoxy(5, 10);
				printf("2. 끝으로 이동합니다");
				if (kbhit())
				{
					FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
					break;
				}
			}
			break;
		case 19:
			while (1)
			{
				gotoxy(5, 6);
				printf("1. 3개의 숫자를 입력합니다");
				gotoxy(5, 7);
				printf("2. 자리, 수 일치는 스트라이크");
				gotoxy(5, 8);
				printf("3. 수만 일치하면 볼");
				gotoxy(5, 9);
				printf("4. 9라운드 안에 수를 맞추세요");
				gotoxy(5, 11);
				printf("* 띄어쓰기, 숫자만 입력");
				if (kbhit())
				{
					FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
					break;
				}
			}
			break;
		case 35:
			while (1)
			{
				gotoxy(5, 7);
				printf("1. 맞춰야 할 초가 나옵니다");
				gotoxy(5, 8);
				printf("2. 시간이 흘러갑니다");
				gotoxy(5, 9);
				printf("3. 아무키나 클릭을 하세요");
				gotoxy(5, 10);
				printf("4. 제시된 초를 맞추면 됩니다");
				gotoxy(5, 12);
				printf("* 초를 바꾸려면 아니요 선택");
				if (kbhit())
				{
					FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
					break;
				}
			}
			break;
		case 20:
			return attribute();
		case 36:
			exit_EBS();
		}
		system("cls");
	}
}

void light(int x, int y)
{
	int light[8][9] =
	{
		{0,0,0,0,0},
		{0,0,1,0,0},
		{0,1,1,1,0},
		{1,1,1,1,1},
		{1,1,1,1,1},
		{1,1,1,1,1},
		{0,1,1,1,0},
		{0,0,1,0,0},
	};
	for (int i = 0; i < 8; i++)
	{
		gotoxy(x, y);
		for (int j = 0; j < 9; j++)
		{
			if (light[i][j] == 0)
				printf("  ");
			if (light[i][j] == 1)
				printf("■");
		}
		y++;
	}
}

void maze()
{
	system("title 미로게임");
	system("cls");
	srand(time(NULL));
	int k = rand() % 4;
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			if (map[k][i][j] == 1)
				printf("■");
			else if (map[k][i][j] == 0)
				printf("  ");
			else if (map[k][i][j] == 2)
				printf("●");
			else if (map[k][i][j] == 3)
				printf("끝");
		}
		printf("\n");
	}
	move(0, 1, k);
}

void move(int x, int y, int k)
{
	while (1)
	{
		if (GetAsyncKeyState(VK_UP) & 0x8000 && map[k][y - 1][x / 2] != 1)
		{
			gotoxy(x, y);
			printf("  ");
			gotoxy(x, --y);
			printf("●");
		}
		if (GetAsyncKeyState(VK_DOWN) & 0x8000 && map[k][y + 1][x / 2] != 1)
		{
			gotoxy(x, y);
			printf("  ");
			gotoxy(x, ++y);
			printf("●");
		}
		if (GetAsyncKeyState(VK_LEFT) & 0x8000 && map[k][y][x / 2 - 1] != 1)
		{
			gotoxy(x, y);
			printf("  ");
			x -= 2;
			gotoxy(x, y);
			printf("●");
		}
		if (GetAsyncKeyState(VK_RIGHT) & 0x8000 && map[k][y][x / 2 + 1] != 1)
		{
			gotoxy(x, y);
			printf("  ");
			x += 2;
			gotoxy(x, y);
			printf("●");
		}
		Sleep(100);
		if (map[k][y][x / 2] == 3)
			return game();
	}
}

void numbase()
{
	system("title 숫자야구");
	system("cls");
	int user[3], com[3], num = 0, home = 0, ball = 0, x = 0, y = 0, round = 1;
	srand(time(NULL));
	for (int i = 0; i < 3; i++)
	{
		com[i] = rand() % 9 + 1;
		if (com[i] == com[i - 1] && i != 0)
			i--;
		else if (com[i] == com[i - 2] && i == 2)
			i--;
	}
	do
	{
		system("cls");
		gotoxy(30, 0);
		printf("%dROUND", round);
		gotoxy(10, 22);
		printf("입력 : ");
		for (int i = 0; i < 3; i++)
		{
			scanf(" %d", &user[i]);
			printf("\r");
		}
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
			{
				if (user[i] == com[j])
				{
					if (i == j)
						home++;
					else
						ball++;
				}
			}
		print_light(home, 3, 2);
		print_light(ball, 3, 13);
		setcolor(Color, Color1);
		if (home == 3)
			break;
		num++;
		round++;
		home = 0;
		ball = 0;
		Sleep(1000);
	} while (num < 9);
	gotoxy(10, 24);
	if (num < 9)
		good();
	else
	{
		bad();
		Sleep(800);
		printf("\n정답은 %d %d %d입니다", com[0], com[1], com[2]);
	}
	Sleep(1000);
	PlaySound(NULL, 0, 0);
}

void open_diary()
{
	system("cls");
	char file[] = "C:\\Users\\user\\Documents\\GitHub\\TIL\\programing\\프로젝트\\프로젝트\\diary.txt";
	FILE* fin;
	char s[100];
	if ((fin = fopen(file, "rt")) == NULL) {
		printf("File not found: %s\n", file);
		return -1;
	}
	while (!feof(fin))
		printf("%s", fgets(s, 100, fin));
	fclose(fin);
	while (1)
	{
		if (kbhit())
		{
			FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
			break;
		}
		Sleep(10);
	}
}

void print_light(int z, int x, int y)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	if (z == 0)
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
	light(x, y);
	if (z == 1)
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
	light(x + 11, y);
	if (z == 2)
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
	light(x + 22, y);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	gotoxy(3, 2);
	printf("STRIKE");
	gotoxy(3, 12);
	printf("BALL");
}

void print_map()
{
	int x = 3, y = 3;
	for (int i = 0; i < 15; i++)
	{
		gotoxy(x, y++);
		for (int j = 0; j < 15; j++)
		{
			if (map2[J][i][j] == 0 && j != 0 || map2[J][i][j] == 5)
				printf("  ");
			else if (map2[J][i][j] == 1)
				printf("■");
			else if (map2[J][i][j] == 2)
				printf("♣");
			else if (map2[J][i][j] == 3)
				printf("¶");
			else if (map2[J][i][j] == 4)
				printf("▥");
		}
	}
}

void print_num(int k, int x, int y)
{
	for (int i = 0; i < 8; i++)
	{
		gotoxy(x, y++);
		for (int j = 0; j < 5; j++)
		{
			if (num[k][i][j] == 0)
				printf("  ");
			else if (num[k][i][j] == 1)
				printf("■");
		}
	}
}

void print_result(int x)
{
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			if (x == 1 && win[i][j] == 0 || x == 2 && lose[i][j] == 0 || x == 3 && draw[i][j] == 0)
				printf("  ");
			else if (x == 1 && win[i][j] == 1 || x == 2 && lose[i][j] == 1 || x == 3 && draw[i][j] == 1)
				printf("■");
		}
		printf("\n");
	}
}

void print_result_slot(int x)
{
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			if (x == 1 && good1[i][j] == 0 || x == 2 && bad1[i][j] == 0 || x == 3 && wow[i][j] == 0)
				printf("  ");
			else if (x == 1 && good1[i][j] == 1 || x == 2 && bad1[i][j] == 1 || x == 3 && wow[i][j] == 1)
				printf("■");
		}
		printf("\n");
	}
}

void print_rps(int x)
{
	for (int i = 0; i < 16; i++)
	{
		printf("\t");
		for (int j = 0; j < 13; j++)
		{
			if (x == 1 && paper[i][j] == 0 || x == 2 && rock[i][j] == 0 || x == 3 && scissors[i][j] == 0)
				printf("  ");
			else if (x == 1 && paper[i][j] == 1 || x == 2 && rock[i][j] == 1 || x == 3 && scissors[i][j] == 1)
				printf("□");
		}
		printf("\n");
	}
}

void print_time(int h, int m, int s)
{
	printf("%d", h / 10);
	printf("%d", h % 10);
	printf(" : ");
	printf("%d", m / 10);
	printf("%d", m % 10);
	printf(" : ");
	printf("%d", s / 10);
	printf("%d", s % 10);
}

void print_updown(int x)
{
	for (int i = 0; i < 7; i++)
	{
		printf("\t   ");
		for (int j = 0; j < 5; j++)
		{
			if (x == 1 && up[i][j] == 0 || x == 2 && down[i][j] == 0)
				printf("  ");
			else if (x == 1 && up[i][j] == 1 || x == 2 && down[i][j] == 1)
				printf("□");
		}
		printf("\n");
	}
}

void rps()
{
	system("title 가위바위보");
	int com, num, win = 0, draw = 0, lose = 0, x = 15, y = 25, sum, q = 1, k, j, i, z = 25;
	srand(time(NULL));
	do
	{
		system("cls");
		printf("\n\n\n\n\n\n\n\n\n\t   판수 입력 : _\b");
		scanf("%d", &num);
		if (num < 11 && num > 0)
			break;
		printf("\t   최대 10판까지 할 수 있습니다.");
		Sleep(800);
	} while (1);
	system("cls");
	for (i = 0; i < num; i++)
	{
		com = rand() % 3 + 1;
		gotoxy(x - 2, y);
		printf("> 가위");
		gotoxy(x, y + 1);
		printf("바위");
		gotoxy(x, y + 2);
		printf("보");
		k = 0;
		sum = -1;
		z = 25;
		for (j = rand() % 4 + 4;;)
		{
			if (sum > 0)
				k++;
			else if (sum < 0)
			{
				z = choice2(15, z, 25, 27, 15, 15);
				sum = z - 39;
			}
			gotoxy(0, 0);
			if (q == 1)
			{
				print_rps(3);
				if (k >= j && q == com)
					break;
				else q++;
				Sleep(100);
			}
			else if (q == 2)
			{
				print_rps(2);
				if (k >= j && q == com)
					break;
				else q++;
				Sleep(100);
			}
			else if (q == 3)
			{
				print_rps(1);
				if (k >= j && q == com)
					break;
				else q = 1;
				Sleep(100);
			}
		}
		if (sum == q)
		{
			gotoxy(0, 17);
			print_result(3);
			draw++;
		}
		else if (sum == 1 && q == 3 || sum == 2 && q == 1 || sum == 3 && q == 2)
		{
			gotoxy(0, 17);
			print_result(1);
			win++;
		}
		else
		{
			gotoxy(0, 17);
			print_result(2);
			lose++;
		}
		Sleep(800);
		system("cls");
	}
	printf("\n\n\n\n\n\n\n\n\n\n\n\t   전적 %d전 %d승 %d패 %d무", num, win, lose, draw);
	Sleep(800);
}

void setcolor(unsigned char _BgColor, unsigned char _TextColor) {
	if (_BgColor > 15 || _TextColor > 15) return;

	unsigned short ColorNum = (_BgColor << 4) | _TextColor;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), ColorNum);
}

void sever()
{
	system("title 끝말잇기");
	system("cls");
	SOCKET s, cs;
	WSADATA wsaData;
	SOCKADDR_IN sin, cli_addr;

	if (WSAStartup(WINSOCK_VERSION, &wsaData) != 0) {
		printf("WSAStartup 실패, 에러코드 : %d\n", WSAGetLastError());
		return 0;
	}

	s = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	if (s == INVALID_SOCKET) {
		printf("소켓 생성 실패, 에러코드 : %d\n", WSAGetLastError());
		WSACleanup(); return 0;
	}

	sin.sin_family = AF_INET;
	sin.sin_port = htons(8888);
	sin.sin_addr.S_un.S_addr = htonl(ADDR_ANY);

	if (bind(s, (SOCKADDR*)&sin, sizeof(sin)) == SOCKET_ERROR) {
		printf("bind 실패, 에러코드 : %d\n", WSAGetLastError());
		closesocket(s); WSACleanup(); return 0;
	}

	if (listen(s, 10) != 0) {
		printf("listen 모드 설정 실패, 에러코드 : %d\n", WSAGetLastError());
		closesocket(s); WSACleanup(); return 0;
	}


	int cli_size = sizeof(cli_addr);
	cs = accept(s, (SOCKADDR*)&cli_addr, &cli_size);
	if (cs == INVALID_SOCKET) {
		printf("접속 승인 실패, 에러코드 : %d\n", WSAGetLastError());
		closesocket(s); WSACleanup(); return 0;
	}

	printf("시훈님과 연결되었습니다.\n");

	char Buffer[1024];
	while (1) {
		recv(cs, Buffer, 1024, 0);
		printf("\n시훈 ; %s\n", Buffer);
		printf("\n");
		printf("승민 : ");
		scanf("%s", Buffer);
		if (strcmp(Buffer, "/x") == 0)
			break;
		send(cs, Buffer, strlen(Buffer) + 1, 0);
	}
	if (closesocket(cs) != 0 || closesocket(s) != 0) {
		printf("소켓 제거 실패, 에러코드 : %d\n", WSAGetLastError());
		WSACleanup(); return 0;
	}

	if (WSACleanup() != 0) {
		printf("WSACleanup 실패, 에러코드 : %d\n", WSAGetLastError());
	}

	printf("서버를 종료합니다.\n");
	return main();
}

void slot()
{
	system("title 슬롯머신");
	system("cls");
	int a, b, c;
	a = rand_num(2, 0, 0, 0);
	b = rand_num(14, 1, a, 0);
	c = rand_num(26, 2, a, b);
	gotoxy(0, 0);
	printf("┌───────────┯───────────┯─────────────┐\n");
	printf("│           │           │             │\n");
	printf("│           │           │             │\n");
	printf("│           │           │             │\n");
	printf("│           │           │             │\n");
	printf("│           │           │             │\n");
	printf("│           │           │             │\n");
	printf("│           │           │             │\n");
	printf("│           │           │             │\n");
	printf("│           │           │             │\n");
	printf("└───────────┷───────────┷─────────────┘\n");
	print_num(a, 2, 2);
	print_num(b, 14, 2);
	print_num(c, 26, 2);
	gotoxy(0, 15);
	if (a == b && b == c)
		print_result_slot(3);
	else if (a == b || b == c || a == c)
		print_result_slot(1);
	else
		print_result_slot(2);
	Sleep(1000);
}

void taza()
{
	system("mode con cols=40 lines=30");
	system("title 타자연습");
	srand(time(NULL));
	char kr_sh[20][40] = {
		"안녕하세요",
		"남의 발에 버선 신긴다",
		"내 물건이 좋아야 값을 받는다",
		"눈 코 뜰 사이 없다",
		"가난한 집에 자식이 많다",
		"시골 놈 제 말 하면 온다",
		"콩에서 콩 나고 팥에서 팥 난다",
		"가난한 집 신주 굶듯 한다",
		"가는 세월, 오는 백발",
		"오늘은 하늘이 맑다" };
	char kr_lo[5][5][40] = {
		{
			{"애국가 1절"},
			{"동해물과 백두산이 마르고 닳도록"},
			{"하느님이 보우하사 우리나라 만세"},
			{"무궁화 삼천리 화려 강산"},
			{"대한 사람 대한으로 길이 보전하세"}
		},
		{
			{"애국가 2절"},
			{"남산 위에 저 소나무 철갑을 두른 듯"},
			{"바람 서리 불변함은 우리 기상일세"},
			{"무궁화 삼천리 화려 강산"},
			{"대한 사람 대한으로 길이 보전하세"}
		},
		{
			{"애국가 3절"},
			{"가을 하늘 공활한데 높고 구름 없이"},
			{"밝은 달은 우리 가슴 일편 단심일세"},
			{"무궁화 삼천리 화려 강산"},
			{"대한 사람 대한으로 길이 보전하세"}
		},
		{
			{"애국가 4절"},
			{"이 기상과 이 맘으로 충성을 다하여"},
			{"괴로우나 즐거우나 나라 사랑하세"},
			{"무궁화 삼천리 화려 강산"},
			{"대한 사람 대한으로 길이 보전하세"}
		}
	};
	char kr_wo[90][20] = {
		"상어",
		"자전거",
		"할머니",
		"가방",
		"개울가",
		"산기슭",
		"오스트랄로 피테쿠스",
		"오페라의 유령",
		"악어",
		"꿈",
		"벌",
		"늑대",
		"노트북",
		"컴퓨터",
		"스마트폰",
		"아파트",
		"프로그래밍",
		"햄버거",
		"피자",
		"닭볶음탕",
		"제육볶음",
		"태극기",
		"애국가",
		"서울",
		"노래방",
		"마스크",
		"옷장",
		"영화관",
		"선생님",
		"아버지",
		"어머니",
		"할아버지",
		"나무",
		"감자튀김",
		"키보드",
		"마우스",
		"장난감",
		"강아지",
		"고양이",
		"코끼리",
		"호랑이",
		"사자",
		"거북이",
		"사막",
		"늪지",
		"장마",
		"전봇대",
		"전갈",
		"잠자리",
		"개구리",
		"농구",
		"축구",
		"배드민턴",
		"수영",
		"핸드볼",
		"피구",
		"대학교",
		"고등학교",
		"중학교",
		"초등학교",
		"서점",
		"소방관",
		"경찰관",
		"변호사",
		"검사",
		"환경미화원",
		"판사",
		"회사원",
		"미용사",
		"과학자",
		"요리사",
		"재빵사",
		"금붕어",
		"잉어",
		"스위스",
		"핀란드",
		"네덜란드",
		"뉴욕",
		"워싱턴",
		"홍콩",
		"이탈리아",
		"상하이",
		"도쿄",
		"광주소마고",
		"손가락",
		"발가락",
		"심장",
		"폐",
		"신발",
		"바지",
	};
	int y = 8, x = 15;
	int cnt = 0, c = 0, b = 1, sum, kr;
	char 받는거;
	while (1)
	{
		system("cls");
		printf("\n\n\n\n\n        ┌────────────────────┐\n");
		printf("        │                    │\n");
		printf("        │                    │\n");
		printf("        │                    │\n");
		printf("        │                    │\n");
		printf("        │                    │\n");
		printf("        │                    │\n");
		printf("        │                    │\n");
		printf("        │                    │\n");
		printf("        │                    │\n");
		printf("        └────────────────────┘\n");
		gotoxy(x - 2, y);
		printf("> 짧은 글");
		gotoxy(x, y + 1);
		printf("긴 글");
		gotoxy(x, y + 2);
		printf("단어 연습");
		gotoxy(x, y + 3);
		printf("뒤로가기");
		gotoxy(x, y + 4);
		printf("종료하기");
		sum = choice(15, 8, 8, 12, 15, 15);
		system("cls");
		switch (sum)
		{
		case 23:
			taza_krs(kr_sh);
			break;
		case 24:
			taza_krl(kr_lo);
			break;
		case 25:
			taza_kwo(kr_wo);
			break;
		case 26:
			return main();
		case 27:
			exit_EBS();
			break;
		}
	}
}

void taza_krl(char p[5][5][40])
{
	srand(time(NULL));
	char c[5][40];
	clock_t before;
	double result = 0, speed = 0;
	int cnt = 0, discnt = 0, k = rand() % 4, x = 0, y = 3, b = 0, sum = 19;
	for (;;) {
		if (b == 1) {
			system("cls");
			k = rand() % 4;
			gotoxy(8, 7);
			printf("계속하시겠습니까?");
			gotoxy(6, 11);
			printf("> 예");
			gotoxy(24, 11);
			printf("아니요");
			cnt = 0;
			discnt = 0;
			x = 0;
			y = 0;
			result = 0;
			sum = choice(8, 11, 11, 11, 8, 27);
		}
		if (sum == 19)
		{
			system("cls");
			for (int i = 0; i < 5; i++)
			{
				gotoxy(x, y);
				y += 3;
				printf("%s\n", p[k][i]);
			}
			y = 4;
			for (int i = 0; i < 5; i++)
			{
				before = clock();
				gotoxy(x, y);
				y += 3;
				gets(c[i]);
				result += (double)(clock() - before) / CLOCKS_PER_SEC;
			}
			for (int j = 0; j < 5; j++)
			{
				for (int i = 0; i < 40; i++)
				{
					if (p[k][j][i] == '\0')
						break;
					if (c[j][i] == p[k][j][i])
						cnt++;
					else
					{
						cnt++;
						discnt++;
					}
				}
			}
			printf("오타수 : %d\n", discnt - (discnt / 2));
			speed = (cnt - discnt - (discnt / 2)) * 60 / result;
			printf("%.2f", speed);
			Sleep(800);
			b = 1;
		}
		else if (sum != 19)
		{
			return;
		}
	}
}

void taza_krs(char p[20][40])
{
	srand(time(NULL));
	double result, speed;
	clock_t before;
	int cnt = 0, discnt = 0, c = 0, b = 0, sum = 19, kr = rand() % 10;
	for (;;) {
		if (b == 1) {
			kr = rand() % 10;
			gotoxy(8, 7);
			printf("계속하시겠습니까?");
			gotoxy(6, 11);
			printf("> 예");
			gotoxy(24, 11);
			printf("아니요");
			cnt = 0;
			discnt = 0;
			result = 0;
			sum = choice(8, 11, 11, 11, 8, 27);
		}
		if (sum == 19)
		{
			before = clock();
			system("cls");
			gotoxy(4, 10);
			printf("%s\n", p[kr]);
			char 답[40] = { '\0', };
			gotoxy(4, 13);
			printf("입력 : ");
			scanf(" %[^\n]s", 답);
			while (getchar() != '\n');
			result = (double)(clock() - before) / CLOCKS_PER_SEC;
			for (int i = 0; i < 40; i++)
			{
				if (답[i] > 'a' && 답[i] < 'z')
				{
					c = 1;
					break;
				}
				else
					c = 0;
			}
			if (c != 1)
			{
				for (int i = 0; i < 38; i++)
				{
					if (답[i] == NULL)
						break;
					else if (답[i] == 8)
						답[i + 1] = 답[i];
				}
				for (int i = 0; i < 39; i++)
				{
					if (답[i] != p[kr][i])
					{
						discnt++;
						cnt++;
					}
					else if (답[i] == p[kr][i])
						cnt++;
					else if (답[i] == NULL)
						break;
				}
				gotoxy(20, 0);
				speed = (cnt - discnt - (discnt / 2)) * 60 / result;
				printf("오타수 : %d개\n", discnt - (discnt / 2));
				gotoxy(20, 1);
				printf("타자속도 : %.2f", speed);
				Sleep(800);
				system("cls");
				b = 1;
			}
			else
			{
				gotoxy(8, 22);
				printf("한글로 입력하지 않았습니다.");
				Sleep(800);
				b = 0;
				continue;
			}
		}
		else if (sum != 19)
		{
			return;
		}
	}
}

void taza_kwo(char p[90][20])
{
	srand(time(NULL));
	char c[20];
	clock_t before;
	double result = 0, speed = 0;
	int cnt = 0, discnt = 0, b = 0, sum = 19, k;
	for (;;) {
		if (b == 1) {
			system("cls");
			k = rand() % 90;
			gotoxy(8, 7);
			printf("계속하시겠습니까?");
			gotoxy(6, 11);
			printf("> 예");
			gotoxy(24, 11);
			printf("아니요");
			cnt = 0;
			discnt = 0;
			result = 0;
			sum = choice(8, 11, 11, 11, 8, 27);
		}
		if (sum == 19)
		{
			for (int i = 0; i < 20; i++)
			{
				system("cls");
				k = rand() % 90;
				gotoxy(5, 20);
				printf("%s\n", p[k]);
				before = clock();
				gotoxy(5, 23);
				gets(c);
				result += (double)(clock() - before) / CLOCKS_PER_SEC;
				for (int j = 0; j < 20; j++)
				{
					if (p[k][j] == '\0')
						break;
					if (c[j] == p[k][j])
						cnt++;
					else
					{
						cnt++;
						discnt++;
					}
				}
			}
			printf("오타수 : %d\n", discnt - (discnt / 2));
			speed = (cnt - discnt - (discnt / 2)) * 60 / result;
			printf("%.2f", speed);
			Sleep(800);
			b = 1;
		}
		else if (sum != 19)
		{
			return;
		}
	}
}

void timegame()
{
	system("title 시간 맞추기");
	srand(time(NULL));
	float sum = 0, k;
	int j, a, b;
	do {
		j = rand() % 6 + 4;
		system("cls");
		gotoxy(7, 6);
		printf("목표는 %d초입니다.", j);
		gotoxy(7, 8);
		printf("시작하시겠습니까?");
		gotoxy(5, 11);
		printf("> 예");
		gotoxy(23, 11);
		printf("아니요");
		k = choice(7, 11, 11, 11, 7, 23);
	} while (k != 18);
	if (k == 18)
	{
		system("cls");
		for (int i = 0; i < 200; i++)
		{
			if (kbhit())
			{
				FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
				break;
			}
			Sleep(50);
			sum += 1;
			a = (int)sum % 10;
			print_num(a, 25, 6);
			gotoxy(18, 12);
			printf("■");
			b = sum / 10;
			print_num(b, 5, 6);
		}
		if (sum / 10 == j)
		{
			gotoxy(11, 14);
			good();
		}
		else
		{
			gotoxy(11, 14);
			bad();
			Sleep(800);
			gotoxy(11, 15);
			printf("%f초 차이입니다.", j - (sum / 10));
		}
		Sleep(1000);
		PlaySound(NULL, 0, 0);
	}
}

void update_diary()
{
	system("cls");
	FILE* fout;
	char day[20], did[1000], did1[1000], did2[1000], did3[1000];

	if ((fout = fopen("diary.txt", "at")) == NULL)
	{
		puts("diary.txt - 파일을 생성할 수 없습니다.");
		return -1;
	}
	gotoxy(2, 5);
	printf("날짜입력 : ");
	scanf(" %[^\n]s", day);
	gotoxy(2, 7);
	printf("오늘의 일기");
	gotoxy(2, 9);
	scanf(" %[^\n]s", did);
	gotoxy(2, 10);
	scanf(" %[^\n]s", did1);
	gotoxy(2, 11);
	scanf(" %[^\n]s", did2);
	gotoxy(2, 12);
	scanf(" %[^\n]s", did3);
	fprintf(fout, "\n\t날짜 : %s\n\n\t오늘의 일기\n\t%s\n\t%s\n\t%s\n\t%s\n\n\t------------------", day, did, did1, did2, did3);
	fclose(fout);
}

void updown()
{
	system("title 업다운");
	srand(time(NULL));
	int num = rand() % 100 + 1, ans, cnt = 0, round = 1;
	do
	{
		do
		{
			system("cls");
			gotoxy(30, 0);
			printf("%dROUND", round);
			gotoxy(8, 15);
			printf("입력 : ");
			scanf(" %d", &ans);
			if (ans < 1 || ans > 100)
				printf("1 ~ 100 까지 입력\n");
		} while (ans < 1 || ans > 100);
		if (ans > num)
		{
			gotoxy(0, 5);
			print_updown(2);
		}
		else if (ans < num)
		{
			gotoxy(0, 5);
			print_updown(1);
		}
		else
			break;
		cnt++;
		round++;
		Sleep(800);
	} while (cnt < 9);
	if (cnt < 9)
	{
		gotoxy(8, 17);
		good();
	}
	else
	{
		gotoxy(8, 17);
		bad();
		Sleep(800);
		gotoxy(8, 18);
		printf("정답은 %d", num);
	}
	Sleep(1000);
	PlaySound(NULL, 0, 0);
}

int choice(int x, int y, int a, int b, int c, int d)
{
	int choice;
	while (1)
	{
		choice = keyControl();
		if (choice == 0)
		{
			if (y > a)
			{
				gotoxy(x - 2, y);
				printf(" ");
				gotoxy(x - 2, --y);
				printf(">");
			}
		}
		else if (choice == 1)
		{
			if (y < b)
			{
				gotoxy(x - 2, y);
				printf(" ");
				gotoxy(x - 2, ++y);
				printf(">");
			}
		}
		else if (choice == 2)
		{
			if (x > c)
			{
				gotoxy(x - 2, y);
				printf(" ");
				x -= 16;
				gotoxy(x - 2, y);
				printf(">");
			}
		}
		else if (choice == 3)
		{
			if (x < d)
			{
				gotoxy(x - 2, y);
				printf(" ");
				x += 16;
				gotoxy(x - 2, y);
				printf(">");
			}
		}
		else if (choice == 4)
		{
			return x + y;
		}
	}
}

int choice2(int x, int y, int a, int b, int c, int d)
{
	int choice;
	if (!kbhit())
		return y;
	choice = keyControl();
	if (choice == 0)
	{
		if (y > a)
		{
			gotoxy(x - 2, y);
			printf(" ");
			gotoxy(x - 2, --y);
			printf(">");
			return y;
		}
	}
	else if (choice == 1)
	{
		if (y < b)
		{
			gotoxy(x - 2, y);
			printf(" ");
			gotoxy(x - 2, ++y);
			printf(">");
			return y;
		}
	}
	else if (choice == 2)
	{
		if (x > c)
		{
			gotoxy(x - 2, y);
			printf(" ");
			x -= 16;
			gotoxy(x - 2, y);
			printf(">");
			return x + 5;
		}
	}
	else if (choice == 3)
	{
		if (x < d)
		{
			gotoxy(x - 2, y);
			printf(" ");
			x += 16;
			gotoxy(x - 2, y);
			printf(">");
			return x + 5;
		}
	}
	else if (choice == 4)
	{
		return x + y;
	}
}

int choice3(int x, int y, int a, int b, int c, int d)
{
	int choice;
	while (1)
	{
		choice = keyControl();
		if (choice == 0)
		{
			if (y > a)
			{
				gotoxy(x - 2, y);
				printf(" ");
				y -= 2;
				gotoxy(x - 2, y);
				printf(">");
			}
		}
		else if (choice == 1)
		{
			if (y < b)
			{
				gotoxy(x - 2, y);
				printf(" ");
				y += 2;
				gotoxy(x - 2, y);
				printf(">");
			}
		}
		else if (choice == 2)
		{
			if (x > c)
			{
				gotoxy(x - 2, y);
				printf(" ");
				x -= 16;
				gotoxy(x - 2, y);
				printf(">");
			}
		}
		else if (choice == 3)
		{
			if (x < d)
			{
				gotoxy(x - 2, y);
				printf(" ");
				x += 16;
				gotoxy(x - 2, y);
				printf(">");
			}
		}
		else if (choice == 4)
		{
			return x + y;
		}
	}
}

int end()
{
	int sum;
	system("cls");
	gotoxy(8, 8);
	printf("다시 하시겠습니까?");
	gotoxy(6, 10);
	printf("> 예");
	gotoxy(24, 10);
	printf("아니요");
	sum = choice(8, 10, 10, 10, 8, 24);
	return sum;
}

int keyControl()
{
	int temp = getch();
	if (temp == 224)
	{
		temp = getch();
		switch (temp)
		{
		case 72:
			FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
			return UP;
		case 80:
			FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
			return DOWN;
		case 75:
			FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
			return LEFT;
		case 77:
			FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
			return RIGHT;
		}
	}
	else if (temp == 13)
	{
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
		return 4;
	}
}

int number()
{
	system("title 숫자게임");
	int 기호 = 0, x = 7, y = 6, sum;
	srand(time(NULL));
	system("cls");
	printf("\n\n\n   ┌────────────────────────────────┐\n");
	printf("   │                                │\n");
	printf("   │                                │\n");
	printf("   │                                │\n");
	printf("   │                                │\n");
	printf("   │                                │\n");
	printf("   │                                │\n");
	printf("   │                                │\n");
	printf("   └────────────────────────────────┘");
	gotoxy(x - 2, y);
	printf("> 쉬움");
	gotoxy(x + 16, y);
	printf("보통");
	gotoxy(x, y + 1);
	printf("어려움");
	gotoxy(x + 16, y + 1);
	printf("매우 어려움");
	gotoxy(x, y + 2);
	printf("뒤로가기");
	gotoxy(x + 16, y + 2);
	printf("종료하기");
	Score = 0;
	for (;;)
	{
		sum = choice(7, 6, 6, 8, 7, 23);
		if (sum != 15 && sum != 31)
		{
			gotoxy(9, 16);
			printf("문제수를 입력해주세요\n");
			printf("         입력 : _\b");
			scanf(" %d", &I);
			if (I > 99 || I < 1)
			{
				printf("\n\n\t   지원되지 않습니다");
				printf("\n\t   다시 입력해주세요");
				Sleep(800);
				system("cls");
				continue;
			}
		}
		break;
	}
	if (sum == 13)
	{
		sum = 10;
	}
	else if (sum == 29)
	{
		sum = 20;
	}
	else if (sum == 14)
	{
		sum = 30;
	}
	else if (sum == 30)
	{
		sum = 40;
	}
	else if (sum == 15)
	{
		return main();
	}
	else if (sum == 31)
	{
		exit_EBS();
	}
	for (int l = 0; l < I; l++)
	{
		기호 = rand() % 4;
		if (기호 == 0 || 기호 == 1 || 기호 == 2 || 기호 == 3)
		{
			switch (기호)
			{
			case 0:
				더하기('+', sum, sum);
				break;
			case 1:
				곱하기('*', sum, sum);
				break;
			case 2:
				빼기('-', sum, sum);
				break;
			case 3:
				나누기('/', sum, sum);
				break;
			}
		}
	}
	system("cls");
	printf("\n\n\n\n\n\n\n\n\n\n\t   %d개중 %d개 맞췄습니다.", I, Score);
	Sleep(800);
	return number();
}

int rand_num(int x, int a, int y, int z)
{
	for (int i = 0;; i++)
	{
		gotoxy(0, 0);
		printf("┌───────────┯───────────┯─────────────┐\n");
		printf("│           │           │             │\n");
		printf("│           │           │             │\n");
		printf("│           │           │             │\n");
		printf("│           │           │             │\n");
		printf("│           │           │             │\n");
		printf("│           │           │             │\n");
		printf("│           │           │             │\n");
		printf("│           │           │             │\n");
		printf("│           │           │             │\n");
		printf("└───────────┷───────────┷─────────────┘\n");
		if (i == 10)
			i = 0;
		if (a == 1)
			print_num(y, 2, 2);
		else if (a == 2)
		{
			print_num(y, 2, 2);
			print_num(z, 14, 2);
		}
		print_num(i, x, 2);
		Sleep(70);
		if (kbhit())
		{
			FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
			return i;
		}
	}
}