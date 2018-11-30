#include <stdio.h>


int akinator();
struct Node *  search(struct Node * tree);
struct Node * create_person(struct Node * tree);

struct Node * load_data(FILE * data_file);
int write_node(struct Node * tree, FILE * f_out);


#include "tree.h"


#define SIZE_OF_STR 512


int main()
{
	return akinator();	
}


int akinator()
{
	FILE * akn_data = fopen("akn_data.txt", "r");
	
	char answer = 0;
	
	struct Node * akn_tree = NULL; //load_data(akn_data);
	
	fclose(akn_data);
	
	while(1){
		
		printf("For start pres 'y' and 'return'\n");
		
		answer = getchar();

		if(answer == 'y') break;
		
		akn_tree = search(akn_tree);
		
	}
	/*akn_tree = search(akn_tree);
		
	print_tree_image(akn_tree);
	
	akn_tree = search(akn_tree);
		
	print_tree_image(akn_tree);
	
	akn_tree = search(akn_tree);
		
	print_tree_image(akn_tree);
	
	akn_tree = search(akn_tree);
		
	print_tree_image(akn_tree);
	
	akn_tree = search(akn_tree);
	
	*/
	
	akn_data = fopen("akn_data.txt", "w");
	
	write_node(akn_tree, akn_data);
		
	print_tree_image(akn_tree);
	
	return 0;
}


struct Node * search(struct Node * akn_tree)
{
	char answer = 0;
	
	char str[SIZE_OF_STR] = "\0";
	
	if(akn_tree == NULL)
	{
		printf("I don't know any person, write a question and two person to help me\n");
		scanf("%s", str);
		akn_tree = tree_add(akn_tree, NULL, str);
		scanf("%s", str);
		akn_tree->left = tree_add(akn_tree->left, akn_tree, str);
		scanf("%s", str);
		akn_tree->right = tree_add(akn_tree->right, akn_tree, str);
		//print_tree_image(akn_tree);
		printf("Now I know ur hero\n");
		return akn_tree;
		printf("ERROR\n");
	}
	
	//printf("!!%s!!", akn_tree->val);
	
	printf("%s?\n", akn_tree->val);
	
	scanf("%c", &answer);
	
	answer = getchar();
	
	if(answer == 'y' && akn_tree->left != NULL)
	{
		//printf("YES NULL\n");
		akn_tree->left = search(akn_tree->left);
		return akn_tree;
	}
	
	if(answer == 'n' && akn_tree->right != NULL)
	{
		//printf("NO NULL\n");
		akn_tree->right = search(akn_tree->right);
		return akn_tree;
	}
	
	if (answer == 'n')
	{
		//printf(" I dont \n");
		akn_tree = create_person(akn_tree);
		return akn_tree;
	}
	
	else
	{
		printf("return");
		return akn_tree;
	}
	
	print_tree_image(akn_tree);
	
}


struct Node * create_person(struct Node * tree)
{
	char str[SIZE_OF_STR] = "\0";
	
	tree->left = tree_add(tree->left, tree, tree->val);
	
	printf("Who is ur hero?\n");
	scanf("%s", str);
	tree->right = tree_add(tree->right, tree, str);
	
	printf("%s differs from %s by\n", tree->left->val, tree->right->val);
	scanf("%s", str);
	tree->val = strdup(str);
	
	return tree;
}


struct Node * load_data(FILE * data_file)
{
	char str[SIZE_OF_STR] = "\0";
		printf("1\n");
	static int indent = 0; indent ++;
		printf("1\n");
	fscanf(data_file, "%s", str);
		printf("1\n");
	printf("%s\n", str);
		printf("1\n");
	return NULL;
}


int write_node(struct Node * tree, FILE * f_out)
{
	static int indent = 0; indent ++;
	fprintf(f_out, "%*s{ ", indent * 4, " ");
	fprintf(f_out,"%s\n", tree->val);
	if(tree->left) write_node(tree->left, f_out);
	if(tree->right) write_node(tree->right, f_out);
	fprintf(f_out, "%*s}\n", indent * 4, " ");
	indent --;
	return 0;
}
