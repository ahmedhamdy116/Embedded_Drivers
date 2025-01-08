/*
 * _sev_seg_int.h
 *
 * Created: 11/22/2024 9:17:08 PM
 *  Author: Ahmed
 */ 


#ifndef SEV_SEG_INT_H_
#define SEV_SEG_INT_H_

typedef enum
{
	SevenSegment1,
	SevenSegment2,	
}sev_seg_num_et;

void Turn_on_sev_seg(sev_seg_num_et sev_seg_num);

void Turn_off_sev_seg(sev_seg_num_et sev_seg_num);

void sev_seg_display_two(u8 num);

void sev_seg_display(u8 num);

#endif /* SEV_SEG_INT_H_ */