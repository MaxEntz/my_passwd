/*
** EPITECH PROJECT, 2025
** my_passwd
** File description:
** events
*/

#include "../../include/graphical.h"

static void check_buttons_click(graphic_t *graph, sfEvent event)
{
    for (button_t *tmp = graph->buttons; tmp != NULL; tmp = tmp->next) {
        for (int i = 0; tmp->activation_scenes[i] != NULL; i++) {
            if (strcmp(graph->scene, tmp->activation_scenes[i]) == 0 &&
                event.mouseButton.x >= tmp->pos.x - (tmp->dimensions.x / 2) &&
                event.mouseButton.x <= tmp->pos.x + (tmp->dimensions.x / 2) &&
                event.mouseButton.y >= tmp->pos.y - (tmp->dimensions.y / 2) &&
                event.mouseButton.y <= tmp->pos.y + (tmp->dimensions.y / 2))
                tmp->action(graph);
        }
    }
}

void manage_events(graphic_t *graph)
{
    sfEvent event = graph->win->event;

    if (event.type == sfEvtClosed)
        sfRenderWindow_close(graph->win->window);
    if (event.type == sfEvtMouseButtonPressed &&
        event.mouseButton.button == sfMouseLeft)
        check_buttons_click(graph, event);
}