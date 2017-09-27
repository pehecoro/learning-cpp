#include <iostream>
#include <string>
#include <memory>

/*
	Binary Search Tree
*/

template <typename T>
struct Tree{
	T content;
	unsigned int key;
	std::shared_ptr<Tree<T>> lhs, rhs;
	Tree<T>(const T& _content, const unsigned int& _key) : key(_key), content(_content), lhs(nullptr), rhs(nullptr){}
};

template <typename T>
void insert(const std::shared_ptr<Tree<T>>& tree, const Tree<T>& newTree) {
	if (tree == nullptr) {
		tree->lhs = std::make_shared<Tree<T>>(newTree.content, newTree.key);
	}
	else {
		if (newTree.key < tree->key) {
			if (tree->lhs == nullptr) {
				tree->lhs = std::make_shared<Tree<T>>(newTree.content, newTree.key);
			}
			else {
				insert(tree->lhs, newTree);
			}
		}
		else if (newTree.key > tree->key) {
			if (tree->rhs == nullptr) {
				tree->rhs = std::make_shared<Tree<T>>(newTree.content, newTree.key);
			}
			else {
				insert(tree->rhs, newTree);
			}
		}
	}
}

template <typename T>
void showTreesInOrder(const std::shared_ptr<Tree<T>>& tree) {
	if (tree != nullptr){
		showTreesInOrder(tree->lhs);
		std::cout << "(" << tree->key << ")Content: " << tree->content;
		showTreesInOrder(tree->rhs);
	}
}

template <typename T>
void showTreesPreOrder(const std::shared_ptr<Tree<T>>& tree) {
	if (tree != nullptr) {
		std::cout << "(" << tree->key << ")";
		showTreesPreOrder(tree->lhs);
		showTreesPreOrder(tree->rhs);
	}
}

template <typename T>
void showTreesPostOrder(const std::shared_ptr<Tree<T>>& tree) {
	if (tree != nullptr) {
		showTreesPostOrder(tree->lhs);
		showTreesPostOrder(tree->rhs);
		std::cout << "(" << tree->key << ")";
	}
}

template <typename T>
const std::shared_ptr<Tree<T>> searchTree(std::shared_ptr<Tree<T>> tree, const unsigned int& key) {
	while (tree != nullptr) {
		if (tree->key == key)return tree;
		tree = ((key < tree->key) ? tree->lhs : tree->rhs);
	}
	return nullptr;
}

template <typename T>
std::shared_ptr<Tree<T>> minKey(std::shared_ptr<Tree<T>> tree) {
	while (tree->lhs != nullptr) {
		tree = tree->lhs;
	}
	return tree;
}

template <typename T>
std::shared_ptr<Tree<T>> removeTree(std::shared_ptr<Tree<T>>& tree, const unsigned int& key) {
	if (tree != nullptr) {
		if (key < tree->key) {
			tree->lhs = removeTree(tree->lhs, key);
		}
		else if (key > tree->key) {
			tree->rhs = removeTree(tree->rhs, key);
		}
		else {
			if (tree->lhs == nullptr) {
				tree = tree->rhs;
				return tree;
			}
			else if (tree->rhs == nullptr) {
				tree = tree->lhs;
				return tree;
			}
		
			//inorder sucessor
			std::shared_ptr<Tree<T>> aux = minKey(tree->rhs);
			tree->key = aux->key;
			tree->content = aux->content;
			tree->rhs = removeTree(tree->rhs, aux->key);
		}
	}
	return tree;
}


int main(){

	std::shared_ptr<Tree<std::string>> root = std::make_shared<Tree<std::string>>("fight",50);
	insert(root, Tree<std::string>("This", 10));
	insert(root, Tree<std::string>("sy", 90));
	insert(root, Tree<std::string>("o>", 70));
	insert(root, Tree<std::string>("my", 30));
	insert(root, Tree<std::string>("is", 20));
	insert(root, Tree<std::string>("song", 60));
	std::cout << "In-order" << std::endl;
	showTreesInOrder(root);

	const int rem1 = 70, rem2 = 10, rem3 = 50;

	std::cout << "\n+------Removing " << rem1 << "------+"  << std::endl;
	root = removeTree(root, rem1);
	std::cout << "In-order" << std::endl;
	showTreesInOrder(root);

	std::cout << "\n+------Removing " << rem2 << "------+" << std::endl;
	root = removeTree(root, rem2);
	std::cout << "In-order" << std::endl;
	showTreesInOrder(root);

	std::cout << "\n+------Removing " << rem3 << "------+" << std::endl;
	root = removeTree(root, rem3);
	std::cout << "In-order" << std::endl;
	showTreesInOrder(root);
	std::cout << "\nPre-order" << std::endl;
	showTreesPreOrder(root);
	std::cout << "\nPost-order" << std::endl;
	showTreesPostOrder(root);



	std::cin.get();
}