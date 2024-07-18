#include "iGraphics.h"
#include "bitmap_loader.h"
#include <windows.h>
#include <mmsystem.h>
#include <iostream>
#include <ctime>
#include <cstdlib>

int cursor_x,cursor_y;
int b_x=55,b_y=55;
int player = 1;
int players = 1;
int point=0;

int img2_x[4],img2_y[4];
int img2_flag=0;
int music_flag=0;
int img2_st_flag=0;
int about_flag=0;
int multi_gaming_flag=0;
int single_flag=0;
int score=0;


                         //:::::::::::::::::::::::::::::::::::: User Input Scn ::::::::::::::::::::::::::::::::://


FILE *input=fopen("image\\file.txt","a");

char str[100], str2[100];
int len;
int iflag;

char ch[100];

void rectangle()
{
	iShowBMP(0,0,"image\\score_b.bmp");
	
}


void input_scn()
{
	iShowBMP2(0,0,"image\\Tic-Tac-Toe.bmp",0);
	rectangle();
	if(iflag == 1)
	{
		
		iSetColor(0, 0, 0);
		iText(230, 320, str, GLUT_BITMAP_TIMES_ROMAN_24);

	}
	if(cursor_x>= 210 && cursor_x <= 430 && cursor_y >= 270 && cursor_y <= 410 && iflag == 0)
	{
		iflag = 1;
		cursor_x=0;
		cursor_y=0;
	}

	iSetColor(255, 255, 0);
	
	
}








                       //:::::::::::::::::::::::::::::::::::: 2nd image ::::::::::::::::::::::::::::::::://






void first_scn_variable()
{
	img2_x[0]=253, img2_y[0]=360;
	img2_x[1]=253,img2_y[1]=270;
	img2_x[2]=213,img2_y[2]=180;
	img2_x[3]=253,img2_y[3]=90;
	
}


void first_scrn()
{
	iShowBMP2(0,0,"image\\Tic-Tac-Toe.bmp",0);
	iShowBMP2( img2_x[0],img2_y[0],"image\\Start.bmp",0);
	iShowBMP2(img2_x[1],img2_y[1],"image\\option.bmp",0);
	iShowBMP2(img2_x[2],img2_y[2],"image\\score.bmp",0);
	iShowBMP2(img2_x[3],img2_y[3],"image\\Exit.bmp",0);

	if(cursor_x>= img2_x[0]&& cursor_x<=img2_x[0]+153 && cursor_y>=img2_y[0] && cursor_y<=img2_y[0]+78)
	{
		img2_flag=5;
		img2_st_flag=1;
		cursor_x=0;
		cursor_y=0;

	}


	else if(cursor_x>= img2_x[1]&& cursor_x<=img2_x[1]+153 && cursor_y>=img2_y[1] && cursor_y<=img2_y[1]+78)
	{
		img2_flag=10;
		img2_st_flag=2;
		cursor_x=0;
		cursor_y=0;

	}

	else if(cursor_x>= img2_x[2]&& cursor_x<=img2_x[2]+251 && cursor_y>=img2_y[2] && cursor_y<=img2_y[2]+59)
	{

		score=1;
		img2_flag=20;
		single_flag=10;
		cursor_x=0;
		cursor_y=0;

	}


	else if(cursor_x>= img2_x[3] && cursor_x<= img2_x[3]+156 && cursor_y>= img2_y[3] && cursor_y<= img2_y[3]+78)
	{
		exit(0);
	}

}



           //:::::::::::::::::::::::::::::::::::: 2nd image -> Scoreboard ::::::::::::::::::::::::::::::::://

/*struct user{

	char name[100];
	int  score;
}u[100],carry;

FILE *read=fopen("image\\file.txt","r");

void score_count()
{
	char ch;
   for(int i=0;i<=100;i++)
   {
	   fscanf(read,"%s %d",&u[i].name,&u[i].score);
	   //printf(" User= %s %d",u[i].name,u[i].score);
	   if((ch=fgetc(read))!=EOF)
		   break;
   }

    for(int i=0;i<=100;i++)
	{
		for(int j=0;j<=99;j++)
		{
			if(u[j].score<u[j+1].score)
                {
                    carry=u[j];
                    u[j]=u[j+1];
                    u[j+1]=carry;
                }

		}

	}


}*/



//char ch1[20];
//char ch2[20];
void scoreboard()
{
   
	iShowBMP2(0,0,"image\\Tic-Tac-Toe.bmp",0);
	iShowBMP(b_x, b_y,"image\\back.bmp"); 
	iText(224, 520, "Name",GLUT_BITMAP_TIMES_ROMAN_24);
	iText(560, 520, "Win",GLUT_BITMAP_TIMES_ROMAN_24);


	
	
	iText(224, 480, str2,GLUT_BITMAP_TIMES_ROMAN_24);
	//sprintf(ch,"%d",point);
	iText(560, 480, ch,GLUT_BITMAP_TIMES_ROMAN_24);


	/*iText(224, 440, u[1].name,GLUT_BITMAP_TIMES_ROMAN_24);
	sprintf(ch2,"%d",point);
	iText(560, 440, ch2,GLUT_BITMAP_TIMES_ROMAN_24);*/
	 if(cursor_x>= b_x && cursor_x<= b_x+150 && cursor_y>= b_y && cursor_y<= b_y+78)
	{
		img2_flag=2;
		score=2;
		cursor_x=0;
		cursor_y=0;
	}



}




                      //:::::::::::::::::::::::::::::::::::: 2nd image -> Option ::::::::::::::::::::::::::::::::://

int opt_x[2],opt_y[2];
void option_scn_variable()
{
	opt_x[0]=265,opt_y[0]=365;
	opt_x[1]=259,opt_y[1]=270;


}

