#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "RAYLIB_TEST.h"

void initWindow(WINDOW window);
int8_t hexToDeci(string hex);
Color hexToRGBA(string hex);
void add_event_listener(std::string event, std::function<auto()> callback);


#endif