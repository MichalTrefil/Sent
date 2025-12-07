#pragma once
#include "esp_rom_sys.h"
#include <Arduino.h>
#include <stdio.h>

class SentClass
{
public:
    void begin(long baud = 115200) { (void)baud; }

    // print pro string
    void print(const char *msg) { ets_printf("%s", msg); }

    // print pro čísla
    void print(unsigned long val) { ets_printf("%lu", val); }
    void print(long val) { ets_printf("%ld", val); }
    void print(int val) { ets_printf("%d", val); }
void print(const String &msg) { print(msg.c_str()); }

    void print(float val, int precision = 2)
    {
        char buf[32];
        dtostrf(val, 0, precision, buf);
        ets_printf("%s", buf);
    }

    // println pro string
    void println(const char *msg) { ets_printf("%s\n", msg); }
    void println(unsigned long val) { ets_printf("%lu\n", val); }
    void println(long val) { ets_printf("%ld\n", val); }
    void println(int val) { ets_printf("%d\n", val); }
void println(const String &msg) { println(msg.c_str()); }

    void println(float val, int precision = 2)
    {
        char buf[32];
        dtostrf(val, 0, precision, buf);
        ets_printf("%s\n", buf);
    }

    void println() { ets_printf("\n"); }
};

// globální objekt
extern SentClass Sent;
