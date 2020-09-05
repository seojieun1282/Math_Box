#include <stdio.h>


typedef struct _TreeNode {
	char value;
	struct _TreeNode *left;
	struct _TreeNode *right;
}TreeNode;

void treeInOrder(TreeNode *root) { //중위순회 출력, 재귀함수로
	if (root) {
		treeInOrder(root->left);
		printf("%c", root->value);
		treeInOrder(root->right);
	}
}
TreeNode* searchNode(TreeNode *root, char value) { //노드를 검색하는 함수
	printf("root의 value : %c\n", root->value);
	printf("value : %c\n", value);
	if(root->left!=NULL)
		printf("root->left의 value : %c\n", root->left->value);
	if(root->right!=NULL)
		printf("root->right의 value : %c\n", root->right->value);
	
	//TreeNode* tmp = NULL;
	////전위순회로 찾기
	//if (root!=NULL && tmp==NULL) {
	//	if (root->value == value) tmp = root;
	//	else {
	//		searchNode(root->left, value);
	//		searchNode(root->right, value);
	//	}
	//}
	//TreeNode* tmp = NULL;
	////반복문
	//while (1) {
	//	
	//	if (root!=NULL) {
	//		if (root->value == value) return root;
	//		tmp = root->left;
	//		if (tmp->value == value) return tmp;
	//		tmp = root->right;
	//		if (tmp->value == value) return tmp;
	//		root = root->left;
	//	}
	//	if (root) {
	//		if (root->value == value) return root;
	//		tmp = root->left;
	//		if (tmp->value == value) return tmp;
	//		tmp = root->right;
	//		if (tmp->value == value) return tmp;
	//		root = root->left;
	//	}
	//}
	if (root!=NULL) {
		if (root->value == value) {
			root;
		}
		else {
			searchNode(root->left, value);
			searchNode(root->right, value);
		}
	}
	return root;
}
TreeNode* initNode(char value) {
	if (value != '.') {
		TreeNode* ptr = (TreeNode*)malloc(sizeof(TreeNode));
		ptr->left = NULL;
		ptr->right = NULL;
		ptr->value = value;
		return ptr;
	}
	else return NULL;
}
void createNode(TreeNode *parent, char value) { //자식노드 추가하기
	if (value != '.') {
		if (parent->left != NULL && parent->right != NULL) {
			printf("자식 노드가 꽉 찼습니다.\n");
		}
		else if (parent->left == NULL) {
			TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
			parent->left = newNode;
			newNode->left = NULL;
			newNode->right = NULL;
			newNode->value = value;
		}
		else if (parent->right == NULL) {
			TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
			parent->right = newNode;
			newNode->left = NULL;
			newNode->right = NULL;
			newNode->value = value;
		}
	}
}
int main() {
	int n;
	TreeNode* root = NULL;
	TreeNode* current = NULL;

	//입력
	scanf_s("%d", &n, 1);
	getchar();//버퍼 비우기

	for (int i = 0; i < n; i++) {
		char parent, leftChild, rightChild;
		scanf_s("%c %c %c", &parent,1, &leftChild,1, &rightChild,1);
		getchar();

		if(i==0)
			root = initNode(parent);
		current = searchNode(root, parent);
		createNode(current, leftChild);
		createNode(current, rightChild);
	}

	treeInOrder(root);

}