# include "iGraphics.h"
# include "myheader.h"
# include "veriable.h"
# include "collision.h"
# include "Loadimage.h"
void jerry_move()
{
	stand = false;
	index++;
	if (index >= 8)
	{
		index = 0;
	}
	
}

void change_background()//background movement
{ if(game_on==true)
	{
	for (int i = 0;i < 2; i++)
	{
		if (bg_x[i] + 1500 <= 0)
		{
			bg_x[i] = bg_x[(i + 1) % 2] + 1500;
		}

	}
	//getchar();
		for (int i = 0;i < 2; i++)
		{
			bg_x[i] -= 100;
			printf("%d %d %d\n", i, bg_x[i], bg_x[i]+1500);
		}
		
	}

	
}

void change_coin()//coin changin
{
	if (game_on == true)
	{



		for (int i = 0;i < 2; i++)
		{
			C_x[i] -= 5;
			/*if (C_x[i] + 32 < 0)
			{
				C_x[i] = C_x[(i + 1) % 2 ] + 32;
			}*/
		}
	}
}

void high_score_read()
{

	FILE *fp = fopen("highscore.bin", "rb");
	if (fp != NULL)
		//fp = fopen("high_score.bin", "wb");
		{
		fread(&high_score, sizeof(High_score), 1, fp);
		fclose(fp);

		}
}
/*
	function iDraw() is called again and again by the system.
*/
int gameState = 0;

void iDraw()
{
	//place your drawing codes here
	iClear();
	iSetColor(rand() % 255, 0, 0);
	_itoa(score, gamePoint, 10);
	
	//menu
	if (gameState == 0)
	{
		iShowImage(0, 0, 1500, 1000, menu);
		iShowImage(100, 800, 200, 50, b1);
		iShowImage(100, 700, 200, 50, b2);
		iShowImage(100, 600, 200, 50, b3);
		iShowImage(100, 500, 200, 50, b4);
		iShowImage(100, 400, 200, 50, b5);
	}
	else if(gameState == 1)
	{
		for (int i = 0; i < 2; i++)
		{
			iShowImage(bg_x[i], 0, 1500, 1000, bg[i]);
		}
		if (!stand)
		{
			iShowImage(j.x, j.y, j.height, j.width, je[index]);
			
		}
		else {
			iShowImage(j.x, j.y, j.height, j.width, js);
		}
		//for coin movement
		for (int i = 0; i < 50; i++)
		{
			if (C[i].showCoin)
			{
				iShowImage(C[i].x, C[i].y, C[i].width, C[i].height, coin[i]);
			}
		}
		iSetColor(0,0,0);
		iText(1400, 900, gamePoint, GLUT_BITMAP_TIMES_ROMAN_24);

	}
	else if(gameState == 2)
		iShowImage(0, 0, 1500, 1000, level);
	else if(gameState == 3)
		iShowImage(0, 50, 1500, 1000, instruction);
	/*for (int i = 0;i < 9;i++)
	{
		iShowImage(j.x, j.y, j.width, j.height, je[i]);
	}*/

}

/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{
	//place your codes here
}

/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
	if(button == GLUT_LEFT_BUTTON)
	{
		
		if (mx >= 100 && mx <= 300 && my >= 800 && my <= 850)//start game
		{
			gameState = 1;
			game_on = true;
			PlaySound("music\\1.wav", NULL, SND_LOOP | SND_ASYNC);
		}

		if (mx >= 100 && mx <= 300 && my >= 700 && my <= 750)//option
			gameState = 2;


		if (mx >= 100 && mx <= 300 && my >= 600 && my <= 650)//instruction
			gameState = 3;

		if (mx >= 100 && mx <= 300 && my >= 400 && my <= 450)//quit
			exit(0);
		
		if (mx >= 600 && mx <= 650 && my >= 400 && my <= 480)
			gameState = 0;

		if (mx >= 80 && mx <= 400 && my >= 40 && my <= 70)
			gameState = 0;
	}
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		for (int i = 0; i < 50; i++)
		{
			C[i].showCoin = true;
		}
	}
}
/*iPassiveMouseMove is called to detect and use
the mouse point without pressing any button */

