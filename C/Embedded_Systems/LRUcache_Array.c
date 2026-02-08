/************* What is LRU Cache? ***************
Cache replacement algorithms are efficiently designed to replace the cache when the space is full. The Least Recently Used (LRU) is one of those algorithms. As the name suggests when the cache memory is full, LRU picks the data that is least recently used and removes it in order to make space for the new data. The priority of the data in the cache changes according to the need of that data i.e. if some data is fetched or updated recently then the priority of that data would be changed and assigned to the highest priority , and the priority of the data decreases if it remains unused operations after operations.

/*********** Operations on LRU Cache: **************
    *   LRUCache (Capacity c): Initialize LRU cache with positive size capacity c.
    *   get (key) : Returns the value of key ' k' if it is present in the cache otherwise it returns -1. Also updates the priority of data in the LRU cache.
    *   put (key, value): Update the value of the key if that key exists, Otherwise, add a key-value pair to the cache. If the number of keys exceeds the capacity of the LRU cache then dismiss the least recently used key. 
    Reference : https://www.geeksforgeeks.org/system-design/lru-cache-implementation/  */

    This below code from chat gpt so need to work on it later on, I think its a flaw code
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#define LRU_CAPACITY 4

typedef struct {
    int key;
    int value;
    uint32_t age;
    bool valid;
}LRUEntry_t;

typedef struct {
    LRUEntry_t entries[LRU_CAPACITY];
    uint32_t time;
}LRUCache_t;

//  Initialize cache
void LRU_init(LRUCache_t *cache) {
    cache->time = 0;
    for(int i = 0; i < LRU_CAPACITY; ++i) {
        cache->entries[i].valid = false;
    }
}

    //  Get operation
bool LRU_Get(LRUCache_t *cache, int key, int *value) {
    for(int i = 0 ; i < LRU_CAPACITY; ++i) {
        if(cache->entries[i].valid && cache->entries[i].key == key) {
            *value = cache->entries[i].value;
            cache->entries[i].age = cache->time++;
            return true;
        }
    }
    return false;
}

    //  Put operation
void LRU_Put(LRUCache_t *cache, int key, int value) {
    int LRU_index = -1;
    uint32_t minAge = UINT32_MAX;

    // Check if key is already exists
    for(int i = 0 ; i < LRU_CAPACITY; ++i) {
        if(cache->entries[i].valid && cache->entries[i].key == key) {
            cache->entries[i].value = value;
            cache->entries[i].age = cache->time++;
            return;
        }
    }
    
    /* Find empty slot or LRU entry */
    for(int i = 0; i < LRU_CAPACITY; ++i) {
        if(!cache->entries[i].valid) {
            LRU_index = i;
            break;
        }
        if(cache->entries[i].age < minAge) {
            minAge = cache->entries[i].age;
            LRU_index = i;
        }
    }

    /* replace entries */
    cache->entries[LRU_index].key = key;
    cache->entries[LRU_index].value = value;
    cache->entries[LRU_index].age = cache->time++;
    cache->entries[LRU_index].valid = true;
}

int main(int arg, char* argv[]) {
    LRUCache_t cache;
    LRU_init(&cache);
    LRU_Put(&cache, 1, 100);
    LRU_Put(&cache, 2, 200);
    LRU_Put(&cache, 3, 300);
    LRU_Put(&cache, 4, 400);

    int value;
    LRU_Get(&cache, 2, &value);
    
    LRU_Put(&cache, 5, 500);

    if(!LRU_Get(&cache, 1, &value))
        printf("Key 1 evicted\n");
    return 0;
}
