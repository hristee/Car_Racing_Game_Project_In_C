#include<graphics.h>
int main()
{
    int gd=DETECT,gm;
    initgraph(&gd,&gm,"");
    int t_y=-300,cl,cr,C_y1=0,C_y2=0,a=0,b=0,d=1,cy3=0,uf,df,lk=1,kk=0,mk=0,dk=1;
    int speed=20;
    long long int page=0;
    char pp[5];
    //car variables
    int c_x=0,M_speed=5;
    setcolor(WHITE);
    rectangle(0,0,1000,1000);
    setfillstyle(1,GREEN);
    floodfill(1,1,GREEN);
    settextstyle(10,0,3);

    outtextxy(85,100,"Welcome to The Car Race Game");
    outtextxy(75,190,"Press Enter to Start the Game");
    outtextxy(75,240,"Press 5 to Exit the Game");

    char al;
    al=getch();
    if(al=='5')
    {
        cleardevice();
        setcolor(WHITE);
        rectangle(0,0,1000,1000);
        setfillstyle(1,GREEN);
        floodfill(1,1,GREEN);
        settextstyle(10,0,5);
        outtextxy(85,100,"Good bye Racing");

    }
    else
    {

   while(1)
   {
    setactivepage(page);
    setvisualpage(1-page);
    cleardevice();

    //Background
    setcolor(CYAN);
    rectangle(0,0,1000,1000);
    setfillstyle(1,CYAN);
    floodfill(1,1,CYAN);
    //creating track;
    setcolor(WHITE);
    rectangle(200,-1,400,500);
    setfillstyle(1,8);
    floodfill(201,0,WHITE);
    //lines middle the road
    for(int i=0;i<500;i+=65)
    {
        rectangle(290,10+i+t_y,310,50+i+t_y);
        setfillstyle(1,WHITE);
        floodfill(291,11+i+t_y,WHITE);
    }
    t_y+=15;
    if(t_y>500)
        t_y=-300;


    //life and points
    settextstyle(10,0,2);
    outtextxy(10,10,"SPEED:");
    outtextxy(10,40,"POINTS:");
    //drawing circle for life
    /*setfillstyle(1,WHITE);
    circle(90,20,6);
    floodfill(91,21,WHITE);
    circle(110,20,6);
    floodfill(111,21,WHITE);
    circle(130,20,6);
    floodfill(131,21,WHITE);*/
    //speed
    outtextxy(90,10,"20");
    outtextxy(130,10,"km/h");

    //points
    outtextxy(100,40,"0");
    //Car design
    cl=300+c_x;
    cr=340+c_x;
    if(cl<200)
    {
        cl=200;
        cr=240;
    }
    if(cr>400)
    {
        cr=400;
        cl=360;
    }
    setcolor(BLACK);
    setfillstyle(1,RED);
    rectangle(cl,400,cr,460);
    floodfill(cl+1,401,BLACK);
    //Front
    cl=305+c_x;
    cr=335+c_x;
    if(cl<205)
    {
        cl=205;
        cr=235;
    }
    if(cr>395)
    {
        cr=395;
        cl=365;
    }
    setfillstyle(1,BROWN);
    rectangle(cl,385,cr,400);
    floodfill(cl+1,386,BLACK);
    //hood
    cl=305+c_x;
    cr=335+c_x;
    if(cl<205)
    {
        cl=205;
        cr=235;
    }
    if(cr>395)
    {
        cr=395;
        cl=365;
    }
    setfillstyle(1,GREEN);
    rectangle(cl,405,cr,455);
    floodfill(cl+1,406,BLACK);
    //Wheals
    cl=305+c_x;
    cr=337+c_x;
    if(cl<205)
    {
        cl=205;
        cr=237;
    }
    if(cr>397)
    {
        cl=365;
        cr=397;
    }
    setfillstyle(1,BLACK);
    pieslice(cl,392,90,270,6);
    pieslice(cr,392,270,90,5);

    if(GetAsyncKeyState(VK_LEFT))
        c_x-=M_speed;
    else if(GetAsyncKeyState(VK_RIGHT))
        c_x+=M_speed;
  //enemy CAr1
    setcolor(BLACK);
    setfillstyle(1,RED);
    rectangle(250,(-10)+C_y1,290,50+C_y1);
    floodfill(251,(-9)+C_y1,BLACK);

    //Front
    setfillstyle(1,RED);
    rectangle(255,(-25)+C_y1,285,(-10)+C_y1);
    floodfill(256,(-24)+C_y1,BLACK);

    setfillstyle(1,WHITE);
    rectangle(255,(-5)+C_y1,285,45+C_y1);
    floodfill(256,(-4)+C_y1,BLACK);
    //wheels
    setfillstyle(1,BLACK);
    pieslice(255,((-18)+C_y1),90,270,6);
    pieslice(287,((-18)+C_y1),270,90,5);
//enemy CAr2
    setcolor(BLACK);
    setfillstyle(1,RED);
    rectangle(350,10+C_y2,390,70+C_y2);
    floodfill(351,11+C_y2,BLACK);
    //Front
    setfillstyle(1,RED);
    rectangle(355,(-5)+C_y2,385,10+C_y2);
    floodfill(356,(-4)+C_y2,BLACK);

    setfillstyle(1,BLUE);
    rectangle(355,15+C_y2,385,65+C_y2);
    floodfill(356,16+C_y2,BLACK);
    //wheels
    setfillstyle(1,BLACK);
    pieslice(355,((2)+C_y2),90,270,6);
    pieslice(387,((2)+C_y2),270,90,5);

    C_y1=C_y1+3;
    C_y2=C_y2+1;
    if(C_y1>700)
    {
        b=0;
        C_y1=0;
    }
    if(C_y2>500)
    {
        b=0;
        C_y2=0;
    }
    if(C_y1>495)
    {
        b=b+1;
        if(b==1)
        {
            a=a+1;
            if(a%5==0)
            {
                d=d+1;
                dk=dk+1;
                /*if(d==5)
                {
                    dk=dk-1;
                    printf("dk= %d\n",dk);
                }*/
            }
        }
    }
    if(C_y2>480)
    {
        b=b+1;
        if(b==1)
        {
            a=a+1;
            if(a%5==0)
            {
                d=d+1;
                dk=dk+1;
               /* if(d==5)
                {
                    dk=dk-1;
                    printf("dk= %d\n",dk);
                }*/
                /*if(d%5==0)
                {

                }*/
            }
        }
    }
    sprintf(pp,"%d",a);
    setcolor(WHITE);
    settextstyle(10,0,2);
    outtextxy(110,40,pp);
    outtextxy(10,80,"Levels:");
    sprintf(pp,"%d",d);
    outtextxy(110,80,pp);



    page=1-page;
   // dk=lk;
   //delay((70)/d);
//fuel

   setcolor(WHITE);
    setfillstyle(1,GREEN);
    uf=(-150)+cy3;
    df=(-140)+cy3;
    rectangle(255,uf,280,df);
    floodfill(256,uf+1,WHITE);
    cy3=cy3+3;
    if(cy3>2500)
    {
        kk=0;
        cy3=0;
    }


    if(df<461 && df>400)
    {
        if(cr<=290 && cr>=255)
        {
            kk=kk+1;
           // printf("kk=%d\n",kk);
            if(kk==1)
            {
                dk=dk-1;
                a=a+2;
            //printf("fuel added\n");

                cy3=2500;

            }
        }
    }
    //fuel box
    setcolor(WHITE);
    settextstyle(10,0,3);
    outtextxy(430,10,"Fuel");
    rectangle(500,5,580,35);
    if(dk<1)
      {
         dk=1;
      }
      if(dk<6)
      {
    for(int i=5;i>=dk;i--)
    {
        rectangle((500+(((i-dk)*16))),5,(516+((i-dk)*16)),35);
        if(dk>3)
        {
            setfillstyle(1,RED);
        }
        else if(dk>2)
        {
            setfillstyle(1,YELLOW);
        }
        else
        {
            setfillstyle(1,GREEN);
        }
        floodfill((501+(((i-dk)*16))),6,WHITE);
    }
      }
      else
      {
          cleardevice();

    //Background
    setcolor(CYAN);
    rectangle(0,0,1000,1000);
    setfillstyle(1,CYAN);
    floodfill(1,1,CYAN);

    setcolor(WHITE);
    settextstyle(10,0,2);
    outtextxy(150,150,"Game Over");
      }
    //outtextxy(390,70,"game");

   //delay(20);

   delay(50-(2*a));
   speed=20+(a*2);
  /* for(int i=20;i<100;i++)
    {
        if(a>0)
        {
            speed=speed+5;
        }
        else
        {
            speed=i;
        }*/
        sprintf(pp,"%d",speed);
    setcolor(WHITE);
    settextstyle(10,0,2);
    outtextxy(90,10,pp);



   }
   }
    getch();
}
