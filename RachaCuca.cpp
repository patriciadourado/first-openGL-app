#include <stdlib.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <stdio.h>

/*
	First program with OpenGL;
	Created and developed by Patricia Nunes Dourado;
	RachaCuca.cpp - October 05 of 2011;
*/

void Desenha(void);
void Inicializa(void);
void Visualizacao(void);
void Teclado(unsigned char tecla, GLint x, GLint y);
void Zoom(GLint tecla, GLint x, GLint y);
void AlteraTamanhoJanela(GLsizei w, GLsizei h);
void Mouse(int button, int state,int x, int y);
void CriaMenu(void);
void MenuCor(int op);
void Timer(int value);
void Quadrado(GLint x,GLint y);

GLsizei largura, altura;
GLint idJanela,op=0,ant=-1;

GLfloat win=4.0f;

GLfloat rotacao=0,R=1.0f,G=1.0f,B=1.0f;
GLfloat movx,movy,Mx,My;
GLfloat escala=1;

GLfloat vetorX[4]={0,0,0,0},vetorY[4]={0,0,0,0},vetorRotacao[4]={0,0,0,0},vetorEscala[4]={1,1,1,1};

GLfloat x1 = 4.0f;//Tamanho da Janela, proporcional!

// Largura e altura da janela
GLfloat windowWidth;
GLfloat windowHeight;

// Programa Principal
int main(int argc, char *argv[])
{
    glutInit(&argc,argv);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(500,500);
    glutInitWindowPosition(0,0);//Começa no canto esquerdo superior da tela
    
    idJanela = glutCreateWindow("Racha-Cuca");
    
	glutDisplayFunc(Desenha);   
    glutReshapeFunc(AlteraTamanhoJanela);
    glutMouseFunc(Mouse);    
    Inicializa();  
    
   	glutKeyboardFunc (Teclado);
    glutSpecialFunc(Zoom);
	glutMainLoop();

	return 0;
}

void Inicializa(void)
{
 
    glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-100,100,-100,100);
	glMatrixMode(GL_MODELVIEW);     
    glClearColor(0.0, 0.0, 0.0, 1.0);	
     
}

void Estrela(){
          
      glColor3f(0.5f,0.5f,0.5f);
      glBegin(GL_TRIANGLES);//Aqui Constroi o Triangulo de Cima
                glVertex2f(0,0);
                //glColor3f(0.988200 ,0.988200 ,0.988200);
                glVertex2f(-1,2);
                glVertex2f(-2,0);
      glEnd();
      glBegin(GL_TRIANGLES);//Aqui Constroi o Triangulo Direito
                glVertex2f(0,-2);
                glVertex2f(0,0);
                glVertex2f(2,-1);
      glEnd();

      glBegin(GL_TRIANGLES);//Aqui Constroi o Triangulo Esquerdo
                glVertex2f(-2,-2);
                glVertex2f(-4,-1);               
                glVertex2f(-2,0);
      glEnd();

      glBegin(GL_POLYGON);//Aqui Constroi um Pentagono com uma ponta para baixo.
            glVertex3f( -1, -4,0.0);
            glVertex3f( -2, -2 ,0.0 );                                
            glVertex3f( -2, 0,0.0);
            glVertex3f( 0, 0,0.0);                        
            glVertex3f( 0, -2,0.0);
            
      glEnd();
}

void Part1(GLfloat cor1,GLfloat cor2,GLfloat cor3,GLfloat cor4,GLfloat cor5)
{
      glColor3f(cor4,cor4,cor5);
      glBegin(GL_TRIANGLES);//Aqui Constroi o Triangulo de Cima
                glVertex2f(2,1);
                glColor3f(cor1 ,cor2 ,cor3);
                glVertex2f(3,3);
                glColor3f(cor4,cor4,cor5);
                glVertex2f(4,1);    
     glEnd();

}

void Part3(GLfloat cor1,GLfloat cor2,GLfloat cor3,GLfloat cor4,GLfloat cor5)
{
      glColor3f(cor4,cor4,cor5);
      glBegin(GL_TRIANGLES);//Aqui Constroi o Triangulo Direito
                glVertex2f(2,-0.6);
                glColor3f(cor1 ,cor2 ,cor3);
                glVertex2f(4,-1.6);
                glColor3f(cor4,cor4,cor5);
                glVertex2f(2,-2.6);
      glEnd();     
}

