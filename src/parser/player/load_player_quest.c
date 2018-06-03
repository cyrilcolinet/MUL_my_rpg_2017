/*
** EPITECH PROJECT, 2018
** load_player_quest
** File description:
** rpg
*/

#include "rpg.h"

static void configure_pnj_rect(quest_t *quest)
{
	sfVector2f pos = {1408, 864};

	sfSprite_setPosition(quest->pnj[0]->sprite, pos);
	pos.x = 1552;
	pos.y = 136;
	sfSprite_setPosition(quest->pnj[1]->sprite, pos);
	pos.x = 1518;
	pos.y = 952;
	sfSprite_setPosition(quest->pnj[2]->sprite, pos);
}

static void configure_pnj_quest(quest_t *quest)
{
	quest->pnj = malloc(sizeof(pnj_t *) * 4);
	quest->pnj[3] = NULL;
	for (int i = 0; i < 3; i++) {
		quest->pnj[i] = malloc(sizeof(pnj_t));
		quest->pnj[i]->sprite = sfSprite_create();
		quest->pnj[i]->rec.top = 128;
		quest->pnj[i]->rec.left = 0;
		quest->pnj[i]->rec.width = 64;
		quest->pnj[i]->rec.height = 64;
	}
	quest->pnj[0]->rec.top = 64;
	quest->pnj[2]->rec.top = 128;
	configure_pnj_rect(quest);
}

static quest_t *configure_quest(void)
{
	quest_t *quest = malloc(sizeof(quest_t));

	quest->win = sfRectangleShape_create();
	return (quest);
}

void load_player_quest(rpg_t *rpg)
{
	sfVector2f pos = {210, 140};

	rpg->player->quest = configure_quest();
	configure_pnj_quest(rpg->player->quest);
	rpg->player->quest->id = 0;
	sfRectangleShape_setPosition(rpg->player->quest->win, pos);
	pos.x = 1400;
	pos.y = 800;
	sfRectangleShape_setSize(rpg->player->quest->win, pos);
	sfRectangleShape_setFillColor(rpg->player->quest->win, sfWhite);
	rpg->player->quest->pnj[0]->texture = get_texture(rpg, "paysan");
	rpg->player->quest->pnj[1]->texture = get_texture(rpg, "soldat1");
	rpg->player->quest->pnj[2]->texture = get_texture(rpg, "soldat2");
}
