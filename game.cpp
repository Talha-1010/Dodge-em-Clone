//============================================================================
// Name        : game.cpp
// Author      : Talha
// Version     :
// Copyright   : (c) Reserved
// Description : Basic 2D game of Dodge 'Em...
//============================================================================

#ifndef DODGE_CPP_
#define DODGE_CPP_
#include "util.h"
#include <iostream>
#include<string>
#include<cmath>// for basic math functions such as cos, sin, sqrt
#include <unistd.h> 
using namespace std;

//Global variables
float xnew=400,ynew=50,x2new=350,y2new=50; 
int posx,posy;
int xcod[8];
int ycod[8];
int xcod2[8],ycod2[8],xcod3[8],ycod3[8],xcod4[8],ycod4[8],xcod5[8],ycod5[8],xcod1[8],ycod1[8];
int score=0,lives=3;
bool start=false;
bool gap1=false,gap2=false,gap3=false,gap4=false,gap5=false,gap6=false,gap7=false,gap8=false,gap9=false,gap10=false,gap11=false,gap12=false;

// seed the random numbers generator by current time (see the documentation of srand for further help)...

/* Function sets canvas size (drawing area) in pixels...
 *  that is what dimensions (x and y) your game will have
 *  Note that the bottom-left coordinate has value (0,0) and top-right coordinate has value (width-1,height-1)
 * */
void SetCanvasSize(int width, int height) {
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -1, 1); // set the screen size to given width and height.
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity();
}

void Display_car( float x=xnew ,float  y=ynew )
{
 	//Drawing car
 	 
	float width = 7; 
	float height = 7;
	float* color = colors[BLUE_VIOLET]; 
	float radius = 3;
	DrawRoundRect(x,y,width,height,color,radius); // bottom left tyre
	DrawRoundRect(x+width*3,y,width,height,color,radius); // bottom right tyre
	DrawRoundRect(x+width*3,y+height*4,width,height,color,radius); // top right tyre
	DrawRoundRect(x,y+height*4,width,height,color,radius); // top left tyre
	DrawRoundRect(x, y+height*2, width, height, color, radius/2); // body left rect
	DrawRoundRect(x+width, y+height, width*2, height*3, color, radius/2); // body center rect
	DrawRoundRect(x+width*3, y+height*2, width, height, color, radius/2); // body right rect
}

