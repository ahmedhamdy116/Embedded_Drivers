/*
 * DIO_Cfg.c
 *
 * Created: 11/8/2024 9:05:47 PM
 *  Author: Ahmed
 */ 

#include "../Std_Types.h"
#include "../MCAL/DIO_int.h"

const DIO_PIN_Status_t Pins_status[TOTALPINS]={
		OUTPUT,      /* Port A Pin 0 ADC0*/
		OUTPUT,      /* Port A Pin 1 ADC1*/
		OUTPUT,      /* Port A Pin 2 */
		OUTPUT,      /* Port A Pin 3 */
		OUTPUT,      /* Port A Pin 4 */
		OUTPUT,      /* Port A Pin 5 */
		OUTPUT,      /* Port A Pin 6 */
		OUTPUT,      /* Port A Pin 7 ADC7*/
		OUTPUT,      /* Port B Pin 0   / */
		OUTPUT,      /* Port B Pin 1   /*/
		OUTPUT,		 /* Port B Pin 2 / INT2*/
		OUTPUT,		 /* Port B Pin 3   /OC0*/
		OUTPUT,		 /* Port B Pin 4 /ss*/
		OUTPUT,		 /* Port B Pin 5 //mosi*/
		OUTPUT,		 /* Port B Pin 6 /miso*/
		OUTPUT,		 /* Port B Pin 7 clk*/
		OUTPUT,		 /* Port C Pin 0 */
		OUTPUT,		 /* Port C Pin 1 */
		OUTPUT,		 /* Port C Pin 2 */
		OUTPUT,		 /* Port C Pin 3 */
		OUTPUT,		 /* Port C Pin 4 */
		OUTPUT,		 /* Port C Pin 5 */
		OUTPUT,		 /* Port C Pin 6 */
		OUTPUT,		 /* Port C Pin 7 */
		OUTPUT,		 /* Port D Pin 0 RX*/
		OUTPUT,		 /* Port D Pin 1 TX*/
		INPULL,      /* Port D Pin 2 /INT0*/
		INPULL,      /* Port D Pin 3 / INT1 */
		INPULL,		 /* Port D Pin 4  OC1B*/
		INPULL,		 /* Port D Pin 5 OC1A*/
		OUTPUT,		 /* Port D Pin 6 /   ICP*/
		OUTPUT		 /* Port D Pin 7 */
	};