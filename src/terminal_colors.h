#pragma once

#ifndef TERMINAL_COLORS_H
#define TERMINAL_COLORS_H

#ifdef __cplusplus
  extern "C" {
#endif

void colored_print(int red ,int green, int blue, const char* text);
void colored_printf(int red, int green, int blue, const char *fmt, ...);

void error_print(const char* text);
void error_printf(const char* text);

void warning_print(const char* text);
void warning_printf(const char* text);

void success_print(const char* text);
void success_printf(const char* text);

#ifdef __cplusplus
  }
#endif

#endif /* TERMINAL_COLOURS_H */