void option_scrn()
{
	iShowBMP2(0,0,"image\\Tic-Tac-Toe.bmp",0);
	iShowBMP(opt_x[0],opt_y[0],"image\\music.bmp");
	iShowBMP(opt_x[1],opt_y[1],"image\\about.bmp");
	iShowBMP(b_x, b_y,"image\\back.bmp"); 


	if(cursor_x>= opt_x[0] && cursor_x<= opt_x[0]+118 && cursor_y>= opt_y[0] && cursor_y<= opt_y[0]+60)
	{
		music_flag=1;
		img2_st_flag=0;
		cursor_x=0;
		cursor_y=0;
	}

	else if(cursor_x>= opt_x[1] && cursor_x<= opt_x[1]+133 && cursor_y>= opt_y[1] && cursor_y<= opt_y[1]+63)
	{
		about_flag=1;
		img2_st_flag=10;
		cursor_x=0;
		cursor_y=0;
	}

	else if(cursor_x>= b_x && cursor_x<= b_x+150 && cursor_y>= b_y && cursor_y<= b_y+78)
	{
		img2_flag=2;
		img2_st_flag=0;
		cursor_x=0;
		cursor_y=0;
	}

}              
              //:::::::::::::::::::::::::::::::::::: 2nd image -> Option -> Music -> On/Off::::::::::::::::::::::::::::::::://



int music_x[2],music_y[2];

void music_scn_variable()
{
	music_x[0]=259,music_y[0]=365;
	music_x[1]=259,music_y[1]=270;

}

void music_scn()
{
	iShowBMP2(0,0,"image\\Tic-Tac-Toe.bmp",0);
	iShowBMP(music_x[0],music_y[0],"image\\On.bmp");
	iShowBMP(music_x[1],music_y[1],"image\\Off.bmp");
	iShowBMP(b_x, b_y,"image\\back.bmp"); 

	if(cursor_x>= music_x[0] && cursor_x<= music_x[0]+74 && cursor_y>= music_y[0] && cursor_y<= music_y[0]+63 )
	{

		PlaySound("image\\music.wav",NULL,SND_ASYNC|SND_LOOP);

		cursor_x=0;
		cursor_y=0;

	}

	else if(cursor_x>= music_x[1] && cursor_x<= music_x[1]+74 && cursor_y>= music_y[1] && cursor_y<= music_y[1]+63)
	{

		PlaySound("image\\no.wav",NULL,SND_ASYNC|SND_LOOP);
		cursor_x=0;
		cursor_y=0;

	}
	else if(cursor_x>= b_x && cursor_x<= b_x+150 && cursor_y>= b_y && cursor_y<= b_y+78)
	{
		music_flag=0;
		img2_st_flag=2;
		cursor_x=0;
		cursor_y=0;
	}
}


                   //:::::::::::::::::::::::::::::::::::: 2nd image -> Option -> About  ::::::::::::::::::::::::::::::::://


void about_scn()
{

	iShowBMP(0,0,"image\\About2.bmp");
	iShowBMP(604,1,"image\\back_game.bmp"); 

	if(cursor_x>= 604 && cursor_x<= 604+90 && cursor_y>= 1 && cursor_y<= 1+55)
	{
		about_flag=2;
		img2_st_flag=2;
		cursor_x=0;
		cursor_y=0;

	}

}

                   //:::::::::::::::::::::::::::::::::::: 2nd image -> Start ->Mode  ::::::::::::::::::::::::::::::::://





int img2_st_x[2],img2_st_y[2];


void start_scn_variable()
{
	img2_st_x[0]=200, img2_st_y[0]=320;
	img2_st_x[1]=200,img2_st_y[1]=231;

}


void start_scrn()
{

	iShowBMP2(0,0,"image\\Tic-Tac-Toe.bmp",0);
	iShowBMP(img2_st_x[0],img2_st_y[0],"image\\Single_player.bmp");
	iShowBMP(img2_st_x[1],img2_st_y[1],"image\\Multi_player.bmp");
	iShowBMP(b_x,b_y,"image\\back.bmp");

	if(cursor_x>= img2_st_x[0] && cursor_x<=img2_st_x[0]+301 && cursor_y>img2_st_y[0] && cursor_y<=img2_st_y[0]+77)
	{
		single_flag=1;
		img2_st_flag=10;
		cursor_x=0;
		cursor_y=0;
		players = 1; 
	}


	else  if(cursor_x>= img2_st_x[1] && cursor_x<=img2_st_x[1]+301 && cursor_y>img2_st_y[1] && cursor_y<=img2_st_y[1]+77)
	{
		multi_gaming_flag=1;
		img2_st_flag=4;
		cursor_x=0;
		cursor_y=0;
		player=1;
	}

	else if(cursor_x>= b_x && cursor_x<= b_x+150 && cursor_y>= b_y && cursor_y<= b_y+78)
	{

		img2_flag=2;
		img2_st_flag=0;
		cursor_x=0;
		cursor_y=0;
	}



}









//::::::::::::::::::::::::::::::::::::  ->Multiplayer Mode Gaming-> ::::::::::::::::::::::::::::::::://



int image1, image2, image3;
int win_x=1;
int count=0;
int show_res_x=0;
int show_res_o=0;
int show_res_draw=0;
int stop_img_show=1;
int win_music=0;




int box_1 = 1 , box_2 = 1, box_3= 1, box_4 = 1,box_5 = 1,box_6 = 1,box_7 = 1,box_8 = 1,box_9 = 1;

int image_x_1 = 0,image_x_2 = 0,image_x_3 = 0,image_x_4 = 0,image_x_5 = 0,image_x_6 = 0,image_x_7 = 0,image_x_8 = 0,image_x_9 = 0;
int image_o_1 = 0,image_o_2 = 0,image_o_3 = 0,image_o_4 = 0,image_o_5 = 0,image_o_6 = 0,image_o_7 = 0,image_o_8 = 0,image_o_9 = 0;




