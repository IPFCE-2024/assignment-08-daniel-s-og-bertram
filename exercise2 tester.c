#include "exercise2.c"

int main() {
    node* list = NULL;
    list = create_node(3);
    list->next = create_node(2);
    list->next->next = create_node(1);

    print_list(list);

    isort(list);

    print_list(list);
}