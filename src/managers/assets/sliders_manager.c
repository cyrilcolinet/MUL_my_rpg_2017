/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** sliders_manager functions
*/

# include "rpg.h"

void callback_slide(slider_t *slide, slider_t conf)
{
	slide->state = conf.state;
	slide->onSlide = conf.onSlide;
}

void add_slider(rpg_t *rpg, slider_t conf)
{
	slider_t *tmp = rpg->slides;

	while (tmp != NULL)
		tmp = tmp->next;

	tmp = malloc(sizeof(slider_t));
	if (tmp == NULL)
		return;

	tmp->name = conf.name;
	tmp->range = conf.range;
	tmp->mid_axis = conf.mid_axis;
	tmp->btn = conf.btn;
	tmp->text = conf.text;
	tmp->next = NULL;

	callback_slide(tmp, conf);
}

slider_t *get_slider(rpg_t *rpg, char *name)
{
	slider_t *tmp = rpg->slides;

	while (tmp != NULL) {
		if (my_strequ(tmp->name, name))
			return (tmp);
		tmp = tmp->next;
	}

	return (NULL);
}
