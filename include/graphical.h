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
#define FONT "./assets/fonts/coolvetica_regular.otf"
#define BUTTON_DARK "./assets/graphical/buttons/dark/"
#define BUTTON_LIGHT "./assets/graphical/buttons/light/"

typedef struct graphic_s {
    struct window_s *win;
    struct button_s *buttons;
    struct textbox_s *textboxes;
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
    sfVector2f pos;
    sfVector2f dimensions;
    int (*action)(struct graphic_s *graph);
    struct button_s *next;
} button_t;

typedef struct textbox_s {
    sfRectangleShape *box;
    sfText *text;
    sfFont *font;
    int max_text_len;
    char *input;
    int active;
    struct textbox_s *next;
} textbox_t;

// Prototypes
window_t *init_window();
graphic_t *init_graph();
void manage_events(graphic_t *graph);
void display_buttons(graphic_t *graph);
void display_textboxes(graphic_t *graph);
int window_loop(void);
int change_color_mode(graphic_t *graph);

// Object creation
void create_button(char *icon_name, sfVector2f pos,
    sfVector2f dim, int (*action)(struct graphic_s *graph), graphic_t **graph);
void create_textbox(graphic_t **graph, sfVector2f position, sfVector2f size, int max_txt_len);

// Scenes
void log_in_scene(graphic_t **graph);

#endif /* GRAPHICAL_H_ */
