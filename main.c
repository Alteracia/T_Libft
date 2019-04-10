#include "libft.h"

# include <string.h>
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

char target[21] = "a shiny white sphere";
char  buf[10];

void printArray(int arr[], int n) 
{ 
   for (int i=0; i<n; i++) 
      printf("%d ", arr[i]);
}

void fillArray(int *arr, int nb, int n)
{
    for (int i=0; i<n; i++) 
      arr[i] = nb;
}

void	*ftt_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*pd;
	const unsigned char	*ps;

	pd = dst;
	ps = src;
	if (ps > pd)
	{
		while (len--)
		{
			pd += len;
			ps += len;
			*pd-- = *ps--;
		}
	}
	else
		while (len--)
			*pd++ = *ps++;
	return (dst);
	
	
}

size_t	ftt_strlcat(char *dst, const char *src, size_t siz)
{
	char *d = dst;
	const char *s = src;
	size_t n = siz;
	size_t dlen;

	/* Find the end of dst and adjust bytes left but don't go past end */
	while (n-- != 0 && *d != '\0')
		d++;
	dlen = d - dst;
	n = siz - dlen;

	if (n == 0)
		return(dlen + strlen(s));
	while (*s != '\0') {
		if (n != 1) {
			*d++ = *s;
			n--;
		}
		s++;
	}
	*d = '\0';

	return(dlen + (s - src));	/* count does not include NUL */
}

int	ftt_strcmp(char *s1, char *s2)
{
	while (*s1 != '\0')
	{
		if (*s2 != *s1)
			return (*s2 - *s1);
		else
		{
			s1++;
			s2++;
		}
	}
	if (*s1 != '\0')
		return (*s1 - *s2);
	return (0);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dsize)
{
	const char *osrc = src;
	size_t nleft = dsize;

	/* Copy as many bytes as will fit. */
	if (nleft != 0) {
		while (--nleft != 0) {
			if ((*dst++ = *src++) == '\0')
				break;
		}
	}

	/* Not enough room in dst, add NUL and traverse rest of src. */
	if (nleft == 0) {
		if (dsize != 0)
			*dst = '\0';		/* NUL-terminate dst */
		while (*src++)
			;
	}

	return(src - osrc - 1);	/* count does not include NUL */
}

