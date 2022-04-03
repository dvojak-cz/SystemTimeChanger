#include <sys/time.h>
#include <stdlib.h>
#include "WhiteListCaps.h"

int stringIsZero( const char* str1 )
{ return str1[0] == '0' && str1[1] == 0; }

int main( int argc , const char* argv[] )
{
	cap_value_t whiteList = {CAP_SYS_TIME};
	if ( WhiteListCapabilities(&whiteList, 1) != 0 )
	{ return 4; }
	if ( argc != 2 )
	{ return 1; }
	long seconds = atol( argv[1] );
	if ( seconds == 0 && !stringIsZero( argv[1] ))
	{ return 1; }

	struct timeval newTs;
	newTs.tv_sec = seconds;
	newTs.tv_usec = 0;

	if ( settimeofday( &newTs , NULL) != 0)
	{ return 3; }
	return 0;
}
