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
#define BUTTON_DARK "./assets/graphical/buttons/dark/"
#define BUTTON_LIGHT "./assets/graphical/buttons/light/"

typedef struct graphic_s {
    struct window_s *win;
    struct button_s *buttons;
    int dark_mode; //Get the info from the system
    char *scene;
} graphic_t;

typedef struct window_s {
    sfRenderWindow *window;
    sfVideoMode v_mode;
    sfEvent event;
    sfClock *clock;
    double time;
} window_t;

typedef struct button_s {
    char *dark_icon;
    char *light_icon;
    char **activation_scenes; //Scenes on which to display this button, "*" for all scenes
    sfVector2f pos;
    sfVector2f dimensions;
    int (*action)(struct graphic_s *graph);
    struct button_s *next;
} button_t;

// Prototypes
window_t *init_window();
int window_loop(void);

#endif /* GRAPHICAL_H_ */
