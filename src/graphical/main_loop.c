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
    window_t *win = init_window();

    while (sfRenderWindow_isOpen(win->window)) {
        // EVENTS
        while (sfRenderWindow_pollEvent(win->window, &win->event)) {
            if (win->event.type == sfEvtClosed)
                sfRenderWindow_close(win->window);
        }

        sfRenderWindow_clear(win->window, sfColor_fromRGB(25, 23, 23));
        sfRenderWindow_display(win->window);
    }
    sfRenderWindow_destroy(win->window);
    return 0;
}
