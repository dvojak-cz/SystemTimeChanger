#include "WhiteListCaps.h"
#include <stddef.h>

int WhiteListCapabilities( const cap_value_t whiteList[] , int len )
{
	cap_t caps = cap_get_proc();
	if ( caps == NULL ||
		 cap_clear_flag( caps , CAP_PERMITTED ) != 0 ||
		 cap_clear_flag( caps , CAP_INHERITABLE ) != 0 ||
		 cap_clear_flag( caps , CAP_EFFECTIVE ) != 0 ||
		 cap_clear_flag( caps , CAP_EFFECTIVE ) != 0 ||
		 !( len == 0 || cap_set_flag( caps , CAP_PERMITTED , len , whiteList , CAP_SET ) == 0 ) ||
		 !( len == 0 || cap_set_flag( caps , CAP_EFFECTIVE , len , whiteList , CAP_SET ) == 0 ) ||
		 cap_set_proc( caps ) != 0 ||
		 cap_free( caps ) != 0 )
	{
		cap_free( caps );
		return 1;
	}
	return 0;
}
