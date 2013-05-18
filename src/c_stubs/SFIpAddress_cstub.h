#ifndef _CSF_IPADDRESS_INC
#define _CSF_IPADDRESS_INC

#include <SFML/Network/IpAddress.h>
#include <string.h>

static inline sfIpAddress
SfIpAddress_val(value addr, const char *func_name)
{
    sfIpAddress address;
    if (caml_string_length(addr) != 16) {
        char buf[80];
        snprintf(buf, 80, "%s: address length <> 16", func_name);
        caml_invalid_argument(buf);
    }
    memcpy(address.address, String_val(addr), 16);
    return address;
}

value Val_sfIpAddress(sfIpAddress address);

#endif // _CSF_IPADDRESS_INC
