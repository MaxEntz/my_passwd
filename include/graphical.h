/*
** EPITECH PROJECT, 2025
** my_passwd.h
** File description:
** Its the header file of my_passwd project
*/

#ifndef GRAPHICAL_H_
    #define GRAPHICAL_H_
    #include <stdlib.h>
    #include <stdio.h>
    #include <string.h>
    #include <SFML/Graphics.h>
    #include <SFML/System.h>
    #include <SFML/Window.h>
    #include <SFML/Audio.h>
    #include <SFML/Config.h>

#define S_WIDTH 1280
#define S_HEIGHT 720

typedef struct button_s {
    /* data */
} button_t;


typedef struct window_s {
    sfRenderWindow *window;
    sfVideoMode v_mode;
    sfEvent event;
    sfClock *clock;
    double time;
} window_t;

typedef struct programm_s {
    struct window_s *win;
    int dark_mode;
} programm_t;

window_t *init_window();
int window_loop(void);

#endif /* GRAPHICAL_H_ */
