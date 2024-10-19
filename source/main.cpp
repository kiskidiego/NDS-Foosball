#include <nds.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <nds/ndstypes.h>
#include <maxmod9.h>

#include "Controles.h"

#include "soundbank.h"
#include "soundbank_bin.h"

//===========================================================================================================================
//-----------------------------------------------TESELAS---------------------------------------------------------------------
//===========================================================================================================================
u8 t_cesped[64] =
{
	2,2,2,2,2,2,2,2,
	2,2,2,2,2,2,2,2,
	2,2,2,2,2,2,2,2,
	2,2,2,2,2,2,2,2,
	2,2,2,2,2,2,2,2,
	2,2,2,2,2,2,2,2,
	2,2,2,2,2,2,2,2,
	2,2,2,2,2,2,2,2,
};

u8 t_bola00Anim1[64] =
{
	2,2,2,0,0,1,1,1,
	2,2,0,0,0,1,1,1,
	2,0,0,0,0,0,1,1,
	0,0,0,0,0,0,0,0,
	1,1,0,0,0,0,0,0,
	1,1,1,0,0,0,1,1,
	1,1,1,0,0,1,1,1,
	1,1,0,0,0,1,1,1,
};

u8 t_bola01Anim1[64] =
{
	1,1,1,0,0,2,2,2,
	1,1,1,0,0,0,2,2,
	1,1,0,0,0,0,0,2,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,1,1,
	1,1,0,0,0,1,1,1,
	1,1,1,0,0,1,1,1,
	1,1,1,0,0,0,1,1,
};

u8 t_bola10Anim1[64] =
{
	0,0,0,0,0,1,1,1,
	0,0,0,0,0,1,1,1,
	0,0,0,0,0,0,1,1,
	0,0,0,0,0,0,0,0,
	1,1,1,1,0,0,0,0,
	2,1,1,1,1,0,0,0,
	2,2,1,1,1,0,0,0,
	2,2,2,1,1,0,0,0,
};

u8 t_bola11Anim1[64] =
{
	1,1,1,0,0,0,0,0,
	1,1,1,0,0,0,0,0,
	1,1,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	0,0,0,0,1,1,1,1,
	0,0,0,1,1,1,1,2,
	0,0,0,1,1,1,2,2,
	0,0,0,1,1,2,2,2,
};


u8 t_bola00Anim2[64] =
{
	2,2,2,1,1,1,0,0,
	2,2,1,1,1,1,0,0,
	2,1,1,1,1,1,0,0,
	0,0,1,1,1,0,0,0,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,1,1,
	0,0,0,0,0,1,1,1,
	0,0,0,0,0,1,1,1,
};

u8 t_bola01Anim2[64] =
{
	0,0,1,1,1,2,2,2,
	0,0,1,1,1,1,2,2,
	0,0,1,1,1,1,1,2,
	0,0,0,1,1,1,0,0,
	0,0,0,0,0,0,0,0,
	1,1,0,0,0,0,0,0,
	1,1,1,0,0,0,0,0,
	1,1,1,0,0,0,0,0,
};

u8 t_bola10Anim2[64] =
{
	1,1,0,0,0,1,1,1,
	1,1,1,0,0,1,1,1,
	1,1,1,0,0,0,1,1,
	1,1,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	2,0,0,0,0,0,1,1,
	2,2,0,0,0,1,1,1,
	2,2,2,0,0,1,1,1,
};

u8 t_bola11Anim2[64] =
{
	1,1,1,0,0,0,1,1,
	1,1,1,0,0,1,1,1,
	1,1,0,0,0,1,1,1,
	0,0,0,0,0,0,1,1,
	0,0,0,0,0,0,0,0,
	1,1,0,0,0,0,0,2,
	1,1,1,0,0,0,2,2,
	1,1,1,0,0,2,2,2,
};

u8 t_lineahorizontal[64] =
{
	2,2,2,2,2,2,2,2,
	2,2,2,2,2,2,2,2,
	2,2,2,2,2,2,2,2,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	2,2,2,2,2,2,2,2,
	2,2,2,2,2,2,2,2,
	2,2,2,2,2,2,2,2,
};

u8 t_lineavertical[64] =
{
	2,2,2,0,0,2,2,2,
	2,2,2,0,0,2,2,2,
	2,2,2,0,0,2,2,2,
	2,2,2,0,0,2,2,2,
	2,2,2,0,0,2,2,2,
	2,2,2,0,0,2,2,2,
	2,2,2,0,0,2,2,2,
	2,2,2,0,0,2,2,2,
};

u8 t_esquina1[64] =
{
	2,2,2,2,2,2,2,2,
	2,2,2,2,2,2,2,2,
	2,2,2,2,2,2,2,2,
	2,2,2,0,0,0,0,0,
	2,2,2,0,0,0,0,0,
	2,2,2,0,0,2,2,2,
	2,2,2,0,0,2,2,2,
	2,2,2,0,0,2,2,2,
};

u8 t_esquina2[64] =
{
	2,2,2,2,2,2,2,2,
	2,2,2,2,2,2,2,2,
	2,2,2,2,2,2,2,2,
	0,0,0,0,0,2,2,2,
	0,0,0,0,0,2,2,2,
	2,2,2,0,0,2,2,2,
	2,2,2,0,0,2,2,2,
	2,2,2,0,0,2,2,2,
};

u8 t_esquina3[64] =
{
	2,2,2,0,0,2,2,2,
	2,2,2,0,0,2,2,2,
	2,2,2,0,0,2,2,2,
	2,2,2,0,0,0,0,0,
	2,2,2,0,0,0,0,0,
	2,2,2,2,2,2,2,2,
	2,2,2,2,2,2,2,2,
	2,2,2,2,2,2,2,2,
};

u8 t_esquina4[64] =
{
	2,2,2,0,0,2,2,2,
	2,2,2,0,0,2,2,2,
	2,2,2,0,0,2,2,2,
	0,0,0,0,0,2,2,2,
	0,0,0,0,0,2,2,2,
	2,2,2,2,2,2,2,2,
	2,2,2,2,2,2,2,2,
	2,2,2,2,2,2,2,2,
};

u8 t_tetris1[64] =
{
	2,2,2,0,0,2,2,2,
	2,2,2,0,0,2,2,2,
	2,2,2,0,0,2,2,2,
	2,2,2,0,0,0,0,0,
	2,2,2,0,0,0,0,0,
	2,2,2,0,0,2,2,2,
	2,2,2,0,0,2,2,2,
	2,2,2,0,0,2,2,2,
};

u8 t_tetris2[64] =
{
	2,2,2,2,2,2,2,2,
	2,2,2,2,2,2,2,2,
	2,2,2,2,2,2,2,2,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	2,2,2,0,0,2,2,2,
	2,2,2,0,0,2,2,2,
	2,2,2,0,0,2,2,2,
};

u8 t_tetris3[64] =
{
	2,2,2,0,0,2,2,2,
	2,2,2,0,0,2,2,2,
	2,2,2,0,0,2,2,2,
	0,0,0,0,0,2,2,2,
	0,0,0,0,0,2,2,2,
	2,2,2,0,0,2,2,2,
	2,2,2,0,0,2,2,2,
	2,2,2,0,0,2,2,2,
};

u8 t_tetris4[64] =
{
	2,2,2,0,0,2,2,2,
	2,2,2,0,0,2,2,2,
	2,2,2,0,0,2,2,2,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	2,2,2,2,2,2,2,2,
	2,2,2,2,2,2,2,2,
	2,2,2,2,2,2,2,2,
};

u8 t_cruz[64] =
{
	2,2,2,0,0,2,2,2,
	2,2,2,0,0,2,2,2,
	2,2,2,0,0,2,2,2,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	2,2,2,0,0,2,2,2,
	2,2,2,0,0,2,2,2,
	2,2,2,0,0,2,2,2,
};

u8 t_palo[64] =
{
	2,2,2,1,1,2,2,2,
	2,2,2,1,1,2,2,2,
	2,2,2,1,1,2,2,2,
	2,2,2,1,1,2,2,2,
	2,2,2,1,1,2,2,2,
	2,2,2,1,1,2,2,2,
	2,2,2,1,1,2,2,2,
	2,2,2,1,1,2,2,2,
};

u8 t_paloCruzado[64] =
{
	2,2,2,1,1,2,2,2,
	2,2,2,1,1,2,2,2,
	2,2,2,1,1,2,2,2,
	0,0,0,1,1,0,0,0,
	0,0,0,1,1,0,0,0,
	2,2,2,1,1,2,2,2,
	2,2,2,1,1,2,2,2,
	2,2,2,1,1,2,2,2,
};

u8 t_jugador1[64] =
{
	2,2,2,1,1,2,2,2,
	2,2,3,3,3,3,2,2,
	2,3,3,3,3,3,3,2,
	2,3,3,3,3,3,3,2,
	2,3,3,3,3,3,3,2,
	2,3,3,3,3,3,3,2,
	2,2,3,3,3,3,2,2,
	2,2,2,1,1,2,2,2,
};

u8 t_jugador2[64] =
{
	2,2,2,1,1,2,2,2,
	2,2,4,4,4,4,2,2,
	2,4,4,4,4,4,4,2,
	2,4,4,4,4,4,4,2,
	2,4,4,4,4,4,4,2,
	2,4,4,4,4,4,4,2,
	2,2,4,4,4,4,2,2,
	2,2,2,1,1,2,2,2,
};

u8 t_jugador1Cruzado[64] =
{
	2,2,2,1,1,2,2,2,
	2,2,3,3,3,3,2,2,
	2,3,3,3,3,3,3,2,
	0,3,3,3,3,3,3,0,
	0,3,3,3,3,3,3,0,
	2,3,3,3,3,3,3,2,
	2,2,3,3,3,3,2,2,
	2,2,2,1,1,2,2,2,
};

