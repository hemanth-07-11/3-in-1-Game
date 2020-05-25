
#include<graphics.h>
#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<iostream.h>
#include<process.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>

#define true  1
#define false 0
void drawLine(int n, char symbol);  //for casino
void rules();

void country();
void state();
void cricket();


void ticintro();
void  *buf;            /*for micky mouse*/
void firstleft();
void secondleft();



					  //for hangman
  const int MAXLENGTH=80;
const int MAX_TRIES=6;
const int MAXROW=7;

int letterFill (char, char[], char[]);
void initUnknown (char[], char[]);
void intro();

void disp();
void printmenu();
void intro();
void levelmenu();void easy();
void initial(int x);
void draw(int x, int y, int i);
void userwin(int no);int check(int key);
int load,i,step,level,num[25],win;


char square[10] = {'0','1','2','3','4','5','6','7','8','9'};
void hangman();
void casino();
void micky();
void tictactoe();
void end();


//FOR MOUSE SETTINGS
  union REGS in,out;

       int callmouse()
       {
	      in.x.ax=1;
	      int86(51,&in,&out);
	      return 1;
       }
       void mouseposi(int &xpos,int &ypos,int &click)
       {
	      in.x.ax=3;
	      int86(51,&in,&out);
	      click=out.x.bx;
	      xpos=out.x.cx;
	      ypos=out.x.dx;
       }
       int mousehide()
       {
	      in.x.ax=2;
	      int86(51,&in,&out);
	      return 1;
       }
       void setposi(int &xpos,int &ypos)
       {
	     in.x.ax=4;
	     in.x.cx=xpos;
	     in.x.dx=ypos;
	     int86(51,&in,&out);
       }
		     //-------------------//

void start()
{
 int x,y,cl,a,b;
int gd=DETECT,gm;
initgraph(&gd,&gm,"c://tc//bgi");

setcolor(13);
bar3d(100,70,530,150,10,20);
settextstyle(DEFAULT_FONT,HORIZ_DIR,6);
outtextxy(190,90,"GAMES");

bar3d(200,190,400,230,10,20);
setcolor(12);
settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
outtextxy(240,200,"HANGMAN");

setcolor(12);
bar3d(200,250,400,290,10,20);
setcolor(12);
settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
outtextxy(240,260,"GAMBLING");

setcolor(5);
bar3d(200,310,400,350,10,20);
setcolor(12);
settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
outtextxy(220,322,"TIC-TAC-TOE");

setcolor(5);
bar3d(140,380,470,440,10,20);
setcolor(BLUE);
settextstyle(DEFAULT_FONT,HORIZ_DIR,5);
outtextxy(220,400,"EXIT");



 a=100;
 b=400;
 setposi(a,b);
 callmouse();
	     do
	     {
		    mouseposi(x,y,cl);
		    gotoxy(10,9);
		    if(cl==1 && x>=200 && x<=400 && y>=190 && y<=230)
		    {
		    cleardevice();
		    hangman();
		    break;
		    }
		    else if(cl==1 && x>=200 && x<=400 && y>=250 && y<=290)
		    {
		    cleardevice();
		    casino();
		    break;
		    }
		    else if(cl==1 && x>=200 && x<=400 && y>=310 &&y<=350)
		    {
		    cleardevice();
		    tictactoe();
		    break;
		    }
		    else if(cl==1 && x>=140 && x<=470  && y>=380 &&y<=440)
		    {
		    cleardevice();
		    exit(0);
		    // end();
		    break;
		    }
	     } while( !kbhit() );

}