void multi_win()
{

	iShowImage(0,0,600,600,image1);


	iShowBMP(601,55,"image\\back_game.bmp"); 
	iShowBMP(605,500,"image\\player1x.bmp"); 
	iShowBMP(605,430,"image\\player2o.bmp"); 
	if(show_res_x==1 && win_music==1)
	{	
		iShowBMP2(601,330,"image\\player1win.bmp",0);	

	}
	else if(show_res_o==1 && win_music==1)
	{
		iShowBMP2(601,270,"image\\player2win.bmp",0);		
	}
	else if(show_res_draw==1)
	{
		iShowBMP2(601,270,"image\\draw.bmp",0);
	}





	//:::::::::::::::::::::::::::::::::::: Show Image Per Co_Ordinate ::::::::::::::::::::::::::::::::://


	if (image_x_1 == 1 )  iShowImage(0 ,400,200,200,image2);
	if (image_x_2 == 1 )  iShowImage(200,400,200,200,image2);
	if (image_x_3 == 1 )  iShowImage(400,400,200,200,image2);

	if (image_x_4 == 1 )  iShowImage(0,200,200,200,image2);
	if (image_x_5 == 1 )  iShowImage(200,200,200,200,image2);
	if (image_x_6 == 1 )  iShowImage(400,200,200,200,image2);

	if (image_x_7 == 1 )  iShowImage(0,0,200,200,image2);
	if (image_x_8 == 1 )  iShowImage(200,0,200,200,image2);
	if (image_x_9 == 1 )  iShowImage(400,0,200,200,image2);

	if (image_o_1 == 1 )  iShowImage(0  ,400,200,200,image3);
	if (image_o_2 == 1 )  iShowImage(200,400,200,200,image3);
	if (image_o_3 == 1 )  iShowImage(400,400,200,200,image3);

	if (image_o_4 == 1 )  iShowImage(0,200,200,200,image3);
	if (image_o_5 == 1 )  iShowImage(200,200,200,200,image3);
	if (image_o_6 == 1 )  iShowImage(400,200,200,200,image3);

	if (image_o_7 == 1 )  iShowImage(0,0,200,200,image3);
	if (image_o_8 == 1 )  iShowImage(200,0,200,200,image3);
	if (image_o_9 == 1 )  iShowImage(400,0,200,200,image3);



	//:::::::::::::::::::::::::::::::::::: Mouse Pointer Click ::::::::::::::::::::::::::::::::://


	if (cursor_x >= 10 && cursor_x <= 200 && cursor_y >= 400 && cursor_y <= 600 && box_1 == 1 && stop_img_show==1)
	{
		box_1= 0;

		if (player == 1)
		{  
			image_x_1 = 1;
			player = 2;


		}

		else if (player == 2 )

		{
			image_o_1 = 1;
			player = 1;

		}

		count++;

	}

	else if ( cursor_x >= 200 && cursor_x <= 400 && cursor_y >= 400 && cursor_y <= 600 && box_2 == 1 && stop_img_show==1 )
	{
		box_2= 0;

		if (player == 1)
		{
			image_x_2 = 1;
			player = 2;

		}

		else if (player == 2)
		{
			image_o_2 = 1;
			player = 1;

		}
		count++;


	}

	else if ( cursor_x >= 400 && cursor_x <= 600 && cursor_y >= 400 && cursor_y <= 600 && box_3 == 1 && stop_img_show==1 )
	{
		box_3= 0;

		if (player == 1)
		{
			image_x_3 = 1;
			player = 2;
		}

		else if (player == 2)
		{
			image_o_3 = 1;
			player = 1;

		}
		count++;

	}

	else if ( cursor_x>= 10 && cursor_x <= 200 && cursor_y >= 200 && cursor_y <= 400 && box_4 == 1 && stop_img_show==1 )
	{
		box_4= 0;

		if (player == 1)
		{
			image_x_4 = 1;
			player = 2;

		}

		else if (player == 2)
		{
			image_o_4 = 1;
			player = 1;

		}
		count++;

	}

	else if ( cursor_x >= 200 && cursor_x <= 400 && cursor_y >= 200 && cursor_y <= 400 && box_5 == 1 && stop_img_show==1 )
	{
		box_5= 0;

		if (player == 1)
		{
			image_x_5 = 1;
			player = 2;

		}

		else if (player == 2)
		{
			image_o_5 = 1;
			player = 1;

		}
		count++;

	}

	else if ( cursor_x >= 400 && cursor_x <= 600 && cursor_y >= 200 && cursor_y <= 400 && box_6 == 1 && stop_img_show==1 )
	{
		box_6= 0;



		if (player == 1)
		{
			image_x_6 = 1;
			player = 2;

		}
		else if (player == 2)
		{
			image_o_6 = 1;
			player = 1;

		}
		count++;

	}	



	else if ( cursor_x >= 200 && cursor_x <= 400 && cursor_y >= 10 && cursor_y <= 200 && box_8 == 1 && stop_img_show==1 ) 
	{
		box_8= 0;



		if (player == 1)
		{
			image_x_8 = 1;
			player = 2;

		}

		else if (player == 2)
		{
			image_o_8 = 1;
			player = 1;

		}
		count++;

	}

	else if ( cursor_x >= 400 && cursor_x <= 600 && cursor_y >= 10 && cursor_y <= 200 && box_9 == 1 && stop_img_show==1)
	{
		box_9= 0;



		if (player == 1)
		{
			image_x_9 = 1;
			player = 2;

		}

		else if (player == 2)
		{
			image_o_9 = 1;
			player = 1;

		}
		count++;

	}

	else if ( cursor_x >= 10 && cursor_x <= 200 && cursor_y >= 10 && cursor_y <= 200 && box_7 == 1 && stop_img_show==1 )
	{
		box_7= 0;



		if (player == 1)
		{
			image_x_7 = 1;
			player = 2;

		}

		else if (player == 2)
		{
			image_o_7 = 1;
			player = 1;

		}
		count++;

	}




	//:::::::::::::::::::::::::::::::::::: Win /Draw Logic ::::::::::::::::::::::::::::::::://


	if(image_x_1==1 && image_x_2==1 && image_x_3==1 && win_x==1 && stop_img_show==1)
	{		

		win_x=0;
		show_res_x=1;
		stop_img_show=0;
		win_music=1;
	}
	else if(image_x_4==1 && image_x_5==1 && image_x_6==1 && win_x==1 && stop_img_show==1)
	{

		win_x=0;
		show_res_x=1;
		stop_img_show=0;
		win_music=1;
	}
	else if(image_x_7==1 && image_x_8==1 && image_x_9==1 && win_x==1 && stop_img_show==1)
	{

		win_x=0;
		show_res_x=1;
		stop_img_show=0;
		win_music=1;
	}
	else if(image_x_1==1 && image_x_4==1 && image_x_7==1 &&win_x==1 && stop_img_show==1)
	{

		win_x=0;
		show_res_x=1;
		stop_img_show=0;
		win_music=1;
	}

	else if(image_x_2==1 && image_x_5==1 && image_x_8==1 && win_x==1 && stop_img_show==1)
	{

		win_x=0;
		show_res_x=1;
		stop_img_show=0;
		win_music=1;
	}
	else if(image_x_3==1 && image_x_6==1 && image_x_9==1 && win_x==1 && stop_img_show==1)
	{

		win_x=0;
		show_res_x=1;
		stop_img_show=0;
		win_music=1;
	}
	else if(image_x_1==1 && image_x_5==1 && image_x_9==1 && win_x==1 && stop_img_show==1)
	{

		win_x=0;
		show_res_x=1;
		stop_img_show=0;
		win_music=1;
	}
	else if(image_x_3==1 && image_x_5==1 && image_x_7==1 && win_x==1 && stop_img_show==1)
	{

		win_x=0;
		show_res_x=1;
		stop_img_show=0;
		win_music=1;
	}



	else if(image_o_1==1 && image_o_2==1 && image_o_3==1 && win_x==1 && stop_img_show==1)
	{

		win_x=0;
		show_res_o=1;
		stop_img_show=0;
		win_music=1;
	}
	else if(image_o_4==1 && image_o_5==1 && image_o_6==1 &&  win_x==1 && stop_img_show==1)
	{

		win_x=0;
		show_res_o=1;
		stop_img_show=0;
		win_music=1;

	}
	else if(image_o_7==1 && image_o_8==1 && image_o_9==1 &&  win_x==1 && stop_img_show==1)

	{

		win_x=0;
		show_res_o=1;
		stop_img_show=0;
		win_music=1;
	}
	else if(image_o_1==1 && image_o_4==1&& image_o_7==1 &&  win_x==1 && stop_img_show==1)
	{

		win_x=0;
		show_res_o=1;
		stop_img_show=0;
		win_music=1;
	}
	else if(image_o_2==1 && image_o_5==1 && image_o_8==1 &&  win_x==1 && stop_img_show==1)
	{

		win_x=0;
		show_res_o=1;
		stop_img_show=0;
		win_music=1;
	}
	else if(image_o_3==1 && image_o_6==1 && image_o_9==1 &&  win_x==1 && stop_img_show==1)
	{

		win_x=0;
		show_res_o=1;
		stop_img_show=0;
		win_music=1;
	}
	else if(image_o_1==1 && image_o_5==1 && image_o_9==1 &&  win_x==1 && stop_img_show==1) 
	{

		win_x=0;
		show_res_o=1; 
		stop_img_show=0;
		win_music=1;
	}
	else if(image_o_3==1 && image_o_5==1 && image_o_7==1 &&  win_x==1 && stop_img_show==1)
	{

		win_x=0;
		show_res_o=1;
		stop_img_show=0;
		win_music=1;
	}
	else if(count==9 && win_x==1)
	{

		win_x=0;
		show_res_draw=1;

	}


	if(cursor_x>= 601 && cursor_x<= 601+90 && cursor_y>= 55 && cursor_y<= 55+55)
	{
		player=0;
		count=0;
		win_x=1;
		show_res_x=0;
		show_res_o=0;
		show_res_draw=0;
		box_1 = 1 , box_2 = 1, box_3= 1, box_4 = 1,box_5 = 1,box_6 = 1,box_7 = 1,box_8 = 1,box_9 = 1;
		image_x_1 = 0,image_x_2 = 0,image_x_3 = 0,image_x_4 = 0,image_x_5 = 0,image_x_6 = 0,image_x_7 = 0,image_x_8 = 0,image_x_9 = 0;
		image_o_1 = 0,image_o_2 = 0,image_o_3 = 0,image_o_4 = 0,image_o_5 = 0,image_o_6 = 0,image_o_7 = 0,image_o_8 = 0,image_o_9 = 0;
		stop_img_show=1;
		img2_st_flag=1;
		cursor_x=0;
		cursor_y=0;
		multi_gaming_flag=0;

	}

}








