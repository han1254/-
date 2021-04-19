#include <stdio.h>
#include <stdlib.h>
#define MaxSize 10

typedef struct {
	int left_ptr;
	int right_ptr;
	int data[MaxSize];
} SharedStack;

void init_share_stack(SharedStack* stack);
int is_full_share_stacK(SharedStack stack);
int is_empty_share_stack(int index, SharedStack stack);
void print_share_stack(SharedStack stack);
int push_share_stack(int index, SharedStack* stack, int data);
int pop_share_stack(int index, SharedStack* stack, int* res);

void init_share_stack(SharedStack* stack) {
	stack->left_ptr = -1;
	stack->right_ptr = MaxSize;
}


int pop_share_stack(int index, SharedStack* stack, int* res) {
	if(is_empty_share_stack(index, *stack) == 1) {
		printf("Stack is empty\n");
		return 0;
	}

	if(index == 0) *res = stack->data[stack->left_ptr--];
	else *res = stack->data[stack->right_ptr++];

	return 1;
}

int push_share_stack(int index, SharedStack* stack, int data) {
	if(is_full_share_stacK(*stack) == 1)
		printf("SharedStack is full\n");
	if(index == 0)
		stack->data[++stack->left_ptr] = data;
	else 
		stack->data[--stack->right_ptr] = data;
	return 1;
}


void print_share_stack(SharedStack stack) {

	printf("left:\n");
	for(int i = 0; i <= stack.left_ptr; i++) {
		printf("%d ", stack.data[i]);
	}
	printf("\n");

	printf("right:\n");
	for(int i = MaxSize - 1; i >= stack.right_ptr; i--) {

		printf("%d ", stack.data[i]);
	}
	printf("\n");
}

int is_empty_share_stack(int index, SharedStack stack) {
	if(index == 0) 
		return stack.left_ptr == -1 ? 1 : 0;
	else 
		return stack.right_ptr == MaxSize ? 1 : 0;

}
	

int is_full_share_stacK(SharedStack stack) {
	if(stack.right_ptr - stack.left_ptr <= 1)
		return 1;
	return 0;
}


	

int main() {
	SharedStack stack;
	init_share_stack(&stack);
	push_share_stack(0, &stack, 1);
	push_share_stack(0, &stack, 3);

	push_share_stack(0, &stack, 5);

	push_share_stack(0, &stack, 7);
	print_share_stack(stack);

	push_share_stack(1, &stack, 2);

	push_share_stack(1, &stack, 4);

	print_share_stack(stack);
	int res;
	pop_share_stack(0, &stack, &res);

	print_share_stack(stack);
}

