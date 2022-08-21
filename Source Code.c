#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include<time.h>
#include<ctype.h>
#include <time.h>
#include <windows.h>
#include <process.h>
#include<conio.h>

#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77

HANDLE hStdout;
struct SMALL_RECT {
    SHORT Left;
    SHORT Top;
    SHORT Right;
    SHORT Bottom;
};

int length;
int bend_no=0;
int len;
char key;
void load();
int life;
void Delay(long double);
void Move();
void Food();
int Score();
void Print();
void gotoxy(int x, int y);
void GotoXY(int x,int y);
void Bend();
void Boarder();
void Down();
void Left();
void Up();
void Right();
int ExitGame();
int Scoreonly();
void drowbox(int,int,int,int);
void delay(unsigned int);
void drowlineH(int,int,int,int);
void gotoxy(int,int);
void MSGinM(char*,int);
void blinking_msg(char*,int);
int MainMenu(void);
void createdby(void);
struct record
{
    char Name[70];
    int day;
    int month;
    int year;
    int Score;
}gdata;
struct coordinate
{
    int x;
    int y;
    int direction;
};
struct set
{
    int speed;
}gset;
struct media
{
    char Recycle[70];
    char Notify[70];
    char Logoff_Sound[70];
    char Logon_Sound[70];
    char Menu_Command[70];
    char Error[70];
    char Navigation_Start[70];
};
struct media gmedia={"a:\\Windows\\Media\\Windows Recycle.wav",
                    "a:\\Windows\\Media\\notify.wav",
                    "a:\\Windows\\Media\\Windows Logoff Sound.wav",
                    "a:\\Windows\\Media\\Windows Logon Sound.wav",
                    "a:\\Windows\\Media\\Windows Menu Command.wav",
                    "a:\\Windows\\Media\\Windows Error.wav",
                    "a:\\Windows\\Media\\Windows Navigation Start.wav"};
typedef struct coordinate coordinate;

coordinate head, bend[700],food,body[700];


void media_path()
{
    char ch;
    detect_drive(&ch);
    gmedia.Recycle[0]=ch;
    gmedia.Notify[0]=ch;
    gmedia.Logoff_Sound[0]=ch;
    gmedia.Logon_Sound[0]=ch;
    gmedia.Menu_Command[0]=ch;
    gmedia.Error[0]=ch;
    gmedia.Navigation_Start[0]=ch;
}
int detect_drive(char *ch)
{
    char a='a';
    FILE *fp;
    char path[]="a:\\Windows\\System32\\control.exe";
    while(a<='z')
    {
        fp=fopen(path,"r");
        if(fp!=NULL)
        {
            *ch=a;
            fclose(fp);
            return 1;
        }
        a++;
        path[0]=a;
    }
    return 0;
}
void Move()
{
    int a,i,k;
    restart:
    setcolor(3);
    do{

        Food();
        fflush(stdin);
        len=0;
        for(i=0;i<700;i++)
        {
            body[i].x=0;
            body[i].y=0;
            if(i==length)
            break;
        }

        delay(gset.speed); //start Border
        setcolor(12);
        system("cls");
        setcolor(4);
        GotoXY(food.x,food.y);   /*displaying food*/
        printf("%c",271);
        setcolor(12);
        gotoxy(1,2);
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
        gotoxy(1,24);
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
        gotoxy(1,3);
        printf("%c",219);
        gotoxy(1,4);
        printf("%c",219);
        gotoxy(1,5);
        printf("%c",219);
        gotoxy(1,6);
        printf("%c",219);
        gotoxy(1,7);
        printf("%c",219);
        gotoxy(1,8);
        printf("%c",219);
        gotoxy(1,9);
        printf("%c",219);
        gotoxy(1,10);
        printf("%c",219);
        gotoxy(1,11);
        printf("%c",219);
        gotoxy(1,12);
        printf("%c",219);
        gotoxy(1,13);
        printf("%c",219);
        gotoxy(1,14);
        printf("%c",219);
        gotoxy(1,15);
        printf("%c",219);
        gotoxy(1,16);
        printf("%c",219);
        gotoxy(1,17);
        printf("%c",219);
        gotoxy(1,18);
        printf("%c",219);
        gotoxy(1,19);
        printf("%c",219);
        gotoxy(1,20);
        printf("%c",219);
        gotoxy(1,21);
        printf("%c",219);
        gotoxy(1,22);
        printf("%c",219);
        gotoxy(1,23);
        printf("%c",219);
            gotoxy(78,3);
        printf("%c",219);
        gotoxy(78,4);
        printf("%c",219);
        gotoxy(78,5);
        printf("%c",219);
        gotoxy(78,6);
        printf("%c",219);
        gotoxy(78,7);
        printf("%c",219);
        gotoxy(78,8);
        printf("%c",219);
        gotoxy(78,9);
        printf("%c",219);
        gotoxy(78,10);
        printf("%c",219);
        gotoxy(78,11);
        printf("%c",219);
        gotoxy(78,12);
        printf("%c",219);
        gotoxy(78,13);
        printf("%c",219);
        gotoxy(78,14);
        printf("%c",219);
        gotoxy(78,15);
        printf("%c",219);
        gotoxy(78,16);
        printf("%c",219);
        gotoxy(78,17);
        printf("%c",219);
        gotoxy(78,18);
        printf("%c",219);
        gotoxy(78,19);
        printf("%c",219);
        gotoxy(78,20);
        printf("%c",219);
        gotoxy(78,21);
        printf("%c",219);
        gotoxy(78,22);
        printf("%c",219);
        gotoxy(78,23);
        printf("%c",219);
        GotoXY(12,1);
        printf("SCORE : %d",(length-3));
        GotoXY(60,1);
        printf("Life : %d",life);
        setcolor(3);                    //End start Border

        if(head.direction==RIGHT)

            Right();

        else if(head.direction==LEFT)

            Left();

        else if(head.direction==DOWN)

            Down();

        else if(head.direction==UP)

            Up();

        k=ExitGame();
        if(k==402)
        {
            return 1;
        }

    }while(!kbhit());

    a=getch();

    if(a==27)

    {

        system("cls");

        exit(0);

    }
    fflush(stdin);
    key=getch();

    if((key==RIGHT&&head.direction!=LEFT&&head.direction!=RIGHT)||(key==LEFT&&head.direction!=RIGHT&&head.direction!=LEFT)||(key==UP&&head.direction!=DOWN&&head.direction!=UP)||(key==DOWN&&head.direction!=UP&&head.direction!=DOWN))
    {
        bend_no++;
        bend[bend_no]=head;
        head.direction=key;
        if(key==UP)

            head.y--;

        if(key==DOWN)

            head.y++;

        if(key==RIGHT)

            head.x++;

        if(key==LEFT)

            head.x--;

        Move();
        //goto restart;
    }
    else if(key==27)
    {
        system("cls");
        exit(0);
    }
    else
    {
        printf("\a");
        Move();
        //goto restart;
    }
}
void GotoXY(int x, int y)
{
    HANDLE a;
    COORD b;
    fflush(stdout);
    b.X = x;
    b.Y = y;
    a = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(a,b);
 }