void Part2(GLfloat cor1,GLfloat cor2,GLfloat cor3,GLfloat cor4,GLfloat cor5)
{
      glColor3f(cor4,cor4,cor5);
      glBegin(GL_TRIANGLES);//Aqui Constroi o Triangulo Esquerdo
                glVertex2f(2,-0.1);
                glColor3f(cor1 ,cor2 ,cor3);
                glVertex2f(4,0.9);
                glColor3f(cor4,cor4,cor5);               
                glVertex2f(4,-1.1);
      glEnd();     
}

void Part4(GLfloat cor1,GLfloat cor2,GLfloat cor3,GLfloat cor4,GLfloat cor5)
{
     glColor3f(cor4,cor4,cor5);     
      glBegin(GL_POLYGON);//Aqui Constroi um Pentagono com uma ponta para baixo.
            glVertex3f( 3.5, -4/2,0.0);
            glColor3f(cor1 ,cor2 ,cor3);           
            glVertex3f( 4, -3 ,0.0 );
            glColor3f(cor4,cor4,cor5);                                        
            glVertex3f( 4, -4,0.0);
            glColor3f(cor1 ,cor2 ,cor3);
            glVertex3f( 3, -4,0.0);
            glColor3f(cor4,cor4,cor5);                            
            glVertex3f( 3, -3,0.0);
            
      glEnd();
}   

void Moldura2(){
     
    glColor3f(R,G,B);
	glLineWidth(4);
	glBegin(GL_LINE_LOOP);
		glVertex2f(x1,-x1);   
		glVertex2f(x1/2,-x1);    
		glVertex2f(x1/2,x1-1); 
		glVertex2f(x1,x1-1);                    
	glEnd();
	glLineWidth(1);                           
}

void Moldura1()
{
    glColor3f(R,G,B);
     glLineWidth(4);
	 glBegin(GL_LINE_LOOP);
		glVertex2f(x1/2,-x1);   
		glVertex2f(-x1,-x1);    
		glVertex2f(-x1,x1-1); 
		glVertex2f(x1/2,x1-1);                    
	glEnd();
	glLineWidth(1);                           
     
}
// Função que recebe a fonte e um texto por parâmetro para ser exibido na 
// tela usando fonte de linhas
void DesenhaTextoStroke(void *font, char *string) 
{  
	// Exibe caractere a caractere
	while(*string)
		glutStrokeCharacter(GLUT_STROKE_ROMAN,*string++); 
}


void TextosDeTela()
{
     
     glColor3f(R,G,B);
	// Posiciona o texto stroke usando transformações geométricas
	glPushMatrix();	
	glTranslatef(-3,-1,0);
	glScalef(0.0039, 0.0039, 0.0039); // diminui o tamanho do fonte
	glLineWidth(2); // define a espessura da linha
	DesenhaTextoStroke(GLUT_STROKE_ROMAN,"Monte a Estrela");
	glPopMatrix();
	
	glColor3f(R,G,B);
	// Posiciona o texto stroke usando transformações geométricas
	glPushMatrix();	
	glTranslatef(-4,3.1,0);
	glScalef(0.0089, 0.0089, 0.0089); // diminui o tamanho do fonte
	glLineWidth(7); // define a espessura da linha
	DesenhaTextoStroke(GLUT_STROKE_ROMAN,"RACHA CUCA");
	glPopMatrix();
	
	
      	glColor3f(1,0,0);
    	glPushMatrix();
    	glRasterPos2f(-20,-20);
        glScalef(0.2, 0.2, 0.2); // diminui o tamanho do fonte
    	glLineWidth(2); // define a espessura da linha
    	DesenhaTextoStroke(GLUT_STROKE_ROMAN,"LETS PLAY CS!");
    	glPopMatrix();
	 
}

void EnumeraObjeto()
{
    glColor3f(0.5,0.5,0.5);
	glPushMatrix();	
    	glTranslatef(2.1,2.7,0);
	    glScalef(0.0019, 0.0019, 0.0019);
        glLineWidth(2); // define a espessura da linha
	    DesenhaTextoStroke(GLUT_STROKE_ROMAN,"1");
	glPopMatrix();

    glColor3f(0.5,0.5,0.5);
	glPushMatrix();	
    	glTranslatef(2.1,0.7,0);
	    glScalef(0.0019, 0.0019, 0.0019);
        glLineWidth(2); // define a espessura da linha
	    DesenhaTextoStroke(GLUT_STROKE_ROMAN,"2");
	glPopMatrix();     
	
    glColor3f(0.5,0.5,0.5);
	glPushMatrix();	
    	glTranslatef(2.1,-0.5,0);
	    glScalef(0.0019, 0.0019, 0.0019);
        glLineWidth(2); // define a espessura da linha
	    DesenhaTextoStroke(GLUT_STROKE_ROMAN,"3");
	glPopMatrix();
	
    glColor3f(0.5,0.5,0.5);
	glPushMatrix();	
    	glTranslatef(2.9,-2.6,0);
	    glScalef(0.0019, 0.0019, 0.0019);
        glLineWidth(2); // define a espessura da linha
	    DesenhaTextoStroke(GLUT_STROKE_ROMAN,"4");
	glPopMatrix();
     
}