u8 t_jugador2Cruzado[64] =
{
	2,2,2,1,1,2,2,2,
	2,2,4,4,4,4,2,2,
	2,4,4,4,4,4,4,2,
	0,4,4,4,4,4,4,0,
	0,4,4,4,4,4,4,0,
	2,4,4,4,4,4,4,2,
	2,2,4,4,4,4,2,2,
	2,2,2,1,1,2,2,2,
};

u8 t_jugador1Chutando0[64] =
{
	2,2,2,1,1,2,2,2,
	2,3,3,3,3,0,0,0,
	3,3,3,3,3,3,0,0,
	3,3,3,3,3,3,0,0,
	3,3,3,3,3,3,0,0,
	3,3,3,3,3,3,0,0,
	2,3,3,3,3,0,0,0,
	2,2,2,1,1,2,2,2,
};

u8 t_jugador2Chutando0[64] =
{
	2,2,2,1,1,2,2,2,
	1,1,1,4,4,4,4,2,
	1,1,4,4,4,4,4,4,
	1,1,4,4,4,4,4,4,
	1,1,4,4,4,4,4,4,
	1,1,4,4,4,4,4,4,
	1,1,1,4,4,4,4,2,
	2,2,2,1,1,2,2,2,
};

u8 t_jugador1Chutando1[64] =
{
	2,2,2,2,2,2,2,2,
	2,2,2,2,2,2,2,2,
	0,0,0,0,0,3,3,3,
	0,0,0,0,0,3,3,3,
	0,0,0,0,0,3,3,3,
	0,0,0,0,0,3,3,3,
	2,2,2,2,2,2,2,2,
	2,2,2,2,2,2,2,2,
};

u8 t_jugador2Chutando1[64] =
{
	2,2,2,2,2,2,2,2,
	2,2,2,2,2,2,2,2,
	4,4,4,1,1,1,1,1,
	4,4,4,1,1,1,1,1,
	4,4,4,1,1,1,1,1,
	4,4,4,1,1,1,1,1,
	2,2,2,2,2,2,2,2,
	2,2,2,2,2,2,2,2,
};

u8 t_boostDerecha[64] =
{
	5,5,5,5,5,5,5,5,
	5,3,4,3,4,5,5,5,
	5,5,3,4,3,4,5,5,
	5,5,5,3,4,3,4,5,
	5,5,5,3,4,3,4,5,
	5,5,3,4,3,4,5,5,
	5,3,4,3,4,5,5,5,
	5,5,5,5,5,5,5,5,
};

u8 t_boostIzquierda[64] =
{
	5,5,5,5,5,5,5,5,
	5,5,5,4,3,4,3,5,
	5,5,4,3,4,3,5,5,
	5,4,3,4,3,5,5,5,
	5,4,3,4,3,5,5,5,
	5,5,4,3,4,3,5,5,
	5,5,5,4,3,4,3,5,
	5,5,5,5,5,5,5,5,
};

u8 t_boostBouncy[64] =
{
	5,5,5,5,5,5,5,5,
	5,5,4,3,3,4,5,5,
	5,4,3,4,4,3,4,5,
	5,3,4,3,3,4,3,5,
	5,3,4,3,3,4,3,5,
	5,4,3,4,4,3,4,5,
	5,5,4,3,3,4,5,5,
	5,5,5,5,5,5,5,5,
};

u8 t_boostChute[64] =
{
	5,5,5,5,5,5,5,5,
	5,3,4,5,5,3,4,5,
	5,4,3,4,3,4,3,5,
	5,5,4,3,4,3,5,5,
	5,5,3,4,3,4,5,5,
	5,3,4,3,4,3,4,5,
	5,4,3,5,5,4,3,5,
	5,5,5,5,5,5,5,5,
};
//===================================================================================================================



u16 mapData[2080] =		//Campo
{
	3,1,1,1,21,1,1,1, 1,1,1,1,21,1,1,1, 1,1,1,1,21,1,1,1, 1,1,1,1,1,1,1,1, 8, 1,1,1,1,1,1,1,1, 1,1,1,21,1,1,1,1, 1,1,1,21,1,1,1,1, 1,1,1,21,1,1,1,4,
	2,0,0,0,20,0,0,0, 0,0,0,0,20,0,0,0, 0,0,0,0,20,0,0,0, 0,0,0,0,0,0,0,0, 2, 0,0,0,0,0,0,0,0, 0,0,0,20,0,0,0,0, 0,0,0,20,0,0,0,0, 0,0,0,20,0,0,0,2,
	2,0,0,0,20,0,0,0, 0,0,0,0,20,0,0,0, 0,0,0,0,20,0,0,0, 0,0,0,0,0,0,0,0, 2, 0,0,0,0,0,0,0,0, 0,0,0,20,0,0,0,0, 0,0,0,20,0,0,0,0, 0,0,0,20,0,0,0,2,
	2,0,0,0,20,0,0,0, 0,0,0,0,20,0,0,0, 0,0,0,0,20,0,0,0, 0,0,0,0,0,0,0,0, 2, 0,0,0,0,0,0,0,0, 0,0,0,20,0,0,0,0, 0,0,0,20,0,0,0,0, 0,0,0,20,0,0,0,2,

	2,0,0,0,20,0,0,0, 0,0,0,0,20,0,0,0, 0,0,0,0,20,0,0,0, 0,0,0,0,0,0,0,0, 2, 0,0,0,0,0,0,0,0, 0,0,0,20,0,0,0,0, 0,0,0,20,0,0,0,0, 0,0,0,20,0,0,0,2,
	2,0,0,0,20,0,0,0, 0,0,0,0,20,0,0,0, 0,0,0,0,20,0,0,0, 0,0,0,0,0,0,0,0, 2, 0,0,0,0,0,0,0,0, 0,0,0,20,0,0,0,0, 0,0,0,20,0,0,0,0, 0,0,0,20,0,0,0,2,
	2,0,0,0,20,0,0,0, 0,0,0,0,20,0,0,0, 0,0,0,0,20,0,0,0, 0,0,0,0,0,0,0,0, 2, 0,0,0,0,0,0,0,0, 0,0,0,20,0,0,0,0, 0,0,0,20,0,0,0,0, 0,0,0,20,0,0,0,2,
	2,0,0,0,20,0,0,0, 0,0,0,0,20,0,0,0, 0,0,0,0,20,0,0,0, 0,0,0,0,0,0,0,0, 2, 0,0,0,0,0,0,0,0, 0,0,0,20,0,0,0,0, 0,0,0,20,0,0,0,0, 0,0,0,20,0,0,0,2,

	7,1,1,1,21,1,1,1, 1,1,4,0,20,0,0,0, 0,0,0,0,20,0,0,0, 0,0,0,0,0,0,0,0, 2, 0,0,0,0,0,0,0,0, 0,0,0,20,0,0,0,0, 0,0,0,20,0,3,1,1, 1,1,1,21,1,1,1,9,
	2,0,0,0,20,0,0,0, 0,0,2,0,20,0,0,0, 0,0,0,0,20,0,0,0, 0,0,0,0,0,0,0,0, 2, 0,0,0,0,0,0,0,0, 0,0,0,20,0,0,0,0, 0,0,0,20,0,2,0,0, 0,0,0,20,0,0,0,2,
	2,0,0,0,20,0,0,0, 0,0,2,0,20,0,0,0, 0,0,0,0,20,0,0,0, 0,0,0,0,0,0,0,0, 2, 0,0,0,0,0,0,0,0, 0,0,0,20,0,0,0,0, 0,0,0,20,0,2,0,0, 0,0,0,20,0,0,0,2,
	10,1,1,4,20,0,0,0, 0,0,2,0,20,0,0,0, 0,0,0,0,20,0,0,0, 0,0,0,0,0,0,0,0, 2, 0,0,0,0,0,0,0,0, 0,0,0,20,0,0,0,0, 0,0,0,20,0,2,0,0, 0,0,0,20,3,1,1,10,

	0,0,0,2,20,0,0,0, 0,0,7,1,21,1,1,4, 0,0,0,0,20,0,0,0, 0,0,0,0,3,1,1,1, 11, 1,1,1,4,0,0,0,0, 0,0,0,20,0,0,0,0, 3,1,1,21,1,9,0,0, 0,0,0,20,2,0,0,0,
	0,0,0,2,20,0,0,0, 0,0,2,0,20,0,0,2, 0,0,0,0,20,0,0,0, 0,0,0,0,2,0,0,0, 2, 0,0,0,2,0,0,0,0, 0,0,0,20,0,0,0,0, 2,0,0,20,0,2,0,0, 0,0,0,20,2,0,0,0,
	0,0,0,2,20,0,0,0, 0,0,2,0,20,0,0,2, 0,0,0,0,20,0,0,0, 0,0,0,0,2,0,0,0, 2, 0,0,0,2,0,0,0,0, 0,0,0,20,0,0,0,0, 2,0,0,20,0,2,0,0, 0,0,0,20,2,0,0,0,
	0,0,0,2,20,0,0,0, 0,0,2,0,20,0,0,2, 0,0,0,0,20,0,0,0, 0,0,0,0,2,0,0,0, 2, 0,0,0,2,0,0,0,0, 0,0,0,20,0,0,0,0, 2,0,0,20,0,2,0,0, 0,0,0,20,2,0,0,0,

	0,0,0,2,20,0,0,0, 0,0,2,0,20,0,0,2, 0,0,0,0,20,0,0,0, 0,0,0,0,2,0,0,0, 2, 0,0,0,2,0,0,0,0, 0,0,0,20,0,0,0,0, 2,0,0,20,0,2,0,0, 0,0,0,20,2,0,0,0,
	0,0,0,2,20,0,0,0, 0,0,2,0,20,0,0,2, 0,0,0,0,20,0,0,0, 0,0,0,0,2,0,0,0, 2, 0,0,0,2,0,0,0,0, 0,0,0,20,0,0,0,0, 2,0,0,20,0,2,0,0, 0,0,0,20,2,0,0,0,
	0,0,0,2,20,0,0,0, 0,0,2,0,20,0,0,2, 0,0,0,0,20,0,0,0, 0,0,0,0,2,0,0,0, 2, 0,0,0,2,0,0,0,0, 0,0,0,20,0,0,0,0, 2,0,0,20,0,2,0,0, 0,0,0,20,2,0,0,0,
	0,0,0,2,20,0,0,0, 0,0,7,1,21,1,1,6, 0,0,0,0,20,0,0,0, 0,0,0,0,5,1,1,1, 11, 1,1,1,6,0,0,0,0, 0,0,0,20,0,0,0,0, 5,1,1,21,1,9,0,0, 0,0,0,20,2,0,0,0,

	8,1,1,6,20,0,0,0, 0,0,2,0,20,0,0,0, 0,0,0,0,20,0,0,0, 0,0,0,0,0,0,0,0, 2, 0,0,0,0,0,0,0,0, 0,0,0,20,0,0,0,0, 0,0,0,20,0,2,0,0, 0,0,0,20,5,1,1,8,
	2,0,0,0,20,0,0,0, 0,0,2,0,20,0,0,0, 0,0,0,0,20,0,0,0, 0,0,0,0,0,0,0,0, 2, 0,0,0,0,0,0,0,0, 0,0,0,20,0,0,0,0, 0,0,0,20,0,2,0,0, 0,0,0,20,0,0,0,2,
	2,0,0,0,20,0,0,0, 0,0,2,0,20,0,0,0, 0,0,0,0,20,0,0,0, 0,0,0,0,0,0,0,0, 2, 0,0,0,0,0,0,0,0, 0,0,0,20,0,0,0,0, 0,0,0,20,0,2,0,0, 0,0,0,20,0,0,0,2,
	7,1,1,1,21,1,1,1, 1,1,6,0,20,0,0,0, 0,0,0,0,20,0,0,0, 0,0,0,0,0,0,0,0, 2, 0,0,0,0,0,0,0,0, 0,0,0,20,0,0,0,0, 0,0,0,20,0,5,1,1, 1,1,1,21,1,1,1,9,

	2,0,0,0,20,0,0,0, 0,0,0,0,20,0,0,0, 0,0,0,0,20,0,0,0, 0,0,0,0,0,0,0,0, 2, 0,0,0,0,0,0,0,0, 0,0,0,20,0,0,0,0, 0,0,0,20,0,0,0,0, 0,0,0,20,0,0,0,2,
	2,0,0,0,20,0,0,0, 0,0,0,0,20,0,0,0, 0,0,0,0,20,0,0,0, 0,0,0,0,0,0,0,0, 2, 0,0,0,0,0,0,0,0, 0,0,0,20,0,0,0,0, 0,0,0,20,0,0,0,0, 0,0,0,20,0,0,0,2,
	2,0,0,0,20,0,0,0, 0,0,0,0,20,0,0,0, 0,0,0,0,20,0,0,0, 0,0,0,0,0,0,0,0, 2, 0,0,0,0,0,0,0,0, 0,0,0,20,0,0,0,0, 0,0,0,20,0,0,0,0, 0,0,0,20,0,0,0,2,
	2,0,0,0,20,0,0,0, 0,0,0,0,20,0,0,0, 0,0,0,0,20,0,0,0, 0,0,0,0,0,0,0,0, 2, 0,0,0,0,0,0,0,0, 0,0,0,20,0,0,0,0, 0,0,0,20,0,0,0,0, 0,0,0,20,0,0,0,2,

	2,0,0,0,20,0,0,0, 0,0,0,0,20,0,0,0, 0,0,0,0,20,0,0,0, 0,0,0,0,0,0,0,0, 2, 0,0,0,0,0,0,0,0, 0,0,0,20,0,0,0,0, 0,0,0,20,0,0,0,0, 0,0,0,20,0,0,0,2,
	2,0,0,0,20,0,0,0, 0,0,0,0,20,0,0,0, 0,0,0,0,20,0,0,0, 0,0,0,0,0,0,0,0, 2, 0,0,0,0,0,0,0,0, 0,0,0,20,0,0,0,0, 0,0,0,20,0,0,0,0, 0,0,0,20,0,0,0,2,
	2,0,0,0,20,0,0,0, 0,0,0,0,20,0,0,0, 0,0,0,0,20,0,0,0, 0,0,0,0,0,0,0,0, 2, 0,0,0,0,0,0,0,0, 0,0,0,20,0,0,0,0, 0,0,0,20,0,0,0,0, 0,0,0,20,0,0,0,2,
	5,1,1,1,21,1,1,1, 1,1,1,1,21,1,1,1, 1,1,1,1,21,1,1,1, 1,1,1,1,1,1,1,1, 10, 1,1,1,1,1,1,1,1, 1,1,1,21,1,1,1,1, 1,1,1,21,1,1,1,1, 1,1,1,21,1,1,1,6,
};

