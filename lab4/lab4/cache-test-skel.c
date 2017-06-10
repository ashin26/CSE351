/*
Aigerim Shintemirova
CSE 351 - Spring 2017
Lab 4 - Mystery Caches

Mystery Cache Geometries:
mystery0:
    block size = 64
    cache size = 262144
    associativity = 1
mystery1:
    block size = 8
    cache size = 16379
    associativity = 1638
mystery2:
    block size = 16
    cache size = 65534
    associativity = 4096
mystery3:
    block size = 2
    cache size = 131072
    associativity = 2
*/

#include <stdlib.h>
#include <stdio.h>

#include "mystery-cache.h"

/*
 * NOTE: When using access_cache() you do not need to provide a "real" memory
 * addresses. You can use any convenient integer value as a memory address.
 * You should not be able to cause a segmentation fault by providing a memory
 * address out of your programs address space as the argument to access_cache.
 */

/*
   Returns the size (in B) of each block in the cache.
*/
int get_block_size(void) {
  	int addr = 0;
	flush_cache();
	access_cache(addr);
	for(; ; addr++) {
		if (access_cache(addr) == TRUE)
			addr++;
		else
			break;
	}
	
	return addr;
  }

/*
   Returns the size (in B) of the cache.
*/
int get_cache_size(int block_size) {
	int i, j = 0;
	int cache;

	for(; ; i++){
		i += block_size; //fill in the cache
		for(j = 0; j < i; j += block_size){
			access_cache(j);
		}
		
		if(access_cache(0) == FALSE) { //fill in until it's a miss
			cache = i - block_size;	// calculate the cache size

			return cache;
		}
	
	}
	//return cache;
}

/*
   Returns the associativity of the cache.
*/
int get_cache_assoc(int cache_size) {
	int assoc = 0;
	access_cache(0);
	while(access_cache(0)){
		assoc++;
		for(int i = 0; i <= assoc; i++) {
			int temp = i*cache_size;
			access_cache(temp);
		}

	}
	
	return assoc;
}

int main(void) {
  int size;
  int assoc;
  int block_size;

  cache_init(0,0);

  block_size=get_block_size();
  size=get_cache_size(block_size);
  assoc=get_cache_assoc(size);

  printf("Cache block size: %d bytes\n", block_size);
  printf("Cache size: %d bytes\n", size);
  printf("Cache associativity: %d\n", assoc);

  return EXIT_SUCCESS;
}
