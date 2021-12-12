#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

p_node push(char input){ 
    p_node new_node = (p_node) malloc(sizeof(node));
    if(!new_node){
        exit(1);
    }
    else{
        new_node->data = input;
  
        return new_node;
    }
}

void stack(p_node list, char input){
    p_node new_node = push(input);
    p_node old_Head = list->node_above;
 
    list->node_above = new_node;
    new_node->node_above = old_Head;
}

p_node pop (p_node list){
    if(list->node_above == NULL){
        
        return NULL;
    }
    else{
        p_node temporary_node = list->node_above;
        list->node_above = temporary_node->node_above;

        return temporary_node;
    }
}

int is_footer(p_node node){
    if(node->node_above == NULL){

        return 1;
    }    
    else{

    return 0;
    }
}

int show_size(p_node list){
    if(is_footer(list)){
        
        return 0;
    }

    int size = 0;
    p_node temporary_node = list->node_above;

    while( temporary_node != NULL){
        size += 1;
        temporary_node = temporary_node->node_above;
    }

    return size;
}

void count_enters(char input, int* line){
    if(input == '\n'){
        *line = *line + 1;
    }
}

void free_list(p_node list){
    if(!is_footer(list)){
        p_node next_Node;
        p_node current_Node;

        current_Node = list->node_above;
        
        while(current_Node != NULL){
            next_Node = current_Node->node_above;

            free(current_Node);

            current_Node = next_Node;
        }
    }
}

int main(void) {
  int flag = 0;
  int line = 1;
  char input;

  p_node list_p = (p_node) malloc(sizeof(node));
  p_node list_k = (p_node) malloc(sizeof(node));
  p_node list_c = (p_node) malloc(sizeof(node));

  if(!list_p || !list_k || !list_c){
    exit(1);
  }
  else{
    flag = scanf("%c", &input);
    count_enters(input, &line);
    
    p_node temporary_node;

    while(flag >= 0){
      switch (input){
        case '{':
          stack(list_k, input);

          break;
      
        case '[':
          stack(list_c, input);         

          break;

        case '(':
          stack(list_p, input);
          
          break;

        case '}':
          if (show_size(list_k) != 0){
            temporary_node = pop(list_k);
          }
          else{
            printf("Problema com '%c' na linha %d", input, line);
            
            return 0;
          }
          break;
      
        case ']':
          if (show_size(list_c) != 0){
            temporary_node = pop(list_c);
          }
          else{
            printf("Problema com '%c' na linha %d", input, line);
            
            return 0;
          }
          break;

        case ')':
          if (show_size(list_p) != 0){
            temporary_node = pop(list_p);
          }
          else{
            printf("Problema com '%c' na linha %d", input, line);
            
            return 0;
          } 
          break;

      default: 
        count_enters(input, &line);
        
        break;
    }

    flag = scanf("%c", &input);
    }
  }

  if(show_size(list_k) != 1 ){
    printf("Sobrou um '('");
  }
  else if(show_size(list_p) != 1){
    printf("Sobrou um '{'");
  }
  else{
    if(show_size(list_c) != 1){
      printf("Sobrou um '['");
    }
    else{
      printf("tudo ok!");
    }
  }
  
  free_list(list_p);
  free_list(list_k);
  free_list(list_c);

  return 0;
}