//===============================================================================================
//--------------------------Declaracion de variables globales------------------------------------
//===============================================================================================

//Efectos de sonido
mm_sound_effect gol;
mm_sound_effect bote;
mm_sound_effect navegacion;

//Memoria para las teselas
static u16* mapMemory = (u16*)BG_MAP_RAM(0);
static u8* tileMemory = (u8*)BG_TILE_RAM(1);

//Booleano que controla si cerrar el juego
bool jugando;

//La posicion de la tesela de la esquina superior izquierda de la pantalla en el campo
int posicionXbola;
int posicionYbola;

//Posicion de la bola en la pantalla
int posxbola;
int posybola;

//velocidad de la bola en cada direccion, medido en teselas por segundo
float velx, vely;

//contadores utilizados para mover la bola
int contx;
int conty;

//booleano que controla el estado de animacion de la bola
bool paso;

//booleanos que controlan el sentido del movimiento de la bola
bool directionX;
bool directionY;

//booleanos que indican si cada equipo esta chutando
bool chute1;
bool chute2;

//contadores para controlar elestado de animacion de los jugadores
int contChute1;
int contChute2;

//contadores que controlan cuando aparece cada drop
int timerdrop1;
int timerdrop2;
int timerdrop3;
int timerdrop4;

//cantidad de goles que ha marcado cada equipo
int golesEquipo1;
int golesEquipo2;

//cantidad de goles necesarios para ganar
int golesObjetivo;

//entero que controla el tipo del proximo drop 1
int tipodrop1;

//posicion en la que va a aparecer el proximo drop 1
int xdrop1;
int ydrop1;

//entero que controla el tipo del proximo drop 2
int tipodrop2;

//posicion en la que va a aparecer el proximo drop 2
int xdrop2;
int ydrop2;

//entero que controla el tipo del proximo drop 3
int tipodrop3;

//posicion en la que va a aparecer el proximo drop 3
int xdrop3;
int ydrop3;

//entero que controla el tipo del proximo drop 4
int tipodrop4;

//posicion en la que va a aparecer el proximo drop 4
int xdrop4;
int ydrop4;

//numero que se le multiplica a la veocidad de la bola cada vez que rebota
float rebote;

//contador que controla la duracion del boost "bouncy"
int timerRebote;

//numero que se le suma a la velocidad de la bola cuando se le da una patada
int patada;

//contador que controla la duracion del boost "kicker"
int timerPatada;

//controla el estado de juego: 0 significa dentro de partida, 1 significa en pausa, 2 significa que ha terminado la partida y 3 significa que esta en el menu principal
int estado;

//controla que opcion esta seleccionada en un menu
int seleccion;

//Declaracion de metodos
void ResetearCampo();
void MostrarJugadores();
void MoverJugadoresEquipo1(int);
void MoverJugadoresEquipo2(int);
void ChutarEquipo1();
void ChutarEquipo2();
void MoverBolaX();
void MoverBolaY();
void int_teclas();
void int_t1();
void int_t2();
void ConfigurarInterrupciones();
double closed_interval_rand(double, double);
void GolEquipo1();
void GolEquipo2();
void MostrarDrops();
void ActualizarPantalla();
void iniciarPartida();
void Pausa();
void Continuar();
void Victoria();
void Menu();

class Drops	//los drops que aparecen en el centro del campo, hay de 4 tipos
{
public:
	//cada drop tiene como atributos su posicion y su tipo, que se le pasan como argumento al constructor
	int x;
	int y;
	int tipo;
	Drops(int X, int Y, int Tipo)
	{
		x = X;
		y = Y;
		tipo = Tipo;
		Mostrar();		//despues de crearse un drop, se muestra en pantalla
	}

	//Cada drop tiene un efecto cuando toca la bola, que depende de su tipo
	void Efecto()
	{
		switch (tipo)
		{
		case 30:	//el tipo 30 hace que la bola salga disparada hacia la derecha
			if (velx < 20) velx += 20;
			velx *= 2;
			vely = 0;
			directionX = true;
			break;
		case 31:	//el tipo 30 hace que la bola salga disparada hacia la izquierda
			if (velx < 20) velx += 20;
			velx *= 2;
			vely = 0;
			directionX = false;
			break;
		case 32:	//el tipo 32 hace que la bola gane velocidad al rebotar en vez de perderla, dura 5 segundos
			rebote = 1.5f;
			timerRebote = 5;
			break;
		case 33:	//el tipo 33 hace que la pelota coja mas velocidad al ser chutada, dura 15 segundos
			patada = 25;
			timerPatada = 15;
			break;
		}
		//Al activarse el efecto de un drop este desaparece y aparece otro.
		tipo = (int)closed_interval_rand(30, 33.99);
		x = (int)closed_interval_rand(23, 41.99);
		y = (int)closed_interval_rand(0, 32.99);
	}
	void Mostrar()	//Muestra los drops en pantalla, si es preciso
	{
		if (x >= posicionXbola && x < posicionXbola + 32 && y >= posicionYbola && y < posicionYbola + 32)	//Comprueba que este dentro de la pantalla
		{
			int pos = posybola * 32 + posxbola;
			int posdrop = (y - posicionYbola) * 32 + x - posicionXbola;
			if (pos == posdrop || pos + 1 == posdrop || pos + 32 == posdrop || pos + 33 == posdrop)		//si esta tocando la bola se activa su efecto y se recalcula su posicion
			{
				Efecto();
				posdrop = (y - posicionYbola) * 32 + x - posicionXbola;
			}
			mapMemory[posdrop] = tipo;		//se muestra por pantalla
		}
	}
};