void adjustWindowSize(int left,int top,int x,int y)
{
    struct SMALL_RECT test;

    HANDLE hStdout;
    COORD coord;
    BOOL ok;

    hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

    coord.X = x;      //width 112 full size with same buffer size  or (111 width & 42 height with large buffer size;
    coord.Y = y;       //hieght 43
    //ok = SetConsoleScreenBufferSize(hStdout, coord);

    test.Left = left;	//0
    test.Top = top;		//0
    test.Right = coord.X-1;
    test.Bottom = coord.Y-1;

    SetConsoleWindowInfo(hStdout, ok, &test);

}
void buffer_size(int x,int y)
{
    HANDLE wHnd;    // Handle to write to the console.
    wHnd=GetStdHandle(STD_OUTPUT_HANDLE);
    COORD bufferSize;
    bufferSize.X=x;
    bufferSize.Y=y;
    SetConsoleScreenBufferSize(wHnd, bufferSize);
}
void load()
{
    int r,j,i;
    register int loading;
    float count=0;
    drowbox(25,60,8,16);
    setcolor(7);
    create_load_shadow();
    setcolor(12);
    gotoxy(38,12);
    printf("HARVINDAR SINGH");
    gotoxy(39,10);
    printf("Loading...");
    setcolor(3);
    fflush(stdin);
    srand(count);
    i=70;
    for(r=1;r<=30;r++)
    {
        loading=rand()%i+30;
        for(j=0;j<7;j++);
        delay(loading);
        GotoXY(41,14);
        printf("%1.f%c",count,37);
        count=count+(float)3.45;
        gotoxy(27+r,12);
        printf("%c",219);
    }
    setcolor(12);
    getch();
    system("cls");
}
void create_load_shadow()
{
    drowlineH(26,61,17,219);
    drowlineV(9,17,61,219);
}
void Down()
{
    int i;
    for(i=0;i<=(head.y-bend[bend_no].y)&&len<length;i++)
    {
        GotoXY(head.x,head.y-i);
        {
            if(len==0)
                printf("%c",287);
            else
                printf("%c",260);
        }
        body[len].x=head.x;
        body[len].y=head.y-i;
        len++;
    }
    Bend();
    if(!kbhit())
        head.y++;
}
void Delay(long double k)
{
    Score();
    long double i;
    for(i=0;i<=(10000000);i++);
}
int ExitGame()
{
    int i,check=0,m;
    for(i=4;i<length;i++)   //starts with 4 because it needs minimum 4 element to touch its own body
    {
        if(body[0].x==body[i].x&&body[0].y==body[i].y)
        {
            check++;    //check's value increases as the coordinates of head is equal to any other body coordinate
        }
        if(i==length||check!=0)
            break;
    }
    if(head.x<=1||head.x>=78||head.y<=2||head.y>=24||check!=0)
    {
        life--;
        if(life>=0)
        {
            head.x=25;
            head.y=20;
            bend_no=0;
            head.direction=RIGHT;
            Move();
        }
        else
        {
            Clear_buffer();
            setcolor(12);
            system("cls");
            drowbox(20,65,7,17);
            setcolor(7);
            create_gameover_shadow();
            setcolor(9);
            MSGinM("  All lives completed",9);
            MSGinM("   Better Luck Next Time",11);
            MSGinM(" Press any key to Quit the Game",13);
            gdata.Score=(length-3);
            get_system_date(&gdata.day,&gdata.month,&gdata.year);
            m=add_new_record();
            if(m==404)
            {
                MSGinM("RECORD DOES NOT SAVED",19);
            }
            setcolor(12);
            blinking_msg("GAME OVER",15);
            return 402;
        }
    }
}
void create_gameover_shadow()
{
    drowlineV(8,18,66,219);
    drowlineH(22,66,18,219);
}
void get_system_date(int *day,int *month,int *year)
{
    SYSTEMTIME st;
    GetSystemTime(&st);
    *day=st.wDay;
    *month=st.wMonth;
    *year=st.wYear;
}
int input_string(char *a,int lenth,int x,int y)
{
    int i=0;
    for(i=0;i<lenth;i++)
    {
        abc:
        gotoxy(x,y);
        a[i]=getche();
        if(a[i]==-32)
        {
            a[i]=getche();
            gotoxy(x,y);
            printf("%c",256);
            goto abc;
        }
        if(a[i]==8)
        {
            if(i==0)
            {
                goto abc;
            }
            else
            {
            i--;
            x--;
            gotoxy(x,y);
            printf("%c",256);
            goto abc;
            }

        }
        if((a[i]>='a' && a[i]<='z') || (a[i]>='A' && a[i]<='Z'))
        {

        }
        else if(a[i]==32 && i!=0 && a[i-1]!=' ')
        {

        }
        else if(a[i]==13 && i>=5)
        {
            a[i]='\0';
            return 1;
        }
        else
        {
            gotoxy(x,y);
            printf("%c",256);
            goto abc;
        }
        x++;
    }
    a[i]='\0';
    return a;
}
void Food()
{
    if(head.x==food.x&&head.y==food.y)
    {
        length++;
        time_t a;
        a=time(0);
        srand(a);
        food.x=rand()%78;
        if(food.x<=1)
            food.x=2;
        food.y=rand()%24;
        if(food.y<=2)
            food.y=3;
        if(food.y>23)
            food.y=23;
        if(food.x>77)
            food.x=77;

    }
    else if(food.x==0)/*to create food for the first time coz global variable are initialized with 0*/
    {
        food.x=rand()%78;
        if(food.x<=1)
            food.x=2;
        food.y=rand()%24;
        if(food.y<=2)
            food.y=3;
        if(food.y>23)
            food.y=23;
        if(food.x>77)
            food.x=77;
    }
}
void Left()
{
    int i;
    for(i=0;i<=(bend[bend_no].x-head.x)&&len<length;i++)
    {
        GotoXY((head.x+i),head.y);
       {
                if(len==0)
                    printf("%c",273);
                else
                    printf("%c",260);
        }
        body[len].x=head.x+i;
        body[len].y=head.y;
        len++;
    }
    Bend();
    if(!kbhit())
        head.x--;

}
void Right()
{
    int i;
    for(i=0;i<=(head.x-bend[bend_no].x)&&len<length;i++)
    {
        //GotoXY((head.x-i),head.y);
        body[len].x=head.x-i;
        body[len].y=head.y;
        GotoXY(body[len].x,body[len].y);
        {
            if(len==0)
                printf("%c",272);
            else
                printf("%c",260);
        }
        /*body[len].x=head.x-i;
        body[len].y=head.y;*/
        len++;
    }
    Bend();
    if(!kbhit())
        head.x++;
}
void Bend()
{
    int i,j,diff;
    for(i=bend_no;i>=0&&len<length;i--)
    {
            if(bend[i].x==bend[i-1].x)
            {
                diff=bend[i].y-bend[i-1].y;
                if(diff<0)
                    for(j=1;j<=(-diff);j++)
                    {
                        body[len].x=bend[i].x;
                        body[len].y=bend[i].y+j;
                        GotoXY(body[len].x,body[len].y);
                        printf("%c",260);
                        len++;
                        if(len==length)
                            break;
                    }
                else if(diff>0)
                    for(j=1;j<=diff;j++)
                    {
                        /*GotoXY(bend[i].x,(bend[i].y-j));
                        printf("*");*/
                        body[len].x=bend[i].x;
                        body[len].y=bend[i].y-j;
                        GotoXY(body[len].x,body[len].y);
                        printf("%c",260);
                        len++;
                        if(len==length)
                            break;
                    }
            }
        else if(bend[i].y==bend[i-1].y)
        {
            diff=bend[i].x-bend[i-1].x;
            if(diff<0)
                for(j=1;j<=(-diff)&&len<length;j++)
                {
                    /*GotoXY((bend[i].x+j),bend[i].y);
                    printf("*");*/
                    body[len].x=bend[i].x+j;
                    body[len].y=bend[i].y;
                    GotoXY(body[len].x,body[len].y);
                        printf("%c",260);
                   len++;
                   if(len==length)
                           break;
               }
           else if(diff>0)
               for(j=1;j<=diff&&len<length;j++)
               {
                   /*GotoXY((bend[i].x-j),bend[i].y);
                   printf("*");*/
                   body[len].x=bend[i].x-j;
                   body[len].y=bend[i].y;
                   GotoXY(body[len].x,body[len].y);
                       printf("%c",260);
                   len++;
                   if(len==length)
                       break;
               }
       }
   }
}
void Boarder()
{


}
void Print()
{
    system("cls");
    MSGinM("GAME INSTRUCTIONS",1);
    drowbox(1,78,2,23);
    setcolor(3);
    GotoXY(3,4);
    printf("Use arrow keys to move the Snake [ ");
    setcolor(9);
    printf("%c",16);
    setcolor(20);
    printf(" %c",17);
    setcolor(5);
    printf(" %c",30);
    setcolor(13);
    printf(" %c",31);
    setcolor(3);
    printf(" ]");
    delay(40);
    GotoXY(3,6);
    printf("You will be provided foods at the several coordinates of the screen which");
    delay(40);
    GotoXY(3,8);
    printf("you have to eat.");
    delay(40);
    GotoXY(3,10);
    printf("Everytime you eat a food the length of the snake will be increased by 1");
    delay(40);
    GotoXY(3,12);
    printf("Element and thus the score.");
    delay(40);
    GotoXY(3,14);
    printf("Here you are provided with three lives.");
    delay(40);
    GotoXY(3,16);
    printf("Your life will decrease as you hit the wall or snake's body.");
    delay(40);
    GotoXY(3,18);
    printf("You can pause the game in its middle by pressing any key.");
    delay(40);
    GotoXY(3,20);
    printf("To continue the paused game press any other key once Again.");
    setcolor(12);
    getch();
}
int Score()
{
   int score;
   GotoXY(12,1);
   score=length-3;
   printf("SCORE : %d",(length-3));
   score=length-3;
   GotoXY(60,1);
   printf("Life : %d",life);
   return score;
}
int Scoreonly()
{
int score=Score();
system("cls");
return score;
}
void Up()
{
   int i;

   for(i=0;i<=(bend[bend_no].y-head.y)&&len<length;i++)
   {
       GotoXY(head.x,head.y+i);
       {
           if(len==0)
               printf("%c",286);
           else
               printf("%c",260);
       }
       body[len].x=head.x;
       body[len].y=head.y+i;
       len++;
   }
   Bend();
   if(!kbhit())
       head.y--;
}
void drowbox(int x,int x1,int y,int y1)
{
    int i;
    for(i=x;i<=x1;i++)
    {
        gotoxy(i,y);
        printf("%c",219);
        gotoxy(i,y1);
        printf("%c",219);
    }
    for(i=y;i<=y1;i++)
    {
        gotoxy(x,i);
        printf("%c",219);
        gotoxy(x1,i);
        printf("%c",219);
    }
}
int drow_search_box(char *p,int pos,int y,int y1)
{
    int i,j=6;
    j=j+strlen(p);
    for(i=1;i<=78;i++)
    {
        gotoxy(i,y);
        printf("%c",219);
        gotoxy(i,y1);
        printf("%c",219);
    }
    for(i=y;i<=y1;i++)
    {
        gotoxy(1,i);
        printf("%c",219);
        gotoxy(78,i);
        printf("%c",219);
        gotoxy(j,i);
        printf("%c",219);
    }
    gotoxy(3,pos);
    printf("%s",p);
    gotoxy(j+2,pos);
    return j+2;
}
void delay(unsigned int msecond)
{
    clock_t goal=msecond+clock();
    while(goal>clock());
}
void drowlineH(int x,int x1,int y,int type)
{
    int i;
    for(i=x;i<=x1;i++)
    {
        gotoxy(i,y);
        printf("%c",type);
    }
}
void gotoxy(int x,int y)
{

    COORD c;
    c.X=x;
    c.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
void MSGinM(char *a,int y)
{
    gotoxy(42-(strlen(a)/2),y);
    printf("%s",a);
}
void blinking_msg(char *a,int y)
{
    int i,x;
    char b[230];
    for(i=0;i<strlen(a);i++)
        b[i]=32;
    b[i]='\0';
    x=(44-(strlen(a)/2));
    fflush(stdin);
    while(!kbhit())
    {
        if(!kbhit())
        {
            gotoxy(x,y);
            printf("%s",a);
        }
        if(!kbhit())
            delay(500);
            gotoxy(x,y);
            printf("%s",b);
        if(!kbhit())
            delay(500);
    }
    fflush(stdin);
}
void setcolor(int ForgC)
{
    WORD wColor;
    HANDLE hStdOut=GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if(GetConsoleScreenBufferInfo(hStdOut,&csbi))
    {
    wColor=(csbi.wAttributes & 0xF0)+(ForgC & 0x0F);
    // SetConsoleTextAttributes(hStdOut,wColor);
    SetConsoleTextAttribute(hStdOut,wColor);
    }
}
void create_shadow()
{
    drowlineV(7,19,66,219);
    drowlineH(22,66,19,219);
}
int MainMenu()
{
    int x,y,i;
    char ch;
    reset:
    setcolor(9);
    system("cls");
    drowbox(20,65,6,18);
    setcolor(7);
    create_shadow();
    gotoxy(33,8);
    setcolor('c');
    printf("Play Game");
    gotoxy(33,10);
    printf("Game Instructions");
    gotoxy(33,12);
    printf("View Your Previous Record");
    gotoxy(33,14);
    printf("Setting");
    gotoxy(33,16);
    printf("Exit");
    x=28;
    y=8;
    chack_setting();
    restart:
        while(!kbhit())
        {
            gotoxy(x,y);
            printf("%c",16);
            delay(60);
            gotoxy(x,y);
            printf("%c",256);
            delay(60);
        }
        //printf("%c",16);
        gotoxy(67,16);
        ch=getche();
        gotoxy(67,16);
        printf("%c",256);
        if(ch==-32)
        {
            ch=getche();
            if(ch==UP || ch==DOWN)
            {
                switch(ch)
                {
                case UP:
                    if(y>8 && y<=16)
                    {
                        gotoxy(x,y);
                        printf("%c",256);
                        y=y-2;
                    }
                    goto restart;
                    break;
                case DOWN:
                    if(y>=8 && y<16)
                    {
                        gotoxy(x,y);
                        printf("%c",256);
                        y=y+2;
                    }
                    goto restart;
                    break;
                }
            }
            else
            {
                goto restart;
            }
        }
        else if(ch==13)
        {
            setcolor(12);
            switch(y)
            {
            case 8:
                system("cls");
                i=drow_search_box("Your Name",12,10,14);
                setcolor(7);
                drow_player_shadow();
                setcolor(3);
                input_string(gdata.Name,58,i,12);
                setcolor(12);
                fflush(stdin);
                system("cls");
                load();
                bend_no=0;
                length=3;
                head.x=25;
                head.y=20;
                head.direction=RIGHT;
                Boarder();
                Food(); //to generate food coordinates initially
                life=3; //number of extra lives
                bend[0]=head;
                Move();
                Clear_buffer();
                goto reset;
                break;
            case 10:
                system("cls");
                Print();
                Clear_buffer();
                goto reset;
                break;
            case 12:
                system("cls");
                adjustWindowSize(0,0,80,26);
                buffer_size(80,300);
                view_User_record();
                adjustWindowSize(0,0,80,26);
                buffer_size(80,26);
                Clear_buffer();
                goto reset;
                break;
            case 14:
                system("cls");
                setting();
                Clear_buffer();
                goto reset;
                break;
            case 16:
                exit(0);
                break;
            }
        }
        else
        {
            goto restart;
        }

}
void drow_player_shadow()
{
    drowlineH(2,78,15,219);
    drowlineV(11,15,79,219);
}
void chack_setting()
{
    FILE *fp;
    fp=fopen("setting.dat","rb");
    if(fp==NULL)
    {
        gset.speed=170;
    }
    else
    {
        fread(&gset,sizeof(struct set),1,fp);
        if(gset.speed>=40 && gset.speed<=200)
        {

        }
        else
        {
            gset.speed=170;
        }
    }
    fclose(fp);
}
void create_setting_shadow()
{
    drowlineV(11,15,69,219);
    drowlineH(23,69,15,219);
}
int setting()
{
    int i,j,x,x1;
    char ch;
    FILE *fp;
    fp=fopen("setting.dat","rb");
    if(fp==NULL)
    {
        gset.speed=170;
    }
    else
    {
        fread(&gset,sizeof(struct set),1,fp);
        if(gset.speed>=40 && gset.speed<=200)
        {

        }
        else
        {
            gset.speed=100;
        }
    }
    fclose(fp);
    drowbox(22,68,10,14);
    setcolor(7);
    create_setting_shadow();
    setcolor(12);
    gotoxy(24,12);
    printf("Snake Speed");
    gotoxy(44,12);
    printf("%c",17);
    gotoxy(64,12);
    printf("%c",16);
    x1=x=46;
    for(j=200;j>=40;j=j-10)
    {
        gotoxy(x1,12);
        if(j>=gset.speed)
            printf("%c",221);
        else
            printf("-");
        x1++;
    }
    for(j=200;j>=gset.speed;j-=10)
        x++;
    x--;
    i=gset.speed;
    setcolor(3);
    restart:
        gotoxy(2,2);
        ch=getche();
        gotoxy(2,2);
        printf("%c",256);
        if(ch==-32)
        {
            ch=getche();
            if(ch==75 || ch==77)
            {
                switch(ch)
                {
                    case LEFT:
                        setcolor(9);
                        gotoxy(44,12);
                        printf("%c",17);
                        setcolor(12);
                        gotoxy(64,12);
                        printf("%c",16);
                        setcolor(3);
                        if(x>46 && x<=62)
                        {
                            gotoxy(x,12);
                            printf("-");
                            i=i+10;
                            x--;
                        }
                        goto restart;
                        break;
                    case RIGHT:
                        setcolor(9);
                        gotoxy(64,12);
                        printf("%c",16);
                        setcolor(12);
                        gotoxy(44,12);
                        printf("%c",17);
                        setcolor(3);
                        if(x>=46 && x<62)
                        {
                            if(i>gset.speed)
                                setcolor(12);
                            else
                                setcolor(3);
                            x++;
                            gotoxy(x,12);
                            printf("%c",221);
                            i=i-10;
                        }
                        goto restart;
                        break;
                }
            }
            else
            {
               goto restart;
            }
        }
        else if(ch==13)
        {
            setcolor(12);
            gset.speed=i;
            fp=fopen("setting.dat","wb");
            fwrite(&gset,sizeof(struct set),1,fp);
        }
        else
        {
            goto restart;
        }
}
void Clear_buffer()
{
    while(kbhit())
    {
        getche();
    }
}
void createdby()
{
    int i;
    int li;
    char a[]="BRIGHTGOAL.IN";
    char a1[]="      MINI SNAKE GAME";
    char a2[]="CREATED BY HARVINDAR SINGH";
    system("COLOR FC");
    for(i=27;i<=56;i++)
    {
        gotoxy(i,9);
        printf("%c",219);
        for(li=0;li<=1000000;li++);
    }

    for(i=9;i<=15;i++)
    {
        gotoxy(56,i);
        printf("%c",219);
        for(li=0;li<=1000000;li++);
    }
    for(i=56;i>=27;i--)  //56,27
    {
        gotoxy(i,15);
        printf("%c",219);
        for(li=0;li<=1000000;li++);
    }
    for(i=15;i>=9;i--) //15,9
    {
        gotoxy(27,i);
        printf("%c",219);
        for(li=0;li<=1000000;li++);
    }
    for(i=8;i>=7;i--)
    {
        gotoxy(30,i);
        printf("%c",219);
        for(li=0;li<=10000000;li++);
    }
    for(i=30;i>=23;i--) //23,30
    {
        gotoxy(i,6);
        printf("%c",220);
        for(li=0;li<=10000000;li++);

    }
    for(i=7;i<=11;i++)  //7,11
    {
        gotoxy(23,i);
        printf("%c",219);
        for(li=0;li<=10000000;li++);
    }
    for(i=24;i<=26;i++)     //23,26
    {
        gotoxy(i,11);
        printf("%c",220);
        for(li=0;li<=10000000;li++);
    }
    gotoxy(32,7);
    setcolor(9);
    for(i=0;a[i]!='\0';i++)
    {
        printf("%c",a[i]);
        for(li=0;li<=10000000;li++);
    }
    gotoxy(29,11);
    for(i=0;a1[i]!='\0';i++)
    {
        printf("%c",a1[i]);
        for(li=0;li<=10000000;li++);
    }
    gotoxy(29,13);
    for(i=0;a2[i]!='\0';i++)
    {
        printf("%c",a2[i]);
        for(li=0;li<=10000000;li++);
    }
    PlaySound(TEXT("C:\\Windows\\Media\\Speech On.wav"),NULL,SND_SYNC);
    gotoxy(32,7);
    for(i=0;a[i]!='\0';i++)
    {
        printf("%c",256);
        for(li=0;li<=10000000;li++);
    }
    gotoxy(29,11);
    for(i=0;a1[i]!='\0';i++)
    {
        printf("%c",256);
        for(li=0;li<=10000000;li++);
    }
    gotoxy(29,13);
    for(i=0;a2[i]!='\0';i++)
    {
        printf("%c",256);
        for(li=0;li<=10000000;li++);
    }
    for(i=27;i<=56;i++)  //erase............................................
    {
        gotoxy(i,9);
        printf("%c",256);
        for(li=0;li<=1000000;li++);
    }
    for(i=9;i<=15;i++)
    {
        gotoxy(56,i);
        printf("%c",256);
        for(li=0;li<=1000000;li++);
    }
    for(i=56;i>=27;i--)  //56,27
    {
        gotoxy(i,15);
        printf("%c",256);
        for(li=0;li<=1000000;li++);
    }
    for(i=15;i>=9;i--) //15,9
    {
        gotoxy(27,i);
        printf("%c",256);
        for(li=0;li<=1000000;li++);
    }
    for(i=8;i>=7;i--)
    {
        gotoxy(30,i);
        printf("%c",256);
        for(li=0;li<=10000000;li++);
    }
    for(i=30;i>=23;i--) //23,30
    {
        gotoxy(i,6);
        printf("%c",256);
        for(li=0;li<=10000000;li++);

    }
    for(i=7;i<=11;i++)  //7,11
    {
        gotoxy(23,i);
        printf("%c",256);
        for(li=0;li<=10000000;li++);
    }
    for(i=24;i<=26;i++)     //23,26
    {
        gotoxy(i,11);
        printf("%c",256);
        for(li=0;li<=10000000;li++);
    }
    Clear_buffer();
}
void drow_view_record()
{
    drowlineH(2,79,15,219);
    drowlineV(11,15,79,219);
}
void view_User_record()
{
    char name[70];
    struct record view;
    FILE *fp;
    int i,flag=0,j,k,count=0;
    i=drow_search_box("Your Name: ",12,10,14);
    setcolor(7);
    drow_view_record();
    setcolor(3);
    input_string(name,58,i,12);
    setcolor(12);
    fp=fopen("record.dat","rb");
    if(fp==NULL)
    {
       MSGinM("Record List Empty",16);
       getch();
       return 404;
    }
    system("cls");
    drowlineH(1,78,1,223);
    drowlineH(1,78,3,220);
    drowlineV(1,3,1,219);
    drowlineV(1,3,78,219);
    gotoxy(42-(strlen(name)/2),2);//36
    for(i=0;i<strlen(name);i++)
    {
        if(name[i]>='a' && name[i]<='z')
        {
            printf("%c",name[i]-32);
        }
        else
        {
            printf("%c",name[i]);
        }
    }
    j=5;
    k=5;
    while(fread(&view,sizeof(struct record),1,fp)>0)
    {
        if(match_two_string(name,view.Name))
        {
            flag=1;
            count++;
            for(i=1;i<=78;i++)
            {
                gotoxy(i,k-1);
                printf("%c",220);
                gotoxy(i,k+5);
                printf("%c",220);
            }
            for(i=k;i<=k+5;i++)
            {
                gotoxy(1,i);
                printf("%c",219);
                gotoxy(78,i);
                printf("%c",219);
            }
            setcolor(3);
            gotoxy(3,k);
            printf("Name  : %s",view.Name);
            gotoxy(3,k+2);
            printf("Date  : %d/%d/%d",view.day,view.month,view.year);
            gotoxy(3,k+4);
            printf("Score : %d",view.Score);
            setcolor(12);
            k=k+7;
            j=j+7;
            if(k==292)
            {
                if(list_choise("CONTINUE","BACK TO HOME",296))
                {
                    system("cls");
                    for(i=1;i<=78;i++)
                    {
                        gotoxy(i,1);
                        printf("%c",220);
                        gotoxy(i,4);
                        printf("%c",220);
                    }
                    for(i=2;i<5;i++)
                    {
                        gotoxy(1,i);
                        printf("%c",219);
                        gotoxy(78,i);
                        printf("%c",219);
                    }
                    gotoxy(42-(strlen(name)/2),3);//36
                    for(i=0;i<strlen(name);i++)
                    {
                        if(name[i]>='a' && name[i]<='z')
                        {
                            printf("%c",name[i]-32);
                        }
                        else
                        {
                            printf("%c",name[i]);
                        }
                    }
                    j=5;
                    k=5;
                }
                else
                {
                    fclose(fp);
                    return 0;
                }

            }
        }
    }
    if(flag==0)
    {
        MSGinM("RECORD DOES NOT FOUND",16);
        getche();
        return 0;
    }
    setcolor(12);
    getch();
}
void drowlineV(int y,int y1,int x,int type)
{
    int i;
    for(i=y;i<=y1;i++)
    {
        gotoxy(x,i);
        printf("%c",type);
    }
}
int add_new_record()
{
    FILE *fp;
    fp=fopen("record.dat","ab");
    if(fp==NULL)
    {
        fclose(fp);
        return 404;
    }
    fwrite(&gdata,sizeof(struct record),1,fp);
    fclose(fp);
}
int list_choise(char *msg1,char *msg2,int y)
{
    char ch;
    int x;
    x=7;  //56,7
    rechoise:
    gotoxy(13,y);
    printf("%s",msg1); //CONTINUE
    gotoxy(60,y);
    printf("%s",msg2);   //BACK TO HOME
    drowlineH(x,x+19,y-1,220);
    drowlineH(x,x+19,y+1,223);
    drowlineV(y,y,x,219);
    drowlineV(y,y,x+19,219);
    gotoxy(35,y);
    ch=getche();
    gotoxy(35,y);
    printf("%c",256);
    if(ch==-32)
    {
        ch=getche();
        if(ch==75 || ch==77)
        {
            switch(ch)
            {
            case 75:
                if(x==56)
                {
                    drowlineH(7,75,y-1,256);
                    drowlineH(7,75,y,256);
                    drowlineH(7,75,y+1,256);
                    x=7;
                }
                goto rechoise;
                break;
            case 77:
                if(x==7)
                {
                    drowlineH(7,75,y-1,256);
                    drowlineH(7,75,y,256);
                    drowlineH(7,75,y+1,256);
                    x=56;
                }
                goto rechoise;
                break;
            }
        }
        else
        {
            goto rechoise;
        }
    }
    else if(ch==13)
    {
        switch(x)
        {
        case 7:
            return 1;
            break;
        case 56:
            return 0;
            break;
        }
    }
    else
    {
        goto rechoise;
    }
}
int match_two_string(char *a,char *b)
{
    char a1[65];
    char b1[65];
    int i,j,m1,m2,m3,m4;
    for(i=0;a[i]!='\0';i++)
    {
        if(a[i]>='a' && a[i]<='z')
            a1[i]=a[i]-32;
        else
            a1[i]=a[i];
    }
    a1[i]='\0';
    for(j=0;b[j]!='\0';j++)
    {
        if(b[j]>='a' && b[j]<='z')
            b1[j]=b[j]-32;
        else
            b1[j]=b[j];
    }
    b1[j]='\0';
    m1=m2=m3=m4=0;
    for(i=0;a1[i]!='\0';i++)
    {
        m1++;
        if(a1[i]==b1[i])
            m2++;
    }
    for(j=0;b1[j]!='\0';j++)
    {
        m3++;
        if(a1[j]==b1[j])
            m4++;
    }
    if(m1==m2 && m3==m4)
        return 1;
    else
        return 0;
}
int Hide_cursor()
{
	 //Get a console handle
	 HANDLE myconsole = GetStdHandle(STD_OUTPUT_HANDLE);
	/* It is already defined.
	 struct CONSOLE_CURSOR_INFO
	 {
	  DWORD dwSize;
	  BOOL bVisible;
	 };
	*/
	 //CONSOLE_CURSOR_INFO is defined type.
	 CONSOLE_CURSOR_INFO CURSOR;
	 BOOL result;
	 CURSOR.dwSize = 1;
	 CURSOR.bVisible = FALSE;
	 result=SetConsoleCursorInfo(myconsole, &CURSOR);//second argument need pointer
	 if(result){//success
	   return 1;
	 }
	 return 0;
}
int main()
{
    Hide_cursor();
    SetConsoleTitleA("SNAKE GAME POWERED BY Brightgoal.in");
    adjustWindowSize(0,0,80,26);
    buffer_size(80,26);
    system("COLOR FC");
    createdby();
    chack_setting();
    MainMenu();
    return 0;
}
