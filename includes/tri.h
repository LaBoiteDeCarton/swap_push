#ifndef TRI_H
# define TRI_H

#include "push_swap.h"
#include "moves.h"


void	trier(t_ps *ps);

/*Tri Radix : 
	blablabla
	Complexité : 
*/

void	triradix(t_ps *ps);
void	rec_triradixright(t_ps *ps, int n, int start);
void	rec_triradixleft(t_ps *ps, int n, int start);
void	rec_triradixleftbot(t_ps *ps, int n, int start);
void	rec_triradixrightbot(t_ps *ps, int n, int start);

/*Tri Rapide : diviser pour reigner
	On deplace la moitié de la pile dans la pile opposé.
	Nous trions par recurence les deux piles.
	Nous fusionons les deux piles en choisisant a chaque toutr le plus petit 
	element de la premiere valeur de chaque pile.
	Complexité : 2*N*log2(N)
*/

void	trirapide(t_ps *ps);
void	rectrirapiderightn(t_ps *ps, int n);
void	rectrirapideleftn(t_ps *ps, int n);

/*Tri pivot : Diviser pour reigner mais en mieux
	On choisit une valeur pivot correspondant au "milieu" de toute les valeurs de la pile.
	La pile est divisé en deux parties contant respectivement les valeurs plus grandes
	et plus petites que le pivot.
	On utilise la recurence sur les sous piles.
	Les deux piles sont ensuite fusionnées de facon triviale.
	Complexité : Ne me rapel plus
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
	Complexité : 3/2*N*log3(N)
*/

void	tridoublepivot(t_ps *ps);
void	rec_tridoublepivotleft(t_ps *ps, int n, int start);
void	rec_tridoublepivotrightbot(t_ps *ps, int n, int start);
void	rec_tridoublepivotleftbot(t_ps *ps, int n, int start);
void	rec_tridoublepivotright(t_ps *ps, int n, int start);

/*Tri Simple : Algorithme GLOUTON
	On parcours la pile en swapant l'element en cours avec le suivant
	ssi il est plus grand.
	Complexité : O(N^2)
*/
void	trisimple(t_ps *ps);
void	trisimple_n(t_ps *ps, int n);

#endif