void hangman()
{
micky();
cleardevice();




int x,y,cl,a,b;
int gd=DETECT,gm;
initgraph(&gd,&gm,"c://tc//bgi");

setcolor(1);
bar3d(100,70,530,150,10,20);
settextstyle(DEFAULT_FONT,HORIZ_DIR,6);
outtextxy(140,90,"HANGMAN");

bar3d(200,190,400,230,10,20);
setcolor(6);
settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
outtextxy(240,200,"COUNTRY");

setcolor(5);
bar3d(200,250,400,290,10,20);
setcolor(6);
settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
outtextxy(230,260,"CRICKETER");

setcolor(5);
bar3d(200,310,400,350,10,20);
setcolor(6);
settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
outtextxy(200,322,"STATE CAPITAL ");

setcolor(5);
bar3d(140,380,470,440,10,20);
setcolor(RED);
settextstyle(DEFAULT_FONT,HORIZ_DIR,5);
outtextxy(220,400,"EXIT");



 a=100;
 b=400;
 setposi(a,b);
 callmouse();
	     do
	     {
		    mouseposi(x,y,cl);
		    gotoxy(10,9);
		    if(cl==1 && x>=200 && x<=400 && y>=190 && y<=230)
		    {
		    cleardevice();
		    country();
		    break;
		    }
		    else if(cl==1 && x>=200 && x<=400 && y>=250 && y<=290)
		    {
		    cleardevice();
		    cricket();
		    break;
		    }
		    else if(cl==1 && x>=200 && x<=400 && y>=310 &&y<=350)
		    {
		    cleardevice();
		    state();
		    break;
		    }
		    else if(cl==1 && x>=140 && x<=470  && y>=380 &&y<=440)
		    {
		    cleardevice();
		    end();
		    break;
		    }
	     } while( !kbhit() );


}

void cricket()
{
intro();
	char unknown [MAXLENGTH];
	char letter;
	int num_of_wrong_guesses=0;
	char word[MAXLENGTH];
	char words[][MAXLENGTH] =
	{
		"kohli",
		"raina",
		"dhoni",
		"bhuvi",
		"chahal",
		"jadeja",
		"rohit",
		"rahane",
		"pandya",
		"ashwin"
	};

	//choose and copy a word from array of words randomly
	randomize();
	int n=random(10);
	strcpy(word,words[n]);

	// Initialize the secret word with the * character.
	initUnknown(word, unknown);

	// welcome the user
	cout << "\n\nWelcome to hangman...Guess a cricketer's Name";
	cout << "\n\nEach letter is represented by a star.";
	cout << "\n\nYou have to type only one letter in one try";
	cout << "\n\nYou have " << MAX_TRIES << " tries to try and guess the word.";
	cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";

	// Loop until the guesses are used up
	while (num_of_wrong_guesses < MAX_TRIES)
	{
		cout << "\n\n" << unknown;
		cout << "\n\nGuess a letter: ";
		cin >> letter;
		// Fill secret word with letter if the guess is correct,
		// otherwise increment the number of wrong guesses.
		if (letterFill(letter, word, unknown)==0)
		{
			cout << endl << "Whoops! That letter isn't in there!" << endl;
			num_of_wrong_guesses++;
		}
		else
		{
			cout << endl << "You found a letter! Isn't that exciting!" << endl;
		}
		// Tell user how many guesses is left.
		cout << "You have " << MAX_TRIES - num_of_wrong_guesses;
		cout << " guesses left." << endl;
		// Check if they guessed the word.
		if (strcmp(word, unknown) == 0)
		{
			cout << word << endl;
			cout << "Yeah! You got it!";
			delay(2000);
			break;
		}
	}
	if(num_of_wrong_guesses == MAX_TRIES)
	{
		cout << "\nSorry, you lose...you've been hanged." << endl;
		cout << "The word was : " << word << endl;
		delay(2000);
	}

}

