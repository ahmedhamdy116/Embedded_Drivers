#include "Memory_Map.h"
#include "Std_Types.h"
#include "MCAL/DIO_int.h"
#include "SERVICE/delay_int.h"
#include "HAL/LED_int.h"
#include "HAL/Motor_int.h"
#include "HAL/PB_int.h"
#include "HAL/sev_seg_int.h"

#define F_CPU  8000000
#include "util/delay.h"


extern Button_Filter_st Buttons_Charcterstic[4];

int main(void)
{
	DIO_init_all();
	while (1)
	{
		sev_seg_display_two(5);
		_delay_ms(3000);
		sev_seg_display_two(7);
		_delay_ms(3000);
	}
			
	
}