class Jugador
{
	//cada jugador guarda su posicion, la posicion mas alta a la que puede moverse, la posicion mas baja a la que puede moverse y el equipo del que forma
	int x;
	int y;
	int limArriba;
	int limAbajo;
	int equipo;
public: 
	Jugador(int X, int Y, int limA, int limB, int e)	//todos sus atributos se pasan como argumentos al constructor
	{
		x = X;
		y = Y;
		limArriba = limA;
		limAbajo = limB;
		equipo = e;
		mostrar();		//despues de crearse un jugador, se muestra en pantalla
	}
	void mostrar()		//mostrar los jugadores por pantalla si es preciso
	{
		if (x >= posicionXbola && x < posicionXbola + 32 && y >= posicionYbola && y < posicionYbola + 24)		//se comprueba que el jugador esta dentro de la pantalla
		{
			int pos = (y - posicionYbola) * 32 + x - posicionXbola;		//se calcula su posicion en pantalla
			if (chute1 && equipo == 0)		//si el equipo 1 esta chutando y es de equipo 1 se muestra chutando
			{
				mapMemory[pos] = 24;
				mapMemory[pos + 1] = 26;
				mapMemory[pos + 2] = 26;
			}
			else if (chute2 && equipo == 1)		//si el equipo 2 esta chutando y es de equipo 2 se muestra chutando
			{
				mapMemory[pos] = 25;
				mapMemory[pos - 1] = 27;
				mapMemory[pos - 2] = 27;
			}
			else
			{
				if (mapData[y * 65 + x] == 21) mapMemory[pos] = 28 + equipo;	//se muestra el jugador por pantalla con una tesela u otra dependiendo de lo que tenga detras
				else mapMemory[pos] = 22 + equipo;

				if (equipo == 0)
				{
					if ((mapMemory[pos + 1] < 12 || mapMemory[pos + 1] > 19) && (mapMemory[pos + 2] < 12 || mapMemory[pos + 2] > 19))	//si no esta la bola delante del jugador 
					{																													//se pinta el campo enfrente del jugador
						mapMemory[pos + 1] = mapData[y * 65 + x + 1];																	//para quitar las piernas del jugador en 
						mapMemory[pos + 2] = mapData[y * 65 + x + 2];																	//caso de que antes estuviera chutando
					}
				}
				else
				{
					if ((mapMemory[pos - 1] < 12 || mapMemory[pos - 1] > 19) && (mapMemory[pos - 2] < 12 || mapMemory[pos - 2] > 19))	//si no esta la bola delante del jugador 
					{																													//se pinta el campo enfrente del jugador
						mapMemory[pos - 1] = mapData[y * 65 + x - 1];																	//para quitar las piernas del jugador en 
						mapMemory[pos - 2] = mapData[y * 65 + x - 2];																	//caso de que antes estuviera chutando
					}
				}
			}
		}
	}
	void mover(int i)	//cambiar la posicion del jugador, i es el numero a sumar a su posicion en y, sera 1 o -1
	{
		if ((i < 0 && y > limArriba) || (i > 0 && y < limAbajo))	//solo se mueve si esta entre sus limites de posicion
		{
			if (x >= posicionXbola && x < posicionXbola + 32 && y >= posicionYbola && y < posicionYbola + 24)	//compreba si el jugador esta en pantalla
			{
				int pos = (y - posicionYbola) * 32 + x - posicionXbola;		//calcula la posicion actual del jugador en pantalla
				if (equipo == 0)
				{
					if ((mapMemory[pos + 1] < 12 || mapMemory[pos + 1] > 19) && (mapMemory[pos + 2] < 12 || mapMemory[pos + 2] > 19))	//si no esta la bola delante del jugador 
					{																													//se pinta el campo enfrente del jugador
						mapMemory[pos + 1] = mapData[y * 65 + x + 1];																	//para quitar las piernas del jugador en 
						mapMemory[pos + 2] = mapData[y * 65 + x + 2];																	//caso de que antes estuviera chutando
					}
				}
				else
				{
					if ((mapMemory[pos - 1] < 12 || mapMemory[pos - 1] > 19) && (mapMemory[pos - 2] < 12 || mapMemory[pos - 2] > 19))	//si no esta la bola delante del jugador 
					{																													//se pinta el campo enfrente del jugador
						mapMemory[pos - 1] = mapData[y * 65 + x - 1];																	//para quitar las piernas del jugador en 
						mapMemory[pos - 2] = mapData[y * 65 + x - 2];																	//caso de que antes estuviera chutando
					}
				}
				mapMemory[pos] = mapData[y * 65 + x];		//se pinta la posicion del jugador con lo que hubiese en el campo
				pos = (y - posicionYbola + i) * 32 + x - posicionXbola;		//pos = la nueva posicion del jugador
				int posbola = posybola * 32 + posxbola;		//se calcula la posicion de la bola en pantalla

				//se comprueban las colisiones con la bola
				if (pos == posbola)		//si esta tocando la esquina superior izquierda de la bola la bola sale disparada hacia abajo a la derecha, gana velocidad vertical y se mueve
				{
					vely += patada;
					directionX = true;
					directionY = true;
					MoverBolaY();
				}
				if (pos == posbola + 1)	//si esta tocando la esquina superior derecha de la bola la bola sale disparada hacia abajo a la izquierda, gana velocidad vertical y se mueve
				{
					vely += patada;
					directionX = false;
					directionY = true;
					MoverBolaY();
				}
				if (pos == posbola + 32)//si esta tocando la esquina inferior izquierda de la bola la bola sale disparada hacia arriba a la derecha, gana velocidad vertical y se mueve
				{
					vely += patada;
					directionX = true;
					directionY = false;
					MoverBolaY();
				}
				if (pos == posbola + 33)//si esta tocando la esquina inferior derecha de la bola la bola sale disparada hacia arriba a la izquierda, gana velocidad vertical y se mueve
				{
					vely += patada;
					directionX = false;
					directionY = false;
					MoverBolaY();
				}
			}
			y += i;		//se cambia la posicion del jugador
			mostrar();	//se muestra por pantalla
		}
	}
	void chutar()	
	{
		if (x >= posicionXbola && x < posicionXbola + 32 && y >= posicionYbola && y < posicionYbola + 24)	//Comprueba que el jugador este en pantalla
		{
			mostrar();	//se muestra por pantalla
			if ((chute1 && equipo == 0) || (chute2 && equipo == 1))	//si esta chutando
			{
				int pos = (y - posicionYbola) * 32 + x - posicionXbola;	//calcula su posicion
				int posbola = posybola * 32 + posxbola;					//calcula la posicion de la bola
				if (equipo == 0)	//si es del equipo 1
				{
					
					if (pos + 2 == posbola || pos + 1 == posbola || pos + 33 == posbola || pos + 34 == posbola)		//si le pega a la bola por arriba
					{
						mmEffectEx(&bote);		//suena el efecto de rebote de la bola
						directionX = true;		//la bola sale disparada hacia abajo a la derecha
						directionY = true;
						velx += patada;			//se aumenta la velocidad de la bola
						vely += patada;
						MoverBolaX();			//se mueve la bola
					}
					else if (pos + 2 == posbola + 32 || pos + 1 == posbola + 32 || pos - 31 == posbola + 32 || pos - 30 == posbola + 32)	//si le pega a la bola por abajo
					{
						mmEffectEx(&bote);		//suena el efecto de rebote de la bola
						directionX = true;		//la bola sale disparada hacia arriba a la derecha
						directionY = false;
						velx += patada;			//se aumenta la velocidad de la bola
						vely += patada;
						MoverBolaX();			//se mueve la bola
					}
				}
				else			//si es del equipo 2
				{
					
					if (pos - 2 == posbola + 1 || pos - 1 == posbola + 1 || pos + 31 == posbola + 1 || pos + 30 == posbola + 1)		//si le pega a la bola por arriba
					{
						mmEffectEx(&bote);		//suena el efecto de rebote de la bola
						directionX = false;		//la bola sale disparada hacia abajo a la izquierda
						directionY = true;
						velx += patada;			//se aumenta la velocidad de la bola
						vely += patada;
						MoverBolaX();			//se mueve la bola
					}
					else if (pos - 2 == posbola + 33 || pos - 1 == posbola + 33 || pos - 33 == posbola + 33 || pos - 34 == posbola + 33)		//si le pega a la bola por abajo
					{
						mmEffectEx(&bote);		//suena el efecto de rebote de la bola
						directionX = false;		//la bola sale disparada hacia arriba a la izquierda
						directionY = false;
						velx += patada;			//se aumenta la velocidad de la bola
						vely += patada;
						MoverBolaX();			//se mueve la bola
					}
				}
			}
		}
	}
};

//Declaracion de los drops
Drops* drop1;
Drops* drop2;
Drops* drop3;
Drops* drop4;