void state()
{
  intro();

	char unknown [MAXLENGTH];
	char letter;
	int num_of_wrong_guesses=0;
	char word[MAXLENGTH];
	char words[][MAXLENGTH] =
	{
		"mumbai",
		"bengaluru",
		"chennai",
		"hyderabad",
		"vizag",
		"patna",
		"shimla",
		"chandigarh",
		"dispur",
		"agartala"
	};

	//choose and copy a word from array of words randomly
	randomize();
	int n=random(10);
	strcpy(word,words[n]);

	// Initialize the secret word with the * character.
	initUnknown(word, unknown);

	// welcome the user
	cout << "\n\nWelcome to hangman...Guess a State capital's Name";
	cout << "\n\nEach letter is represented by a star.";
	cout << "\n\nYou have to type only one letter in one try";
	cout << "\n\nYou have " << MAX_TRIES << " tries to try and guess the word.";
	cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";

	// Loop until the guesses are used up
	while (num_of_wrong_guesses < MAX_TRIES)
	{
		cout << "\n\n" << unknown;
		cout << "\n\nGuess a letter: ";
		cin >> letter;
		// Fill secret word with letter if the guess is correct,
		// otherwise increment the number of wrong guesses.
		if (letterFill(letter, word, unknown)==0)
		{
			cout << endl << "Whoops! That letter isn't in there!" << endl;
			num_of_wrong_guesses++;
		}
		else
		{
			cout << endl << "You found a letter! Isn't that exciting!" << endl;
		}
		// Tell user how many guesses is left.
		cout << "You have " << MAX_TRIES - num_of_wrong_guesses;
		cout << " guesses left." << endl;
		// Check if they guessed the word.
		if (strcmp(word, unknown) == 0)
		{
			cout << word << endl;
			cout << "Yeah! You got it!";
			delay(2000);
			break;
		}
	}
	if(num_of_wrong_guesses == MAX_TRIES)
	{
		cout << "\nSorry, you lose...you've been hanged." << endl;
		cout << "The word was : " << word << endl;
		delay(2000);
	}
}

void country()
{
intro();
	char unknown [MAXLENGTH];
	char letter;
	int num_of_wrong_guesses=0;
	char word[MAXLENGTH];
	char words[][MAXLENGTH] =
	{
		"india",
		"pakistan",
		"nepal",
		"malaysia",
		"philippines",
		"australia",
		"iran",
		"ethiopia",
		"oman",
		"indonesia"
	};

	//choose and copy a word from array of words randomly
	randomize();
	int n=random(10);
	strcpy(word,words[n]);

	// Initialize the secret word with the * character.
	initUnknown(word, unknown);

	// welcome the user
	cout << "\n\nWelcome to hangman...Guess a country Name";
	cout << "\n\nEach letter is represented by a star.";
	cout << "\n\nYou have to type only one letter in one try";
	cout << "\n\nYou have " << MAX_TRIES << " tries to try and guess the word.";
	cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";

	// Loop until the guesses are used up
	while (num_of_wrong_guesses < MAX_TRIES)
	{
		cout << "\n\n" << unknown;
		cout << "\n\nGuess a letter: ";
		cin >> letter;
		// Fill secret word with letter if the guess is correct,
		// otherwise increment the number of wrong guesses.
		if (letterFill(letter, word, unknown)==0)
		{
			cout << endl << "Whoops! That letter isn't in there!" << endl;
			num_of_wrong_guesses++;
		}
		else
		{
			cout << endl << "You found a letter! Isn't that exciting!" << endl;
		}
		// Tell user how many guesses is left.
		cout << "You have " << MAX_TRIES - num_of_wrong_guesses;
		cout << " guesses left." << endl;
		// Check if they guessed the word.
		if (strcmp(word, unknown) == 0)
		{
			cout << word << endl;
			cout << "Yeah! You got it!";
			delay(2000);
			break;
		}
	}
	if(num_of_wrong_guesses == MAX_TRIES)
	{
		cout << "\nSorry, you lose...you've been hanged." << endl;
		cout << "The word was : " << word << endl;
		delay(2000);
	}


}
void intro()
{  int i,j;
   clrscr();
   cleardevice();
   setbkcolor(BLACK);
  // gotoxy (25,12);
   settextstyle(4,0,13);
   for(i=0;i<=10;i++)
   {
   setcolor(i%16);

   outtextxy(50,60,"HANGMAN");
   settextstyle(1,0,13);

   outtextxy(0,110,"OUR GREATEST GLORY IS NOT IN NEVER FALLING...    ");
     outtextxy(20,130," BUT IN RISING UP EVERY TIME WE FALL");
     settextstyle(1,0,13);
   outtextxy(20,200,"");
   delay(50);
   outtextxy(180,200,"A");
   delay(50);
   outtextxy(220,200,"B");
   delay(50);
   outtextxy(260,200,"C");
   delay(50);
   outtextxy(300,200,"D");
   delay(50);
   outtextxy(180,300,"E");
   delay(50);
   outtextxy(220,300,"F");
   delay(50);
   outtextxy(260,300,"G");
   delay(50);
   outtextxy(300,300,"H");
   settextstyle(4,0,13);
   delay(50);

}
cleardevice();
}



