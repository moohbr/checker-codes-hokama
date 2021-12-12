typedef struct node{
    char data;
    struct node* node_above;
} node;
typedef struct node* p_node;

p_node push(char input);
p_node pop (p_node list);

void stack(p_node list, char input);
void count_enters(char input, int* line);
void free_list(p_node list);

int is_footer(p_node node);
int show_size(p_node list);