void iPassiveMouse(int mx,int my)
{
	//place your code here

 mposx = mx;
 mposy = my;
 if(mx== 2){}        /*Something to do with mx*/
 else if(my== 2){}   /*Something to do with my*/

}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
*/
void iKeyboard(unsigned char key)
{
	if(key == 'w')
	{
		//do something with 'q'
	}
	if (key == 's')
	{
		//do something with 'q'
	}
	if (key == 'l')
	{
		//j.x -= 5;

	}
	if (key == 'r')
	{
		
	}
	//place your codes for other keys here
}

/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/
void iSpecialKeyboard(unsigned char key)
{

	if(key == GLUT_KEY_END)
	{
		printf(":%d\n", score);
		if (score > high_score.score)
		{
			FILE *fp = fopen("high_score.bin", "wb");
			high_score.score = score;
			fwrite(&high_score, sizeof(High_score), 1, fp);
			fclose(fp);
			getchar();
		}
		
		exit(0);
	}
	else if (key == GLUT_KEY_RIGHT)
	{
		if(j.x<1400)
		j.x += 10;
		

	}
	else if (key == GLUT_KEY_LEFT)
	{
		if (j.x>10)
		j.x -= 10;
		
	}
	else if (key == GLUT_KEY_UP)
	{
		if (j.y != 30)
		{
			j.x += 2;
			j.y += 5;
		}
	
		
	}
	else if (key == GLUT_KEY_DOWN)
	{
		/*if (j.y = 30)
		{
		j.x += 2;
		j.y -= 5;
		}*/
	}
	else if (key == GLUT_KEY_HOME)
	{
		gameState = 0;
	}
	//place your codes for other keys here
}
//
int main()
{
	C_x[0] = 160;
	C_x[1] = 200;
	C_y[0] = 0;
	C_y[1] = 0;

	//place your own initialization codes here.
	/*/if (musicOn)
	{
		PlaySound("music\\1", NULL, SND_LOOP | SND_ASYNC);
	}*/
	iInitialize(1500, 1000, "Help Jerry to Escape");
	setValuejerry();
	setValueCoin();
	eatCoin();
	iSetTimer(5, eatCoin);
	iSetTimer(250, change_background);
	iSetTimer(2000,change_coin);

	iSetTimer(250, jerry_move);
	menu = iLoadImage("image\\menu.png");
	level = iLoadImage("image\\level.png");
	instruction = iLoadImage("image\\instruction.png");
	b1 = iLoadImage("image\\m1.png");
	b2 = iLoadImage("image\\m2.png");
	b3 = iLoadImage("image\\m3.png");
	b4 = iLoadImage("image\\m4.png");
	b5 = iLoadImage("image\\m5.png");
	bg[0] = iLoadImage("image\\bg1.png");
	bg[1] = iLoadImage("image\\bg.png");
	je[0] = iLoadImage("je\\1.png");
	je[1] = iLoadImage("je\\2.png");
	je[2] = iLoadImage("je\\3.png");
	je[3] = iLoadImage("je\\4.png");
	je[4] = iLoadImage("je\\5.png");
	je[5] = iLoadImage("je\\6.png");
	je[6] = iLoadImage("je\\7.png");
	je[7] = iLoadImage("je\\8.png");
	js = iLoadImage("je\\10.png");

	

	
	high_score_read();
	printf("%d\n", high_score.score);




	//jerry = iLoadImage("image\\jerry.png");
	for (int i = 0;i < 30;i++)
	{
		coin[i] = iLoadImage("image\\Coin.png");
	}
	//fire = iLoadImage("image\\skrell.png");

	iStart();
}