/* Take a one character guess and the secret word, and fill in the
 unfinished guessword. Returns number of characters matched.
 Also, returns zero if the character is already guessed. */

int letterFill (char guess, char secretword[], char guessword[])
{
	int i;
	int matches=0;
	for (i = 0; secretword[i]!='\0'; i++)
	{
		// Did we already match this letter in a previous guess?
		if (guess == guessword[i])
			return 0;
		// Is the guess in the secret word?
		if (guess == secretword[i])
		{
			guessword[i] = guess;
			matches++;
		}
	}
	return matches;
}


// Initialize the unknown word

void initUnknown (char word[], char unknown[])
{
	int i;
	int length = strlen(word);
	for (i = 0; i < length; i++)
		unknown[i]='*';
	unknown[i]='\0';
}








void end()
{
 int x,y,cl,a,b;
int gd=DETECT,gm;
initgraph(&gd,&gm,"c://tc//bgi");

setcolor(RED);
bar3d(100,100,530,200,10,20);
setcolor(6);
settextstyle(DEFAULT_FONT,HORIZ_DIR,5);
outtextxy(150,140,"GAME OVER");
delay(1500);

cleardevice();

bar3d(200,230,400,280,10,20);
setcolor(GREEN);
settextstyle(DEFAULT_FONT,HORIZ_DIR,5);
outtextxy(230,240,"HOME");

setcolor(RED);
bar3d(200,320,400,370,10,20);
setcolor(4);
settextstyle(DEFAULT_FONT,HORIZ_DIR,5);
outtextxy(230,330,"EXIT");


 a=100;
 b=400;
 setposi(a,b);
 callmouse();
	     do
	     {
		    mouseposi(x,y,cl);
		    gotoxy(10,9);
		    if(cl==1 && x>=200 && x<=400 && y>=230 && y<=280)
		    {
		    cleardevice();
		    start();
		    break;
		    }
		    else if(cl==1 && x>=200 && x<=400 && y>=320 && y<=370)
		    {
		    exit(0);
		    break;
		    }
	     }while(!kbhit());

}
void casino()
{

micky();
setcolor(12);
settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
outtextxy(600,100," PRESS ENTER TO CONTINUE ");
cleardevice();

char playerName[90];
    int amount; // hold player's balance amount
    int bettingAmount;
    int guess;
    int dice; // hold computer generated number
    char choice;

    srand(time(0)); // "Seed" the random generator

    drawLine(60,'=');
    cout << "\n\n\n\t\t\t GAMBLING......  \n\n\n\n";
    drawLine(60,'=');
    outtextxy(0,110,"ITS NOT LIFE IF U KNOW U R GOING TO WIN...  ");

    // outtextxy(0,100," ITS NOT LIFE IF U KNOW U R GOING TO WIN...");
    cout << "\n\n\t  Enter Your Name : ";
   cin.getline(playerName,50);

    cout << "\n\n\t  Enter Deposit amount to play game : $";
    cin >> amount;

    do
    {
	system("cls");
	rules();
	cout << "\n\nYour current balance is $ " << amount << "\n";

		// Get player's betting amount
	do
	{
	    cout <<playerName<<", enter money to bet : $";
	    cin >> bettingAmount;
	    if(bettingAmount<=0)
	    {
	    cout<<" AMT. SHOULD BE MORE THAN 0 "<<endl;
	    //goto tryagain;

	    cout<<" RE ENTER DATA ";
	     cin>>bettingAmount;
		    }

		    if(bettingAmount > amount)
		cout << "Your betting amount is more than your current balance\n"
		       <<"\nRe-enter data\n ";
	}while(bettingAmount > amount);


		// Get player's numbers
	do
	{
	    cout << "Guess your number to bet between 1 to 10 :";
	    cin >> guess;
	    if(guess <= 0 || guess > 10)
		cout << "Please check the number!! should be between 1 to 10\n"
		    <<"\nRe-enter data\n ";
	}while(guess <= 0 || guess > 10);

	dice = rand()%10 + 1; // Will hold the randomly generated integer between 1 and 10

	if(dice == guess)
	{
	    cout << "\n\nGood Luck!! You won Rs." << bettingAmount * 10;
	    amount = amount + bettingAmount * 10;
	}
	else
	{
	    cout << "Hard Luck this time !! You lost $ "<< bettingAmount <<"\n";
	    amount = amount - bettingAmount;
	}

	cout << "\nThe winning number was : " << dice <<"\n";
	cout << "\n"<<playerName<<", You have $ " << amount << "\n";
	if(amount == 0)
	{
	    cout << "You have no money to play ";
	    break;
	}
	cout<<" BUT....";
	cout<<"THE BEST THING HUMAN CAN DO IS TRY & TRY AGAIN ";




	cout << "\n\n SO ...Do you want to play again (y/n)? ";
	cin >> choice;
    }while(choice =='Y'|| choice=='y');

    cout << "\n\n\n";
    drawLine(70,'=');
    cout << "\n\n Your balance amount is $ " << amount << "\n\n";
    drawLine(70,'=');

end();
}

