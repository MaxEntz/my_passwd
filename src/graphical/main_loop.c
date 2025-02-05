/*
** EPITECH PROJECT, 2025
** log_in.c
** File description:
** To log in on your account
*/

#include "../../include/graphical.h"
#include "../../include/my_lib.h"

button_t *create_button(char *icon_name, char **scenes, sfVector2f pos,
    sfVector2f dim, int (*action)(struct graphic_s *graph), graphic_t **graph)
{
    button_t *button = malloc(sizeof(button_t));

    if (!button)
        exit(my_puterror("Invalid MALLOC at | create button |\n"));
    button->dark_icon = my_str_concat(BUTTON_DARK, icon_name);
    button->light_icon = my_str_concat(BUTTON_LIGHT, icon_name);
    if (!button->dark_icon || !button->light_icon)
        exit(my_puterror("Invalid CONCATENATE at | create button |\n"));
    button->activation_scenes = scenes;
    button->pos = pos;
    button->action = action;
    button->dimensions = dim;
    button->next = (*graph)->buttons;
    (*graph)->buttons = button;
    return button;
}

int window_loop(void)
{
    graphic_t *graph = init_graph();

    char *scenes_b_test[2] = {"test_scene"};
    create_button("test.jpeg", scenes_b_test, (sfVector2f){S_WIDTH / 2, S_HEIGHT / 2}, (sfVector2f){256, 256}, &change_color_mode, &graph);

    while (sfRenderWindow_isOpen(graph->win->window)) {
        while (sfRenderWindow_pollEvent(graph->win->window, &graph->win->event))
            manage_events(graph);
        sfRenderWindow_clear(graph->win->window, graph->dark_mode == 1 ?
                                    sfColor_fromRGB(25, 23, 23) : sfWhite);
        display_buttons(graph);
        sfRenderWindow_display(graph->win->window);
    }
    sfRenderWindow_destroy(graph->win->window);
    free(graph);
    return 0;
}
