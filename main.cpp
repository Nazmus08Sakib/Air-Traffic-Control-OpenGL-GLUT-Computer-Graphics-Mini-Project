#include <GL/gl.h>
#include <GL/glut.h>
#include<stdio.h>
#include<windows.h>
#include<math.h>
#include<mmsystem.h>


float p=0.0;
float px2=0.0;
float py2=0.0;
int state=1;

static GLfloat spin = 0.0;
static float	tx	=  0.0;
static float	ty	=  0.0;




void circle(GLfloat rx,GLfloat ry,GLfloat cx,GLfloat cy)
{
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx,cy);

    for(int i=0; i<=100; i++)
    {
        float angle = 2.0f * 3.1416f * i/100;

        float x = rx * cosf(angle);
        float y = ry * sinf (angle);

        glVertex2f((x+cx),(y+cy));
    }
    glEnd();
}

/*void spinDisplay_left(void)
{
    spin = spin + 1;

    glutPostRedisplay();
}

void spinDisplay_right(void)
{
    spin = spin - 1;

    glutPostRedisplay();
}*/


void timer1(int)
{

    if(p<100)
        p=p+0.20;
    else
        p=-100;


    glutPostRedisplay();
    glutTimerFunc(1000/60,timer1,0);
}


/**void spinDisplay()
{
    spin=spin + 0.1;
    if (spin > 360.0)
    {
        spin=0.0;
    }
    glutPostRedisplay();
}*/

void plane ()
{
    glPushMatrix();
    //glRotatef(spin, p+9, 75, 1.0);
    glColor3f(0,0,0);
    glLineWidth(4);
    glTranslatef(tx,ty,.50);
    glBegin(GL_LINES);  //plane wing            //left plane
    glVertex2f(p+8.5,76);
    glVertex2f(p+9.5,74);
    glEnd();
    glPopMatrix();



    glPushMatrix();
    //glRotatef(spin, p+9, 74, 1.0);
    glColor3f(0,0,0);
    glLineWidth(4);
    glTranslatef(tx,ty,.5);
    glBegin(GL_LINES);  //plane wing
    glVertex2f(p+8.5,74);
    glVertex2f(p+9.5,76);
    glEnd();
    glPopMatrix();









    glColor3f(0,0,0);      // plane up fan
    circle(.4,1.5,p+7,76.5);

    glColor3f(0,0,0);    //plane front tear allay
    circle(.2,1,p+7,73);


    glColor3f(0,0,0);   //plane black shade
    circle(.7,.7,p+7,72);

    glColor3f(0.9,0.9,0.2);  //  front plane yellow color
    circle(.3,.3,p+7,72);

    glColor3f(0,0,0);    // plane back tear allay
    circle(.2,1,p+3,73);

    glColor3f(0,0,0);        // back plane black tear
    circle(.7,.7,p+3,72);


    glColor3f(0.9,0.9,0.2);        // back plane yellow color
    circle(.3,.3,p+3,72);





    glColor3f(1,0.7,.3);   //plane body
    circle(5,1.7,p+4,75);


    glColor3f(0,0,0);
    circle(.7,.3,p+7.5,74.5);  // plane mirror view


    glColor3f(0,0,0);        // plane side door
    circle(1.5,.5,p+5,74);




}
int flagp=1;
void timer2(int)
{

    if(px2>-70)
    {
        px2=px2-.2;

        if(py2>-4)
        {
            py2=py2-.2;

        }

        else
        {
            py2=-4.5;
        }
    }
    else
    {
        px2=90;
        py2=-4;
    }

    glutPostRedisplay();
    glutTimerFunc(1000/60,timer2,0);
}




