/*******************************************************************************
Name	: key
Author	: longcd
*******************************************************************************/
#ifndef _KEY_H
#define _KEY_H



typedef enum{
	KEY_ALL_RELEASE		= ((u16)0XFFFF),
	KEY1,
	KEY2,
	KEY3,
	KEY4,
	KEY5
}key_value_t;


void 		key_init(void);
key_value_t	key_getValue(void);


#endif

