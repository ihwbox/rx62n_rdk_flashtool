/*""FILE COMMENT""*******************************************************
* System Name	: BSC API for RX62N
* File Name		: r_pdl_bsc_RX62Nxx.h
* Version		: 0.10
* Contents		: BSC API header
* Customer		: 
* Model			: 
* Order			: 
* CPU			: RX600
* Compiler		: RXC
* OS			: Nothing
* Programmer	: 
* Note			: 
************************************************************************
* Copyright,2010 RENESAS ELECTRONICS CORPORATION
* AND RENESAS SOLUTIONS CORPORATION
************************************************************************
* History		: 2010.04.09
*				: Ver 0.10
*""FILE COMMENT END""**************************************************/

#ifndef R_PDL_BSC_RX62Nxx_H
#define R_PDL_BSC_RX62Nxx_H

#define BSC_AREAS	8

/* Callback function storage */
extern VoidCallBackFunc rpdl_BSC_callback_func;

/* Library prototypes */
bool R_BSC_CreateAll(
	const uint32_t,
	const uint32_t,
	const uint8_t,
	VoidCallBackFunc const,
	const uint8_t
);
bool R_BSC_CreateAreaAll(
	const uint8_t,
	const uint16_t,
	const uint8_t,
	const uint8_t,
	const uint8_t,
	const uint8_t,
	const uint8_t,
	const uint8_t,
	const uint8_t,
	const uint8_t,
	const uint8_t,
	const uint8_t,
	const uint8_t,
	const uint8_t,
	const uint8_t
);
bool R_BSC_SDRAM_CreateAreaAll(
	const uint16_t,
	const uint16_t,
	const uint8_t,
	const uint8_t,
	const uint8_t,
	const uint8_t,
	const uint8_t,
	const uint8_t,
	const uint8_t,
	const uint8_t,
	const uint8_t,
	const uint16_t
);
bool R_BSC_DestroyAll(
	const uint8_t
);
bool R_BSC_ControlAll(
	const uint16_t
);
bool R_BSC_GetStatusAll(
	volatile uint8_t * const,
	volatile uint16_t * const,
	volatile uint8_t * const
);
bool ReturnFalse(void);

/* Macro definitions */

#define R_BSC_Create(a, b, c, d, e) \
( \
( (e) <= IPL_MAX ) ? \
R_BSC_CreateAll( (a), (b), (c), (d), (e) ) : \
ReturnFalse() \
)

#define R_BSC_CreateArea(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o) \
( \
( (a) < BSC_AREAS ) ? \
R_BSC_CreateAreaAll( (a), (b), (c), (d), (e), (f), (g), (h), (i), (j), (k), (l), (m), (n), (o) ) : \
ReturnFalse() \
)

#define R_BSC_SDRAM_CreateArea(a, b, c, d, e, f, g, h, i, j, k, l) \
( \
R_BSC_SDRAM_CreateAreaAll( (a), (b), (c), (d), (e), (f), (g), (h), (i), (j), (k), (l) ) \
)

#define R_BSC_Destroy(a) \
( \
( (a) < BSC_AREAS ) ? \
R_BSC_DestroyAll( (a) ) : \
ReturnFalse() \
)

#define R_BSC_Control(a) \
( \
R_BSC_ControlAll( (a) ) \
)

#define R_BSC_GetStatus(a, b, c) \
( \
R_BSC_GetStatusAll( (a), (b), (c) ) \
)

#endif
/* End of file */