//void endcs()
//{
// outtextxy(0,110,"the diff. b/w winning and losing is most often not quittng  ");
//     outtextxy(20,130," BUT IN RISING UP EVERY TIME WE FALL");

//cout<<" the diff. b/w winning and losing is most often not quittng";




void drawLine(int n, char symbol)
{
    for(int i=0; i<n; i++)
	cout << symbol;
    cout << "\n" ;
}

void rules()
{
    system("cls");
    cout << "\n\n";
    drawLine(80,'-');
    cout << "\t\tRULES OF THE GAME\n";
    drawLine(80,'-');
    cout << "\t1. Choose any number between 1 to 10\n";
    cout << "\t2. If you win you will get 10 times of money you bet\n";
    cout << "\t3. If you bet on wrong number you will lose your betting amount\n\n";
    drawLine(80,'-');
}




void tictactoe()
{
micky();
setcolor(12);
ticintro();
settextstyle(DEFAULT_FONT,HORIZ_DIR,7);
outtextxy(600,100," PRESS ENTER TO CONTINUE ");

//delay(500);
cleardevice();
setbkcolor(RED);
//char square[10] = {'o','1','2','3','4','5','6','7','8','9'};
int checkwin();
void board();

	int player = 1,i,choice;
	char mark;
	clrscr();
	do
	{
		board();
		player=(player%2)?1:2;
		cout << "Player " << player << ", enter a number:  ";
		cin >> choice;
		mark=(player == 1) ? 'X' : 'O';
		if (choice == 1 && square[1] == '1')
			square[1] = mark;
		else if (choice == 2 && square[2] == '2')
			square[2] = mark;
		else if (choice == 3 && square[3] == '3')
			square[3] = mark;
		else if (choice == 4 && square[4] == '4')
			square[4] = mark;
		else if (choice == 5 && square[5] == '5')
			square[5] = mark;
		else if (choice == 6 && square[6] == '6')
			square[6] = mark;
		else if (choice == 7 && square[7] == '7')
			square[7] = mark;
		else if (choice == 8 && square[8] == '8')
			square[8] = mark;
		else if (choice == 9 && square[9] == '9')
			square[9] = mark;
		else
		{
			cout<<"Invalid move ";
			player--;
			getch();
		}
		i=checkwin();
		player++;
	}while(i==-1);
	board();
	if(i==1)
	{
		cout<<"==>\aPlayer "<<--player<<" win ";
		delay(3000);
     }	else

     {
		cout<<"==>\aGame draw";
		delay(3000);
			     }
}

