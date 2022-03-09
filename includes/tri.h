/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmercadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 13:28:20 by dmercadi          #+#    #+#             */
/*   Updated: 2022/03/08 13:28:21 by dmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRI_H
# define TRI_H

# include "push_swap.h"
# include "moves.h"

void	trier(t_ps *ps);

/*Tri Rapide : diviser pour reigner
	On deplace la moitié de la pile dans la pile opposé.
	Nous trions par recurence les deux piles.
	Nous fusionons les deux piles en choisisant a chaque toutr le plus petit 
	element de la premiere valeur de chaque pile.
	Complexité : C(N) = 3Nlog2(N/3) + N
*/

void	trirapide(t_ps *ps);
void	rectrirapiderightn(t_ps *ps, int n);
void	rectrirapideleftn(t_ps *ps, int n);

/*Tri pivot : Diviser pour reigner mais en mieux
	On choisit une valeur pivot correspondant au "milieu" de toute 
	les valeurs de la pile. La pile est divisé en deux parties contant
	respectivement les valeurs plus grandes
	et plus petites que le pivot.
	On utilise la recurence sur les sous piles.
	Les deux piles sont ensuite fusionnées de facon triviale.
	Complexité : C(N) = (3/2)Nlog2(N/3) + N
*/

void	recpivotright(t_ps *ps, int n, int start);
void	recpivotleft(t_ps *ps, int n, int start);
void	tripivot(t_ps *ps);

/*Tri Double pivot : Tri pivot mais avec deux pivots et trois segments
	On choisit deux pivots separent la pile en 3 * 1/3
	Les trois sous parties contenant les valeurs "grandes" "moyennes" "petites"
	sont stockés en bas de la pile principale, en haut et en bas de la pile opposé
	Une fois la recurence sur chaque partie faite, la partie se positionne au dessus
	de la pile principale (et trié).
	Complexité : C(N)=(10/6)Nlog3(N/3) + N
*/

void	tridoublepivot(t_ps *ps);
void	rec_tridoublepivotleft(t_ps *ps, int n, int start);
void	rec_tridoublepivotrightbot(t_ps *ps, int n, int start);
void	rec_tridoublepivotleftbot(t_ps *ps, int n, int start);
void	rec_tridoublepivotright(t_ps *ps, int n, int start);

/*Tri triple : 
	Tri pivot mais moins performant. Le placement des
	parties "grande"/"moyenne"/"petit" different.
	Utilisation du rrr pour remonter les parties en bas en meme temps
	Complexité : Non calcule.
*/

void	tritriple(t_ps *ps);
void	rec_tritripleright(t_ps *ps, int n, int start);
void	rec_tritripleleft(t_ps *ps, int n, int start);
void	rec_tritripleleftbot(t_ps *ps, int n, int start);
void	rec_tritriplerightbot(t_ps *ps, int n, int start);

/*Tri Simple : Algorithme GLOUTON
	On parcours la pile en swapant l'element en cours avec le suivant
	ssi il est plus grand.
	Complexité : pire cas C(N)=(1/2)(3Nˆ2 - N) = O(N^2)
				 en moyenne C(N)=Nˆ2
*/

void	trisimple(t_ps *ps);
void	trisimple_n(t_ps *ps, int n);

/*Tri Insert : Un autre algorithme GLOUTON
	On deplace de la pile A dans B le plus petit elements N fois.
	La pile B est trié a l'envers.
	On reinsere dans la pile A.
	Complexité : C(N)=(1/8)(Nˆ2 + 9N) en moyenne
*/

void	ft_triinsert(t_ps *ps);
void	insertright_n(t_ps *ps, int n);
void	insertleft_n(t_ps *ps, int n);
void	insertrightnormal_n(t_ps *ps, int n);

#endif
