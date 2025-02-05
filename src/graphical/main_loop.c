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
    graph->scene = "test_scene";
    graph->buttons = NULL;

    char *scenes_b_test[2] = {"test_scene"};
    create_button("test.jpeg", scenes_b_test, (sfVector2f){S_WIDTH / 2, S_HEIGHT / 2}, (sfVector2f){256, 256}, NULL, &graph);

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
        
        sfSprite *button = sfSprite_create();
        sfTexture *b_texture;
        if (!button)
            exit(my_puterror("Invalid INIT at | draw buttons |\n"));
        for (button_t *tmp = graph->buttons; tmp != NULL; tmp = tmp->next) {
            for (int i = 0; tmp->activation_scenes[i] != NULL; i++) {
                if (strcmp(graph->scene, tmp->activation_scenes[i]) == 0) {
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
        }

        sfRenderWindow_display(graph->win->window);
    }
    sfRenderWindow_destroy(graph->win->window);
    free(graph);
    return 0;
}