//::::::::::::::::::::::::::::::::::::  ->Singleplayer Mode Gaming-> ::::::::::::::::::::::::::::::::://


int images1, images2, images3;

int counts=0;
int user_click=0;
int random_number;
int win=1;
int show_resl_x=0;
int show_resl_o=0;
int show_resl_draw=0;
int stop_img_shows=1;
int boxx_1 = 1 , boxx_2 = 1, boxx_3= 1, boxx_4 = 1,boxx_5 = 1,boxx_6 = 1,boxx_7 = 1,boxx_8 = 1,boxx_9 = 1;

int imagee_x_1 = 0,imagee_x_2 = 0,imagee_x_3 = 0,imagee_x_4 = 0,imagee_x_5 = 0,imagee_x_6 = 0,imagee_x_7 = 0,imagee_x_8 = 0,imagee_x_9 = 0;
int imagee_o_1 = 0,imagee_o_2 = 0,imagee_o_3 = 0,imagee_o_4 = 0,imagee_o_5 = 0,imagee_o_6 = 0,imagee_o_7 = 0,imagee_o_8 = 0,imagee_o_9 = 0;



void computer();

void single_player_scn()
{

	//:::::::::::::::::::::::::::::::::::: background+win/loss/draw image  ::::::::::::::::::::::::::::::::://


	iShowImage(0,0,600,600,images1);
	iShowBMP(605,500,"image\\Computer-O.bmp"); 
	iShowBMP(605,430,"image\\Player-X.bmp"); 
	iShowBMP(601,55,"image\\back_game.bmp"); 

	if(show_resl_x==1)
	{
		iShowBMP2(601,330,"image\\Player Win!.bmp",0);
		
	}
	else if( show_resl_o==1)
	{

		iShowBMP2(601,270,"image\\Computer Win!.bmp",0);

	}
	else if(show_resl_draw==1)
	{
		iShowBMP2(601,270,"image\\draw.bmp",0);
	}







	//:::::::::::::::::::::::::::::::::::: Mouse Pointer Logic :::::::::::::::::::::::::::::::::



	if ( cursor_x >= 0 && cursor_x <= 200 && cursor_y >= 400 && cursor_y <= 600 && boxx_1 == 1 && stop_img_shows==1)
	{

		boxx_1= 0;
		if (players == 1)
		{
			imagee_x_1 = 1;
			players = 2;
			user_click=1; 

		}

		counts++;


	}

	else if ( cursor_x >= 200 && cursor_x <= 400 && cursor_y >= 400 && cursor_y <= 600 && boxx_2 == 1 && stop_img_shows==1)
	{
		boxx_2= 0;
		if (players == 1)
		{
			imagee_x_2 = 1;
			players = 2;
			user_click=2;
		}


		counts++;

	}

	else if ( cursor_x >= 400 && cursor_x <= 600 && cursor_y >= 400 && cursor_y <= 600 && boxx_3 == 1 && stop_img_shows==1)
	{
		boxx_3= 0;
		if (players == 1)
		{
			imagee_x_3 = 1;
			players = 2;
			user_click=3;
		}


		counts++;

	}

	else  if (cursor_x >= 0 && cursor_x <= 200 && cursor_y >= 200 && cursor_y <= 400 && boxx_4 == 1 && stop_img_shows==1)
	{
		boxx_4= 0;
		if (players == 1)
		{
			imagee_x_4 = 1;
			players = 2;
			user_click=4;
		}


		counts++;

	}

	else if (cursor_x >= 200 && cursor_x <= 400 && cursor_y >= 200 && cursor_y <= 400 && boxx_5 == 1 && stop_img_shows==1)
	{
		boxx_5= 0;
		if (players == 1)
		{
			imagee_x_5 = 1;
			players = 2;
			user_click=5;
		}


		counts++;

	}

	else if (cursor_x >= 400 && cursor_x <= 600 && cursor_y >= 200 && cursor_y <= 400 && boxx_6 == 1 && stop_img_shows==1)
	{

		boxx_6= 0;
		if (players == 1)
		{

			imagee_x_6 = 1;
			players = 2;
			user_click=6;
		}

		counts++;

	}

	else if (cursor_x >= 10 && cursor_x <= 200 && cursor_y >=10 && cursor_y <= 200 && boxx_7 == 1 && stop_img_shows==1)
	{
		boxx_7= 0;
		if (players == 1)
		{
			imagee_x_7 = 1;
			players = 2;
			user_click=7;
		}



		counts++;

	}

	else if (cursor_x >= 200 && cursor_x <= 400 && cursor_y >= 0 && cursor_y <= 200 && boxx_8 == 1 && stop_img_shows==1)
	{
		boxx_8= 0;
		if (players == 1)
		{
			imagee_x_8 = 1;
			players = 2;
			user_click=8;
		}


		counts++;

	}

	else if (cursor_x >= 400 && cursor_x <= 600 && cursor_y >= 0 && cursor_y <= 200 && boxx_9 == 1 && stop_img_shows==1)
	{

		boxx_9= 0;
		if (players == 1)
		{
			imagee_x_9 = 1;
			players = 2;
			user_click=9;
		}


		counts++;

	}



	               //:::::::::::::::::::::::::::::::::::: Win/Loss/Draw Logic ::::::::::::::::::::::::::::::::://




	if(imagee_x_1==1 && imagee_x_2==1 && imagee_x_3==1 && win==1)
	{
		show_resl_x=1;
		win=0;
		stop_img_shows=0;
		
	}
	else if(imagee_x_4==1 && imagee_x_5==1 && imagee_x_6==1 && win==1)
	{
		show_resl_x=1;
		win=0;
		stop_img_shows=0;
		
	}
	else if(imagee_x_7==1 && imagee_x_8==1 && imagee_x_9==1 && win==1)
	{
		show_resl_x=1;
		win=0;
		stop_img_shows=0;
		
	}
	else if(imagee_x_1==1 && imagee_x_4==1 && imagee_x_7==1 &&win==1)
	{
		show_resl_x=1;		
		win=0;
		stop_img_shows=0;
		
	}

	else if(imagee_x_2==1 && imagee_x_5==1 && imagee_x_8==1 && win==1)
	{
		show_resl_x=1;		
		win=0;
		stop_img_shows=0;
		
	}
	else if(imagee_x_3==1 && imagee_x_6==1 && imagee_x_9==1 && win==1)
	{
		show_resl_x=1; 
		win=0;
		stop_img_shows=0;
		
	}
	else if(imagee_x_1==1 && imagee_x_5==1 && imagee_x_9==1 && win==1){
		show_resl_x=1;

		win=0;
		stop_img_shows=0;
		
	}
	else if(imagee_x_3==1 && imagee_x_5==1 && imagee_x_7==1 && win==1){
		show_resl_x=1;

		win=0;
		stop_img_shows=0;
		
		
	}
	else if(imagee_o_1==1 && imagee_o_2==1 && imagee_o_3==1 && win==1)
	{
		show_resl_o=1;
		win=0;
		stop_img_shows=0;
		
	}
	else if(imagee_o_4==1 && imagee_o_5==1 && imagee_o_6==1 &&  win==1)
	{
		show_resl_o=1;
		win=0;
		stop_img_shows=0;	  
	}
	else if(imagee_o_7==1 && imagee_o_8==1 && imagee_o_9==1 &&  win==1)
	{
		show_resl_o=1;
		win=0;
		stop_img_shows=0;
	}
	else if(imagee_o_1==1 && imagee_o_4==1&& imagee_o_7==1 &&  win==1)
	{
		show_resl_o=1;
		win=0;     
	}
	else if(imagee_o_2==1 && imagee_o_5==1 && imagee_o_8==1 &&  win==1)
	{
		show_resl_o=1;
		win=0;
		stop_img_shows=0;
	}
	else if(imagee_o_3==1 && imagee_o_6==1 && imagee_o_9==1 &&  win==1)
	{
		show_resl_o=1;
		win=0;
		stop_img_shows=0;
	}
	else if(imagee_o_1==1 && imagee_o_5==1 && imagee_o_9==1 &&  win==1)
	{
		show_resl_o=1;
		win=0;
		stop_img_shows=0;
	}
	else if(imagee_o_3==1 && imagee_o_5==1 && imagee_o_7==1 &&  win==1)
	{
		show_resl_o=1;
		win=0;
		stop_img_shows=0; 
	}
	else if(counts==5 && win==1)
	{
		show_resl_draw=1;
		win=0;
		stop_img_shows=0;
	}


	//::::::::::::::::::::::::::::::::::::  Auto Genarator Calling ::::::::::::::::::::::::::::::::://


	computer();

	//:::::::::::::::::::::::::::::::::::: Image Show Per Co-Ordinate ::::::::::::::::::::::::::::::::://




	if (imagee_x_1 == 1 )  iShowImage(0  ,400,200,200,images2);
	if (imagee_x_2 == 1 )  iShowImage(200,400,200,200,images2);
	if (imagee_x_3 == 1)  iShowImage(400,400,200,200,images2);

	if (imagee_x_4 == 1 )  iShowImage(0,200,200,200,images2);
	if (imagee_x_5 == 1)  iShowImage(200,200,200,200,images2);
	if (imagee_x_6 == 1)   iShowImage(400,200,200,200,images2);

	if (imagee_x_7 == 1 )   iShowImage(0,0,200,200,images2);
	if (imagee_x_8 == 1 )  iShowImage(200,0,200,200,images2);
	if (imagee_x_9 == 1 )  iShowImage(400,0,200,200,images2);

	if (imagee_o_1 == 1  )  iShowImage(0  ,400,200,200,images3);
	if (imagee_o_2 == 1  )  iShowImage(200,400,200,200,images3);
	if (imagee_o_3 == 1 )   iShowImage(400,400,200,200,images3);

	if (imagee_o_4 == 1 )  iShowImage(0,200,200,200,images3);
	if (imagee_o_5 == 1 )  iShowImage(200,200,200,200,images3);
	if (imagee_o_6 == 1 )  iShowImage(400,200,200,200,images3);

	if (imagee_o_7 == 1 )  iShowImage(0,0,200,200,images3);
	if (imagee_o_8 == 1 )  iShowImage(200,0,200,200,images3);
	if (imagee_o_9 == 1 )  iShowImage(400,0,200,200,images3);



	if(cursor_x>= 601 && cursor_x<= 601+90 && cursor_y>= 55 && cursor_y<= 55+55)
	{
		players=0;
		counts=0;
		win=1;
		show_resl_x=0;
		show_resl_o=0;
		show_resl_draw=0;
		boxx_1 = 1 , boxx_2 = 1, boxx_3= 1, boxx_4 = 1,boxx_5 = 1,boxx_6 = 1,boxx_7 = 1,boxx_8 = 1,boxx_9 = 1;
		imagee_x_1 = 0,imagee_x_2 = 0,imagee_x_3 = 0,imagee_x_4 = 0,imagee_x_5 = 0,imagee_x_6 = 0,imagee_x_7 = 0,imagee_x_8 = 0,imagee_x_9 = 0;
		imagee_o_1 = 0,imagee_o_2 = 0,imagee_o_3 = 0,imagee_o_4 = 0,imagee_o_5 = 0,imagee_o_6 = 0,imagee_o_7 = 0,imagee_o_8 = 0,imagee_o_9 = 0;
		stop_img_shows=1;
		img2_st_flag=1;
		cursor_x=0;
		cursor_y=0;
		single_flag=1;
		
	}

}



