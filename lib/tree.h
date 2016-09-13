/*
	ADT para BST
	@author Dayvson Sales
*/

#include <stdlib.h>

typedef struct bt{
	int value;
	struct bt *right;
	struct bt *left;
}bt;

/* Cria a bst */
bt* bst_create(int value);

/* Insere na bst um valor. */
bt* bst_insert(bt* bst, int value);

/* Insere na bst um array de valores. */
bt* bst_insert_array(bt* bst, int arr[], int size);

/* Busca um valor na bst e retorna o número de comparações */
int bst_search(bt* bst, int value);

/* Limpa a binary tree */
void bst_free(bt* bst);

/*Imprime a bst */
void bst_print(bt* bst);

/*Cria uma arvore vazia*/
bt* create_empty_tree();

/*Compara dois inteiros e verifica o maior */
int max(int a, int b);

bt* create_empty_tree(){
	return NULL;
}


bt* bst_create(int value){
	bt* bst = (bt*)malloc(sizeof(bt));
	bst->value = value;
	bst->left = NULL;
	bst->right = NULL;

	return bst;
}


bt* bst_insert(bt* bst, int value){
	if(bst == NULL){
		bst = bst_create(value);
	}else if(bst->value > value){
		bst->left = bst_insert(bst->left, value);
	}else{
		bst->right = bst_insert(bst->right, value);
	}
	return bst;
}

bt* bst_insert_array(bt* bst, int arr[], int size){

	int i;

	for(i = 0; i < size; i++){
		bst = bst_insert(bst, arr[i]);
	}

	return bst;
}

int bst_search(bt* bst, int value){

	if(bst == NULL) return 0;
	if(bst->value > value) return 1 + bst_search(bst->left, value);
	if(bst->value < value) return 1 + bst_search(bst->right, value);

	return 1;
}

void bst_free(bt* bst){
	if(bst == NULL){
		bst_free(bst->left);
		bst_free(bst->right);
		free(bst);
	}
}

void bst_print(bt* bst){
	printf("(");
	if(bst != NULL){
		printf("%d", bst->value);
		bst_print(bst->left);
		bst_print(bst->right);
	}
	printf(")");
}

int max(int a, int b){
	return ((a > b) ? a : b);
}

int bst_height(bt* bst){
	if(bst_is_empty(bst)){
		return -1;	
	}else{
		return 1 + max(bst_height(bst->left), bst_height(bst->right));	
	}
}

bt* bst_balance(bt* avl){
	if(){
	}		
}

