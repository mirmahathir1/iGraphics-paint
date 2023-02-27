# include "iGraphics.h"
#include<math.h>
#include<stdlib.h>
#include"mahathircpp.h"
#include<windows.h>
#include<conio.h>

double ***saveRGB;

int RGB[3];
int u;
int MX,MY,nib=32;

//poly variable
double tri_poly_x[]={0,0,0};
double tri_poly_y[]={0,0,0};
double tetra_poly_x[]={0,0,0,0};
double tetra_poly_y[]={0,0,0,0};
//circle variables
signed int circle_x=0,circle_y=0,circle_r=0;
signed int circle_x2=0,circle_y2=0;
//line variables
int linex1=0,liney1=0,linex2=0,liney2=0;

int count_click=0;
//Mode
int mode=0,mode_co_ord=0;
save()
{
    int i=0,j=0;
    int RGB[3];

    for(i=0;i<1000;i++)
        for(j=0;j<700;j++)
    {
        iGetPixelColor(i+400,j,RGB);
        saveRGB[i][j][0]=RGB[0];
        saveRGB[i][j][1]=RGB[1];
        saveRGB[i][j][2]=RGB[2];
    }
    savebmp("NEW.bmp",1000,700,72,saveRGB);
}
co_ord()
{
    int x,y;
    iSetColor(0,0,0);
    for(x=0;x<=1400;x=x+100)
    {
        for(y=0;y<=800;y=y+100)
        {
           iFilledCircle(x,y,2);
        }
    }
}
nib_selection()
{
    switch(nib)
    {
        case 2:iText(55,275,"Current nib size: 2", GLUT_BITMAP_HELVETICA_18);break;
        case 4:iText(55,275,"Current nib size: 4", GLUT_BITMAP_HELVETICA_18);break;
        case 6:iText(55,275,"Current nib size: 6", GLUT_BITMAP_HELVETICA_18);break;
        case 8:iText(55,275,"Current nib size: 8", GLUT_BITMAP_HELVETICA_18);break;
        case 10:iText(55,275,"Current nib size: 10", GLUT_BITMAP_HELVETICA_18);break;
        case 12:iText(55,275,"Current nib size: 12", GLUT_BITMAP_HELVETICA_18);break;
        case 14:iText(55,275,"Current nib size: 14", GLUT_BITMAP_HELVETICA_18);break;
        case 16:iText(55,275,"Current nib size: 16", GLUT_BITMAP_HELVETICA_18);break;
        case 18:iText(55,275,"Current nib size: 18", GLUT_BITMAP_HELVETICA_18);break;
        case 20:iText(55,275,"Current nib size: 20", GLUT_BITMAP_HELVETICA_18);break;
        case 22:iText(55,275,"Current nib size: 22", GLUT_BITMAP_HELVETICA_18);break;
        case 24:iText(55,275,"Current nib size: 24", GLUT_BITMAP_HELVETICA_18);break;
        case 26:iText(55,275,"Current nib size: 26", GLUT_BITMAP_HELVETICA_18);break;
        case 28:iText(55,275,"Current nib size: 28", GLUT_BITMAP_HELVETICA_18);break;
        case 30:iText(55,275,"Current nib size: 30", GLUT_BITMAP_HELVETICA_18);break;
        case 32:iText(55,275,"Current nib size: 32", GLUT_BITMAP_HELVETICA_18);break;
    }
}
mode_selection()
{
    switch(mode)
    {
    case 0:iText(245,175,"Nib",GLUT_BITMAP_HELVETICA_18);break;
    case 3:iText(245,175,"Non-fill Rectangle",GLUT_BITMAP_HELVETICA_18);break;
    case 1:iText(245,175,"Filled Rectangle",GLUT_BITMAP_HELVETICA_18);break;
    case 4:iText(245,175,"Non-filled Circle",GLUT_BITMAP_HELVETICA_18);break;
    case 2:iText(245,175,"Filled Circle",GLUT_BITMAP_HELVETICA_18);break;
    case 5:iText(245,175,"Filled Triangle",GLUT_BITMAP_HELVETICA_18);break;
    case 6:iText(245,175,"Non-fill Triangle",GLUT_BITMAP_HELVETICA_18);break;
    case 7:iText(245,175,"Line",GLUT_BITMAP_HELVETICA_18);break;
    }
}
void colorboard()
{
	//Color selection box
	iSetColor(255,255,255);iFilledRectangle(0,0,400,800);
	iSetColor(255,128,128);iFilledRectangle(0,750,50,50);
	iSetColor(128,255,128);iFilledRectangle(100,750,50,50);
	iSetColor(0,255,128);iFilledRectangle(150,750,50,50);
	iSetColor(128,255,255);iFilledRectangle(200,750,50,50);
	iSetColor(0,128,255);iFilledRectangle(250,750,50,50);
	iSetColor(255,128,192);iFilledRectangle(300,750,50,50);
	iSetColor(255,128,255);iFilledRectangle(350,750,50,50);
	iSetColor(255,0,0);iFilledRectangle(0,700,50,50);
	iSetColor(255,255,0);iFilledRectangle(50,700,50,50);
	iSetColor(128,255,0);iFilledRectangle(100,700,50,50);
	iSetColor(0,255,64);iFilledRectangle(150,700,50,50);
	iSetColor(0,255,255);iFilledRectangle(200,700,50,50);
	iSetColor(0,128,192);iFilledRectangle(250,700,50,50);
	iSetColor(128,128,192);iFilledRectangle(300,700,50,50);
	iSetColor(255,0,255);iFilledRectangle(350,700,50,50);
	iSetColor(128,64,64);iFilledRectangle(0,650,50,50);
	iSetColor(255,128,64);iFilledRectangle(50,650,50,50);
	iSetColor(0,255,0);iFilledRectangle(100,650,50,50);
    iSetColor(0,128,128);iFilledRectangle(150,650,50,50);
    iSetColor(0,64,128);iFilledRectangle(200,650,50,50);
    iSetColor(128,128,255);iFilledRectangle(250,650,50,50);
    iSetColor(128,0,64);iFilledRectangle(300,650,50,50);
    iSetColor(255,0,128);iFilledRectangle(350,650,50,50);
	iSetColor(128,0,0);iFilledRectangle(0,600,50,50);
	iSetColor(255,128,0);iFilledRectangle(50,600,50,50);
	iSetColor(0,128,0);iFilledRectangle(100,600,50,50);
	iSetColor(0,128,64);iFilledRectangle(150,600,50,50);
	iSetColor(0,0,255);iFilledRectangle(200,600,50,50);
	iSetColor(0,0,160);iFilledRectangle(250,600,50,50);
	iSetColor(128,0,128);iFilledRectangle(300,600,50,50);
	iSetColor(128,0,255);iFilledRectangle(350,600,50,50);
	iSetColor(64,0,0);iFilledRectangle(0,550,50,50);
	iSetColor(128,64,0);iFilledRectangle(50,550,50,50);
	iSetColor(0,64,0);iFilledRectangle(100,550,50,50);
	iSetColor(0,64,64);iFilledRectangle(150,550,50,50);
	iSetColor(0,0,128);iFilledRectangle(200,550,50,50);
    iSetColor(0,0,64);iFilledRectangle(250,550,50,50);
    iSetColor(64,0,64);iFilledRectangle(300,550,50,50);
    iSetColor(64,0,128);iFilledRectangle(350,550,50,50);
	iSetColor(0,0,0);iFilledRectangle(0,500,50,50);
	iSetColor(128,128,0);iFilledRectangle(50,500,50,50);
    iSetColor(128,128,64);iFilledRectangle(100,500,50,50);
    iSetColor(128,128,128);iFilledRectangle(150,500,50,50);
    iSetColor(64,128,128);iFilledRectangle(200,500,50,50);
    iSetColor(192,192,192);iFilledRectangle(250,500,50,50);
    iSetColor(64,64,64);iFilledRectangle(300,500,50,50);
    iSetColor(255,255,255);iFilledRectangle(350,500,50,50);
	//current chosen color
	iSetColor(0,0,0);
	iLine(401,0,401,800);
	iText(53, 475,"Current chosen color.", GLUT_BITMAP_HELVETICA_12);
	iText(53, 455,"Right click on the above colors to change current color", GLUT_BITMAP_HELVETICA_12);
	//Lines of margin
	iSetColor(RGB[0],RGB[1],RGB[2]);iFilledRectangle(0,445,50,50);
	iSetColor(0,0,0);
	iLine(0,499,400,499);
	iLine(0,440,400,440);
	iSetColor(0,0,0);
	iRectangle(0,445,50,50);
	//Box of nib width selection
	iLine(0,400,400,400);
	iLine(0,350,400,350);
	iLine(0,300,400,300);
	iText(10,415,"Right click on number to choose nib", GLUT_BITMAP_HELVETICA_12);
	//Chart of nib width
	iLine(50,300,50,400);
	iLine(100,300,100,400);
	iLine(150,300,150,400);
	iLine(200,300,200,400);
	iLine(250,300,250,400);
	iLine(300,300,300,400);
	iLine(350,300,350,400);

	//numbers of nib chart
	iText(18,370,"2",GLUT_BITMAP_TIMES_ROMAN_24);
	iText(68,370,"4",GLUT_BITMAP_TIMES_ROMAN_24);
	iText(118,370,"6",GLUT_BITMAP_TIMES_ROMAN_24);
	iText(168,370,"8",GLUT_BITMAP_TIMES_ROMAN_24);
	iText(218,370,"10",GLUT_BITMAP_TIMES_ROMAN_24);
	iText(268,370,"12",GLUT_BITMAP_TIMES_ROMAN_24);
	iText(318,370,"14",GLUT_BITMAP_TIMES_ROMAN_24);
	iText(368,370,"16",GLUT_BITMAP_TIMES_ROMAN_24);
	iText(18,320,"18",GLUT_BITMAP_TIMES_ROMAN_24);
	iText(68,320,"20",GLUT_BITMAP_TIMES_ROMAN_24);
	iText(118,320,"22",GLUT_BITMAP_TIMES_ROMAN_24);
	iText(168,320,"24",GLUT_BITMAP_TIMES_ROMAN_24);
	iText(218,320,"26",GLUT_BITMAP_TIMES_ROMAN_24);
	iText(268,320,"28",GLUT_BITMAP_TIMES_ROMAN_24);
	iText(318,320,"30",GLUT_BITMAP_TIMES_ROMAN_24);
	iText(368,320,"32",GLUT_BITMAP_TIMES_ROMAN_24);
	//current nib selection
	nib_selection();
	iLine(0,250,400,250);
	//current mode selection
	mode_selection();
	//Above box of title
	iSetColor(128,255,255);
	iFilledRectangle(402,700,1000,100);
	iSetColor(0,0,0);
	iLine(400,700,1400,700);
	iText(800,750,"PaintMania v2.0",GLUT_BITMAP_TIMES_ROMAN_24);
	iText(1000,725,"Created by Mahathir (BUET CSE 1605011)",GLUT_BITMAP_9_BY_15);
	//Geometric shape box
	iSetColor(0,0,0);
	iRectangle(0,195,50,50);//mode 1 filled rectangle
	iRectangle(0,140,50,50);//mode 2 filled circle
	iRectangle(0,250,50,50);//mode 0 default nib
	iRectangle(50,195,50,50);//mode 3 general rectangle
	iRectangle(50,140,50,50);//mode 4 general circle
	iRectangle(105,195,50,50);//mode 5 filled triangle
	iRectangle(155,195,50,50);//mode 6 general triangle
	iRectangle(105,140,50,50);//mode 7 for line
	//indication of Geometric shape box
	iFilledRectangle(5,200,40,40);//mode 1 filled rectangle
	iFilledCircle(25,165,20);//mode 2 filled circle
	iText(5,275,"Nib",GLUT_BITMAP_TIMES_ROMAN_24);//mode 0 default nib
	iRectangle(55,200,40,40);//mode 3 general rectangle
	iCircle(75,165,20);//mode 4 general circle
	double triangle_x[]={110,150,130};
	double triangle_y[]={200,200,240};
	iFilledPolygon(triangle_x,triangle_y,3);//mode 5 filled triangle
	double gtriangle_x[]={160,200,180};
	double gtriangle_y[]={200,200,240};
	iPolygon(gtriangle_x,gtriangle_y,3);;//mode 6 general triangle
	iText(108,160,"Line",GLUT_BITMAP_TIMES_ROMAN_24);//mode 7 line
	//Current Mode box
	iRectangle(225,160,176,90);
	iText(245,225,"Current Mode:",GLUT_BITMAP_TIMES_ROMAN_24);
	//New box
	iRectangle(200,0,50,50);
	iText(205,10,"NEW",GLUT_BITMAP_HELVETICA_18);
	//save box
	iRectangle(250,0,70,50);
	iText(255,10,"SAVE",GLUT_BITMAP_HELVETICA_18);
}
void whiteboard()
{
	iSetColor(255,255,255);
	iFilledRectangle(0,0,1400,800);
}
void rect()
{
    if(mode==1)
	//iFilledRectangle(rect_x,rect_y,rect_width,rect_height);
	if(count_click==4)
    {
	iFilledPolygon(tetra_poly_x,tetra_poly_y,4);
    count_click=0;
    }
	if(mode==3)
	//iRectangle(rect_x,rect_y,rect_width,rect_height);
	if(count_click==4)
    {
	iPolygon(tetra_poly_x,tetra_poly_y,4);
    count_click=0;
    }
}
void triangle()
{
    if(mode==5)
	if(count_click==3)
    {
	iFilledPolygon(tri_poly_x,tri_poly_y,3);
    count_click=0;
    }
	if(mode==6)
	if(count_click==3)
    {
	iPolygon(tri_poly_x,tri_poly_y,3);
    count_click=0;
    }
}
void circle()
{
	if(mode==2)
	if(count_click==2)
	{
	iFilledCircle(circle_x,circle_y,circle_r);
	count_click=0;
	}
	if(mode==4)
	if(count_click==2)
	{
	iCircle(circle_x,circle_y,circle_r);
	count_click=0;
	}
}
void line()
{
    if(mode==7)
    {
        if(count_click==2)
        {
            iLine(linex1,liney1,linex2,liney2);
            count_click=0;
        }
    }
}
void Nib()
{
	if(mode==0)
	iFilledCircle(MX,MY,nib);
}
void iDraw()
{
	colorboard();
	iSetColor(RGB[0],RGB[1],RGB[2]);//To set color for nib and shapes
    Nib();
	rect();
    circle();
    triangle();
    line();
	//co_ord();
}
void iMouseMove(int mx, int my)
{
	MX=mx;
	MY=my;
}
void iMouse(int button, int state, int mx, int my)
{
if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
{
	if((mode==1)||(mode==3))
	{
		count_click++;
		if(count_click==1)
        {
            tetra_poly_x[0]=mx;
            tetra_poly_y[0]=my;
            iFilledCircle(mx,my,1);
        }
        if(count_click==2)
        {
            tetra_poly_x[1]=mx;
            tetra_poly_y[1]=my;
            iFilledCircle(mx,my,1);
        }
        if(count_click==3)
        {
            tetra_poly_x[2]=mx;
            tetra_poly_y[2]=my;
            iFilledCircle(mx,my,1);
        }
        if(count_click==4)
        {
            tetra_poly_x[3]=mx;
            tetra_poly_y[3]=my;
        }
	}
	if((mode==2)||(mode==4))
	{
		count_click++;
		if(count_click==1)
		{
		circle_x=mx;
		circle_y=my;
		if(mode==2)
		iFilledCircle(mx,my,3);
		}
		if(count_click==2)
		{
			circle_x2=mx;
			circle_y2=my;
			circle_r=sqrt(pow((circle_x2-circle_x),2)+pow((circle_y2-circle_y),2));
		}
	}
	if((mode==5)||(mode==6))
	{
		count_click++;
		if(count_click==1)
        {
            tri_poly_x[0]=mx;
            tri_poly_y[0]=my;
            iFilledCircle(mx,my,1);
        }
        if(count_click==2)
        {
            tri_poly_x[1]=mx;
            tri_poly_y[1]=my;
            iFilledCircle(mx,my,1);
        }
        if(count_click==3)
        {
            tri_poly_x[2]=mx;
            tri_poly_y[2]=my;
            iFilledCircle(mx,my,1);
        }
	}
	if(mode==7)
    {
        count_click++;
        if(count_click==1)
        {
            linex1=mx;
            liney1=my;
            iFilledCircle(mx,my,1);
        }
        if(count_click==2)
        {
            linex2=mx;
            liney2=my;
            iFilledCircle(mx,my,1);
        }
    }
}
if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
{
//place your codes here
	int rgb[3];
	//Nib size
	if ((mx>0)&&(mx<50)&&(my>350)&&(my<400))nib=2;
	else if((mx>50)&&(mx<100)&&(my>350)&&(my<400))nib=4;
	else if((mx>100)&&(mx<150)&&(my>350)&&(my<400))nib=6;
	else if((mx>150)&&(mx<200)&&(my>350)&&(my<400))nib=8;
	else if((mx>200)&&(mx<250)&&(my>350)&&(my<400))nib=10;
	else if((mx>250)&&(mx<300)&&(my>350)&&(my<400))nib=12;
	else if((mx>300)&&(mx<350)&&(my>350)&&(my<400))nib=14;
	else if((mx>350)&&(mx<400)&&(my>350)&&(my<400))nib=16;
	else if((mx>0)&&(mx<50)&&(my>300)&&(my<350))nib=18;
	else if((mx>50)&&(mx<100)&&(my>300)&&(my<350))nib=20;
	else if((mx>100)&&(mx<150)&&(my>300)&&(my<350))nib=22;
	else if((mx>150)&&(mx<200)&&(my>300)&&(my<350))nib=24;
	else if((mx>200)&&(mx<250)&&(my>300)&&(my<350))nib=26;
	else if((mx>250)&&(mx<300)&&(my>300)&&(my<350))nib=28;
	else if((mx>300)&&(mx<350)&&(my>300)&&(my<350))nib=30;
	else if((mx>350)&&(mx<400)&&(my>300)&&(my<350))nib=32;
    //mode change
    else if((mx>0)&&(mx<50)&&(my>195)&&(my<245)){mode=1,count_click=0;}
	else if((mx>0)&&(mx<50)&&(my>140)&&(my<190)){mode=2,count_click=0;}
    else if((mx>0)&&(mx<50)&&(my>250)&&(my<300)){mode=0,count_click=0;}
    else if((mx>50)&&(mx<100)&&(my>195)&&(my<245)){mode=3,count_click=0;}
	else if((mx>50)&&(mx<100)&&(my>140)&&(my<190)){mode=4,count_click=0;}
	else if((mx>105)&&(mx<155)&&(my>195)&&(my<245)){mode=5,count_click=0;}
	else if((mx>155)&&(mx<205)&&(my>195)&&(my<245)){mode=6,count_click=0;}
	else if((mx>105)&&(mx<155)&&(my>140)&&(my<190)){mode=7,count_click=0;}
	//color change
	else if((mx>0)&&(mx<400)&&(my>500)&&(my<800))
    {
	iGetPixelColor(mx,my,rgb);
	RGB[0]=rgb[0];
	RGB[1]=rgb[1];
	RGB[2]=rgb[2];
	}
	else if((mx>200)&&(mx<250)&&(my>0)&&(my<50))whiteboard();
	else if((mx>250)&&(mx<320)&&(my>0)&&(my<50))save();
}
}


void iKeyboard(unsigned char key)
{
    if(key == 'n')
    {
       whiteboard();
    }
    else if(key == 's')
    {
        save();
    }
}

void iSpecialKeyboard(unsigned char key){if(key == GLUT_KEY_END){exit(0);}}
int main()
{
saveRGB=create_3D_array(saveRGB,1000,700,3);
iInitialize(1400, 800, "PaintMania v2.0");
return 0;
}
