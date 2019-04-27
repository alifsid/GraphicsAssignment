#include<stdio.h>
#include<graphics.h>
#include<conio.h>

#include<math.h>


void boundaryfill(int x, int y, int fill_col, int boundary_col)
{
     if(getpixel(x,y)!=boundary_col && getpixel(x,y)!=fill_col)
     {
                                    putpixel(x,y,fill_col);
                                    boundaryfill(x+1,y,fill_col,boundary_col);
                                    boundaryfill(x,y+1,fill_col,boundary_col);
                                    boundaryfill(x-1,y,fill_col,boundary_col);
                                    boundaryfill(x,y-1,fill_col,boundary_col);                                    
     }
}

int main()
{
	initwindow(640,480);
	int xcor,ycor,rad,bcol,fcol;
	while(!kbhit())
	{
		xcor=rand()%550;
		ycor=rand()%550;
		rad=rand()%100;
		bcol=rand()%10;
		fcol=rand()%10;
		cleardevice();
		circle(xcor,ycor,rad);
		boundaryfill(xcor,ycor,7,15);
		delay(1000);
	}
	
	closegraph();
	getch();
	return 0;
	
}
