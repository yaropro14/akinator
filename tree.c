#ifndef TREE_C
#define TREE_C


#include "tree.h"
#include <string.h>

struct root create_tree()
{
	struct root new_root;
	
	new_root.tree = NULL;
	
	return new_root;
}


struct Node * tree_add(struct Node * tree, struct Node * parent, Data val)
{
	tree = (struct Node *) calloc(1, sizeof(struct Node));
	//printf("&&%s&&\n", val);
	//tree->val = (char *) calloc(sizeof(val), sizeof(char));
	//printf("1\n");
	tree->val = strdup(val);
	//printf("1\n");
	tree->left = NULL;
	//printf("1\n");
	tree->right = NULL;
	//printf("1\n");
	tree->parent = parent;
	//printf("1\n");
	return tree;
}


Data tree_get_elem( struct Node * node)
{
	return node->val;
}


void tree_destroy (struct Node * tree)
{
	if(tree->left != NULL)
		tree_destroy(tree->left);
	if (tree->right != NULL)
		tree_destroy(tree->right);
	free(tree);
}


struct Node * search_element(struct Node * tree, Data val)
{
	struct Node * tree_l = NULL;
	struct Node * tree_r = NULL;
	
	
	if(tree == NULL) return NULL;
	
	if(strcmp(val,tree->val) == 0) return tree;
	
	else
	{
		if(tree->left != NULL)
			tree_l = search_element(tree->left, val);
		
		if(tree->right != NULL)
			tree_r = search_element(tree->right, val);
			
		if(tree_l == NULL) 
			return tree_l;
			
		else
			return tree_r;
	}
}


int tree_height(struct Node * tree) {
	
	if (tree == NULL)
		return 0;
		
	return 1 + max(tree_height(tree->left), tree_height(tree->right));
}


void tree_print (struct Node * tree)
{
	if (tree == NULL)
		return;
		
	//printf("\n|%p|\n", tree->parent);
	tree_print(tree->left);
	printf("%s\n ", tree->val);
	tree_print(tree->right);
}


void print_tree_image(struct Node * tree)
{
	FILE * file_graph = fopen("graph.dot", "w");
	fprintf(file_graph, "graph tree {\n");
	//char ** lists = (char **) calloc(1, sizeof(cahr *));
	//int n_lists = 0;
	int i = print_tree_list(tree, file_graph);
	fprintf(file_graph, "}\n");
	fclose(file_graph);
	system("dot -Tpng graph.dot -o gtaph.png");
}


/*void print_tree_postfix(struct Node * tree, FILE * postfix, int left, int right)
{
	if (tree == NULL)
		return;
		
	else
	{
		if(left)
		{
			if (tree->left == NULL && tree->right == NULL)
			{
				//printf("!!!");
				fprintf(postfix, "%d", tree->val);
				return;
			}
			
			if (tree->left != NULL && tree->right != NULL)
			{
				fprintf(postfix, "(");
				left = 1;
				print_tree_postfix(tree->left, postfix, 1, 0);
				fprintf(postfix, ",");
				print_tree_postfix(tree->right, postfix, 0, 1);
				fprintf(postfix, ")");
				fprintf(postfix, "%d", tree->val);
				return;
			}
			
			if(tree->left == NULL)
			{
				//printf("left");
				fprintf(postfix, "(");
			}
			
			if(tree->left != NULL)
			{
				//printf("left");
				fprintf(postfix, "(");
				left = 1;
				print_tree_postfix(tree->left, postfix, 1, 0);
				fprintf(postfix, ",");
			}
			
			if(tree->right != NULL)
			{
				//printf("right");
				//printf("(");
				print_tree_postfix(tree->right, postfix, 0, 1);
				fprintf(postfix, ")");
			}
			
			if(tree->right == NULL)
			{
				fprintf(postfix, "0)");
				return;
			}
			
			fprintf(postfix, "%d", tree->val);
			
		}
			
			
		if(right)
		{
			
			if (tree->left != NULL && tree->right != NULL)
			{
				fprintf(postfix, "(");
				left = 1;
				print_tree_postfix(tree->left, postfix, 1, 0);
				fprintf(postfix, ",");
				print_tree_postfix(tree->right, postfix, 0, 1);
				fprintf(postfix, ")");
				fprintf(postfix, "%d", tree->val);
				return;
			}
			
			//printf("left");
			if(tree->left != NULL)
			{
				fprintf(postfix, "(");
				left = 1;
				print_tree_postfix(tree->left, postfix, 1, 0);
				fprintf(postfix, ",");
			}
			
			if (tree->left == NULL && tree->right == NULL)
			{
				//printf("!!!");
				fprintf(postfix, "%d", tree->val);
				//printf(")");
				return;
				
			}
			
			if(tree->left == NULL)
			{
				//printf("left");
				fprintf(postfix, "(");
			}
			
			if(tree->right != NULL)
			{
				fprintf(postfix, "(");
				print_tree_postfix(tree->right, postfix, 0, 1);
				fprintf(postfix, ")");
				return;
			}
			
			fprintf(postfix, "%d", tree->val);
			fprintf(postfix, ")");
		}
	}
	
	//return left;
}
*/

int print_tree_list(struct Node * tree, FILE * file_graph)
{
	if (tree == NULL)
		return 0;
		
	if(tree->left != NULL)
	{
		fprintf(file_graph, "%s", tree->val);
		fprintf(file_graph, " -- ");
		int i = print_tree_list(tree->left, file_graph);
	}
	
	if(tree->right != NULL)
	{
		fprintf(file_graph, "%s", tree->val);
		fprintf(file_graph, " -- ");
		int i = print_tree_list(tree->right, file_graph);
	}
	
	
	if(tree->left == NULL && tree->right == NULL)
	{
		fprintf(file_graph, "%s;\n", tree->val);
	}
	
	return 0;
}


int max (int x, int y)
{
	return x > y ? x : y;
}


#endif //TREE_C
