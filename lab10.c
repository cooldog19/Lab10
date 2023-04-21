#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct Trie {
    int flag;
    struct trie* next[26];
}Trie;
void insert(struct Trie **ppTrie, char *word){
    if(*ppTrie == NULL) return;
    int length = strlen(word);
    Trie *tmp = *ppTrie;
    for(int i = 0; i < length; i++){
        int index = word[i] - 'a';
        if(tmp->next[index] == NULL){
        tmp->next[index] = (Trie*)calloc(1, sizeof(Trie));
        }
        tmp = tmp->next[index];
    }
    tmp->flag++;
}
int numberOfOccurances(struct Trie *pTrie, char *word){
    int length = strlen(word);
    Trie *tmp = pTrie;
    for(int i = 0; i < length; i++){
        int index = word[i] - 'a';
        if(tmp->next[index] == NULL){
            return 0;
        }
        tmp = tmp->next[index];
    }
    return tmp->flag;
}
struct Trie *deallocateTrie(struct Trie *pTrie){
    for(int i = 0; i <26; i++){
      if (pTrie->next[i] != NULL){
      pTrie->next[i] = deallocateTrie(pTrie->next[i]);
      }
    }
    free(pTrie);
    return 0;
}
int main(void)
{
      //read the number of the words in the dictionary
      // parse line  by line, and insert each word to the trie data structure
      Trie *trie = (Trie*)calloc(1, sizeof(Trie));
      char *pWords[] = {"notaword", "ucf", "no", "note", "corg"};
      for (int i=0;i<5;i++)
      {
        insert(&trie, pWords[i]);
          printf("\t%s : %d\n",pWords[i], numberOfOccurances(trie, pWords[i]));
     }
    trie = deallocateTrie(trie);
    if (trie != NULL)
       printf("There is an error in this program\n");
    return 0;
}


