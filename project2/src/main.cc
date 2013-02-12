#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/Xos.h>
#include <X11/Xatom.h>
#include <unistd.h> // sleep
#include <cstdlib> // exit
#include "button.h"

int main()
{
  Display* d = XOpenDisplay(NULL);
  Window w = XCreateSimpleWindow(d, RootWindow(d, 0), 1, 1, 500, 500,
                              0, BlackPixel(d, 0), BlackPixel(d, 0));

	/*Atom atom = XInternAtom(d, "_MOTIF_WM_HINTS", False);
	if (atom != None) {
		long prop[5] = { 2, 0, 0, 0, 0};
		XChangeProperty(d, w, atom, atom, 32, PropModeReplace,
			(unsigned char *) prop, 5);
	}*/

	Button *pButton = new Button;
	pButton->Print();
	delete pButton;	

	unsigned long black = XBlackPixel(d, DefaultScreen(d));
	unsigned long white = XWhitePixel(d, DefaultScreen(d));

	Window btn = XCreateSimpleWindow(d, w, 10, 10, 30, 30, 2, black, white);
	
  XMapWindow(d, w);
	XMapWindow(d, btn);

  XFlush(d);

	XSelectInput(d, w, ButtonPressMask);
	XSelectInput(d, btn, ButtonPressMask);

  //sleep(3);
  
	XEvent e;
	while (1)
	{
		XNextEvent(d, &e);

		if (e.type == ButtonPress)
		{
			if (e.xbutton.window == w)
			{
				
			}
			else if (e.xbutton.window == btn)
			{
				XCloseDisplay(d);
				exit(0);
			}
		}
	}
  return(0);
}