//Declaracion de los jugadores
Jugador * jugador1Equipo1;
Jugador * jugador2Equipo1;
Jugador * jugador3Equipo1;
Jugador * jugador4Equipo1;
Jugador * jugador5Equipo1;
Jugador * jugador6Equipo1;
Jugador * jugador7Equipo1;
Jugador * jugador8Equipo1;

Jugador * jugador1Equipo2;
Jugador * jugador2Equipo2;
Jugador * jugador3Equipo2;
Jugador * jugador4Equipo2;
Jugador * jugador5Equipo2;
Jugador * jugador6Equipo2;
Jugador * jugador7Equipo2;
Jugador * jugador8Equipo2;

void Victoria(bool equipo)		//Se llama al final de la partida y se le pasa como parametro un booleano que indica el equipo ganador
{
	mmStop();
	mmStart(MOD_SOCCER_KID_BONUS, MM_PLAY_LOOP);	//Reproduce la cancion de victoria

	estado = 2;		//Actualiza el estado del juego
	seleccion = 0;	//cambia la seleccion a 0

	//desactiva los dos timers
	irqDisable(IRQ_TIMER0);
	irqDisable(IRQ_TIMER1);


	if (equipo)		//Se imprime un mensaje conratulando al equipo ganador
		iprintf("\x1b[5;0H    Victoria del equipo Rojo!   ");
	else
		iprintf("\x1b[5;0H    Victoria del equipo Azul!   ");

	//se imprime el menu
	iprintf("\x1b[10;0H        :Volver a jugar:        ");
	iprintf("\x1b[13;0H         Menu principal         ");

	//se borran el resto de lineas
	iprintf("\x1b[6;0H                                ");
	iprintf("\x1b[7;0H                                ");
	iprintf("\x1b[8;0H                                ");
	iprintf("\x1b[9;0H                                ");
	iprintf("\x1b[11;0H                                ");
	iprintf("\x1b[12;0H                                ");
	iprintf("\x1b[14;0H                                ");
	iprintf("\x1b[15;0H                                ");
	iprintf("\x1b[16;0H                                ");
	iprintf("\x1b[17;0H                                ");
	iprintf("\x1b[18;0H                                ");
	iprintf("\x1b[19;0H                                ");
	iprintf("\x1b[20;0H                                ");
	iprintf("\x1b[21;0H                                ");
	iprintf("\x1b[22;0H                                ");
	iprintf("\x1b[23;0H                                ");
}

void ResetearCampo()	//Devuelve el campo a su estado original
{
	//Pone la bola en su posicion original
	posicionXbola = 16;
	posicionYbola = 4;
	posxbola = 15;
	posybola = 11;

	//Le da su velocidad original
	velx = 10;
	vely = 0;

	//Resetea los contadores
	contx = 0;
	conty = 50;

	//Resetea el estado de animacion
	paso = true;

	//le da una direccion inicial aleatoriamente
	if (closed_interval_rand(0, 1) > 0.5)
	{
		directionX = false;
	}
	else
	{
		directionX = true;
	}
	directionY = true;

	//Resetea todas las variables a sus valores iniciales
	chute1 = false;
	chute2 = false;
	contChute1 = 0;
	contChute2 = 0;
	rebote = 0.9f;
	timerRebote = 0;
	patada = 10;
	timerPatada = 0;

	//Pinta el campo
	int fila;
	int columna;
	int pos_mapMemory;
	int pos_mapData;

	for (fila = 0; fila < 24; fila++)
		for (columna = 0; columna < 32; columna++)
		{
			pos_mapData = (fila + posicionYbola) * 65 + columna + posicionXbola;
			pos_mapMemory = fila * 32 + columna;
			mapMemory[pos_mapMemory] = mapData[pos_mapData];
		}

	//Pinta la bola
	int pos = posybola * 32 + posxbola;
	mapMemory[pos] = 12;
	mapMemory[pos + 1] = 13;
	mapMemory[pos + 32] = 14;
	mapMemory[pos + 33] = 15;

	//crea los jugadores
	jugador1Equipo1 = new Jugador(4, 12, 0, 23, 0);
	jugador2Equipo1 = new Jugador(4, 19, 8, 31, 0);
	jugador3Equipo1 = new Jugador(12, 8, 0, 16, 0);
	jugador4Equipo1 = new Jugador(12, 23, 15, 31, 0);
	jugador5Equipo1 = new Jugador(20, 6, 0, 12, 0);
	jugador6Equipo1 = new Jugador(20, 12, 6, 18, 0);
	jugador7Equipo1 = new Jugador(20, 19, 13, 25, 0);
	jugador8Equipo1 = new Jugador(20, 25, 19, 31, 0);

	jugador1Equipo2 = new Jugador(60, 12, 0, 23, 1);
	jugador2Equipo2 = new Jugador(60, 19, 8, 31, 1);
	jugador3Equipo2 = new Jugador(52, 8, 0, 16, 1);
	jugador4Equipo2 = new Jugador(52, 23, 15, 31, 1);
	jugador5Equipo2 = new Jugador(44, 6, 0, 12, 1);
	jugador6Equipo2 = new Jugador(44, 12, 6, 18, 1);
	jugador7Equipo2 = new Jugador(44, 19, 13, 25, 1);
	jugador8Equipo2 = new Jugador(44, 25, 19, 31, 1);

	//Crea los drops y les da valores aleatorios
	timerdrop1 = (int)closed_interval_rand(5, 15);
	tipodrop1 = (int)closed_interval_rand(30, 33.99);
	xdrop1 = (int)closed_interval_rand(23, 41.99);
	ydrop1 = (int)closed_interval_rand(0, 32.99);
	drop1 = new Drops(xdrop1, ydrop1, tipodrop1);

	timerdrop1 = (int)closed_interval_rand(5, 15);
	tipodrop1 = (int)closed_interval_rand(30, 33.99);
	xdrop1 = (int)closed_interval_rand(23, 41.99);
	ydrop1 = (int)closed_interval_rand(0, 32.99);

	timerdrop2 = (int)closed_interval_rand(5, 15);
	tipodrop2 = (int)closed_interval_rand(30, 33.99);
	xdrop2 = (int)closed_interval_rand(23, 41.99);
	ydrop2 = (int)closed_interval_rand(0, 32.99);
	drop2 = new Drops(xdrop2, ydrop2, tipodrop2);

	timerdrop2 = (int)closed_interval_rand(5, 15);
	tipodrop2 = (int)closed_interval_rand(30, 33.99);
	xdrop2 = (int)closed_interval_rand(23, 41.99);
	ydrop2 = (int)closed_interval_rand(0, 32.99);

	timerdrop3 = (int)closed_interval_rand(5, 15);
	tipodrop3 = (int)closed_interval_rand(30, 33.99);
	xdrop3 = (int)closed_interval_rand(23, 41.99);
	ydrop3 = (int)closed_interval_rand(0, 32.99);
	drop3 = new Drops(xdrop3, ydrop3, tipodrop3);

	timerdrop3 = (int)closed_interval_rand(5, 15);
	tipodrop3 = (int)closed_interval_rand(30, 33.99);
	xdrop3 = (int)closed_interval_rand(23, 41.99);
	ydrop3 = (int)closed_interval_rand(0, 32.99);

	timerdrop4 = (int)closed_interval_rand(5, 15);
	tipodrop4 = (int)closed_interval_rand(30, 33.99);
	xdrop4 = (int)closed_interval_rand(23, 41.99);
	ydrop4 = (int)closed_interval_rand(0, 32.99);
	drop4 = new Drops(xdrop4, ydrop4, tipodrop4);

	timerdrop4 = (int)closed_interval_rand(5, 15);
	tipodrop4 = (int)closed_interval_rand(30, 33.99);
	xdrop4 = (int)closed_interval_rand(23, 41.99);
	ydrop4 = (int)closed_interval_rand(0, 32.99);
}

void GolEquipo1()	//Se llama cuando marca el equipo 1
{
	if (golesEquipo1 < golesObjetivo)
	{
		mmEffectEx(&gol);	//suena el efecto de gol
		golesEquipo1++;		//se aumenta el numero de goles del equipo 1
		iprintf("\x1b[4;2H%d", golesEquipo1);	//se imprime por pantalla
		if (golesEquipo1 < golesObjetivo)		//si no se han alcanzado los goles objetivo se resetea el campo
		{
			ResetearCampo();
		}
		else	//Si no, se termina la partida
		{
			Victoria(false);
		}
	}
}

void GolEquipo2()	//Se llama cuando marca el equipo 2
{
	if (golesEquipo2 < golesObjetivo)
	{
		mmEffectEx(&gol);	//suena el efecto de gol
		golesEquipo2++;		//se aumenta el numero de goles del equipo 2
		iprintf("\x1b[4;29H%d", golesEquipo2);	//se imprime por pantalla
		if (golesEquipo2 < golesObjetivo)		//si no se han alcanzado los goles objetivo se resetea el campo
		{
			ResetearCampo();
		}
		else	//Si no, se termina la partida
		{
			Victoria(true);
		}
	}
}

double closed_interval_rand(double x0, double x1)	//Obtener un numero aleatorio entre los dos limites, inclusive
{
	return x0 + (x1 - x0) * rand() / ((double)RAND_MAX);
}

void MostrarJugadores()		//Mostrar todos los jugadores
{
	jugador1Equipo1->mostrar();
	jugador2Equipo1->mostrar();
	jugador3Equipo1->mostrar();
	jugador4Equipo1->mostrar();
	jugador5Equipo1->mostrar();
	jugador6Equipo1->mostrar();
	jugador7Equipo1->mostrar();
	jugador8Equipo1->mostrar();

	jugador1Equipo2->mostrar();
	jugador2Equipo2->mostrar();
	jugador3Equipo2->mostrar();
	jugador4Equipo2->mostrar();
	jugador5Equipo2->mostrar();
	jugador6Equipo2->mostrar();
	jugador7Equipo2->mostrar();
	jugador8Equipo2->mostrar();
}

