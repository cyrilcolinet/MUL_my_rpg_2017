/*
** EPITECH PROJECT, 2018
** lizz_overlay
** File description:
** btn_general functions
*/

# include "utils.h"
# include "debug.h"
# include "lizz.h"

/*
** Détruire tout les composants de la structure btn_t (sprite, texture)
** @param (btn_t *btn) - Bouton à destroy
** @return (void)
*/
void lizz_btn_destroy(btn_t *btn)
{
	if (!btn || !btn->asset)
		return;

	btn->asset->destroy(btn->asset);
}

void lizz_btn_create_asset(btn_t *btn, lizz_t *lizz)
{
	assets_t *tmp = NULL;

	lizz_info("Creation of the texture of the \"");
	lizz_print(1, btn->name);
	lizz_print(1, "\" button...\n");

	if (!btn)
		return;
	if (lizz_assets_create(lizz, btn->name, btn->belongsTo) < 0)
		return;
	tmp = lizz_get_assets(lizz, btn->name, btn->belongsTo);
	if (tmp == NULL) {
		lizz_error("Unable to create asset for button \"");
		lizz_print(1, btn->name);
		lizz_print(1, "\".\n");
		return;
	}
	tmp->is_btn = true;
	btn->asset = tmp;
	btn->sprite = tmp->sprite;
}