/*********************************************
	FUNCTION TO RETURN GAME STATUS
	1 FOR GAME IS OVER WITH RESULT
	-1 FOR GAME IS IN PROGRESS
	O GAME IS OVER AND NO RESULT
**********************************************/

int checkwin()
{

	if (square[1] == square[2] && square[2] == square[3])
		return 1;
	else if (square[4] == square[5] && square[5] == square[6])
		return 1;
	else if (square[7] == square[8] && square[8] == square[9])
		return 1;
	else if (square[1] == square[4] && square[4] == square[7])
		return 1;
	else if (square[2] == square[5] && square[5] == square[8])
		return 1;
	else if (square[3] == square[6] && square[6] == square[9])
		return 1;
	else if (square[1] == square[5] && square[5] == square[9])
		return 1;
	else if (square[3] == square[5] && square[5] == square[7])
		return 1;
	else if (square[1] != '1' && square[2] != '2' && square[3] != '3' &&
		 square[4] != '4' && square[5] != '5' && square[6] != '6' &&
	    square[7] != '7' && square[8] != '8' && square[9] != '9')
		return 0;
	else
		return -1;
}


void ticintro()
{



setcolor(RED);
bar3d(100,100,530,200,10,20);
setcolor(6);
settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
outtextxy(120,140,"MAKE YOUR MOVES CAREFULLY");
delay(3000);

cleardevice();
  }
/*******************************************************************
     FUNCTION TO DRAW BOARD OF TIC TAC TOE WITH PLAYERS MARK
********************************************************************/


void board()
{
	clrscr();
	cout << "\n\n\tTic Tac Toe\n\n";
	cout << "Player 1 (X)  -  Player 2 (O)" << endl << endl;
	cout << endl;
	cout << "     |     |     " << endl;
	cout << "  " << square[1] << "  |  " << square[2] << "  |  " << square[3] << endl;
	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;
	cout << "  " << square[4] << "  |  " << square[5] << "  |  " << square[6] << endl;
	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;
	cout << "  " << square[7] << "  |  " << square[8] << "  |  " << square[9] << endl;
	cout << "     |     |     " << endl << endl;
}
void main()
{

start();
cleardevice();
end();
getch();
closegraph();
restorecrtmode();
}

