/*------------------------------------------------------------------
 * test_strisdigit_s
 *
 *------------------------------------------------------------------
 */

#include <stdio.h>
#include <string.h>

#include "safe_str_lib.h"


#define LEN   ( 128 )


int main()
{
    boolean_t rc;

    uint32_t len;
    char   str[LEN];

/*--------------------------------------------------*/

    len = 5;
    rc = strisdigit_s(NULL, len);
    if (rc != FALSE) {
        printf("%s %u   Error rc=%u \n",
                     __FUNCTION__, __LINE__,  rc );
    }

/*--------------------------------------------------*/

    len = 0;
    rc = strisdigit_s("1234", len);
    if (rc != FALSE) {
        printf("%s %u   Error rc=%u \n",
                     __FUNCTION__, __LINE__,  rc );
    }

/*--------------------------------------------------*/

    len = 99999;
    rc = strisdigit_s("1234", len);
    if (rc != FALSE) {
        printf("%s %u   Error rc=%u \n",
                     __FUNCTION__, __LINE__,  rc );
    }

/*--------------------------------------------------*/

    len = 9;
    rc = strisdigit_s("", len);
    if (rc != FALSE) {
        printf("%s %u   Error rc=%u \n",
                     __FUNCTION__, __LINE__,  rc );
    }

/*--------------------------------------------------*/

    strcpy(str, "123456789");
    len = 4; 

    rc = strisdigit_s(str, len);
    if (rc != TRUE) {
        printf("%s %u   Error rc=%u \n",
                     __FUNCTION__, __LINE__,  rc );
    }

/*--------------------------------------------------*/

    strcpy(str, "1");
    len = strlen(str);

    rc = strisdigit_s(str, len);
    if (rc != TRUE) {
        printf("%s %u   Error rc=%u \n",
                     __FUNCTION__, __LINE__,  rc );
    }

/*--------------------------------------------------*/

    strcpy(str, "12");
    len = strlen(str);

    rc = strisdigit_s(str, len);
    if (rc != TRUE) {
        printf("%s %u   Error rc=%u \n",
                     __FUNCTION__, __LINE__,  rc );
    }

/*--------------------------------------------------*/

    strcpy(str, "1abcd");
    len = strlen(str);

    rc = strisdigit_s(str, len);
    if (rc != FALSE) {
        printf("%s %u   Error rc=%u \n",
                     __FUNCTION__, __LINE__,  rc );
    }

/*--------------------------------------------------*/

    strcpy(str, "abcd");
    len = strlen(str);

    rc = strisdigit_s(str, len);
    if (rc != FALSE) {
        printf("%s %u   Error rc=%u \n",
                     __FUNCTION__, __LINE__,  rc );
    }

/*--------------------------------------------------*/

    return (0);
}
