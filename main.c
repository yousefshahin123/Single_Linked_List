/********************#defines sectioon****************************/
#include<stdio.h>
#include<stdlib.h>
/********************#defines sectioon****************************/

/********************typedef section******************************/
typedef struct node_t{
    signed int data;
    struct node_t *next;
}node;
typedef enum{
    NOK,
    OK
}fun_status;
/********************typedef section******************************/

/******************function declaration section*******************/
fun_status insert_at_beginning(node **list);
fun_status insert_at_ending(node **list);
fun_status insert_at_index(node **list);
void delete_at_beginning(node **list);
void delete_at_ending(node **list);
void delete_by_index(node **list);
void delete_by_value(node **list);
unsigned int search_element(node *list);
unsigned int get_list_length(node *list);
void display_list(node *list);
/******************function declaration section*******************/

int main(){

    node *list_1=NULL;

    printf("\nHello to single linked list");
    while(1){
        printf("\n\n**************************************************************\n");
        printf("Please select a number to do your operation\n");
        printf("1) Insert at beginning\n");
        printf("2) Insert at ending\n");
        printf("3) Insert at index\n");
        printf("******************************\n");
        printf("4) Delete at beginning\n");
        printf("5) Delete at ending\n");
        printf("6) delete by index\n");
        printf("7) delete by value\n");
        printf("******************************\n");
        printf("8) Search element\n");
        printf("9) Get list length\n");
        printf("10) Display list\n");
        printf("11) End the program\n");
        printf("**************************************************************\n\n");
        unsigned int user_choice=0;
        printf("your choice : ");
        scanf("%i",&user_choice);
        switch(user_choice){
            case 1 :
                insert_at_beginning(&list_1);
                break;
            case 2 :
                insert_at_ending(&list_1);
                break;
            case 3 :
                insert_at_index(&list_1);
                break;
            case 4 :
                delete_at_beginning(&list_1);
                break;
            case 5 :
                delete_at_ending(&list_1);
                break;
            case 6 :
                delete_by_index(&list_1);
                break;
            case 7 :
                delete_by_value(&list_1);
                break;
            case 8 :
                search_element(list_1);
                break;
            case 9 :
                get_list_length(list_1);
                break;
            case 10 :
                display_list(list_1);
                break;
            case 11 :
                printf("The program is closed successfully\n");
                exit(1);
            default :
                printf("Invalid choice!!!\n");
                break;
        }
    }
    return 0;
}

/******************function definition section*******************/
fun_status insert_at_beginning(node **list){
    fun_status fun_return=NOK;
    node *new_node=NULL;
    new_node=(node *)malloc(sizeof(node));
    if(NULL==new_node){
        printf("Couldn't allocate memory\n");
        fun_return=NOK;
    }
    else{
        printf("Please, enter element value :  ");
        scanf("%i",&(new_node->data));
        if(NULL==*list){
            new_node->next=NULL;
            *list=new_node;
        }
        else{
            new_node->next=*list;
            *list=new_node;
        }
        fun_return=OK;
    }
    return fun_return;
}

fun_status insert_at_ending(node **list){
    fun_status fun_return=NOK;
    node *new_node=NULL;
    new_node=(node *)malloc(sizeof(node));
    if(NULL==new_node){
        printf("Couldn't allocate memory\n");
        fun_return=NOK;
    }
    else{
        if(NULL==*list){
            fun_return=insert_at_beginning(list);
        }
        else{
            node *treverse_node=*list;
            while(treverse_node->next){
                treverse_node=treverse_node->next;
            }
            treverse_node->next=new_node;
            new_node->next=NULL;
            printf("Please, enter element value :  ");
            scanf("%i",&(new_node->data));  
            fun_return=OK;
        }
    }
    return fun_return;
}

fun_status insert_at_index(node **list){
    fun_status fun_return=NOK;
    unsigned int index=0;
    printf("Please, enter element index ( first element index is 1 ) : ");
    scanf("%i",&index);
    if(index>get_list_length(*list)||0==index){
        printf("Index is bigger than list length\n");
        fun_return=NOK;
    }
    else{
        if(1==index){
            fun_return=insert_at_beginning(list);
        }
        else if(get_list_length(*list)==index){
            fun_return=insert_at_ending(list);
        }
        else{
            node *treverse_node=*list;
            unsigned int counter=1;
            for(counter=1;counter<index;counter++){
                treverse_node=treverse_node->next;
            }
            node *new_node=NULL;
            new_node=(node *)malloc(sizeof(node));
            if(NULL==new_node){
            printf("Couldn't allocate memory\n");
            fun_return=NOK;
            }
            else{
                fun_return=OK;
                printf("Please, enter element value :  ");
                scanf("%i",&(new_node->data));
                new_node->next=treverse_node->next;
                treverse_node->next=new_node;
            }
        }
    }
    return fun_return;
}