int main(void)
{
    /* MEMSET */

    char str1[50] = "School 21 * 2 is for programming geeks."; 
    printf("\nBefore memset(): %s\n", str1);
    memset(str1 + 13, '.', 8*sizeof(char));
    printf("After memset():  %s\n", str1);

    int n = 10; 
    int arr1[n];
    printf("Empty array before memset():");
    printArray(arr1, n);
    printf("\n");
    ft_memset(arr1, 0, n*sizeof(arr1[0]));
    printf("Array after memset():");
    printArray(arr1, n);
    printf("\n");

    /* BZERO */

    char str2[50] = "School 21 * 2 is for programming geeks."; 
    printf("\nBefore bzero(): %s\n", str2);
    ft_bzero(str2, sizeof(str2));
    printf("After bzero():  %s\n", str2);
     
    int arr2[n];
    fillArray(arr2, 42, n);
    printf("Array of 42 before bzero():");
    printArray(arr2, n);
    printf("\n");
    ft_bzero(arr2, n*sizeof(arr2[0]));
    printf("Array after bzero():");
    printArray(arr2, n);
    printf("\n");

    /* MEMCPY */
                          
    const char src[50] = "School 21 * 2 is for programming geeks.";
    char dest[50];
    strcpy(dest,"Heloooo!!");
    printf("\nBefore memcpy dest = %s\n", dest);
    ft_memcpy(dest, src, strlen(src)+1);
    printf("After memcpy dest = %s\n", dest);

    char csrc[] = "GeeksforGeeks"; 
    char cdest[100];
    ft_memcpy(cdest, csrc, strlen(csrc)+1); 
    printf("Copied string is %s", cdest); 
  
    int isrc[] = {10, 20, 30, 40, 50}; 
    n = sizeof(isrc)/sizeof(isrc[0]); 
    int idest[n], i; 
    ft_memcpy(idest, isrc,  sizeof(isrc)); 
    printf("\nCopied array is "); 
    for (i=0; i<n; i++) 
        printf("%d ", idest[i]);
    printf("\n");

    /* MEMCCPY */

    char buffer[80];
    const char *msg = "This is the copied string: not copied";
    memset( buffer, '\0', 11);
    ft_memccpy( buffer, msg, ':', 11);
    printf( "\n%s\n", buffer );
    printf( "%s\n", ft_memccpy( buffer, msg, ':', 11));

    /* MEMMOVE */

    char target[21] = "a shiny white sphere";
    char *p = target + 8;
    char *source = target + 2;
    printf( "Before memmove, target is \"%s\"\n", target );
    ft_memmove( p, source, 5 );
    printf( "After memmove, target becomes \"%s\"\n", target );
	char	src3[] = "lorem ipsum dolor sit amet";
	char	*dest2;
	dest2 = src3 + 1;
	ft_memmove(dest2, src3, 8);	
	printf( "\n MEMMOVE \nAfter memmove, target becomes \"%s\"\n", dest2);
	ft_memmove(src3, dest2, 8);	
	printf( "After memmove, target becomes \"%s\"\n", dest2);

	/* MEMCHR */

    char *s1 = "";
	char *s2 = "abcdefabcdef";
	char *s3 = "11111111111111111111";
	printf("\nTesting memchr():\nTest1...");
	if (memchr(s1, 'x', 0) == NULL)
		printf("passed.");
	else	printf("FAILED.");
	printf("\nTest2...");
	if (memchr(s2, 'y', 0) == NULL)
		printf("passed.");
	else	printf("FAILED.");
	printf("\nTest3...");
	if ((char *)memchr(s2, 'a', 1) - s2 == 0)
		printf("passed.");
	else	printf("FAILED.");
	printf("\nTest4...");
	if (memchr(s2, 'd', 2)  == NULL)
		printf("passed.");
	else	printf("FAILED.");
	printf("\nTest5...");
	if ((char *)memchr(s2, 'd', 12)  - s2 == 3)
		printf("passed.");
	else	printf("FAILED.");
	printf("\nTest6...");
	if ((char *)memchr(s2, 'f', 12)  - s2 == 5)
		printf("passed.");
	else	printf("FAILED.");
	printf("\nTest7...");
	if ((char *)memchr(s3, '1', 20)  - s3 == 0)
		printf("passed.");
	else	printf("FAILED.");

	/* STRLCPY */

	const char *str3 = "образец строки";
	size_t sz = 0;
	buf[0] = '\0';
	printf("строка: \"%s\"\n\n", str3);
	printf("буфер перед копированием: \"%s\"\n", buf);
	sz = ft_strlcat(buf, str3, sizeof(buf));
	if (sz >= sizeof(buf))
 	printf("обнаружено усечение строки с %zu до %lu символов !\n", sz, sizeof(buf)-1);
 	printf("буфер после копирования:  \"%s\"\n", buf);

	/* STRCMP */

	printf("\nresult of origin: %i", strcmp("\200", "\0"));
	printf("\nresult of my: %i", ft_strcmp("\200", "\0"));

	/* STRNCMP */

	printf("\nresult of origin: %i", strncmp("test", "tEst", 4));
	printf("\nresult of my: %i\n", ft_strncmp("test", "tEst", 4));

	/* STRNSTR */

	char		*str4 = "Hello les genw";
	if (strnstr(str4, "Hello", 6) != ft_strnstr(str4, "Hello", 6))
		printf("\nerr0");
	if (strnstr(str4, "Hello", 3) != ft_strnstr(str4, "Hello", 3))
		printf("\nerr1");
	if (strnstr(str4, "les", 1) != ft_strnstr(str4, "les", 1))
	{
		printf("\noriginal: %s", strnstr(str4, "les", 1));
		printf("\nmy: %s", ft_strnstr(str4, "les", 1));
	}
	if (strnstr(str4, "gen", 2) != ft_strnstr(str4, "gen", 2))
	{
		printf("\noriginal: %s", strnstr(str4, "gen", 2));
		printf("\nmy: %s", ft_strnstr(str4, "gen", 2));
	}
	if (strnstr("abcdef", "abcdefghijklmnop", 6) != ft_strnstr("abcdef", "abcdefghijklmnop", 6))
	{
		printf("\noriginal: %s", strnstr("abcdef", "abcdefghijklmnop", 6));
		printf("\nmy: %s", ft_strnstr("abcdef", "abcdefghijklmnop", 6));
	}
	if (strnstr("AAAAAAAAAAAAA", "AAAAAAAAAAAAA", 13) != ft_strnstr("AAAAAAAAAAAAA", "AAAAAAAAAAAAA", 13))
	{
		printf("\noriginal: %s", strnstr("AAAAAAAAAAAAA", "AAAAAAAAAAAAA", 13));
		printf("\nmy: %s", ft_strnstr("AAAAAAAAAAAAA", "AAAAAAAAAAAAA", 13));
	}
	if (strnstr("lorem ipsum dolor sit amet", "", 10) != ft_strnstr("lorem ipsum dolor sit amet", "", 10))
	{
		printf("\noriginal: %s", strnstr("lorem ipsum dolor sit amet", "", 10));
		printf("\nmy: %s", ft_strnstr("lorem ipsum dolor sit amet", "", 10));
	}
	if (strnstr("lorem ipsum dolor sit amet", "ipsumm", 30) != ft_strnstr("lorem ipsum dolor sit amet", "ipsumm", 30))
	{
		printf("\noriginal fn: %s", strnstr("lorem ipsum dolor sit amet", "ipsumm", 30));
		printf("\nmy function: %s", ft_strnstr("lorem ipsum dolor sit amet", "ipsumm", 30));
	}
	if (strnstr("MZIRIBMZIRIBMZE123", "MZIRIBMZE", 9) != ft_strnstr("MZIRIBMZIRIBMZE123", "MZIRIBMZE", 9))
	{
		printf("\noriginal fn: %s", strnstr("MZIRIBMZIRIBMZE123", "MZIRIBMZE", 9));
		printf("\nmy function: %s", ft_strnstr("MZIRIBMZIRIBMZE123", "MZIRIBMZE", 9));
	}
	if (strnstr("123456789", "9", 8) != ft_strnstr("123456789", "9", 8))
	{
		printf("\noriginal fn: %s", strnstr("123456789", "9", 8));
		printf("\nmy function: %s", ft_strnstr("123456789", "9", 8));
	}
	char	buf[11];

	bzero(buf, 11);
	strcpy(buf, "un deux 9");
	buf[9] = '6';
	if (strnstr(buf, "deux", 10) != ft_strnstr(buf, "deux", 10))
	{
		printf("\noriginal fn: %s", strnstr(buf, "deux", 10));
		printf("\nmy function: %s", ft_strnstr(buf, "deux", 10));
	}
	char *	big = "123456789";
	char *	little = "9";
	size_t	max = 8;

	char 	*s6 = strnstr(big, little, max);
	char 	*s7 = ft_strnstr(big, little, max);

	if (s6 != s7)
		printf("\nERROR%s and %s", s6, s7);

	printf("\n");

	/* ATOI */

	/*
	char	nbrl[40];	
	sprintf(nbrl, "%ld", (LONG_MAX));
	
	*/
	char	nbrl[40] = "000000000000000009999999999999999999999";
	
	printf("\nresult of origin: %i", atoi(nbrl));
	printf("\nresult of my: %i\n", ft_atoi(nbrl));

	/* STRSPLIT */

	char **ara;

	ara = ft_strsplit("   foo  fooo", ' ');
	i = 0;
	while(ara[i])
		printf("\n%s", ara[i++]);

	/* ITOA */

	printf("\n\nitoa %s", ft_itoa(0));

    return 0;
}