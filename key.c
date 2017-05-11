/*******************************************************************************
Name	: key
Author	: longcd
*******************************************************************************/
#include "type.h"
#include "key.h"

/******************************************************************************/


/******************************************************************************/

typedef enum{
	WAIT_PRESS,
	PRESSING,
	WAIT_RELEASE
}key_status_t;

typedef struct{
	u8	status;
	u16	preValue;
	u8	pressTime;
	u8	releaseTime;
	u16	value;
}key_t;

/******************************************************************************/
key_t	key;

/******************************************************************************/

u16 key_getPressValue(void)
{
	u16	pressValue = KEY_ALL_RELEASE;

	return pressValue;
}


void key_init(void)
{
	key.status = WAIT_PRESS;
	key.value = KEY_ALL_RELEASE;
}

void key_scan(void)
{
	switch(key.status){
	case WAIT_PRESS:
		key.preValue = key_getPressValue();
		if(key.preValue != KEY_ALL_RELEASE){
			key.pressTime = 1;
			key.status = PRESSING;
		}
		break;

	case PRESSING:
		if(key_getPressValue() == key.preValue){
			key.pressTime++;
			if(key.pressTime > 5){
				key.value = key.preValue;
				key.releaseTime = 0;
				key.status = WAIT_RELEASE;
			}
		} else {
			key.status = WAIT_PRESS;
		}
		break;

	case WAIT_RELEASE:
		if(key_getPressValue() == KEY_ALL_RELEASE){
			key.releaseTime++;
			if(key.releaseTime > 5){
				key.status = WAIT_PRESS;
			}
		} else {
			key.releaseTime = 0;
		}
		break;

	default:
		key.status = WAIT_PRESS;
		break;
	}
}

key_value_t key_getValue(void)
{
	return key.value;
}