void micky()
{

int h=0;
int gd=DETECT,gm,n,m,area;
//initgraph( &gd,&gm,"c://tc//bgi");//put your directory contains egavga.bgi
initgraph(&gd,&gm,"c://tc//bgi");
settextstyle(DEFAULT_FONT,HORIZ_DIR,4);
outtextxy(320,300,"WELCOME");
settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
outtextxy(310,380,"CLICK ENTER TO PLAY");


rectangle(0,0,getmaxx(),getmaxy());
arc(240,120,40,140,70);
ellipse(165,80,10,280,20,20);
ellipse(315,80,-100,170,20,20);
arc(235,120,163,215,70);
arc(245,120,-35,17,70);
ellipse(193,178,85,280,40,20);
ellipse(283,178,-100,95,40,20);
ellipse(238,199,180,0,39,50);
ellipse(213,123,44,240,33,40);
ellipse(262,123,-60,135,33,40);
ellipse(210,123,0,360,13,20);//left eye
ellipse(265,123,0,360,13,20);//right eye
ellipse(210,133,0,360,10,10);//left eye ball
ellipse(265,133,0,360,10,10);//right eye ball
ellipse(210,133,0,360,3,3);//left eye ball
ellipse(265,133,0,360,3,3);//right eye ball
ellipse(238,160,0,360,10,13);//nose
arc(240,125,228,312,68);//mouth
arc(240,120,230,310,72);//mouth
setfillstyle(1,4);
floodfill(238,160,15);//nose
setfillstyle(1,15);
floodfill(210,113,15);
floodfill(265,113,15);
setfillstyle(1,9);
floodfill(210,100,15);
setfillstyle(1,1);
floodfill(315,80,15);
moveto(203,220);
lineto(203,260);
lineto(183,260);
lineto(183,350);
lineto(293,350);
lineto(293,260);
lineto(273,260);
lineto(273,220);
moveto(183,350);
lineto(173,460);
lineto(213,460);
lineto(238,400);
lineto(263,460);
lineto(303,460);
lineto(293,350);
moveto(173,460);
lineto(143,478);
lineto(213,478);
lineto(213,460);
moveto(263,460);
lineto(263,478);
lineto(333,478);
lineto(303,460);
line(238,400,238,350);
//right hand
moveto(183,260);
lineto(113,310);
lineto(183,375);
moveto(183,280);
lineto(137,310);
lineto(181,353);
setfillstyle(2,13);
floodfill(190,300,15);
setfillstyle(1,5);
floodfill(223,400,15);
setfillstyle(1,5);
floodfill(253,400,15);
setfillstyle(1,6);
floodfill(173,470,15);
floodfill(303,470,15);
//fingers
secondleft();
ellipse(413.5,228,0,180,3.5,3.5);
line(420,240,433,240);
line(423,247,440,247);
line(413,240,410,228);
line(417,228,420,240);
ellipse(433,243.5,-90,90,3.5,3.5);
line(423,254,440,254);
ellipse(440,250.5,-90,90,3.5,3.5);
ellipse(430,257,-90,90,3,3);
line(413,260,430,260);
area=imagesize(409,224,444,261);
buf=malloc(area);
getimage(409,224,444,261,buf);
while(!kbhit())
{
if(h==0)
{
setfillstyle(1,15);
setcolor(15);
ellipse(210,133,0,360,10,10);//left eye ball
ellipse(265,133,0,360,10,10);//right eye ball
setcolor(0);
ellipse(210,133,0,360,3,3);//left eye ball
ellipse(265,133,0,360,3,3);//right eye ball
floodfill(210,133,15);
floodfill(265,133,15);
setcolor(0);
putimage(391,209,buf,1);
firstleft();
setcolor(15);
secondleft();
putimage(409,224,buf,0);
h=1;
}
else
{
setfillstyle(1,0);
setcolor(0);
ellipse(210,133,0,360,10,10);//left eye ball
ellipse(265,133,0,360,10,10);//right eye ball
floodfill(210,133,0);
floodfill(265,133,0);
setcolor(15);
ellipse(210,133,0,360,3,3);//left eye ball
ellipse(265,133,0,360,3,3);//right eye ball
floodfill(210,133,15);
floodfill(265,133,15);
setcolor(0);
putimage(409,224,buf,1);
secondleft();
setcolor(15);
firstleft();
putimage(391,209,buf,0);
h=0;
}
delay(300);
}
getch();
}
void firstleft()
{
moveto(293,260);
lineto(353,276);
lineto(395,223);
moveto(293,280);
lineto(355,296);
lineto(395,245);
}
void secondleft()
{
moveto(293,260);
lineto(363,280);
lineto(413,240);
moveto(293,280);
lineto(363,300);
lineto(413,260);
}
