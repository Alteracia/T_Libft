#include "libft.h"

# include <string.h>
# include <limits.h>
# include <signal.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdint.h>
# include <time.h>
# include <stdbool.h>
# include <sys/types.h>
# include <sys/wait.h>
#include <sys/mman.h>

int main(void)
{
	char *str;
	const char *str1;
	void* dst[50];
	const char *src;	
	
	/* MEMSET */
  
  	printf("\nSTART test ft_MEMSET");	
	if (memset(NULL, INT_MIN, 0) != ft_memset(NULL, INT_MIN, 0))
	{
		printf("\noriginal 00: %s", memset(NULL, INT_MIN, 0));
		printf("\nmy function: %s", ft_memset(NULL, INT_MIN, 0));
	}
	printf(" - test END\n");

    /* BZERO */
    
    /* MEMCPY */
    
	printf("\nSTART test ft_MEMCPY");
	if (memcpy(NULL, NULL, INT_MIN) != ft_memcpy(NULL, NULL, INT_MIN))
	{
		printf("\noriginal 00: %s", memcpy(NULL, NULL, INT_MIN));
		printf("\nmy function: %s", ft_memcpy(NULL, NULL, INT_MIN));
	}
	printf(" - test END\n");

    /* MEMCCPY */

	printf("\nSTART test ft_MEMCCPY");	
	if (memccpy(NULL, NULL, INT_MIN, 0) != ft_memccpy(NULL, NULL, INT_MIN, 0))
	{
		printf("\noriginal 00: %s", memccpy(NULL, NULL, INT_MIN, 0));
		printf("\nmy function: %s", ft_memccpy(NULL, NULL, INT_MIN, 0));
	}
	printf(" - test END\n");

    /* MEMMOVE */

	printf("\nSTART test ft_MEMMOVE");	
	str = NULL;
	if (memmove(str, str, 4) != ft_memmove(str, str, 4))
	{
		printf("\noriginal 00: %s", memmove(str, str, 4));
		printf("\nmy function: %s", ft_memmove(str, str, 4));
	}
	printf(" - test END\n");

	/* MEMCHR */

	/* MEMCMP */

	/* STRLEN */

	printf("\nSTART test ft_STRLEN");
	src = "Hello world";
	if (strlen(src) != ft_strlen(src))
	{
		printf("\noriginal 00: %lu", strlen(src));
		printf("\nmy function: %lu", ft_strlen(src));
	}	
	printf(" - test END\n");

	/* STRDUP */

	printf("\nSTART test ft_STRDUP");
	src = "Hello world";
	if (strcmp(strdup(src), ft_strdup(src)))
	{
		printf("\noriginal 00: %s", strdup(src));
		printf("\nmy function: %s", ft_strdup(src));
	}
	printf(" - test END\n");	

	/* STRCPY */

	printf("\nSTART test ft_STRCPY");
	src = "Hello world";
	if (strcpy((char*)dst, src) != ft_strcpy((char*)dst, src))
	{
		printf("\noriginal 00: %s", strcpy((char*)dst, src));
		printf("\nmy function: %s", ft_strcpy((char*)dst, src));
	}	
	printf(" - test END\n");
	
	/* STRNCPY */

	printf("\nSTART test ft_STRNCPY");
	src = "Hello world";
	if (strncpy((char*)dst, src, 6) != ft_strncpy((char*)dst, src, 6))
	{
		printf("\noriginal 00: %s", strncpy((char*)dst, src, 6));
		printf("\nmy function: %s", ft_strncpy((char*)dst, src, 6));
	}	
	printf(" - test END\n");

	/* STRCAT */

	printf("\nSTART test ft_STRCAT");	
	str = NULL;
	if (strcat((char*)dst, src) != ft_strcat((char*)dst, src))
	{
		printf("\noriginal 00: %s", strcat((char*)dst, src));
		printf("\nmy function: %s", ft_strcat((char*)dst, src));
	}
	printf(" - test END\n");

	/* STRNCAT */

	printf("\nSTART test ft_STRNCAT");
	src = "Hello world";
	if (strncat((char*)dst, src, 6) != ft_strncat((char*)dst, src, 6))
	{
		printf("\noriginal 00: %s", strncat((char*)dst, src, 6));
		printf("\nmy function: %s", ft_strncat((char*)dst, src, 6));
	}	
	printf(" - test END\n");

	/* STRLCAT */

	printf("\nSTART test ft_STRLCAT");
	src = "Hello world";
	if (strlcat((char*)dst, src, 6) != ft_strlcat((char*)dst, src, 6))
	{
		printf("\noriginal 00: %lu", strlcat((char*)dst, src, 6));
		printf("\nmy function: %lu", ft_strlcat((char*)dst, src, 6));
	}	
	printf(" - test END\n");

	/* STRCHR */

	printf("\nSTART test ft_STRCHR");
	if (strchr(src, INT_MIN) != ft_strchr(src, INT_MIN))
	{
		printf("\noriginal 00: %s", strchr(src, INT_MIN));
		printf("\nmy function: %s", ft_strchr(src, INT_MIN));
	}
	printf(" - test END\n");

	/* STRRCHR */

	printf("\nSTART test ft_STRRCHR");
	if (strrchr(src, INT_MIN) != ft_strrchr(src, INT_MIN))
	{
		printf("\noriginal 00: %s", strrchr(src, INT_MIN));
		printf("\nmy function: %s", ft_strrchr(src, INT_MIN));
	}
	printf(" - test END\n");

	/* STRSTR */

	printf("\nSTART test ft_STRSTR");	
	str = "Hallo world";
	str1 = "Hallo \0World";
	if (strstr(str1, str) != ft_strstr(str1, str))
	{
		printf("\noriginal 00: %s", strstr(str1, str));
		printf("\nmy function: %s", ft_strstr(str1, str));
	}
	printf(" - test END\n");

	/* STRNSTR */

	/* STRCMP */

	printf("\nSTART test ft_STRCMP");
	str = "Hallo World";
	str1 = "Hallo \0World";
	if (strcmp(str1, str) != ft_strcmp(str1, str))
	{
		printf("\noriginal 00: %i", strcmp(str1, str));
		printf("\nmy function: %i", ft_strcmp(str1, str));
	}
	printf(" - test END\n");

	/* STRNCMP */

	printf("\nSTART test ft_STRNCMP");
	str = "Hallo World";
	str1 = "Hallo \0World";
	if (strncmp(str1, str, INT_MIN) != ft_strncmp(str1, str, INT_MIN))
	{
		printf("\noriginal 00: %i", strncmp(str1, str, INT_MIN));
		printf("\nmy function: %i", ft_strncmp(str1, str, INT_MIN));
	}
	printf(" - test END\n");

	/* ATOI */

	printf("\nSTART test ft_ATOI");	
	src = "-9223372036854775809";
	if (atoi(src) != ft_atoi(src))
	{
		printf("\noriginal 00: %i", atoi(src));
		printf("\nmy function: %i", ft_atoi(src));
	}
	src = "9223372036854775808";
	if (atoi(src) != ft_atoi(src))
	{
		printf("\noriginal 01: %i", atoi(src));
		printf("\nmy function: %i", ft_atoi(src));
	}
	src = "-9223372036854775811";
	if (atoi(src) != ft_atoi(src))
	{
		printf("\noriginal 02: %i", atoi(src));
		printf("\nmy function: %i", ft_atoi(src));
	}
	src = "9223372036854775809";
	if (atoi(src) != ft_atoi(src))
	{
		printf("\noriginal 03: %i", atoi(src));
		printf("\nmy function: %i", ft_atoi(src));
	}
	src = "9223372036854775808999999999999";
	if (atoi(src) != ft_atoi(src))
	{
		printf("\noriginal 04: %i", atoi(src));
		printf("\nmy function: %i", ft_atoi(src));
	}
	src = "-9223372036854775808999999999999";
	if (atoi(src) != ft_atoi(src))
	{
		printf("\noriginal 05: %i", atoi(src));
		printf("\nmy function: %i", ft_atoi(src));
	}
	sprintf((char*)dst, "%ld", (LONG_MAX));
	if (atoi((char*)dst) != ft_atoi((char*)dst))
	{
		printf("\noriginal 06: %i", atoi((char*)dst));
		printf("\nmy function: %i", ft_atoi((char*)dst));
	}
	sprintf((char*)dst, "%ld", (LONG_MIN));
	if (atoi((char*)dst) != ft_atoi((char*)dst))
	{
		printf("\noriginal 07: %i", atoi((char*)dst));
		printf("\nmy function: %i", ft_atoi((char*)dst));
	}
	printf(" - test END\n");

	/* STRSPLIT */

	/*char **ara;

	ara = ft_strsplit("   foo  fooo", ' ');
	i = 0;
	while(ara[i])
		printf("\n%s", ara[i++]);*/

	/* ITOA */

	/*printf("\n\nitoa %s", ft_itoa(0));*/

		/* STRNEW */

	printf("\nSTART test ft_STRNEW");
	if (ft_strnew(65535) != NULL)
	{		
		printf("\nft_strnew dose not handle over size_t");
	}
	printf(" - test END\n");

	printf("\n");
    return 0;
}