void MoverJugadoresEquipo1(int i)		//mover los jugadores del equipo 1
{
	jugador1Equipo1->mover(i);
	jugador2Equipo1->mover(i);
	jugador3Equipo1->mover(i);
	jugador4Equipo1->mover(i);
	jugador5Equipo1->mover(i);
	jugador6Equipo1->mover(i);
	jugador7Equipo1->mover(i);
	jugador8Equipo1->mover(i);
}

void MoverJugadoresEquipo2(int i)		//mover los jugadores del equipo 2
{
	jugador1Equipo2->mover(i);
	jugador2Equipo2->mover(i);
	jugador3Equipo2->mover(i);
	jugador4Equipo2->mover(i);
	jugador5Equipo2->mover(i);
	jugador6Equipo2->mover(i);
	jugador7Equipo2->mover(i);
	jugador8Equipo2->mover(i);
}

void ChutarEquipo1()		//los jugadores del equipo 1 chutan
{
	jugador1Equipo1->chutar();
	jugador2Equipo1->chutar();
	jugador3Equipo1->chutar();
	jugador4Equipo1->chutar();
	jugador5Equipo1->chutar();
	jugador6Equipo1->chutar();
	jugador7Equipo1->chutar();
	jugador8Equipo1->chutar();
}

void ChutarEquipo2()		//los jugadores del equipo 2 chutan
{
	jugador1Equipo2->chutar();
	jugador2Equipo2->chutar();
	jugador3Equipo2->chutar();
	jugador4Equipo2->chutar();
	jugador5Equipo2->chutar();
	jugador6Equipo2->chutar();
	jugador7Equipo2->chutar();
	jugador8Equipo2->chutar();
}

void MostrarDrops()		//mostrar todos los drops
{
	drop1->Mostrar();
	drop2->Mostrar();
	drop3->Mostrar();
	drop4->Mostrar();
}

void ActualizarPantalla()		//Actualizar la pantalla
{

	//Pintar el campo
	int pos_mapMemory;
	int pos_mapData;
	for (int fila = 0; fila < 24; fila++)
		for (int columna = 0; columna < 32; columna++)
		{
			pos_mapData = (fila + posicionYbola) * 65 + columna + posicionXbola;
			pos_mapMemory = fila * 32 + columna;
			mapMemory[pos_mapMemory] = mapData[pos_mapData];
		}

	//Pintar la bola
	int pos = posybola * 32 + posxbola;
	if (paso)
	{
		mapMemory[pos] = 12;
		mapMemory[pos + 1] = 13;
		mapMemory[pos + 32] = 14;
		mapMemory[pos + 33] = 15;
	}
	else
	{
		mapMemory[pos] = 16;
		mapMemory[pos + 1] = 17;
		mapMemory[pos + 32] = 18;
		mapMemory[pos + 33] = 19;
	}

	//mostrar los jugadores
	MostrarJugadores();

	//Mostrar los drops
	MostrarDrops();
}

void MoverBolaX()	//Mover la bola en horizontal
{
	paso = !paso;	//Alternar el estado de animacion

	//Dependiendo de directionX mover la bola hacia un lado o hacia otro
	if (directionX)
	{
		if (posicionXbola < 33 && posxbola == 15)	//Si esta dentro de los limites hacer scroll
			posicionXbola++;
		else if (posxbola < 30)		//Si no mover la bola
			posxbola++;
	}
	else
	{
		if (posicionXbola > 0 && posxbola == 15)	//Si esta dentro de los limites hacer scroll
			posicionXbola--;
		else if (posxbola > 0)		//Si no mover la bola
			posxbola--;
	}

	if (posxbola == 0 || posxbola == 30)	//Si esta en el borde de la pantalla
	{
		if (posybola == 11)		//Si esta en la coordenada y de la porteria
		{
			if (posxbola == 0)		//Si esta en la porteria izquierda
			{
				GolEquipo2();		//gol del equipo 2
				return;
			}
			if (posxbola == 30)		//Si esta e la porteria derecha
			{
				GolEquipo1();		//gol del equipo 1
				return;
			}
		}
		else
			mmEffectEx(&bote);	//Si no, reproducir el efecto de sonido de rebotar
		directionX = !directionX;	//cambiar la direccion
		velx *= rebote;
	}
	ActualizarPantalla();
}

void MoverBolaY()
{
	//dependiendo de directionY mover la bola hacia arriba o hacia abajo
	if (directionY)
	{
		if (posicionYbola < 8 && posybola == 11)	//si esta dentro de los limites hacer scroll
			posicionYbola++;
		else if (posybola < 22)		//si no mover la bola
			posybola++;
	}
	else
	{
		if (posicionYbola > 0 && posybola == 11)	//si esta dentro de los limites hacer scroll
			posicionYbola--;
		else if (posybola > 0)		//si no mover la bola
			posybola--;
	}

	if (posybola == 0 || posybola == 22)		//si esta en los bordes del campo
	{
		mmEffectEx(&bote);		//reproducir el rebote
		directionY = !directionY;		//alternar la direccion
		vely *= rebote;		//cambiar la velocidad
	}
	ActualizarPantalla();		//Actualizar la pantalla
}

void Continuar()	//Reanudar la partida
{
	irqEnable(IRQ_TIMER0);		//Activar los timers
	irqEnable(IRQ_TIMER1);
	estado = 0;		//Cambiar el estado a 0
	iprintf("\x1b[5;14H     ");		//borrar el menu de pausa
	iprintf("\x1b[6;11H           ");
	iprintf("\x1b[7;11H           ");
}

void int_teclas()
{
	if (REG_KEYINPUT == 0x03FE)//A
	{
		switch (estado)
		{
		case 0:		//Si esta en partida mueve al equipo 1 hacia arriba
			MoverJugadoresEquipo1(-1);
			break;
		case 1:
			mmEffectEx(&navegacion);	//Si esta en otro estado activa la opcion seleccionada
			if (seleccion == 0)
			{
				Continuar();
			}
			else
			{
				Menu();
			}
			break;
		case 2:
			mmEffectEx(&navegacion);
			if (seleccion == 0)
			{
				iniciarPartida();
			}
			else
			{
				Menu(); 
			}
			break;
		case 3:
			mmEffectEx(&navegacion);
			if (seleccion == 0)
			{
				iniciarPartida();
			}
			else
			{
				jugando = false;
			}
			break;
		}
	}
	
	if (REG_KEYINPUT == 0x03BF)//UP
	{
		switch (estado)
		{
		case 0:		//Si esta en partida mueve al equipo 2 hacia arriba
			MoverJugadoresEquipo2(-1);
			break;
		case 1:		//Si esta en otro estado elige la opcion de arriba
			iprintf("\x1b[6;11H:Continuar:");
			iprintf("\x1b[7;11H Abandonar ");
			seleccion = 0;
			mmEffectEx(&navegacion);
			break;
		case 2:
			iprintf("\x1b[10;8H:Volver a jugar:");
			iprintf("\x1b[13;8H Menu principal ");
			seleccion = 0;
			mmEffectEx(&navegacion);
			break;
		case 3:
			iprintf("\x1b[12;12H:Jugar:");
			iprintf("\x1b[14;12H Salir ");
			seleccion = 0;
			mmEffectEx(&navegacion);
			break;
		}
	}

	if (REG_KEYINPUT == 0x037F)//DOWN
	{
		switch (estado)
		{
		case 0:		//Si esta en partida mueve al equipo 2 hacia abajo
			MoverJugadoresEquipo2(1);
			break;
		case 1:		//Si esta en otro estado elige la opcion de abajo
			iprintf("\x1b[6;11H Continuar ");
			iprintf("\x1b[7;11H:Abandonar:");
			seleccion = 1;
			mmEffectEx(&navegacion);
			break;
		case 2:
			iprintf("\x1b[10;8H Volver a jugar ");
			iprintf("\x1b[13;8H:Menu principal:");
			mmEffectEx(&navegacion);
			seleccion = 1;
			break;
		case 3:
			iprintf("\x1b[12;12H Jugar ");
			iprintf("\x1b[14;12H:Salir:");
			mmEffectEx(&navegacion);
			seleccion = 1;
			break;
		}
	}

	if (REG_KEYINPUT == 0x03F7)//Start
	{
		if (estado == 0)
		{		//si esta en partida, pausa
			mmEffectEx(&navegacion);
			Pausa();
		}
		else if (estado == 1)
		{		//si esta en pausa, reanuda
			mmEffectEx(&navegacion);
			Continuar();
		}
	}

	if (estado == 0)
	{
		if (REG_KEYINPUT == 0x03FD)//B
		{
			MoverJugadoresEquipo1(1);	//Si esta en partida mueve al equipo 1 hacia abajo
		}

		if (REG_KEYINPUT == 0x01FF)//L
		{		//chuta el equipo 1 y comienza el contador
			chute1 = true;
			contChute1 = 20;
			ChutarEquipo1();
		}

		if (REG_KEYINPUT == 0x02FF)//R
		{		//chuta el equipo 2 y comienza el contador
			chute2 = true;
			contChute2 = 20;
			ChutarEquipo2();
		}
	}

	if (estado == 3)		//Si esta en el menu principal
	{
		if (REG_KEYINPUT == 0x03DF && golesObjetivo > 1)//LEFT
		{
			mmEffectEx(&navegacion);	//disminuye el numero de goles objetivo
			golesObjetivo--;
			iprintf("\x1b[20;6HObjetivo: <%d> goles", golesObjetivo);
		}
		if (REG_KEYINPUT == 0x03EF && golesObjetivo < 9)//RIGHT
		{
			mmEffectEx(&navegacion);	//aumenta el numero de goles objetivo
			golesObjetivo++;
			iprintf("\x1b[20;6HObjetivo: <%d> goles", golesObjetivo);
		}
	}
}

