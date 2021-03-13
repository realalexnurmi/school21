void	find_cross(float *cross_x, float *cross_y, t_ray *ray, t_player *pl, t_sprite *sp)
{
	float	pl_c;
	float	sp_c;

	sp_c = -1 * (ray->dir_x * sp->x + ray->dir_y * sp->y);
	pl_c = -1 * (sp->dir_x * pl->x + sp->dir_y * pl->y);
	*cross_x = (pl_c - sp_c) / (sp->dir_x - ray->dir_x);
	*cross_y = ray->dir_x * (*cross_x) + pl_c;
}

void	calculate_sprite(t_ray *ray, t_sprite *sprite, t_game_master *gm)
{
	int		middle_sprite_height;
	int		middle_sprite_width;
	int		middle_sprite_texture;

	sprite->height = sprite->texture->height * sprite->size / sprite->dist;
	sprite->height *= (sprite->dist != 0);
	middle_sprite_height = sprite->height / 2;
	sprite->top = ray->horizon - 0 - middle_sprite_height;
	if (sprite->top < 0)
		sprite->top = 0;
	sprite->bot = ray->horizon + 0 + middle_sprite_height;
	if (sprite->bot >= gm->frame->height)
		sprite->bot = gm->frame->height - 1;
	sprite->width = sprite->texture->width * sprite->size / sprite->dist;
	sprite->width *= (sprite->dist != 0);
	sprite->step_x = (float)sprite->texture->width / (float)sprite->width;
	sprite->dir_x = gm->pl->dir_x;
	sprite->dir_y = gm->pl->dir_y;
	rotate_ninety(&sprite->dir_x, &sprite->dir_y, counter_clock);
	find_cross(&sprite->cross_x, &sprite->cross_y, ray, gm->pl, sprite);
	if (ray->ind == 512)
	{
		printf("SPDIRX=% f\tSPDIRY=% f\n", sprite->dir_x, sprite->dir_y);
		printf("SP  X =% f\tSP  Y =% f\n", sprite->x, sprite->y);
		printf("PLDIRX=% f\tPLDIRY=% f\n", gm->pl->dir_x, gm->pl->dir_y);
		printf("PL  X =% f\tPL  Y =% f\n", gm->pl->x, gm->pl->y);
		printf("CROSSX = %f\tCROSSY = %f\n", sprite->cross_x, sprite->cross_y);
		printf("=====\n\n");
	}
	//middle_sprite_texture = sprite->texture->width / 2;
	//sprite->calc_x = (((sprite->x - gm->pl->x) * gm->frame->width) + gm->frame->width / 2) / sprite->step_x * ray->ind % sprite->width                                                                                                                                                                                                                                                                        ;
	//sprite->texture_x = (int)((ray->ind - (-sprite->width / 2 + middle_sprite_width)) * sprite->step_x);
	//sprite->texture_x = sprite->texture->width - sprite->texture_x - 1;
	// sprite->calc_x = gm->frame->width / 2 - middle_sprite_width;
	sprite->texture_x = (int)(sprite->texture->width * sprite->calc_x);
	if (sprite->texture_x >= sprite->texture->width ||  sprite->texture->width < 0)
		sprite->texture_x = - 1;
	sprite->step_y = (float)sprite->texture->height / (float)sprite->height;
	sprite->calc_y = (sprite->top - ray->horizon + sprite->height / 2) * sprite->step_y;
}
