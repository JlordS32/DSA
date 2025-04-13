BST tree;

   for (int i = 0; i < 10; i++)
   {
      tree.insert(i);
   }

   std::cout << tree.contains(3) << std::endl;