void palne_Right()
{
  glPushMatrix();
    //glRotatef(spin, p+9, 75, 1.0);
    glColor3f(0,0,0);
    glLineWidth(4);
    glTranslatef(tx,ty,.50);
    glBegin(GL_LINES);  //plane wing            //left plane
    glVertex2f(px2+90.5,py2+47.5);
    glVertex2f(px2+91.5,py2+44.5);
    glEnd();
    glPopMatrix();



    glPushMatrix();
    //glRotatef(spin, p+9, 74, 1.0);
    glColor3f(0,0,0);
    glLineWidth(4);
    glTranslatef(tx,ty,.5);
    glBegin(GL_LINES);  //plane wing
    glVertex2f(px2+90.5,py2+44.5);
    glVertex2f(px2+91.5,py2+47.5);
    glEnd();
    glPopMatrix();

    glColor3f(0,0,0);      // plane up fan
    circle(.4,1.5,93+px2,47.5+py2);

    glColor3f(0,0,0);    //plane front tear allay
    circle(.2,1,93+px2,44+py2);


    glColor3f(0,0,0);   //plane black shade
    circle(.7,.7,93+px2,43+py2);

    glColor3f(0.9,0.9,0.2);  //  front plane yellow color
    circle(.3,.3,93+px2,43+py2);

    glColor3f(0,0,0);    // plane back tear allay
    circle(.2,1,97+px2,44+py2);

    glColor3f(0,0,0);        // back plane black tear
    circle(.7,.7,97+px2,43+py2);


    glColor3f(0.9,0.9,0.2);        // back plane yellow color
    circle(.3,.3,97+px2,43+py2);




    glColor3f(1,0.7,.3);   //plane body
    circle(5,1.7,96+px2,46+py2);


    glColor3f(0,0,0);
    circle(.7,.3,92+px2,46+py2);  // plane mirror view


    glColor3f(0,0,0);        // plane side door
    circle(1.5,.5,95+px2,45+py2);


}






