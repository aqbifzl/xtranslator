#ifndef XTRANSLATOR_H
#define XTRANSLATOR_H
#include <X11/Xlib.h>
#include <iostream>
#include <string>

class XTranslator {

public:
  XTranslator(const std::string &clipboardAtomName)
      : sel(XInternAtom(dpy, clipboardAtomName.c_str(), 0)) {}
  std::string getSelectionData();

private:
  std::string getUTF8FromProp(Display *dpy, Window &win, Atom &property);
  Display *dpy = XOpenDisplay(nullptr);

  Atom sel;

  int screen = DefaultScreen(dpy);

  Window targetWindow;
  Atom targetProperty = XInternAtom(dpy, "SELECTION_DATA", false);
  const Atom root = RootWindow(dpy, screen);
  const Atom utf8 = XInternAtom(dpy, "UTF8_STRING", 0);

  XEvent ev;
};

#endif