void computer()
{

	//:::::::::::::::::::::::::::::::::::: Random Function For Auto Genarator Logic ::::::::::::::::::::::::::::::::://



	if(players==2 && stop_img_shows==1)

	{

		random_number= (rand() % 10) + 1;
		if(random_number>=1 && random_number<=9)
		{
			switch(random_number)
			{

			case 1:
				{


					if(user_click==1 && stop_img_shows==1)
					{


						if(boxx_4==1 )
						{

							imagee_o_4=1;
							boxx_4=0;
						}
						else if(boxx_6==1 )
						{

							imagee_o_6=1;
							boxx_6=0;
						}
						else if(boxx_5==1 )
						{

							imagee_o_5=1;
							boxx_5=0;
						}
						else if(boxx_1==1 )
						{

							imagee_o_1=1;
							boxx_1=0;
						}
						else if(boxx_2==1 )
						{

							imagee_o_2=1;
							boxx_2=0;
						}
						else if(boxx_3==1 )
						{

							imagee_o_3=1;
							boxx_3=0;
						}
						else if(boxx_7==1)
						{

							imagee_o_7=1;
							boxx_7=0;
						}
						else if(boxx_8==1 )
						{

							imagee_o_8=1;
							boxx_8=0;
						}
						else if(boxx_9==1 )
						{

							imagee_o_9=1;
							boxx_9=0;
						}


						players=1;
						break;
					}
				}

			case 2:
				{

					if(user_click==2 && stop_img_shows==1)
					{	


						if( boxx_6==1 )
						{

							imagee_o_6=1;
							boxx_6=0;
						}
						else if( boxx_2==1 )
						{

							imagee_o_2=1;
							boxx_2=0;
						}
						else if(boxx_5==1 )
						{

							imagee_o_5=1;
							boxx_5=0;
						}
						else if(boxx_7==1 )
						{

							imagee_o_7=1;
							boxx_7=0;
						}
						else if(boxx_8==1)
						{

							imagee_o_8=1;
							boxx_8=0;
						}
						else if(boxx_2==1)
						{

							imagee_o_2=1;
							boxx_2=0;
						}
						else if(boxx_9==1)
						{

							imagee_o_9=1;
							boxx_9=0;
						}
						else if(boxx_8==1)
						{

							imagee_o_8=1;
							boxx_8=0;
						}
						else if(boxx_3==1)
						{

							imagee_o_3=1;
							boxx_3=0;
						}	


						players=1;
						break;
					}
				}

			case 3:
				{

					if(user_click==3 && stop_img_shows==1) 
					{


						if(boxx_5==1)
						{

							imagee_o_5=1;
							boxx_5=0;
						}
						else if( boxx_8==1)
						{

							imagee_o_8=1;
							boxx_8=0;
						}
						else if( boxx_3==1)
						{

							imagee_o_3=1;
							boxx_3=0;
						}
						else if( boxx_2==1)
						{

							imagee_o_2=1;
							boxx_2=0;
						}
						else if( boxx_6==1)
						{

							imagee_o_6=1;
							boxx_6=0;
						}
						else if( boxx_9==1)
						{

							imagee_o_9=1;
							boxx_9=0;
						}
						else if( boxx_7==1)
						{

							imagee_o_7=1;
							boxx_7=0;
						}
						else if( boxx_1==1)
						{

							imagee_o_1=1;
							boxx_1=0;
						}
						else if( boxx_4==1)
						{

							imagee_o_4=1;
							boxx_4=0;
						}


						players=1;
						break;
					}
				}

			case 4:
				{

					if(user_click==4 && stop_img_shows==1)
					{


						if(boxx_5==1)
						{

							imagee_o_5=1;
							boxx_5=0;
						}
						else if(boxx_8==1)
						{

							imagee_o_8=1;
							boxx_8=0;
						}
						else if(boxx_3==1)
						{

							imagee_o_3=1;
							boxx_3=0;
						}
						else if(boxx_2==1)
						{

							imagee_o_2=1;
							boxx_2=0;
						}
						else if(boxx_6==1)
						{

							imagee_o_6=1;
							boxx_6=0;
						}
						else if(boxx_9==1)
						{

							imagee_o_9=1;
							boxx_9=0;
						}
						else if(boxx_7==1)
						{

							imagee_o_7=1;
							boxx_7=0;
						}
						else if(boxx_1==1)
						{

							imagee_o_1=1;
							boxx_1=0;
						}
						else if(boxx_4==1)
						{

							imagee_o_4=1;
							boxx_4=0;
						}


						players=1;
						break;
					}
				}

			case 5:
				{

					if(user_click==5 && stop_img_shows==1)
					{


						if(boxx_5==1)
						{

							imagee_o_5=1;
							boxx_5=0;
						}
						else if(boxx_8==1)
						{

							imagee_o_8=1;
							boxx_8=0;
						}
						else if(boxx_3==1)
						{

							imagee_o_3=1;
							boxx_3=0;
						}
						else if(boxx_2==1)
						{

							imagee_o_2=1;
							boxx_2=0;
						}
						else if(boxx_6==1)
						{

							imagee_o_6=1;
							boxx_6=0;
						}
						else if(boxx_9==1)
						{

							imagee_o_9=1;
							boxx_9=0;
						}
						else if(boxx_7==1)
						{

							imagee_o_7=1;
							boxx_7=0;
						}
						else if(boxx_1==1)
						{

							imagee_o_1=1;
							boxx_1=0;
						}
						else if(boxx_4==1)
						{

							imagee_o_4=1;
							boxx_4=0;
						}


						players=1;
						break;
					}
				}

			case 6:
				{

					if(user_click==6 && stop_img_shows==1)
					{

						if(boxx_5==1)
						{

							imagee_o_5=1;
							boxx_5=0;
						}
						else if(boxx_8==1)
						{

							imagee_o_8=1;
							boxx_8=0;
						}
						else if(boxx_3==1)
						{

							imagee_o_3=1;
							boxx_3=0;
						}
						else if(boxx_2==1)
						{

							imagee_o_2=1;
							boxx_2=0;
						}
						else if(boxx_6==1)
						{

							imagee_o_6=1;
							boxx_6=0;
						}
						else if(boxx_9==1)
						{

							imagee_o_9=1;
							boxx_9=0;
						}
						else if(boxx_7==1)
						{

							imagee_o_7=1;
							boxx_7=0;
						}
						else if(boxx_1==1)
						{

							imagee_o_1=1;
							boxx_1=0;
						}
						else if(boxx_4==1)
						{

							imagee_o_4=1;
							boxx_4=0;
						}


						players=1;
						break;
					}
				}

			case 7:
				{

					if(user_click==7 && stop_img_shows==1)
					{


						if(boxx_5==1 )
						{

							imagee_o_5=1;
							boxx_5=0;
						}
						else if(boxx_8==1)
						{

							imagee_o_8=1;
							boxx_8=0;
						}
						else if(boxx_3==1)
						{

							imagee_o_3=1;
							boxx_3=0;
						}
						else if(boxx_2==1)
						{

							imagee_o_2=1;
							boxx_2=0;
						}
						else if(boxx_6==1)
						{

							imagee_o_6=1;
							boxx_6=0;
						}
						else if(boxx_9==1)
						{

							imagee_o_9=1;
							boxx_9=0;
						}
						else if(boxx_7==1)
						{

							imagee_o_7=1;
							boxx_7=0;
						}
						else if(boxx_1==1)
						{

							imagee_o_1=1;
							boxx_1=0;
						}
						else if(boxx_4==1)
						{

							imagee_o_4=1;
							boxx_4=0;
						}


						players=1;
						break;
					}
				}

			case 8:
				{

					if(user_click==8 && stop_img_shows==1)
					{


						if(boxx_5==1)
						{

							imagee_o_5=1;
							boxx_5=0;
						}
						else if(boxx_8==1)
						{

							imagee_o_8=1;
							boxx_8=0;
						}
						else if(boxx_3==1)
						{

							imagee_o_3=1;
							boxx_3=0;
						}
						else if(boxx_2==1)
						{

							imagee_o_2=1;
							boxx_2=0;
						}
						else if(boxx_6==1)
						{

							imagee_o_6=1;
							boxx_6=0;
						}
						else if(boxx_9==1)
						{

							imagee_o_9=1;
							boxx_9=0;
						}
						else if(boxx_7==1)
						{

							imagee_o_7=1;
							boxx_7=0;
						}
						else if(boxx_1==1)
						{

							imagee_o_1=1;
							boxx_1=0;
						}
						else if(boxx_4==1)
						{

							imagee_o_4=1;
							boxx_4=0;
						}


						players=1;
						break;
					}
				}

			case 9:
				{

					if(user_click==9 && stop_img_shows==1)
					{


						if(boxx_5==1)
						{

							imagee_o_5=1;
							boxx_5=0;
						}
						else if(boxx_8==1)
						{

							imagee_o_8=1;
							boxx_8=0;
						}
						else if(boxx_3==1)
						{

							imagee_o_3=1;
							boxx_3=0;
						}
						else if(boxx_2==1 )
						{

							imagee_o_2=1;
							boxx_2=0;
						}
						else if(boxx_6==1)
						{

							imagee_o_6=1;
							boxx_6=0;
						}
						else if(boxx_9==1)
						{

							imagee_o_9=1;
							boxx_9=0;
						}
						else if(boxx_7==1)
						{

							imagee_o_7=1;
							boxx_7=0;
						}
						else if(boxx_1==1)
						{

							imagee_o_1=1;
							boxx_1=0;
						}
						else if(boxx_4==1)
						{

							imagee_o_4=1;
							boxx_4=0;
						}


						players=1;
						break;
					}
				}	
			}
		}
	}


}