void Display_car_2( float x=x2new ,float  y=y2new )
{
 	//Drawing car 
	float width = 7; 
	float height = 7;
	float* color = colors[YELLOW]; 
	float radius = 3;
	DrawRoundRect(x,y,width,height,color,radius); // bottom left tyre
	DrawRoundRect(x+width*3,y,width,height,color,radius); // bottom right tyre
	DrawRoundRect(x+width*3,y+height*4,width,height,color,radius); // top right tyre
	DrawRoundRect(x,y+height*4,width,height,color,radius); // top left tyre
	DrawRoundRect(x, y+height*2, width, height, color, radius/2); // body left rect
	DrawRoundRect(x+width, y+height, width*2, height*3, color, radius/2); // body center rect
	DrawRoundRect(x+width*3, y+height*2, width, height, color, radius/2); // body right rect
}
void Menu ()
{

glClearColor(0/*Red Component*/, 0,	//148.0/255/*Green Component*/,
0.0/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
glClear (GL_COLOR_BUFFER_BIT); //Update the colors

DrawString( 350, 500,"Menu " ,colors[BLUE]);
DrawString( 300, 450,"   Press the following keys" ,colors[GREEN]);
DrawString( 300, 400,"     1. play       " ,colors[YELLOW]);
DrawString( 300, 350,"     2. help       " ,colors[GREEN]);
DrawString( 300, 300,"     3. exit        " ,colors[RED]);
DrawString( 300, 250,"     4. controls  " ,colors[BLUE]);

glutSwapBuffers();
glutPostRedisplay();
//glutPostRedisplay();
}
 
void PrintableKeys(unsigned char key, int x, int y) 
{
	if (key == 27/* Escape key ASCII*/) 
	{
		exit(1); // exit the program when escape key is pressed.
	}

	if (key == '1' || key == '1')
	{
		//do something if b is pressed
		start=true;

	}
		glutPostRedisplay();
}
/*
 * Main Canvas drawing function.
 * */
//Board *b;

//if(start==true)

//{
void GameDisplay()/**/
{
	
	if(start==true)
	{
	// set the background color using function glClearColor.
	// to change the background play with the red, green and blue values below.
	// Note that r, g and b values must be in the range [0,1] where 0 means dim rid and 1 means pure red and so on.

	glClearColor(0/*Red Component*/, 0,	//148.0/255/*Green Component*/,
			0.0/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); //Update the colors

	// calling some functions from util.cpp file to help students
	//Square at 400,20 position
	//first Arena food
	
	//std::map<position, std::string> game_map;
//game_map[position(0, 0)] = "Commons";

//...   	
	  
	  for(int j=0;j<8;j++)	
	  {
	      		
	      DrawCircle(xcod[j],ycod[j],5,colors[RED]);
		
	  }	
	  for(int j=0;j<8;j++)	
	  {
	      		
	      DrawCircle(  xcod1[j], ycod1[j],5,colors[BLUE]);
		
	  }
	  
	  for(int j=0;j<8;j++)	
	  {
	      		
	      DrawCircle(  xcod2[j], ycod2[j],5,colors[GREEN]);
		
	  }
	  
	  
	  for(int j=0;j<8;j++)	
	  {
	      		
	      DrawCircle(  xcod3[j], ycod3[j],5,colors[YELLOW]);
		
	  }
			
	  
	  for(int j=0;j<8;j++)	
	  {
	      		
	      DrawCircle(  xcod4[j], ycod4[j],5,colors[BLUE]);
		
	  }	
			
	  for(int j=0;j<8;j++)	
	  {
	      		
	      DrawCircle(  xcod5[j], ycod5[j],5,colors[RED]);
		
	  }
				
				
	 
	//Square at 250,250 position
	//DrawSquare( 50 , 250 ,20,colors[GREEN]); 
	//Display Score
	
	DrawString( 50, 840,"Score ="+Num2Str(score),colors[MISTY_ROSE]);
	DrawString( 300, 840,"Remaing lives " +Num2Str(lives), colors[MISTY_ROSE]);
	//Triangle at 300, 450 position
	//DrawTriangle( 300, 450 , 340, 450 , 320 , 490, colors[MISTY_ROSE] ); 
	//Trianlge Vertices v1(300,50) , v2(500,50) , v3(400,250)
	//Circle at 50, 670 position
	//DrawCircle(50,670,10,colors[RED]);
	//Line from 550,50 to 550,480 with width 10
	//DrawLine(int x1, int y1, int x2, int y2, int lwidth, float *color)
	//DrawLine( 550 , 50 ,  550 , 480 , 10 , colors[MISTY_ROSE] );	
	
	// Drawing my car
	Display_car(xnew,ynew);
	
	//opponent car 
	//GetRandInRange(const long 20, const long 780);
	Display_car_2(x2new,y2new);
	

	// Drawing Arena
	int gap_turn = 60;
	int sx = 20;
	int sy = 10;
	int swidth = 800/2 - gap_turn/2; // half width
	int sheight = 10;
	float *scolor = colors[BLUE];
	DrawRectangle(sx, sy, swidth, sheight, scolor); // bottom left
	DrawRectangle(sx + swidth + gap_turn, sy, swidth, sheight, scolor); // bottom right
	DrawRectangle(sx+swidth*2+gap_turn, sy+sheight, sheight*2, swidth, scolor); // right down
	DrawRectangle(sx+swidth*2+gap_turn, sy+sheight+swidth+gap_turn, sheight*2, swidth, scolor); // right up
	DrawRectangle(sx + swidth + gap_turn, sy+810, swidth, sheight, scolor); // top left
	DrawRectangle(sx, sy+810, swidth, sheight, scolor); // top right
	DrawRectangle(sx-sheight*2, sy+sheight+swidth+gap_turn, sheight*2, swidth, scolor); // left up
	DrawRectangle(sx-sheight*2, sy+sheight, sheight*2, swidth, scolor); // left down
    // Drawing Arena
	gap_turn = 60;
	sx = 120;
	sy = 110;
	swidth = 800/2 - gap_turn/2-100; // half width
	sheight = 10;
	float *s1color = colors[BLUE];
	DrawRectangle(sx, sy, swidth, sheight, scolor); // bottom left
	DrawRectangle(sx + swidth + gap_turn, sy, swidth, sheight, scolor); // bottom right
	DrawRectangle(sx+swidth*2+gap_turn, sy+sheight, sheight*2, swidth, scolor); // right down
	DrawRectangle(sx+swidth*2+gap_turn, sy+sheight+swidth+gap_turn, sheight*2, swidth, scolor); // right up
	DrawRectangle(sx + swidth + gap_turn, sy+610, swidth, sheight, scolor); // top left
	DrawRectangle(sx, sy+610, swidth, sheight, scolor); // top right
	DrawRectangle(sx-sheight*2, sy+sheight+swidth+gap_turn, sheight*2, swidth, scolor); // left up
	DrawRectangle(sx-sheight*2, sy+sheight, sheight*2, swidth, scolor); // left down
	
	// Drawing Arena
	gap_turn = 60;
	sx = 220;
	sy = 210;
	swidth = 800/2 - gap_turn/2-200; // half width
	sheight = 10;
	float *s2color = colors[BLUE];
	DrawRectangle(sx, sy, swidth, sheight, scolor); // bottom left
	DrawRectangle(sx + swidth + gap_turn, sy, swidth, sheight, scolor); // bottom right
	DrawRectangle(sx+swidth*2+gap_turn, sy+sheight, sheight*2, swidth, scolor); // right down
	DrawRectangle(sx+swidth*2+gap_turn, sy+sheight+swidth+gap_turn, sheight*2, swidth, scolor); // right up
	DrawRectangle(sx + swidth + gap_turn, sy+410, swidth, sheight, scolor); // top left
	DrawRectangle(sx, sy+410, swidth, sheight, scolor); // top right
	DrawRectangle(sx-sheight*2, sy+sheight+swidth+gap_turn, sheight*2, swidth, scolor); // left up
	DrawRectangle(sx-sheight*2, sy+sheight, sheight*2, swidth, scolor); // left down
	
	
	// Drawing Arena
	gap_turn = 60;
	sx = 320;
	sy = 310;
	swidth = 800/2 - gap_turn/2-300; // half width
	sheight = 10;
	float *s3color = colors[BLUE];
	DrawRectangle(sx, sy, swidth, sheight, scolor); // bottom left
	DrawRectangle(sx + swidth + gap_turn, sy, swidth, sheight, scolor); // bottom right
	DrawRectangle(sx+swidth*2+gap_turn, sy+sheight, sheight*2, swidth, scolor); // right down
	DrawRectangle(sx+swidth*2+gap_turn, sy+sheight+swidth+gap_turn, sheight*2, swidth, scolor); // right up
	DrawRectangle(sx + swidth + gap_turn, sy+210, swidth, sheight, scolor); // top left
	DrawRectangle(sx, sy+210, swidth, sheight, scolor); // top right
	DrawRectangle(sx-sheight*2, sy+sheight+swidth+gap_turn, sheight*2, swidth, scolor); // left up
	DrawRectangle(sx-sheight*2, sy+sheight, sheight*2, swidth, scolor); // left down
	
	// Drawing Arena
	gap_turn = 60;
	sx = 420;
	sy = 410;
	swidth = 800/2 - gap_turn/2-400; // half width
	sheight = 10;
	float *s4color = colors[BLUE];
	DrawRectangle(sx, sy-25, swidth, sheight, scolor); // bottom left
	DrawRectangle(sx + swidth + gap_turn, sy-25, swidth, sheight, scolor); // bottom right
	DrawRectangle(sx+swidth*2+gap_turn+20, sy+sheight, sheight*2, swidth-5, scolor); // right down
	DrawRectangle(sx+swidth*2+gap_turn+20, sy+sheight+swidth+gap_turn, sheight*2, swidth-5, scolor); // right up
	DrawRectangle(sx + swidth + gap_turn, sy+30, swidth, sheight, scolor); // top left
	DrawRectangle(sx, sy+30, swidth, sheight, scolor); // top right
	DrawRectangle(sx-sheight*2-20, sy+sheight+swidth+gap_turn, sheight*2, swidth-5, scolor); // left up
	DrawRectangle(sx-sheight*2-20, sy+sheight, sheight*2, swidth-5, scolor); // left down
	glutSwapBuffers(); // do not modify this line.. or draw anything below this line
	
	cout<< "x "<< x2new << " y"<< y2new <<endl;

	}
}

//}

void Timer(int m) 
{
	
	 // implement your functionality here
	 // once again we tell the library to call our Timer function after next 1000/FPS
	
	 //first arena movement 
	 
	 if(xnew>=400 && xnew<=770 && ynew==50)
		xnew+=10;	
	 if(xnew==760 && ynew>=50 && ynew<=750)
		ynew+=10;
	 if(ynew==750 && xnew>=60 && xnew<=760)
	    xnew-=10;
	 if(xnew==60 && ynew>=50  && ynew<=750)
		ynew-=10;
	 if(ynew==50 && xnew>=60 && xnew<=400 )
		xnew+=10;
	 //second arena movement	
	 if(ynew==150 && xnew>=390 && xnew<=660)
		xnew+=10;	
	 if(xnew==660 && ynew>=150 && ynew<650 )
		ynew+=10;
	 if(ynew==650 && xnew>=170 && xnew<=660)
		xnew-=10;
	 if(xnew==160 && ynew<=660 && ynew>=150)
		ynew-=10;
	 if(ynew==150 && xnew>=150 && xnew<=390)
		xnew+=10;	
	 //third arena movement 
	 if(ynew==250 && xnew>=390  && xnew<=560)
		xnew+=10;					
	 if(xnew==560 && ynew>=250 && ynew <=560)
		ynew+=10;
	 if(ynew==560 && xnew<=560 && xnew>=250)
		xnew-=10;
	 if(xnew==260 && ynew<=560 && ynew>=250)
		ynew-=10;
	 if(ynew==250 && xnew>=250 && xnew<=390)
		xnew+=10;
	//fourth Arena movement 	 
	 if(ynew==340 && xnew>=340 && xnew<=470)
	 	xnew+=10;
	 if(xnew==470 && ynew>=340 && ynew<=460)
	 	ynew+=10;
	 if(ynew==460 && xnew<=470 && xnew>=340)
	 	xnew-=10;
	 if(xnew==340 && ynew<=460 && ynew>=350)
	    ynew-=10;
	 if(ynew==340 && xnew<=390 && xnew>=340)
	 	xnew+=10;
	 	
	 
	 //movement of opponent car
	 //first arena movement
	 if(x2new>=50 && x2new<=760 && y2new==50)
		x2new-=10;
	 if(x2new==60 && y2new>=50 && y2new<750)
		y2new+=10;
	 if(y2new==750 && x2new>=40 && x2new<760)
	 	x2new+=10;		
	 if(x2new==760 && y2new<=750 && y2new>=50)
	    y2new-=10;
	   
	 //secod arena movement 
	 if(y2new==150 && x2new>=170 && x2new<=660)
		x2new-=10;	
	 if(x2new==650 && y2new>=150 && y2new<=650)
		y2new-=10;
	 if(y2new==650 && x2new>=160 && x2new<650)
		x2new+=10;
	 if(x2new==160 && y2new<650 && y2new>=150)
		y2new+=10;
	 if(y2new==150 && x2new>=150 && x2new<=170)
		x2new-=10;
	 
	 //third arena movement 
	 if(y2new==250 && x2new>=390  && x2new<=560)
		x2new-=10;					
	 if(x2new==560 && y2new>=250 && y2new <=560)
		y2new-=10;
	 if(y2new==560 && x2new<=560 && x2new>=250)
		x2new+=10;
	 if(x2new==260 && y2new<=560 && y2new>=250)
		y2new+=10;
	 if(y2new==250 && x2new>=250 && x2new<=390)
		x2new-=10;		
	//fourth arena movement	
	 if(y2new==340 && x2new>=340 && x2new<=470)
	 	x2new-=10;
	 if(x2new==470 && y2new>=340 && y2new<=460)
	 	y2new-=10;
	 if(y2new==460 && x2new<=470 && x2new>=330)
	 	x2new+=10;
	 if(x2new==330 && y2new<=450 && y2new>=340)
	    y2new+=10;
	 if(y2new==340 && x2new<=390 && x2new>340)
	 	x2new-=10;
	  
	  //Gaps Movement of opponent car  
	  
	  if(gap1==true)
	    {if((x2new >=30  && x2new <=70 ) && (y2new >=390 && y2new<=470  ) ) 	  	
		      x2new=160;
		else if((x2new >=370  && x2new <=420 ) && (y2new >=30 && y2new<=70  ) ) 	  	
			  y2new=150;    
	    else if((x2new >=370  && x2new <=470 ) && (y2new >=730 && y2new<=770  ) ) 	  	
			  y2new=650;
		else if((x2new >=740  && x2new <=790 ) && (y2new >=370 && y2new<=420))
		      x2new= 650;
	    	
	    }
	     
	  if(gap2==true)
	  {
	    if((x2new >=30  && x2new <=70 ) && (y2new >=390 && y2new<=470  ) ) 	  	
		       x2new=160;
		else if((x2new >=370  && x2new <=420 ) && (y2new >=30 && y2new<=70  ) ) 	  	
		       y2new=150;    
	    else if((x2new >=370  && x2new <=470 ) && (y2new >=730 && y2new<=770  ) ) 	  	
			   y2new=650;
		else if((x2new >=740  && x2new <=790 ) && (y2new >=370 && y2new<=420))
		       x2new= 650;
	  }  
	    
	  if(gap3==true)
	  {
	    if((x2new >=30  && x2new <=70 ) && (y2new >=390 && y2new<=470  ) ) 	  	
		       x2new=160;
		else if((x2new >=370  && x2new <=420 ) && (y2new >=30 && y2new<=70  ) ) 	  	
		       y2new=150;    
	    else if((x2new >=370  && x2new <=470 ) && (y2new >=730 && y2new<=770  ) ) 	  	
			   y2new=650;
		else if((x2new >=740  && x2new <=790 ) && (y2new >=370 && y2new<=420))
		       x2new= 650;
	  }    
	  
	  if(gap4==true)
	  {
	    if((x2new >=30  && x2new <=70 ) && (y2new >=390 && y2new<=470  ) ) 	  	
		       x2new=160;
		else if((x2new >=370  && x2new <=420 ) && (y2new >=30 && y2new<=70  ) ) 	  	
		       y2new=150;    
	    else if((x2new >=370  && x2new <=470 ) && (y2new >=730 && y2new<=770  ) ) 	  	
			   y2new=650;
		else if((x2new >=740  && x2new <=790 ) && (y2new >=370 && y2new<=420))
		       x2new= 650;
	  }    	
	 
	  if(gap5==true)
	  {
	    if((x2new >=640  && x2new <=690 ) && (y2new >=370 && y2new<=420))
		       x2new=560;
	  	else if((x2new >=130  && x2new <=170 ) && (y2new >=390 && y2new<=470  ) ) 	  	
		       x2new=260;
		else if((x2new >=370  && x2new <=420 ) && (y2new >=130 && y2new<=170  ) ) 	  	
			   y2new=250;
		else if((x2new >=370  && x2new <=470 ) && (y2new >=630 && y2new<=670  ) ) 	  	
			   y2new=650;
			   
			   	   
			       
	  }
	  if(gap6==true)
	  {
	    if((x2new >=640  && x2new <=690 ) && (y2new >=370 && y2new<=420))
		       x2new= 560;
	  	else if((x2new >=130  && x2new <=170 ) && (y2new >=390 && y2new<=470  ) ) 	  	
		       x2new=260;
		else if((x2new >=370  && x2new <=420 ) && (y2new >=130 && y2new<=170  ) ) 	  	
			   y2new=250;
		else if((x2new >=370  && x2new <=470 ) && (y2new >=630 && y2new<=670  ) ) 	  	
			   y2new=650;
			    
			  	   
			       
	  }
	  if(gap7==true)
	  {
	    if((x2new >=640  && x2new <=690 ) && (y2new >=370 && y2new<=420))
		       x2new= 560;
	  	else if((x2new >=130  && x2new <=170 ) && (y2new >=390 && y2new<=470  ) ) 	  	
		       x2new=260;
		else if((x2new >=370  && x2new <=420 ) && (y2new >=130 && y2new<=170  ) ) 	  	
			   y2new=250;
		else if((x2new >=370  && x2new <=470 ) && (y2new >=630 && y2new<=670  ) ) 	  	
			   y2new=650;
			   
			   	   
			       
	  }
	  if(gap8==true)
	  {
	    if((x2new >=640  && x2new <=690 ) && (y2new >=370 && y2new<=420))
		       x2new=560;
	  	else if((x2new >=130  && x2new <=170 ) && (y2new >=390 && y2new<=470  ) ) 	  	
		       x2new=260;
		else if((x2new >=370  && x2new <=420 ) && (y2new >=130 && y2new<=170  ) ) 	  	
			   y2new=250;
		else if((x2new >=370  && x2new <=470 ) && (y2new >=630 && y2new<=670  ) ) 	  	
			   y2new=650;
			   
			   	   
			       
	  }		 
	  
	  if(gap9==true)
	  {
	  	if((x2new >=540  && x2new <=590 ) && (y2new >=370 && y2new<=420))
			x2new=470;	
		else if((x2new >=230  && x2new <=270 ) && (y2new >=390 && y2new<=470  ) ) 	  	
			x2new=330;
		else if((x2new >=370  && x2new <=420 ) && (y2new >=230 && y2new<=270  ) ) 	  	
			y2new=250;
		else if((x2new >=370  && x2new <=470 ) && (y2new >=530 && y2new<=570  ) ) 	  	
			y2new=650;
			     	 
	 		
	  }
	  
	  if(gap10==true)
	  {
	  	if((x2new >=540  && x2new <=590 ) && (y2new >=370 && y2new<=420))
			x2new=470;	
		else if((x2new >=230  && x2new <=270 ) && (y2new >=390 && y2new<=470  ) ) 	  	
			x2new=330;
		else if((x2new >=370  && x2new <=420 ) && (y2new >=230 && y2new<=270  ) ) 	  	
			y2new=250;
		else if((x2new >=370  && x2new <=470 ) && (y2new >=530 && y2new<=570  ) ) 	  	
			y2new=650;
			     	 
	 			
	  }
	  
	  if(gap11==true)
	  {
	  	if((x2new >=540  && x2new <=590 ) && (y2new >=370 && y2new<=420))
			x2new=470;	
		else if((x2new >=230  && x2new <=270 ) && (y2new >=390 && y2new<=470  ) ) 	  	
			x2new=330;
		else if((x2new >=370  && x2new <=420 ) && (y2new >=230 && y2new<=270  ) ) 	  	
			y2new=250;
		else if((x2new >=370  && x2new <=470 ) && (y2new >=530 && y2new<=570  ) ) 	  	
			y2new=650;
			     	 
	 				 
	 
	  }
	  
	  if(gap12==true)
	  {
	  	if((x2new >=540  && x2new <=590 ) && (y2new >=370 && y2new<=420))
			x2new=470;	
		else if((x2new >=230  && x2new <=270 ) && (y2new >=390 && y2new<=470  ) ) 	  	
			x2new=330;
		else if((x2new >=370  && x2new <=420 ) && (y2new >=230 && y2new<=270  ) ) 	  	
			y2new=340;
		else if((x2new >=370  && x2new <=470 ) && (y2new >=530 && y2new<=570  ) ) 	  	
			y2new=650;
			   	 
	 
	  }
	  
	 	
        //matching and removing food	
	 	
	 	for(int i=0;i<8;i++)
	 	{	
	 		if((xcod[i]>=xnew && xcod[i]<=xnew+63) && (ycod[i]>=ynew && ycod[i]<=ynew+63))
	 		{
	 		  xcod[i]=-1;
	 		  ycod[i]=-1;
	 		  score++;
	 		}
	 		 
	 	}
	 	for(int i=0;i<8;i++)
	 	{	
	 		if((xcod1[i]>=xnew && xcod1[i]<=xnew+70) && (ycod1[i]>=ynew && ycod1[i]<=ynew+70))
	 		{
	 		  xcod1[i]=-1;
	 		  ycod1[i]=-1;
	 		  score++;
	 		}
	 		 
	 	}
	 	
	 	for(int i=0;i<8;i++)
	 	{
	 		if((xcod2[i]>=xnew && xcod2[i]<=xnew+63) && (ycod2[i]>=ynew && ycod2[i]<=ynew+63))
	 		{
	 		  xcod2[i]=-1;
	 		  ycod2[i]=-1;
			  score++;	 		  
	 		}
	 		
	 	}
	 	
	 	for(int i=0;i<8;i++)
	 	{
	 		if((xcod3[i]>=xnew && xcod3[i]<=xnew+63) && (ycod3[i]>=ynew && ycod3[i]<=ynew+63))
	 		{
	 		  xcod3[i]=-1;
	 		  ycod3[i]=-1;
	 		  score++;
	 		}
	 	}
	 	
	 	for(int i=0;i<8;i++)
	 	{
	 		if((xcod4[i]>=xnew && xcod4[i]<=xnew+63) && (ycod4[i]>=ynew && ycod4[i]<=ynew+63))
	 		{
	 		  xcod4[i]=-1;
	 		  ycod4[i]=-1;
	 		  score++;
	 		}
	 	}
	 	
	 	for(int i=0;i<8;i++)
	 	{
	 		if((xcod5[i]>=xnew && xcod5[i]<=xnew+63) && (ycod5[i]>=ynew && ycod5[i]<=ynew+63))			
	 		{
	 		   xcod5[i]=-1;
	 		   ycod5[i]=-1;
	 		   score++;
	 		}
	 	}
	 	//Cars collisons and their removal
	 	if((x2new>=xnew && x2new<=xnew+60) && (y2new>=ynew && y2new<=ynew+60))
	 	{	
	 			xnew=-1000;
	 			ynew=-1000;
	 			x2new=-1000;
	 			y2new=-1000;
	 			
	 	}
	 	
	glutPostRedisplay();	
	glutTimerFunc(90.0, Timer, 0);
	
}

/*This function is called (automatically) whenever any non-printable key (such as up-arrow, down-arraw)
 * is pressed from the keyboard
 *
 * You will have to add the necessary code here when the arrow keys are pressed or any other key is pressed...
 *
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 *
 * */

void NonPrintableKeys(int key, int x, int y) {
	if (key	== GLUT_KEY_LEFT /*GLUT_KEY_LEFT is constant and contains ASCII for left arrow key*/) 
	{
	// what to do when left key is pressed...
		if((xnew >=740  && xnew <=790 ) && (ynew >=370 && ynew<=420))
		{
			xnew= 660;
			gap1=true; 
		}  
   		else if((xnew >=640  && xnew <=690 ) && (ynew >=370 && ynew<=420))
			{
				xnew= 560;
				gap5=true;
			}	
		else if((xnew >=540  && xnew <=590 ) && (ynew >=370 && ynew<=420))
			{
				xnew= 470;
				gap9=true;
			}	
		else if((xnew >=320  && xnew <=370 ) && (ynew >=370 && ynew<=420))
			{	
				xnew= 260;
				gap13=true;
			}
		else if((xnew >=220  && xnew <=270 ) && (ynew >=370 && ynew<=420))
		xnew= 160;
		else if((xnew >=120  && xnew <=170 ) && (ynew >=370 && ynew<=420))
		xnew= 60;			 
   		//xnew-=10;
   		//x2new-=10;
   		
   		
   		
	}
 
else if (key == GLUT_KEY_RIGHT /*GLUT_KEY_RIGHT is constant and contains ASCII for right arrow key*/)
	{	
		if((xnew >=30  && xnew <=70 ) && (ynew >=390 && ynew<=470  ) ) 	  	
		{
			xnew=160;
			gap3=true;
		}
		else if((xnew >=130  && xnew <=170 ) && (ynew >=390 && ynew<=470  ) ) 	  	
			{	xnew=260;
				gap7=true;
			}	
		else if((xnew >=230  && xnew <=270 ) && (ynew >=390 && ynew<=470  ) ) 	  	
			{
				xnew=340;
				gap11=true;
			}
		else if((xnew >=460  && xnew <=490 ) && (ynew >=390 && ynew<=470  ) ) 	  	
			{
				xnew=560;
				gap15=true;
			}	
		else if((xnew >=540  && xnew <=590 ) && (ynew >=390 && ynew<=470  ) ) 	  	
		xnew=660;
		else if((xnew >=640  && xnew <=690 ) && (ynew >=390 && ynew<=470  ) ) 	  	
		xnew=760;				
	    //xnew+=10;     	
		//x2new+=10;
	
	}
			 	
		
	 
		
	
	else if (key== GLUT_KEY_UP/*GLUT_KEY_UP is constant and contains ASCII for up arrow key*/)
	 {
		
		
		
			if((xnew >=370  && xnew <=420 ) && (ynew >=30 && ynew<=70  ) ) 	  	
			{ 
				ynew=150;
				gap4=true;
			}
			else if((xnew >=370  && xnew <=420 ) && (ynew >=130 && ynew<=170  ) ) 	  	
				{
					ynew=250;
					gap8=true;
				}
			else if((xnew >=370  && xnew <=420 ) && (ynew >=230 && ynew<=270  ) ) 	  	
				{	
					ynew=340;
					gap12=true;
				}	
			else if((xnew >=390  && xnew <=470 ) && (ynew >=450 && ynew<=480  ) ) 	  	
				{	
					ynew=560;
					gap16=true;
				}
			else if((xnew >=390  && xnew <=470 ) && (ynew >=550 && ynew<=580  ) ) 	  	
			ynew=650;
			else if((xnew >=390  && xnew <=470 ) && (ynew >=650 && ynew<=680  ) ) 	  	
			ynew=750;
		
			//ynew+=10;
			//y2new+=10;
		
			
	 }

	else if (key== GLUT_KEY_DOWN/*GLUT_KEY_DOWN is constant and contains ASCII for down arrow key*/)
	{
		if((xnew >=370  && xnew <=470 ) && (ynew >=730 && ynew<=770  ) ) 	  	
		{
			ynew=650;
			gap2=true;
		}
		else if((xnew >=370  && xnew <=470 ) && (ynew >=630 && ynew<=670  ) ) 	  	
		
		{
			ynew=560;
			gap6=true;
		}	
		else if((xnew >=370  && xnew <=470 ) && (ynew >=530 && ynew<=570  ) ) 	  	
		{	
			ynew=460;
			gap10=true;
		}	
		else if((xnew >=370  && xnew <=470 ) && (ynew >=320 && ynew<=350  ) ) 	  	
		{	
			ynew=250;
			gap14=true;	
		}
		else if((xnew >=370  && xnew <=470 ) && (ynew >=220 && ynew<=250  ) ) 	  	
		ynew=150;
		else if((xnew >=370  && xnew <=470 ) && (ynew >=120 && ynew<=150  ) ) 	  	
		ynew=50;	
		/*if(ynew>20 )
		{
			ynew-=10;
		
		}
		*/
		//y2new-=10;
	
	}
	
	

	/* This function calls the Display function to redo the drawing. Whenever you need to redraw just call
	 * this function*/

	glutPostRedisplay();

}

/*This function is called (automatically) whenever any printable key (such as x,b, enter, etc.)
 * is pressed from the keyboard
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 * */


/*
 * This function is called after every 1000.0/FPS milliseconds
 * (FPS is defined on in the beginning).
 * You can use this function to animate objects and control the
 * speed of different moving objects by varying the constant FPS.
 *
 * */

/*This function is called (automatically) whenever your mouse moves witin inside the game window
 *
 * You will have to add the necessary code here for finding the direction of shooting
 *
 * This function has two arguments: x & y that tells the coordinate of current position of move mouse
 *
 * */
void MousePressedAndMoved(int x, int y) {
	cout << x << " " << y << endl;
	glutPostRedisplay();
}
void MouseMoved(int x, int y) {

	glutPostRedisplay();
}

/*This function is called (automatically) whenever your mouse button is clicked witin inside the game window
 *
 * You will have to add the necessary code here for shooting, etc.
 *
 * This function has four arguments: button (Left, Middle or Right), state (button is pressed or released),
 * x & y that tells the coordinate of current position of move mouse
 *
 * */
void MouseClicked(int button, int state, int x, int y) {

	if (button == GLUT_LEFT_BUTTON) // dealing only with left button
			{
		cout << GLUT_DOWN << " " << GLUT_UP << endl;

	} else if (button == GLUT_RIGHT_BUTTON) // dealing with right button
			{

	}
	glutPostRedisplay();
}
/*
 * our gateway main function
 * */
int main(int argc, char*argv[]) {

	
	 	
	 	
	 	
	 	
	int numx=60;
	int numy=60;
    	for(int i=0;i<8;i++)
    	{
            	xcod[i]=numx;
    			ycod[i]=numy;
    			numx+=100;
    	}
    	
     
     numx=60;
	 numy=160;
    	for(int i=0;i<8;i++)
    	{
            	xcod2[i]=numx;
    			ycod2[i]=numy;
    			numx+=100;
    	}
    numx=60;
	numy=260;
    	for(int i=0;i<8;i++)
    	{
            	xcod1[i]=numx;
    			ycod1[i]=numy;
    			numx+=100;
    	}	
    	
    numx=60;
	numy=460;
    	for(int i=0;i<8;i++)
    	{
            	xcod3[i]=numx;
    			ycod3[i]=numy;
    			numx+=100;
    	}	
    	
   numx=60;
   numy=650;
    	for(int i=0;i<8;i++)
    	{
            	xcod4[i]=numx;
    			ycod4[i]=numy;
    			numx+=100;
    	}

	numx=60;
    numy=750;
    	for(int i=0;i<8;i++)
    	{
            	xcod5[i]=numx;
    			ycod5[i]=numy;
    			numx+=100;
    	}
                      
InitRandomizer();
//To generate car randomly
int x= GetRandInRange(1,4);
	if(x==1 )
	{
	x2new=250;
	y2new=50;
	}
	if(x==2)
	{
	x2new=50;
	y2new=750;
	
	}
	if(x==3)
	{
	x2new=700;
	y2new=750;
	
	}

	if(x==4)
	{
		x2new=700;
		y2new=50;
	
	}
	
	

	//b = new  Board(60, 60); // create a new board object to use in the Display Function ...

	int width = 840, height = 900; // i have set my window size to be 800 x 600
	//b->InitalizeBoard(width, height);
	InitRandomizer(); // seed the random number generator...
	glutInit(&argc, argv); // initialize the graphics library...
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // we will be using color display mode
	glutInitWindowPosition(50, 50); // set the initial position of our window
	glutInitWindowSize(width, height); // set the size of our window
	glutCreateWindow("OOP Centipede"); // set the title of our game window
	SetCanvasSize(width, height); // set the number of pixels...

	// Register your functions to the library,
	// you are telling the library names of function to call for different tasks.
	//glutDisplayFunc(display); // tell library which function to call for drawing Canvas.
	
	
	Menu();
	glutDisplayFunc(GameDisplay); // tell library which function to call for drawing Canvas.

	glutSpecialFunc(NonPrintableKeys); // tell library which function to call for non-printable ASCII characters
	glutKeyboardFunc(PrintableKeys); // tell library which function to call for printable ASCII characters
	// This function tells the library to call our Timer function after 1000.0/FPS milliseconds...
	glutTimerFunc(200.0, Timer, 0);
	
	glutMouseFunc(MouseClicked);
	glutPassiveMotionFunc(MouseMoved); // Mouse
	glutMotionFunc(MousePressedAndMoved); // Mouse

	// now handle the control to library and it will call our registered functions when
	// it deems necessary...
	glutMainLoop();
	return 1;
}
#endif /* AsteroidS_CPP_ */
