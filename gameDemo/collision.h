#ifndef collision_H_INCLUDED
#define collision_H_INCLUDED

struct Fire
{
	int x;
	int y;
	int height;
	int width;
	bool showFire;
	int index = 0;
}Fire[4];
bool Showfire, Showfire2, Showfire3, Showfire4;
void setValueFire()
{
	for (int i = 0, j = 160; i < 50, j <= 1500; i++, j += 80)
	{
		C[i].x = j;
		C[i].y = 200;
		C[i].height = 32;
		C[i].width = 32;
		C[i].showCoin = true;
		C[i].index++;
	}
}
void FireMove() {

	for (int  i= 0;  i< 5; i++) {
		Fire[i].y -= rand() % 6;
	}

	if (Fire[0].y + 160 <= 0)
	{
		Fire[0].y = 1000 - 200;

		Showfire = true;
			

	}

	if (Fire[1].y + 160 <= 0)
	{
		Fire[1].y = 1000 - 200;
		Showfire2 = true;
	}
	if (Fire[2].y + 160 <= 0)
	{
		Showfire3 = true;
		Fire[2].y = 1000 - 200;
	}
	if (Fire[3].y + 160 <= 0)
	{
		Showfire4 = true;
		Fire[3].y = 1000 - 200;
	}
}



//collision
void eatCoin()
{
	for (int i = 0; i < 50; i++)
	{
		if (j.x + 50 == C[i].x  && C[i].showCoin)//j.y+160 == C[i].y)
		{
			C[i].showCoin = false;
			score++;
			C[i].index = 0;
		}
	}
}

#endif // !collision_H_INCLUDED