//:::::::::::::::::::::::::::::::::::: iDraw Fuction ::::::::::::::::::::::::::::::::://

void iDraw()
{
	//place your drawing codes here
	iClear();

	if(img2_flag==0)
	{
		iShowBMP(0,0,"image\\tictactoe.bmp");
		iSetColor(255, 255, 0);
		iText(240, 50, "Press r to Enter The Name");

	}
	if(img2_flag==1)
	{
		input_scn();

	}
	else if(img2_flag==2)first_scrn();
	else if(img2_st_flag==1 ) start_scrn();
	else if(img2_st_flag==2)option_scrn();
	else if( multi_gaming_flag==1)multi_win();
	else if(music_flag==1)music_scn();
	else if(about_flag==1)about_scn();
	else if(single_flag==1)single_player_scn();
	else if(score==1)
		{
			scoreboard();
			//score_count();
	     }
}

void iPassiveMouse(int x, int y)
{

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
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here
		cursor_x=mx;
		cursor_y=my;
		printf("x = %d \t y= %d\n",mx,my);
		//printf("x= %d \t y=%d\n",cursor_x,cursor_y);
		if(show_resl_x==1 && win==0 && cursor_x>= 601 && cursor_x<= 601+90 && cursor_y>= 55 && cursor_y<= 55+55)
	{
		point+=1;
		


	}


	}
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here

	}
}