void FuncSwitch()
{
     if(ant!=-1)//Atualizar Vetor X Y
        {
            vetorX[ant-1]=movx;
            vetorY[ant-1]=movy;
            vetorRotacao[ant-1]=rotacao;
            vetorEscala[ant-1]=escala;            
        }                            
     switch(op){
                
              case 1:
                   glPushMatrix();//Define que os comandos abaixo serão apenas para Part1
                   movx=vetorX[op-1];
                   movy=vetorY[op-1];         
                   rotacao=vetorRotacao[op-1];
                   escala=vetorEscala[op-1];   
                                             
                   glTranslatef(movx,movy,0);
                   glScalef(escala,escala,0);
                   glRotatef(rotacao,0,0,1);

    
                   //Part1(0.988200 ,0.988200 ,0.988200,1,0);
                   glPopMatrix();
                   ant=op;
                   break;
              case 2:
                   glPushMatrix();//Define que os comandos abaixo serão apenas para Part2
                   movx=vetorX[op-1];
                   movy=vetorY[op-1];         
                   rotacao=vetorRotacao[op-1];
                   escala=vetorEscala[op-1];   
                                                     
                   glTranslatef(movx,movy,0);
                   glScalef(escala,escala,0);
                   glRotatef(rotacao,0,0,1);
   	
    
                   //Part2(0.988200 ,0.988200 ,0.988200,1,0);                   
                   glPopMatrix();
                   ant=op;
                   break;
              case 3:                
                   glPushMatrix();//Define que os comandos abaixo serão apenas para Part3    
                   movx=vetorX[op-1];
                   movy=vetorY[op-1];  
                   rotacao=vetorRotacao[op-1];
                   escala=vetorEscala[op-1];   
                                      
                   glTranslatef(movx,movy,0);
                   glScalef(escala,escala,0);
                   glRotatef(rotacao,0,0,1);

                   //Part3(0.988200 ,0.988200 ,0.988200,1,0);
                   glPopMatrix();     
                   ant=op;                   
                   break;
              case 4:                                
                   glPushMatrix();//Define que os comandos abaixo serão apenas para Part4
                   movx=vetorX[op-1];
                   movy=vetorY[op-1];  
                   rotacao=vetorRotacao[op-1];
                   escala=vetorEscala[op-1];   
                                       
                   glTranslatef(movx,movy,0);
                   glScalef(escala,escala,0);
                   glRotatef(rotacao,0,0,1);
   	
    
                   //Part4(0.988200 ,0.988200 ,0.988200,1,0);
                   glPopMatrix();
                   ant=op;                   
                   break;
    }     
    
             glPushMatrix();//Define que os comandos abaixo serão apenas para Part1    
                                      
                   glTranslatef(vetorX[0],vetorY[0],0);
                   glScalef(vetorEscala[0],vetorEscala[0],0);
                   glRotatef(vetorRotacao[0],0,0,1);

                   Part1(0.988200 ,0.988200 ,0.988200,1,0);
             glPopMatrix();     
             
             glPushMatrix();//Define que os comandos abaixo serão apenas para Part1    
                                      
                   glTranslatef(vetorX[1],vetorY[1],0);
                   glScalef(vetorEscala[1],vetorEscala[1],0);
                   glRotatef(vetorRotacao[1],0,0,1);

                   Part2(0.988200 ,0.988200 ,0.988200,1,0);
             glPopMatrix();     
                          
             glPushMatrix();//Define que os comandos abaixo serão apenas para Part1    
                                      
                   glTranslatef(vetorX[2],vetorY[2],0);
                   glScalef(vetorEscala[2],vetorEscala[0],0);
                   glRotatef(vetorRotacao[2],0,0,1);

                   Part3(0.988200 ,0.988200 ,0.988200,1,0);
             glPopMatrix();                  
             
             glPushMatrix();//Define que os comandos abaixo serão apenas para Part1    
                                      
                   glTranslatef(vetorX[3],vetorY[3],0);
                   glScalef(vetorEscala[3],vetorEscala[3],0);
                   glRotatef(vetorRotacao[3],0,0,1);

                   Part4(0.988200 ,0.988200 ,0.988200,1,0);
             glPopMatrix();     
             
}
void Desenha(void)
{

    glMatrixMode(GL_MODELVIEW);//Essa Funcão diz q as próximas alterações serão referentes ao desenho..
	glLoadIdentity();//e nao a visualização.
	
 	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
 	Visualizacao();//Funcao que vai dizer qual parte do plano cartesiano irá mostrar..
 	
 	gluOrtho2D(-win,win,-win,win);// Habilitar para Zoom

    Moldura1();//Moldura Principal       
    Moldura2();//Moldura que separa os Objetos da tela     
    
    
    Estrela();//Desenha a Estrela Cinza quer será Montada.
    
    TextosDeTela();//Escreve os textos na Tela
    
    EnumeraObjeto();//Enumera os objetos
    
    Part1(0.5f,0.5f,0.5f,0.5f,0.5f);
    Part2(0.5f,0.5f,0.5f,0.5f,0.5f);
    Part3(0.5f,0.5f,0.5f,0.5f,0.5f);
    Part4(0.5f,0.5f,0.5f,0.5f,0.5f);
    
    FuncSwitch();

	// Executa os comandos OpenGL
	glFlush();
    glutSwapBuffers();

}

