/*
** EPITECH PROJECT, 2025
** log_in.c
** File description:
** To log in on your account
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

int window_loop(void)
{
    graphic_t *graph = malloc(sizeof(graphic_t));

    if (!graph)
        exit(my_puterror("Invalid MALLOC at | window loop |\n"));
    graph->win = init_window();
    graph->dark_mode = 1;

    while (sfRenderWindow_isOpen(graph->win->window)) {
        // EVENTS
        while (sfRenderWindow_pollEvent(graph->win->window, &graph->win->event)) {
            if (graph->win->event.type == sfEvtClosed)
                sfRenderWindow_close(graph->win->window);
        }

        // BACKGROUND FILL
        if (graph->dark_mode == 1)
            sfRenderWindow_clear(graph->win->window, sfColor_fromRGB(25, 23, 23));
        else
            sfRenderWindow_clear(graph->win->window, sfWhite);

        sfRenderWindow_display(graph->win->window);
    }
    sfRenderWindow_destroy(graph->win->window);
    free(graph);
    return 0;
}