void int_t1()	//se llama cada 0,01 segundos
{
	if (velx > 99) velx = 99;	//mantiene 99 teselas por segundo como velocidad maxima
	if (vely > 99) vely = 99;

	if (velx < 1) velx = 1;		//mantiene 1 tesela por segundo como la velocidad minima en horizontal

	if (chute1)		//si el equipo 1 esta chutando
	{
		if (contChute1-- <= 0)		//restar 1 a contChute1, si es 0 dejar de chutar
		{
			chute1 = false;
		}
	}
	if (chute2)		//si el equipo 2 esta chutando
	{
		if (contChute2-- == 0)		//restar 1 a contChute2, si es 0 dejar de chutar
		{
			chute2 = false;
		}
	}
	if (contx++ >= (100 / velx))	//si ha pasado el tiempo necesario
	{
		contx = 0;	//resetear el contador de x

		MoverBolaX();	//mover bola en el sentido correspondiente

		int pos = posybola * 32 + posxbola;	//calcular la posicion de la bola

		if (mapMemory[pos] != 12 && mapMemory[pos] != 16)	//si choca con algo en la esquina superior izquierda
		{
			mmEffectEx(&bote);	//rebota hacia abajo a la derecha
			velx *= rebote;
			vely *= rebote;
			directionX = true;
			directionY = true;
			MoverBolaX();
		}
		else if (mapMemory[pos + 1] != 13 && mapMemory[pos + 1] != 17)	//si choca con algo en la esquina superior derecha
		{
			mmEffectEx(&bote);	//rebota hacia abajo a la izquierda
			velx *= rebote;
			vely *= rebote;
			directionX = false;
			directionY = true;
			MoverBolaX();
		}
		else if (mapMemory[pos + 32] != 14 && mapMemory[pos + 32] != 18)	//si choca con algo en la esquina inferior izquierda
		{
			mmEffectEx(&bote);	//rebota hacia arriba a la derecha
			velx *= rebote;
			vely *= rebote;
			directionX = true;
			directionY = false;
			MoverBolaX();
		}
		else if (mapMemory[pos + 33] != 15 && mapMemory[pos + 33] != 19)	//si choca con algo en la esquina inferior derecha
		{
			mmEffectEx(&bote);	//rebota hacia arriba a la izquierda
			velx *= rebote;
			vely *= rebote;
			directionX = false;
			directionY = false;
			MoverBolaX();
		}
	}
	if (vely != 0)
	{
		if (conty++ >= (100 / vely))	//si ha pasado el tiempo necesario

		{
			conty = 0;	//resetear el contador

			MoverBolaY();	//mover bola en el sentido correspondiente

			int pos = posybola * 32 + posxbola;	//calcular la posicion de la bola

			if (mapMemory[pos] >= 22 && mapMemory[pos] <= 29)	//si choca con algo en la esquina superior izquierda
			{
				mmEffectEx(&bote);	//rebota hacia abajo a la derecha
				velx *= rebote;
				vely *= rebote;
				directionX = true;
				directionY = true;
				MoverBolaY();
			}
			else if (mapMemory[pos + 1] >= 22 && mapMemory[pos + 1] <= 29)	//si choca con algo en la esquina superior derecha
			{
				mmEffectEx(&bote);	//rebota hacia abajo a la izquierda
				velx *= rebote;
				vely *= rebote;
				directionX = false;
				directionY = true;
				MoverBolaY();
			}
			else if (mapMemory[pos + 32] >= 22 && mapMemory[pos + 32] <= 29)	//si choca con algo en la esquina inferior izquierda
			{
				mmEffectEx(&bote);	//rebota hacia arriba a la derecha
				velx *= rebote;
				vely *= rebote;
				directionX = true;
				directionY = false;
				MoverBolaY();
			}
			else if (mapMemory[pos + 33] >= 22 && mapMemory[pos + 33] <= 29)	//si choca con algo en la esquina inferior derecha
			{
				mmEffectEx(&bote);	//rebota hacia arriba a la izquierda
				velx *= rebote;
				vely *= rebote;
				directionX = false;
				directionY = false;
				MoverBolaY();
			}
		}
	}
}

void int_t2()	//se llama cada segundo
{
	//se baja el tiempo que queda para spawnear nuevos drops
	timerdrop1--;
	timerdrop2--;
	timerdrop3--;
	timerdrop4--;

	if (timerRebote > 0)	//si el boost bouncy esta activo
	{
		timerRebote--;		//bajar el temporizador
		iprintf("\x1b[12;12HBouncy: %d ", timerRebote);		//mostrarlo por pantalla
	}
	else	//si no
	{
		rebote = 0.9f;		//devolver rebote a su valor original
		iprintf("\x1b[12;12H           ");	//borrar el mensaje
	}

	if (timerPatada > 0)	//si el boost kicker esta activo
	{
		timerPatada--;		//bajar el temporizador
		iprintf("\x1b[10;12HKicker: %d ", timerPatada);		//mostrarlo por pantalla
	}
	else	//si no
	{
		patada = 10;		//devolver rebote a su valor original
		iprintf("\x1b[10;12H           ");	//borrar el mensaje
	}

	if (timerdrop1 < 0)	//si el timer del drop 1 ha llegado a 0
	{
		drop1 = new Drops(xdrop1, ydrop1, tipodrop1);	//crear el drop

		//Cambiar los valores para el siguiente
		timerdrop1 = (int)closed_interval_rand(5, 15);
		tipodrop1 = (int)closed_interval_rand(30, 33.99);
		xdrop1 = (int)closed_interval_rand(23, 41.99);
		ydrop1 = (int)closed_interval_rand(0, 32.99);
	}
	if (timerdrop2 < 0)	//si el timer del drop 2 ha llegado a 0
	{
		drop2 = new Drops(xdrop2, ydrop2, tipodrop2);	//crear el drop

		//Cambiar los valores para el siguiente
		timerdrop2 = (int)closed_interval_rand(5, 15);
		tipodrop2 = (int)closed_interval_rand(30, 33.99);
		xdrop2 = (int)closed_interval_rand(23, 41.99);
		ydrop2 = (int)closed_interval_rand(0, 32.99);
	}
	if (timerdrop3 < 0)	//si el timer del drop 3 ha llegado a 0
	{
		drop3 = new Drops(xdrop3, ydrop3, tipodrop3);	//crear el drop

		//Cambiar los valores para el siguiente
		timerdrop3 = (int)closed_interval_rand(5, 15);
		tipodrop3 = (int)closed_interval_rand(30, 33.99);
		xdrop3 = (int)closed_interval_rand(23, 41.99);
		ydrop3 = (int)closed_interval_rand(0, 32.99);
	}
	if (timerdrop4 < 0)	//si el timer del drop 4 ha llegado a 0
	{
		drop4 = new Drops(xdrop4, ydrop4, tipodrop4);	//crear el drop

		//Cambiar los valores para el siguiente
		timerdrop4 = (int)closed_interval_rand(5, 15);
		tipodrop4 = (int)closed_interval_rand(30, 33.99);
		xdrop4 = (int)closed_interval_rand(23, 41.99);
		ydrop4 = (int)closed_interval_rand(0, 32.99);
	}

	//Mostrar los timers por pantalla
	iprintf("\x1b[15;2HDrop 1: %d ", timerdrop1);
	iprintf("\x1b[15;21HDrop 2: %d ", timerdrop2);
	iprintf("\x1b[20;2HDrop 3: %d ", timerdrop3);
	iprintf("\x1b[20;21HDrop 4: %d ", timerdrop4);

	//Mostrar los tipos de los siguientes drops
	switch (tipodrop1)
	{
	case 30:
		iprintf("\x1b[17;1HNext:BoostR");
		break;
	case 31:
		iprintf("\x1b[17;1HNext:BoostL");
		break;
	case 32:
		iprintf("\x1b[17;1HNext:Bouncy");
		break;
	case 33:
		iprintf("\x1b[17;1HNext:Kicker");
		break;
	}
	switch (tipodrop2)
	{
	case 30:
		iprintf("\x1b[17;20HNext:BoostR");
		break;
	case 31:
		iprintf("\x1b[17;20HNext:BoostL");
		break;
	case 32:
		iprintf("\x1b[17;20HNext:Bouncy");
		break;
	case 33:
		iprintf("\x1b[17;20HNext:Kicker");
		break;
	}
	switch (tipodrop3)
	{
	case 30:
		iprintf("\x1b[22;1HNext:BoostR");
		break;
	case 31:
		iprintf("\x1b[22;1HNext:BoostL");
		break;
	case 32:
		iprintf("\x1b[22;1HNext:Bouncy");
		break;
	case 33:
		iprintf("\x1b[22;1HNext:Kicker");
		break;
	}
	switch (tipodrop4)
	{
	case 30:
		iprintf("\x1b[22;20HNext:BoostR");
		break;
	case 31:
		iprintf("\x1b[22;20HNext:BoostL");
		break;
	case 32:
		iprintf("\x1b[22;20HNext:Bouncy");
		break;
	case 33:
		iprintf("\x1b[22;20HNext:Kicker");
		break;
	}
}

void ConfigurarInterrupciones()
{
	irqSet(IRQ_KEYS, int_teclas);	//Configurar el metodo de interrupciones de teclas
	irqEnable(IRQ_KEYS);	//activar las interrupciones de teclas
	REG_KEYCNT = 0x43FB;	//configurar el registro de control de interrupciones de teclas
	
	irqSet(IRQ_TIMER0, int_t1);		//configurar el metodo del primer temporizador

	TIMER_CR(0) = TIMER_DIV_1024 | TIMER_ENABLE | TIMER_IRQ_REQ;	//configurar el primer temporizador
	TIMER_DATA(0) = 65536 - 0.01 * (33554432 / 1024);	//darle valor al primer temporizador

	irqSet(IRQ_TIMER1, int_t2);		//configurar el metodo del segundo temporizador

	TIMER_CR(1) = TIMER_DIV_1024 | TIMER_ENABLE | TIMER_IRQ_REQ;	//configurar el segundo temporizador
	TIMER_DATA(1) = 65536 - 1 * (33554432 / 1024);		//darle valor al segundo temporizador
}