void Visualizacao(void)
{
     
  	glMatrixMode(GL_PROJECTION);//Dizendo que os parametros abaixo irão alterar a visualizacao e..'
	glLoadIdentity();//.. nao os objetos.
	//gluOrtho2D(-x1,x1,-x1,x1);//Tamanho do Desenho

}

void Teclado(unsigned char tecla, GLint x, GLint y)
{
     if(tecla==27)
       exit(0);
       
     switch(tecla)
     {
                  case '+':
                       escala+=0.1;
                       break;
                  case '-':
                       escala-=0.1;
                       break;
                  case 'r':
                       rotacao+=3;
                       break;
                  case 'R':   
                       rotacao-=3;
                       break;
                  case 'w':
                  case 'W':
                       movy+=0.1;
                       break;
                  case 's':
                  case 'S':
                       movy-=0.1;
                       break;
                  case 'd':
                  case 'D':
                       movx+=0.09;
                       break;
                  case 'a':
                  case 'A':
                       movx-=0.09;
                       break;
                  case '1': 
                       op=1;
                       break;
                  case '2':
                       op=2;
                       break;
                  case '3':
                       op=3;
                       break;
                  case '4': 
                       op=4;
                       break;
                       
     }
                       
     Desenha();
                       
}


void AlteraTamanhoJanela(GLsizei w, GLsizei h)
{

	// Evita a divisao por zero
	if(h == 0) h = 1;

	// Atualiza as variáveis
	largura = w;
	altura = h;
    	
    // Especifica as dimensões da Viewport
	glViewport(0, 0, largura, altura);

	// Inicializa o sistema de coordenadas
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// Estabelece a janela de seleção (esquerda, direita, inferior,
	// superior) mantendo a proporção com a janela de visualização
	if (largura <= altura)
		gluOrtho2D (0.0f,250.0f,0.0f,250.0f*altura/largura);
	else
		gluOrtho2D (0.0f, 250.0f*altura/largura, 0.0f, 250.0f);
}

void Mouse(int button, int state, int x, int y)
{          
     printf("X= %d e Y=%d\n",x,y);
     if(button == GLUT_RIGHT_BUTTON)
               if(state == GLUT_DOWN)
                        CriaMenu();
                        
     
     glutPostRedisplay();
}


void CriaMenu(void){
    int submenu1;
     
    submenu1 = glutCreateMenu(MenuCor);
    glutAddMenuEntry("Vermelho",0);
    glutAddMenuEntry("Verde",1);
    glutAddMenuEntry("Azul",2);
    glutAddMenuEntry("Tela Cheia",3);
    
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void MenuCor(int op){
     switch(op){
                case 0:
                     R=1.0;
                     G=0.0;
                     B=0.0;
                     break;
                case 1:
                     R=0.0;
                     G=1.0;
                     B=0.0;
                     break;
                case 2:
                     R=0.0;
                     G=0.0;
                     B=1.0;
                     break;
                case 3:
                     glutFullScreen();
                     break;
     }
     glutPostRedisplay();
} 

void Zoom(GLint tecla, GLint x, GLint y)
{
     switch(tecla){
                   case GLUT_KEY_UP:
                        win-=0.4;
                        break;
                   case GLUT_KEY_DOWN:
                        win+=0.4;
                        break;
                 }
     Desenha();
                        
}
