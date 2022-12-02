#pragma once

#include <TXLib.h>
#include <stdlib.h>

inline COLORREF int_to_colour(int value)
{
	switch (value)
	{
	case 1:
		return TX_BLUE;
		break;
	case 2:
		return TX_GREEN;
		break;
	case 3:
		return TX_RED;
		break;
	case 4:
		return TX_CYAN;
		break;
	case 5:
		return TX_MAGENTA;
		break;
	case 6:
		return TX_BROWN;
		break;
	case 7:
		return TX_ORANGE;
		break;
	case 8:
		return TX_GRAY;
		break;
	case 9:
		return TX_PINK;
		break;
	case 10:
		return TX_YELLOW;
		break;
	default:
		return TX_WHITE;
	}

}

inline void inttostr(int value, char* str)
{
	int size = 0;
	int temp = value;

	while (temp != 0)
	{
		temp = temp / 10;
		++size;
	}

	if (value < 0)
	{
		str[0] = '-';
		++size;
		value = -value;
	}

	str[size] = '\0';
	while (value != 0)
	{
		str[size - 1] = '0' + value % 10;
		value = value / 10;
		--size;
	}
}

class Drawable
{
	virtual void Show(HDC dc) = 0;
};