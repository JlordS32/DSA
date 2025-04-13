#include <iostream>

class Node
{
private:
   int value;
   Node *left;
   Node *right;

   friend class BST;

public:
   Node(int value) : value(value), left(nullptr), right(nullptr) {}
};

class BST
{
private:
   Node *root;

   Node *successor(Node *node)
   {
      if (!node)
         return nullptr;

      // Case 1: Node has a right child
      if (node->right)
      {
         Node *curr = node->right;
         while (curr->left)
            curr = curr->left;

         return curr;
      }

      // Case 2: Node has no right child

      Node *succ = nullptr;
      Node *curr = root;
      while (curr && curr != node)
      {
         if (node->value < curr->value)
         {
            succ = curr;
            curr = curr->left;
         }
         else
            curr = curr->right;
      }

      return succ;
   }

public:
   BST() : root(nullptr) {}

   void insert(int value)
   {
      Node *tmp;

      if (root == nullptr)
         root = new Node(value);
      else
      {
         tmp = root;
         while (true)
         {
            if (value < tmp->value)
            {
               if (tmp->left == nullptr)
               {
                  tmp->left = new Node(value);
                  break;
               }
               else
                  tmp = tmp->left;
            }
            else
            {
               if (tmp->right == nullptr)
               {
                  tmp->right = new Node(value);
                  break;
               }
               else
                  tmp = tmp->right;
            }
         }
      }
   }

   bool contains(int value)
   {
      return find(root, value) != nullptr;
   }

   Node *find(Node *root, int key)
   {
      while (root)
      {
         if (key < root->value)
            root = root->left;
         else if (key > root->value)
            root = root->right;
         else
            return root;
      }
      return nullptr;
   }

   void remove(Node *&root, int key)
   {
      Node *target = find(root, key);
      if (!target)
         return;

      // Case 1: No children
      if (!target->left && !target->right)
      {
         if (root == target)
            root = nullptr;
         delete target;
         return;
      }

      // Case 2: One child
      if (!target->left || !target->right)
      {
         Node *child = target->left ? target->left : target->right;
         if (root == target)
            root = child;
         else
         {
            Node *parent = root;

            // Find parent
            while (parent->left != target && parent->right != target)
               parent = (key < parent->value) ? parent->left : parent->right;

            if (parent->left == target)
               parent->left = child;
            else
               parent->right = child;
         }
         delete target;
         return;
      }

      // Case 3: Two children
      Node *succ = successor(target);
      target->value = succ->value;
      remove(target->right, succ->value);
   }

   void remove(int key) { remove(root, key); }
};

int main()
{
   BST tree;

   for (int i = 0; i < 10; i++) {
      tree.insert(i);
   }

   std::cout << tree.contains(3) << std::endl;
   std::cout << tree.contains(1) << std::endl;
   std::cout << tree.contains(2) << std::endl;
   std::cout << tree.contains(4) << std::endl;

   tree.remove(3);
   tree.remove(1);
   tree.remove(2);
   tree.remove(4);

   std::cout << tree.contains(3) << std::endl;
   std::cout << tree.contains(1) << std::endl;
   std::cout << tree.contains(2) << std::endl;
   std::cout << tree.contains(4) << std::endl;

   return 0;
}