void delete_at_beginning(node **list){
    if(NULL==*list){
        printf("List is empty\n");
    }
    else{
        node *temp_node=*list;
        printf("element %i has been deleted successfully\n",temp_node->data);
        *list=(*list)->next;
        temp_node->next=NULL;
	    free(temp_node);
    }
}

void delete_at_ending(node **list){
    if(NULL==*list){
        printf("The list is empty\n");
    }
    else if(1==get_list_length(*list)){
        delete_at_beginning(list);
    }
    else{
        node *temp_node=*list;
        while(temp_node->next->next){
            temp_node=temp_node->next;
        }
        printf("element %i has been deleted successfully\n",temp_node->next->data);
        free(temp_node->next);
        temp_node->next=NULL;
        /*unsigned int index=get_list_length(*list);
        node *temp_node_prev=*list;
        node *temp_node=NULL;
        unsigned int counter=0;
        for(counter=2;counter<index;counter++){
            temp_node_prev=temp_node_prev->next;
        }
        temp_node=temp_node_prev->next;
        temp_node_prev->next=temp_node->next;
        printf("element %i has been deleted successfully\n",temp_node->data);
        temp_node->next=NULL;*/
    }
}

void delete_by_index(node **list){
    if(NULL==*list){
        printf("List is empty\n");
    }
    else{
        unsigned int index=0;
        printf("Please, enter element index ( first element index is 1 ) : ");
        scanf("%i",&index);
        if(index>get_list_length(*list)||0==index){
            printf("Index is bigger than list length\n");
        }
        else if(1==index){
            delete_at_beginning(list);
        }
        else{
            node *temp_node_prev=*list;
            node *temp_node=NULL;
            unsigned int counter=0;
            for(counter=2;counter<index;counter++){
                temp_node_prev=temp_node_prev->next;
            }
            temp_node=temp_node_prev->next;
            temp_node_prev->next=temp_node->next;
            printf("element %i has been deleted successfully\n",temp_node->data);
            temp_node->next=NULL;
        }
    }
 
}

void delete_by_value(node **list){
    signed int d_value=0;
    unsigned int d_value_index=0;
    unsigned char found=0;
    printf("Enter the element to be deleted : ");
    scanf("%i",&d_value);
    if(NULL==list){
        d_value_index=0;
        found=0;
    }
    else{
        node *treverse_node=*list;
        while(treverse_node){
            d_value_index++;
            if(treverse_node->data==d_value){
                found=1;
                break;
            }
            treverse_node=treverse_node->next;
        }
    }
    if(!found){
        d_value_index=0;
    }
    else{
        
    }
    if(!d_value_index){
        printf("Element is not found!\n");
    }
    else{
        if(1==d_value_index){
            delete_at_beginning(list);
        }
        else{
            node *temp_node_prev=*list;
            node *temp_node=NULL;
            unsigned int counter=0;
            for(counter=2;counter<d_value_index;counter++){
                temp_node_prev=temp_node_prev->next;
            }
            temp_node=temp_node_prev->next;
            temp_node_prev->next=temp_node->next;
            printf("element %i has been deleted successfully\n",temp_node->data);
            temp_node->next=NULL;
        }
    } 
}

unsigned int search_element(node *list){
    signed int element=0;
    unsigned int index=0;
    unsigned char found=0;
    printf("Please, enter element you want to search for : ");
    scanf("%i",&element);
    if(NULL==list){
        printf("The list is empty!\n");
        index=0;
        found=0;
    }
    else{
        node *treverse_node=list;
        while(treverse_node){
            index++;
            if(treverse_node->data==element){
                printf("FOUND\n");
                found=1;
                break;
            }
            treverse_node=treverse_node->next;
        }
    }
    if(!found){
        index=0;
    }
    return index;
}

unsigned int get_list_length(node *list){
    node *traverse_node=list;
    unsigned int length=0;
    while(traverse_node){
        length++;
        traverse_node=traverse_node->next;
    }
    return length;
}
    
void display_list(node *list){
    node *traverse_node=list;
    if(NULL==traverse_node){
        printf("The list is empty\n");
    }
    else{
        printf("List elements are : [\t");
        while(NULL!=traverse_node){
            printf("%i\t",traverse_node->data);
            traverse_node=traverse_node->next;
        }
        printf("]\n");
    }
}

/******************function definition section*******************/