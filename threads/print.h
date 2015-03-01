#ifndef __PRINT_H__
#define __PRINT_H__


#ifdef DEBUG
#define debug(fmt, ...) printf("%s: %d: "fmt "\n", __func__, __LINE__, ##__VA_ARGS__)
#else
#define debug(fmt, ...) 
#endif		//DEBUG


#endif		//__PRINT_H__