void display(void)
{
    glClear (GL_COLOR_BUFFER_BIT);

    //spinDisplay();
    plane();



    //glutIdleFunc(spinDisplay_left);
    //glutIdleFunc(spinDisplay_right);

    glColor3f(.3,.7,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(0,0);
    glVertex2f(100,0);      //grass
    glVertex2f(100,45);
    glVertex2f(0,45);
    glEnd();

    glColor3f(.6,.0,0.1);
    glBegin(GL_POLYGON);
    glVertex2f(0,43);       //wall
    glVertex2f(95,43);
    glVertex2f(95,50);
    glVertex2f(42,65);
    glVertex2f(0,50);
    glEnd();

    glColor3f(.8,.2,0.2);
    glBegin(GL_POLYGON);
    glVertex2f(25,44.5);
    glVertex2f(60,44.5);
    glVertex2f(70,57);    ////sun effect
    glVertex2f(42,65);
    glVertex2f(15,55.2);
    glEnd();

    glColor3f(.5,.2,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(23,43);
    glVertex2f(62,43);
    glVertex2f(60,44.5); // wall bot
    glVertex2f(25,44.5);
    glEnd();

    glColor3f(1,0,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(70,41);
    glVertex2f(70,45);
    glVertex2f(66,45); // box
    glVertex2f(66,41);
    glEnd();

    glColor3f(0,0,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(66,41);
    glVertex2f(66,45);      // box side
    glVertex2f(65,45.1);
    glVertex2f(65,41.1);
    glEnd();

    glColor3f(0,0,1.0);
    glBegin(GL_POLYGON);
    glVertex2f(68.1,45);
    glVertex2f(68.1,47); //spinning radder stick
    glVertex2f(67.5,47);
    glVertex2f(67.5,45);
    glEnd();

    glColor3f(0,0,1.0);
    glBegin(GL_POLYGON);
    glVertex2f(70,46.5);
    glVertex2f(70,47.5); //spinning radder head
    glVertex2f(65,47.5);
    glVertex2f(65,46.5);
    glEnd();


    /**runway **/
    glColor3f(0.9,0.8,0.5);
    glBegin(GL_POLYGON);
    glVertex2f(95,37);
    glVertex2f(94,40); //L1
    glVertex2f(9,39.5);
    glVertex2f(10,37);
    glEnd();

    glColor3f(0.9,0.8,0.5);
    glBegin(GL_POLYGON);
    glVertex2f(58,15);
    glVertex2f(65,15);  //L2
    glVertex2f(27,40);
    glVertex2f(22,40);
    glEnd();



    /** Road **/

    glColor3f(0.7,0.2,0.1);
    glBegin(GL_POLYGON);
    glVertex2f(12,0);
    glVertex2f(24,0);  //MAIN
    glVertex2f(9.8,39.5);
    glVertex2f(-1,39.5);
    glEnd();

    glColor3f(01,01,01);
    glBegin(GL_POLYGON);
    glVertex2f(16,2);
    glVertex2f(18.5,2);  //Dag
    glVertex2f(6,37);
    glVertex2f(4,37);
    glEnd();

    glColor3f(0.7,0.2,0.1);
    glBegin(GL_POLYGON);
    glVertex2f(5,32);
    glVertex2f(6,31);  //Dag gap 1
    glVertex2f(8,31);
    glVertex2f(9,32);
    glEnd();

    glColor3f(0.7,0.2,0.1);
    glBegin(GL_POLYGON);
    glVertex2f(6,25);
    glVertex2f(8,24);  //Dag gap 2
    glVertex2f(10.5,24);
    glVertex2f(11,25);
    glEnd();


    glColor3f(0.7,0.2,0.1);
    glBegin(GL_POLYGON);
    glVertex2f(6,25);
    glVertex2f(8,24);  //Dag gap 3
    glVertex2f(10.5,24);
    glVertex2f(11,25);
    glEnd();


    glColor3f(0.7,0.2,0.1);
    glBegin(GL_POLYGON);
    glVertex2f(8,18);
    glVertex2f(9,17);  //Dag gap 4
    glVertex2f(13,17);
    glVertex2f(14,18);
    glEnd();


    glColor3f(0.7,0.2,0.1);
    glBegin(GL_POLYGON);
    glVertex2f(10,12);
    glVertex2f(11,11);  //Dag gap 5
    glVertex2f(15,11);
    glVertex2f(16,12);
    glEnd();




    /**park **/

    glColor3f(0.7,0.2,0.1);
    glBegin(GL_POLYGON);
    glVertex2f(10,35);          // park plane 1
    glVertex2f(10,30);
    glVertex2f(21.5,30);
    glVertex2f(19,35);
    glEnd();


    glColor3f(0.7,0.2,0.1);
    glBegin(GL_POLYGON);
    glVertex2f(12,25);          // park plane 2
    glVertex2f(12,20);
    glVertex2f(27,20);
    glVertex2f(24,25);
    glEnd();


    glColor3f(0.7,0.2,0.1);
    glBegin(GL_POLYGON);
    glVertex2f(18,15);          // park plane 3
    glVertex2f(20,10);
    glVertex2f(32,10);
    glVertex2f(29.5,15);
    glEnd();

    glColor3f(1,0,0);        // runway light1;
    circle(.5,.5,32,40);

    glColor3f(1,0,0);        // runway light2;
    circle(.5,.5,35,40);

    glColor3f(1,0,0);        // runway light3;
    circle(.5,.5,38,40);

    glColor3f(1,0,0);        // runway light4;
    circle(.5,.5,41,40);

    glColor3f(1,0,0);        // runway light5;
    circle(.5,.5,44,40);

    glColor3f(1,0,0);        // runway light6;
    circle(.5,.5,47,40);

    glColor3f(1,0,0);        // runway light7;
    circle(.5,.5,50,40);

    glColor3f(1,0,0);        // runway light8;
    circle(.5,.5,53,40);

    glColor3f(1,0,0);        // runway light9;
    circle(.5,.5,56,40);

    glColor3f(1,0,0);        // runway light10;
    circle(.5,.5,59,40);


    palne_Right();


    glColor3f(0,.5,0.5);
    glBegin(GL_POLYGON);
    glVertex2f(27,41.8);
    glVertex2f(20,42); //control room roof top
    glVertex2f(42,8.5);
    glVertex2f(52.5,8.5);
    glEnd();





    glColor3f(0,.3,0.4);
    glBegin(GL_POLYGON);
    glVertex2f(52.4,8.5);
    glVertex2f(42,8.5); //control room front wall
    glVertex2f(42,0);
    glVertex2f(52.4,0);
    glEnd();

    glColor3f(0.1,.6,0.6);
    glBegin(GL_POLYGON);
    glVertex2f(42.4,-5);
    glVertex2f(42,8.5); //control room side wall
    glVertex2f(20,42);
    glVertex2f(20,35);
    glEnd();



    glColor3f(0,00,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(40.4,0);
    glVertex2f(40.5,9); //control room side wall
    glVertex2f(21,39);
    glVertex2f(21,35);
    glEnd();


    /**plane1 */
    glColor3f(0,0,0);      // plane up fan
    circle(.4,1.5,12,36);

    glColor3f(0,0,0);    //plane front tear allay
    circle(.2,1,13,32);



    glColor3f(0,0,0);   //plane black shade
    circle(.7,.7,13,31);

    glColor3f(0.9,0.9,0.2);  //  front plane yellow color
    circle(.3,.3,13,31);


    glColor3f(0,0,0);        // front plane black tear
    circle(.2,1,13,32);


    glColor3f(0,0,0);    // plane back tear allay
    circle(.2,1,17,32);

    glColor3f(0,0,0);        // back plane black tear
    circle(.7,.7,17,31);

    glColor3f(0.9,0.9,0.2);        // back plane yellow color
    circle(.3,.3,17,31);


    glColor3f(1,0,.5);   //plane body
    circle(5,1.7,15,34);

    glColor3f(0,0,0);
    circle(.7,.3,12,34);  // plane mirror view


    glColor3f(0,0,0);        // plane side door
    circle(1.5,.5,15,33);

    /**plane 2*/

    glColor3f(0,0,0);      // plane up fan
    circle(.4,1.5,15,26);

    glColor3f(0,0,0);    //plane front tear allay
    circle(.2,1,16.5,22);

    glColor3f(0,0,0);   //plane black shade
    circle(.7,.7,16.5,21);

    glColor3f(0.9,0.9,0.2);  //  front plane yellow color
    circle(.3,.3,16.5,21);

    glColor3f(0,0,0);    // plane back tear allay
    circle(.2,1,20.5,22);

    glColor3f(0,0,0);        // back plane black tear
    circle(.7,.7,20.5,21);

    glColor3f(0.9,0.9,0.2);        // back plane yellow color
    circle(.3,.3,20.5,21);


    glColor3f(1,0,.5);   //plane body
    circle(5,1.7,18.5,24);

    glColor3f(0,0,0);
    circle(.7,.3,15.5,24);  // plane mirror view


    glColor3f(0,0,0);        // plane side door
    circle(1.5,.5,18,23);



    /**plane3*/

    glColor3f(0,0,0);      // plane up fan
    circle(.4,1.5,20,16);

    glColor3f(0,0,0);    //plane front tear allay
    circle(.2,1,21.5,12);

    glColor3f(0,0,0);   //plane black shade
    circle(.7,.7,21.5,11);

    glColor3f(0.9,0.9,0.2);  //  front plane yellow color
    circle(.3,.3,21.5,11);

    glColor3f(0,0,0);    // plane back tear allay
    circle(.2,1,25.5,12);

    glColor3f(0,0,0);        // back plane black tear
    circle(.7,.7,25.5,11);

    glColor3f(0.9,0.9,0.2);        // back plane yellow color
    circle(.3,.3,25.5,11);


    glColor3f(1,0,.5);   //plane body
    circle(5,1.7,23.5,14);

    glColor3f(0,0,0);
    circle(.7,.3,20.5,14);  // plane mirror view

    glColor3f(0,0,0);        // plane side door
    circle(1.5,.5,23.5,13);


    glutSwapBuffers();
}



void init (void)
{

    glClearColor (1.0, 1.0, 1.0, 0.0);   // Background Color
    glMatrixMode(GL_PROJECTION);        /* initialize viewing values */
    glLoadIdentity();
    glOrtho(0, 100.0, 0.0, 100.0, -100.0, 100.0); // To specify the coordinate & Specify the distances to the nearer and farther depth
}

/*
* Declare initial window size, position, and display mode
* (Double buffer & RGBA). Open window with "hello"
* In its title bar. Call initialization routines.
* Register callback function to display graphics.
* Enter main loop and process events.
*/


int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB); //Double Frame
    glutInitWindowSize (1000, 800);
    glutInitWindowPosition (300, 100);
    glutCreateWindow ("Air_Traffic_Control");
    init ();
    glutDisplayFunc(display);
    glutTimerFunc(0,timer1,0);
    glutTimerFunc(0,timer2,0);

    PlaySound("s.wav", NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);
    glutMainLoop();
} /* ISO C requires main to return int. */
