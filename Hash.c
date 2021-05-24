//MY EXACT CODE

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
/*
*
* SPACE
* Avg: O(n) Worst: O(n)
* 
* ACCESS
* N/A
*
* INSERT
* Avg: O(1) Worst: O(n)
*
* SEARCH
* Avg: O(1) Worst: O(n)
*
* DELETE
* Avg: O(1) Worst: O(n)
*
*/
int SIZE = 100;
int hashify(char* name)
{
  int total = 0;
  for(int i = 0; name[i] != '\0'; i++)
  {
    total += name[i];
  }
  total = (total * 17) % SIZE;
  printf("key: %d\n", total);
  return total;
}

void insert(char** hash, char* name)
{
  int index = hashify(name);
  printf("insert index:%d\n", index);
  if(hash[index] != NULL)
  {
     //linear probing
    int checksMade;
    for(checksMade = 100; checksMade; checksMade--)
    {
      if(strcmp(hash[index], name) == 0)
      {
        break;
      }
      index = (index++) % SIZE;
    }
    if(checksMade == 0)
    {
      return;
    }
/*
    //quadratic probing
    int checksMade, var = 1;
    for(checksMade = 100; checksMade; checksMade--)
    {
      
      if(strcmp(hash[index], name) == 0)
      {
        break;
      }
      index = (index + (int)pow(var, 2)) % SIZE;
      var++;
    }
    if(checksMade == 0)
    {
      return;
    }
    */
  }
    hash[index] = name;
}

void del(char** hash, char* name)
{
  int index = hashify(name);
  printf("delete index:%d\n", index);
  if(hash[index] == NULL)
  {
    //linear probing
    int checksMade;
    for(checksMade = 100; checksMade; checksMade--)
    {
      if(strcmp(hash[index], name) == 0)
      {
        break;
      }
      index = (index++) % SIZE;
    }
    if(checksMade == 0)
    {
      return;
    }
    /*
    //quadratic probing
    int var = 1;
    for(int checksMade = 100; checksMade; checksMade--)
    {
      
      if(strcmp(hash[index], name) == 0)
      {
        break;
      }
      index = (index + (int)pow(var, 2)) % SIZE;
      var++;
    }
    if(checksMade == 0)
    {
      return;
    }
    free(hash[index]);
    */
  }
  hash[index] = NULL;
}
bool verify(char** hash, char* name)
{
  int index = hashify(name);
  printf("verify index:%d\n", index);
  printf("Initial verification name: %s\n", hash[index]);
  //printf("cmp:%d\n", strcmp(hash[index], name));
  if(hash[index] == NULL)
  {
    //linear probing
    int checksMade;
    for(checksMade = 100; checksMade; checksMade--)
    {
        if(hash[index] == NULL)
      {
        continue;
      }
      if(strcmp(hash[index], name) == 0)
      {
        break;
      }
      index = (index++) % SIZE;
    }
    if(checksMade == 0)
    {
      return false;
    }
    /*
    //quadratic probing
    int var = 1;
    for(int checksMade = 100; checksMade; checksMade--)
    {
      
      if(strcmp(hash[index], name) == 0)
      {
        break;
      }
      index = (index + (int)pow(var, 2)) % SIZE;
      var++;
    }
    if(checksMade == 0)
    {
      return false;
    }
   return true;
   */
  }
  return true;
}

int main(int argc, char const *argv[])
{
  
  char** hash = (char**)malloc(SIZE * sizeof(char*));
  for(int i = 0; i < SIZE; ++i)
    hash[i] = NULL;


  char* name1 = "Anna";
  char* name2 = "crystal";
  char* name3 = "peter";
  insert(hash, name1);
  printf("%s\n", hash[hashify(name1)]);
  bool isThere = verify(hash, name1);
  printf(isThere ? "true\n" : "false\n");
  isThere = verify(hash, name2);
  printf(isThere ? "true\n" : "false\n");

  //insert(hash, name2);
  //insert(hash, name3);
  printf("Before Delete:%s\n", hash[hashify(name1)]);
  del(hash, name1);
  printf("After Delete:%s\n", hash[hashify(name1)]);

  printf("Before Delete:%s\n", hash[hashify(name2)]);
  del(hash, name2);
  printf("After Delete:%s\n", hash[hashify(name2)]);

  //isThere = verify(hash, name1);
  //printf("%d", isThere);
    /* code */
    return 0;
}