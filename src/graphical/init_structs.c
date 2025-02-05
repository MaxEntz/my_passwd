/*
** EPITECH PROJECT, 2025
** my_passwd
** File description:
** init_structs
*/

#include "../../include/graphical.h"
#include "../../include/my_lib.h"

window_t *init_window()
{
    window_t *win = malloc(sizeof(window_t));

    if (!win)
        exit(my_puterror("Invalid MALLOC at | window init |\n"));
    win->v_mode = (sfVideoMode){S_WIDTH, S_HEIGHT, 32};
    win->window = sfRenderWindow_create(win->v_mode, "My Passwd",
                    sfDefaultStyle, NULL);
    win->clock = sfClock_create();
    win->time = 0;
    if (!win)
        exit(my_puterror("Invalid INIT at | window init |\n"));
    return win;
}

graphic_t *init_graph()
{
    graphic_t *graph = malloc(sizeof(graphic_t));

    if (!graph)
        exit(my_puterror("Invalid MALLOC at | window loop |\n"));
    graph->win = init_window();
    graph->dark_mode = 1;
    graph->scene = "test_scene";
    graph->buttons = NULL;
    return graph;
}
