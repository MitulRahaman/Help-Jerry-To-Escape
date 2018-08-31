#ifndef MYHEADER_H_INCLUDED
#define MYHEADER_H_INCLUDED

int score = 0;
char gamePoint[100];
struct jerry
{
	int x;
	int y;
	int height;
	int width;
}j;

struct Coin
{
	int x;
	int y;
	int height;
	int width;
	bool showCoin;
	int index = 0;
};
Coin C[50];

struct High_score
{
	char name[20];
	int score;

	High_score()
		{
			;
		}
	High_score(char* _name = "", int _score=0)
	{
		strcpy(name, _name);
		score = _score;
	}
};
High_score high_score("None",0);

void setValuejerry()
{
	j.x = 40;
	j.y = 150;
	j.height = 160;
	j.width = 100;
}

void setValueCoin()
{
	for (int i = 0,j=160; i < 50,j<=1500; i++,j+=80)
	{
		C[i].x = j;
		C[i].y = 200;
		C[i].height = 32;
		C[i].width = 32;
		C[i].showCoin = true;
		C[i].index++;
	}
}


#endif // !MYHEADER_H_INCLUDED
