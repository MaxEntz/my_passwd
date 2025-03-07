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
        if (event.mouseButton.x >= tmp->pos.x - (tmp->dimensions.x / 2) &&
            event.mouseButton.x <= tmp->pos.x + (tmp->dimensions.x / 2) &&
            event.mouseButton.y >= tmp->pos.y - (tmp->dimensions.y / 2) &&
            event.mouseButton.y <= tmp->pos.y + (tmp->dimensions.y / 2))
            tmp->action(graph);
    }
}

static void handleTextBoxEvent(textbox_t *tb, sfEvent event, sfRenderWindow *window) {
    if (event.type == sfEvtMouseButtonPressed &&
        event.mouseButton.button == sfMouseLeft) {
            sfVector2i mouse = sfMouse_getPositionRenderWindow(window);
        sfFloatRect bounds = sfRectangleShape_getGlobalBounds(tb->box);
        tb->active = sfFloatRect_contains(&bounds, mouse.x, mouse.y);
        sfRectangleShape_setOutlineThickness(tb->box, tb->active ? 2 : 0);
    }

    if (tb->active && event.type == sfEvtTextEntered) {
        if (event.text.unicode == 8 && strlen(tb->input) > 0) {  // Backspace
            tb->input[strlen(tb->input) - 1] = '\0';
        } else if (event.text.unicode == 13) {  // Enter key
            tb->active = 0;
            sfRectangleShape_setOutlineThickness(tb->box, 0);
        } else if (event.text.unicode >= 32 && event.text.unicode < 127 &&
                   strlen(tb->input) < tb->max_text_len) {
            size_t len = strlen(tb->input);
            tb->input[len] = (char)event.text.unicode;
            tb->input[len + 1] = '\0';
        }
        sfText_setString(tb->text, tb->input);
    }
}

void manage_events(graphic_t *graph)
{
    sfEvent event = graph->win->event;

    if (event.type == sfEvtClosed)
        sfRenderWindow_close(graph->win->window);
    if (event.type == sfEvtMouseButtonPressed &&
        event.mouseButton.button == sfMouseLeft) {
        check_buttons_click(graph, event);
    }
    for (textbox_t *tmp = graph->textboxes; tmp != NULL; tmp = tmp->next) {
        handleTextBoxEvent(tmp, event, graph->win->window);
    }
}