void iniciarPartida()
{
	mmStop();
	mmStart(MOD_SOCCER_KID_SMASH, MM_PLAY_LOOP);	//poner la cancion de partida

	//Configurar la pantalla
	REG_POWERCNT = POWER_ALL_2D;
	REG_DISPCNT = MODE_0_2D | DISPLAY_BG0_ACTIVE;
	VRAM_A_CR = VRAM_ENABLE | VRAM_A_MAIN_BG;
	BGCTRL[0] = BG_32x32 | BG_COLOR_256 | BG_MAP_BASE(0) | BG_TILE_BASE(1);

	//borrar la pantalla de arriba
	consoleClear();
	
	//configurar los colores
	BG_PALETTE[0] = RGB15(31, 31, 31); // Blanco
	BG_PALETTE[1] = RGB15(0, 0, 0); // Negro
	BG_PALETTE[2] = RGB15(0, 15, 0); // Verde
	BG_PALETTE[3] = RGB15(0, 0, 31); // Azul
	BG_PALETTE[4] = RGB15(31, 0, 0); // Rojo
	BG_PALETTE[5] = RGB15(15, 15, 31); // Cian

	//guardar las teselas en memoria
	dmaCopy(t_cesped, tileMemory, sizeof(t_cesped));	//cesped

	dmaCopy(t_lineahorizontal, tileMemory + 64, sizeof(t_lineahorizontal));	//cesped con linea horizontal

	dmaCopy(t_lineavertical, tileMemory + 64 * 2, sizeof(t_lineavertical));	//cesped con linea vertical

	//cesped con esquina
	dmaCopy(t_esquina1, tileMemory + 64 * 3, sizeof(t_esquina1));
	dmaCopy(t_esquina2, tileMemory + 64 * 4, sizeof(t_esquina2));
	dmaCopy(t_esquina3, tileMemory + 64 * 5, sizeof(t_esquina3));
	dmaCopy(t_esquina4, tileMemory + 64 * 6, sizeof(t_esquina4));

	//cesped con forma de tetris
	dmaCopy(t_tetris1, tileMemory + 64 * 7, sizeof(t_tetris1));
	dmaCopy(t_tetris2, tileMemory + 64 * 8, sizeof(t_tetris2));
	dmaCopy(t_tetris3, tileMemory + 64 * 9, sizeof(t_tetris3));
	dmaCopy(t_tetris4, tileMemory + 64 * 10, sizeof(t_tetris4));

	//cesped con una cruz
	dmaCopy(t_cruz, tileMemory + 64 * 11, sizeof(t_cruz));

	//bola, estado de animacion 1
	dmaCopy(t_bola00Anim1, tileMemory + 64 * 12, sizeof(t_bola00Anim1));
	dmaCopy(t_bola01Anim1, tileMemory + 64 * 13, sizeof(t_bola01Anim1));
	dmaCopy(t_bola10Anim1, tileMemory + 64 * 14, sizeof(t_bola10Anim1));
	dmaCopy(t_bola11Anim1, tileMemory + 64 * 15, sizeof(t_bola11Anim1));

	//bola, estado de animacion 2
	dmaCopy(t_bola00Anim2, tileMemory + 64 * 16, sizeof(t_bola00Anim2));
	dmaCopy(t_bola01Anim2, tileMemory + 64 * 17, sizeof(t_bola01Anim2));
	dmaCopy(t_bola10Anim2, tileMemory + 64 * 18, sizeof(t_bola10Anim2));
	dmaCopy(t_bola11Anim2, tileMemory + 64 * 19, sizeof(t_bola11Anim2));

	//palo en el que estan los jugadores
	dmaCopy(t_palo, tileMemory + 64 * 20, sizeof(t_palo));

	//palo con linea blanca por detras
	dmaCopy(t_paloCruzado, tileMemory + 64 * 21, sizeof(t_paloCruzado));

	//jugadores
	dmaCopy(t_jugador1, tileMemory + 64 * 22, sizeof(t_jugador1));
	dmaCopy(t_jugador2, tileMemory + 64 * 23, sizeof(t_jugador2));

	//jugadores chutando
	dmaCopy(t_jugador1Chutando0, tileMemory + 64 * 24, sizeof(t_jugador1Chutando0));
	dmaCopy(t_jugador2Chutando0, tileMemory + 64 * 25, sizeof(t_jugador2Chutando0));

	//piernas de los jugadores
	dmaCopy(t_jugador1Chutando1, tileMemory + 64 * 26, sizeof(t_jugador1Chutando1));
	dmaCopy(t_jugador2Chutando1, tileMemory + 64 * 27, sizeof(t_jugador2Chutando1));

	//jugadores con linea blanca por detras
	dmaCopy(t_jugador1Cruzado, tileMemory + 64 * 28, sizeof(t_jugador1Cruzado));
	dmaCopy(t_jugador2Cruzado, tileMemory + 64 * 29, sizeof(t_jugador2Cruzado));

	//drops
	dmaCopy(t_boostDerecha, tileMemory + 64 * 30, sizeof(t_boostDerecha));
	dmaCopy(t_boostIzquierda, tileMemory + 64 * 31, sizeof(t_boostIzquierda));
	dmaCopy(t_boostBouncy, tileMemory + 64 * 32, sizeof(t_boostBouncy));
	dmaCopy(t_boostChute, tileMemory + 64 * 33, sizeof(t_boostChute));

	//activar los temporizadores
	irqEnable(IRQ_TIMER0);
	irqEnable(IRQ_TIMER1);

	//inicializar los goles a 0
	golesEquipo1 = 0;
	golesEquipo2 = 0;

	//cambiar el estado a 0 (jugando una partida)
	estado = 0;

	//imprimir los goles de cada equipo y los goles objetivo en pantalla
	iprintf("\x1b[3;8HObjetivo:%d goles", golesObjetivo);
	iprintf("\x1b[4;2H%d", golesEquipo1);
	iprintf("\x1b[4;29H%d", golesEquipo2);

	ResetearCampo();	//poner todos lo elementos del campo
}

void Pausa()
{
	//desactivar los temporizadores
	irqDisable(IRQ_TIMER0);
	irqDisable(IRQ_TIMER1);

	estado = 1;	//cambiar el estado a 1 (pausa)

	//imprimir el menu de pausa
	iprintf("\x1b[5;14HPAUSA");
	iprintf("\x1b[6;11H:Continuar:");
	iprintf("\x1b[7;11H Abandonar ");

	seleccion = 0;	//poner la seleccion a 0
}

void Menu()
{
	mmStop();
	mmStart(MOD_SPORT_SCREEN_THEME, MM_PLAY_LOOP);	//poner la cancion del menu

	seleccion = 0;	//poner la seleccion a 0

	consoleClear();	//borra la pantalla superior

	golesObjetivo = 1;	//inicializa los goles objetivo a 1

	estado = 3;		//pone el estado a 3

	REG_POWERCNT = POWER_LCD | POWER_2D_A;	//configurar la pantalla inferior
	REG_DISPCNT = MODE_FB0;
	VRAM_A_CR = VRAM_ENABLE | VRAM_A_LCD;

	//imprimir el menu
	iprintf("\x1b[7;9HSUPER FUTBOLIN");
	iprintf("\x1b[12;12H:Jugar:");
	iprintf("\x1b[14;12H Salir ");
	iprintf("\x1b[20;6HObjetivo: <%d> goles", golesObjetivo);

	//poner la imagen de los controles en la pantalla inferior
	dmaCopy(ControlesBitmap, VRAM_A, 256 * 192 * 2);
}

int main(void)
{
	jugando = true;		//inicializa jugando a true

	ConfigurarInterrupciones();	//configurar las interrupciones

	consoleDemoInit();	//iniciar la consola

	mmInitDefaultMem((mm_addr)soundbank_bin);	//iniciar la memoria de musica

	//cargar las canciones
	mmLoad(MOD_SPORT_SCREEN_THEME);
	mmLoad(MOD_SOCCER_KID_SMASH);
	mmLoad(MOD_SOCCER_KID_BONUS);

	//cargar los efectos de sonido
	mmLoadEffect(SFX_GAME_UI_SOUNDS_14857);
	mmLoadEffect(SFX_RETRO_VIDEO_GAME_COIN_PICKUP_38299);
	mmLoadEffect(SFX_SOCCERBALLKICK_6770);

	//poner el volumen
	mmSetModuleVolume(128);

	//asigna los efectos de sonido a sus respectivas variables
	gol = {
		{ SFX_RETRO_VIDEO_GAME_COIN_PICKUP_38299 } ,			// id
		(int)(1.0f * (1 << 10)),	// rate
		0,		// handle
		255,	// volume
		127,		// panning
	};
	bote = {
		{ SFX_SOCCERBALLKICK_6770 } ,			// id
		(int)(1.0f * (1 << 10)),	// rate
		0,		// handle
		255,	// volume
		127,		// panning
	};
	navegacion = {
		{ SFX_GAME_UI_SOUNDS_14857 } ,			// id
		(int)(1.0f * (1 << 10)),	// rate
		0,		// handle
		255,	// volume
		127,	// panning
	};

	Menu();	//inicia el menu

	while (jugando)		//bucle infinito, si jugando == false cierra el juego
	{
		swiWaitForVBlank();
	}
}