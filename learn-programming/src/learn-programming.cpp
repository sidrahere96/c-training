#include <graphics.h>
#include <iostream>
using namespace std;

int main()
{

int gd=DETECT , gm;
initgraph(&gd,&gm,(char*)"");
//for eyes(outer layer)
setcolor(0);
ellipse(300,32,0,360,10,18);
setfillstyle(SOLID_FILL,15);
fillellipse(300,32,10,18);
setcolor(0);
ellipse(318,32,0,360,10,18);
setfillstyle(SOLID_FILL,15);
fillellipse(318,32,10,18);
//(inner layer)
setcolor(0);
circle(300,34,5);
setfillstyle(SOLID_FILL,BLACK);
floodfill(300,34,0);
circle(318,34,5);
setfillstyle(SOLID_FILL,BLACK);
floodfill(318,34,0);
//for head
setcolor(15);
circle(310,65,47);
//setfillstyle(SOLID_FILL,WHITE);
//floodfill(310,65,15);
setcolor(9);
circle(310,65,59);
// for body
setcolor(9);
circle(308,205,80);
//setfillstyle(SOLID_FILL,9);
//floodfill(175,189,9);
circle(308,205,70);
//setfillstyle(SOLID_FILL,9);
//floodfill(360,60,9);
setfillstyle(SOLID_FILL,15);
floodfill(308,205,9);
//for bell
setcolor(0);
circle(308,150,10);
setfillstyle(SOLID_FILL,RED);
floodfill(308,150,0);

// for pocket
setcolor(0);
line(258,195,355,195);
arc(306,196,180,0,50);
setfillstyle(SOLID_FILL,4);
floodfill(306,195,0);
// for nose
setcolor(9);
circle(308,58,10);
setfillstyle(SOLID_FILL,RED);
floodfill(308,58,9);
//for moustasch of right side
setcolor(15);
line(320,60,340,50);
line(320,60,340,60);
line(320,60,340,70);
//for moustach on left side
setcolor(15);
line(296,60,276,50);
line(296,60,276,60);
line(296,60,276,70);
//for right leg
setcolor(9);
line(250,265,250,325);
line(290,285,290,325);
ellipse(270,325,0,360,21,12.5);
setfillstyle(SOLID_FILL,15);
fillellipse(270,325,21,12.5);
//for left leg
line(320,285,320,325);
line(360,265,360,325);
setcolor(15);
ellipse(340,325,0,360,21,12.5);
setfillstyle(SOLID_FILL,15);
fillellipse(340,325,21,12.5);
//for right hand
setcolor(9);
line(177,189,228,215);
line(185,158,228,185);
circle(175,172,17);
setfillstyle(SOLID_FILL,15);
floodfill(175,172,9);
// for left hand
line(388,213,449,180);
line(385,185,440,150);
circle(450,165,17);
setfillstyle(SOLID_FILL,15);
floodfill(450,165,9);
//for mouth
line(285,75,335,75);
arc(310,75,180,0,25);
getch();
closegraph();
return 0;
}
