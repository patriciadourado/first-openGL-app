# first-openGL-app

First OpenGL rendering program using GLUT API. 

You can find the file <glut.h> (the library necessary to compile the source code) in the repository.
I used Borland DEV-C++ as an IDE in that time;

This application draw dinamically a four-pointed 'star' in the middle of the screen and its pieces at the right side of the screen, the 'objective' is just to mount the star. 

The comments are in portuguese because its my native language, I will translate them later.

-FuncSwitch(): this function updates the values of x and y of the objects, it detects which object is being used at the moment.
You can rotate, translate and resize the objects (pieces of the star) choosing them by its number on keyboard (1, 2, 3 or 4);

-Teclado(): you can choose the movements (rotate, translate and resize) and choose the object;

-Zoom(): zoom in or zoom out on the screen;

-CriaMenu(): you can choose the color of the borders and fullscreen on window with a right click;

Everything is based on loops, so this small application can demonstrate a few functionalities of OpenGL;

![alt tag](https://github.com/patriciadourado/first-openGL-app/blob/master/img/img1.png)

Rotating and moving:

![alt tag](https://github.com/patriciadourado/first-openGL-app/blob/master/img/img2.png)

Changing color and option to fullscreen(tela cheia):

![alt tag](https://github.com/patriciadourado/first-openGL-app/blob/master/img/img3.png)
