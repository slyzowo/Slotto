#pragma once

#ifndef TERMINAL_COLORS_H
#define TERMINAL_COLORS_H

#ifdef __cplusplus
  extern "C" {
#endif

void cprint(int red ,int green, int blue, const char* text);
void cprintf(int red, int green, int blue, const char *fmt, ...);

#ifdef __cplusplus
  }
#endif

#endif /* TERMINAL_COLOURS_H */