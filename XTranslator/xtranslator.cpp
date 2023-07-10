#include "xtranslator.h"

std::string XTranslator::getSelectionData() {
  if (!dpy || !XGetSelectionOwner(dpy, sel)) {
    throw std::runtime_error("Couln't open display or selection has no owner");
  }

  targetWindow = XCreateSimpleWindow(dpy, root, -10, -10, 1, 1, 0, 0, 0);

  XConvertSelection(dpy, sel, utf8, targetProperty, targetWindow, CurrentTime);

  for (;;) {
    XNextEvent(dpy, &ev);
    switch (ev.type) {
    case SelectionNotify:
      if (!ev.xselection.property) {
        throw std::runtime_error("Requested convertion counln't be made");
      } else {
        return getUTF8FromProp(dpy, targetWindow, targetProperty);
      }
      break;
    }
  }
}

std::string XTranslator::getUTF8FromProp(Display *dpy, Window &win,
                                         Atom &property) {
  Atom type;
  int di;
  unsigned long size, dul;
  unsigned char *propData = nullptr;

  XGetWindowProperty(dpy, win, property, 0, 0, 0, AnyPropertyType, &type, &di,
                     &dul, &size, &propData);
  XFree(propData);
  XGetWindowProperty(dpy, win, property, 0, size, 0, AnyPropertyType, &type,
                     &di, &dul, &size, &propData);

  std::string result = reinterpret_cast<char *>(propData);

  XFree(propData);

  XDeleteProperty(dpy, win, property);

  return result;
}