/*
function iKeyboard() is called whenever the user hits a key in keyboard.
key- holds the ASCII value of the key pressed.
*/

int var=0;
void iKeyboard(unsigned char key)
{
	if (key == 'q')
	{
		exit(0);
	}
	if (key == 'r')
	{
		img2_flag=1;
	}
	if (key == 'x')
	{
		img2_flag=2;
	}

	int i;
	if(iflag == 1)
	{
		if(key == '\r')
		{
			iflag = 0;
			strcpy(str2, str);
			fprintf(input,"%s %d\n",str2,var);
			printf("%s\n", str2);
			for(i = 0; i < len; i++)
				str[i] = 0;
			len = 0;
            

		}

		else if(key == '\b')
		{
			str[len-1] = 0;
			len--;
		}


		else 
		{
			str[len] = key;
			len++;
		}

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

	if (key == GLUT_KEY_END)
	{
		exit(0);
	}
	//place your codes for other keys here
}

int main()
{
	//place your own initialization codes here.

	first_scn_variable();
	start_scn_variable();
	option_scn_variable();
	music_scn_variable();
	


	iInitialize(700, 600, "Tic Tac Toe");
	srand(time(0));

	

	image1 = iLoadImage("image\\board.png");
	image2 = iLoadImage("image\\x.png");
	image3 = iLoadImage("image\\o.png");

	images1 = iLoadImage("image\\board.png");
	images2 = iLoadImage("image\\x.png");
	images3 = iLoadImage("image\\o.png");
	//PlaySound("image\\music.wav",NULL,SND_ASYNC|SND_LOOP);


	iStart(); // it will start drawing

	return 0;
}

