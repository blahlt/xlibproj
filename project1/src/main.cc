#include <X11/Xlib.h>
#include <unistd.h>

int main()
{
  Display* d = XOpenDisplay(NULL);
  Window w = XCreateSimpleWindow(d, RootWindow(d, 0), 1, 1, 500, 500,
                              0, BlackPixel(d, 0), BlackPixel(d, 0));
  XMapWindow(d, w);
  XFlush(d);
  sleep(5);
  return(0);
}
