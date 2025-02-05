/*
** EPITECH PROJECT, 2025
** my_passwd
** File description:
** display_elements.c
*/

#include "../../include/graphical.h"
#include "../../include/my_lib.h"

static void draw_valid_button(graphic_t *graph, button_t *tmp, int i)
{
    sfSprite *button;
    sfTexture *b_texture;

    if (strcmp(graph->scene, tmp->activation_scenes[i]) == 0) {
        button = sfSprite_create();
        if (!button)
        exit(my_puterror("Invalid INIT at | draw buttons |\n"));
        b_texture = graph->dark_mode == 1 ?
            sfTexture_createFromFile(tmp->dark_icon, NULL) :
            sfTexture_createFromFile(tmp->light_icon, NULL);
        sfSprite_setTexture(button, b_texture, sfFalse);
        sfSprite_setOrigin(button,
        (sfVector2f){tmp->dimensions.x / 2, tmp->dimensions.y / 2});
        sfSprite_setPosition(button, tmp->pos);
        sfRenderWindow_drawSprite(graph->win->window, button, NULL);
    }
}

void display_buttons(graphic_t *graph)
{
    for (button_t *tmp = graph->buttons; tmp != NULL; tmp = tmp->next) {
        for (int i = 0; tmp->activation_scenes[i] != NULL; i++) {
            draw_valid_button(graph, tmp, i);
        }
    }
}

int change_color_mode(graphic_t *graph)
{
    graph->dark_mode = !graph->dark_mode;
}