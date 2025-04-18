#include <iostream>

template <typename T>
class Node
{
private:
   T data;
   Node *next;

   template <typename>
   friend class LinkedList;

public:
   Node() : next(nullptr) {}
   Node(T data) : data(data), next(nullptr) {}
};

template <typename T>
class LinkedList
{
private:
   Node<T> *head;
   Node<T> *tail;

   void destroy()
   {
      Node<T> *current = head;
      while (current != nullptr)
      {
         Node<T> *next = current->next;
         delete current;
         current = next;
      }
      head = tail = nullptr;
   }

public:
   LinkedList() : head(nullptr), tail(nullptr) {}
   LinkedList(T data) : head(new Node<T>(data)), tail(nullptr) {}
   LinkedList(std::initializer_list<T> list) : head(nullptr), tail(nullptr)
   {
      for (T data : list)
      {
         insert(data);
      }
   }

   ~LinkedList()
   {
      destroy();
   }

   void insert(T data)
   {
      Node<T> *newNode = new Node<T>(data);
      if (head == nullptr)
      {
         head = tail = newNode;
      }
      else
      {
         tail->next = newNode;
         tail = newNode;
      }
   }

   void erase(T data)
   {
      Node<T> *current = head;
      Node<T> *previous = nullptr;

      while (current != nullptr)
      {
         if (current->data == data)
         {
            if (previous == nullptr)
            {
               head = current->next;
            }
            else
            {
               previous->next = current->next;
            }
            delete current;
            break;
         }

         previous = current;
         current = current->next;
      }

      if (head == nullptr)
         tail = nullptr;
   }

   bool contains(T data)
   {
      return find(data) != end();
   }

   // ---------------------------
   // ITERATOR SUPPORT
   // ---------------------------
   class Iterator
   {
   private:
      Node<T> *current;

   public:
      Iterator(Node<T> *node) : current(node) {}

      T &operator*() { return current->data; }
      Iterator &operator++()
      {
         current = current->next;
         return *this;
      }
      bool operator==(const Iterator &other) const { return current == other.current; }
      bool operator!=(const Iterator &other) const { return current != other.current; }
      Node<T> *get() const { return current; }
   };

   Iterator begin() { return Iterator(head); }
   Iterator end() { return Iterator(nullptr); }

   Iterator find(T data)
   {
      for (Iterator it = begin(); it != end(); ++it)
      {
         if (*it == data)
            return it;
      }
      return end();
   }

   void print()
   {
      Node<T> *current = head;
      while (current != nullptr)
      {
         std::cout << current->data << " ";
         current = current->next;
      }
      std::cout << std::endl;
   }

   // ----------------------------
   // OPERATOR OVERLOADS
   // ----------------------------
   T &operator[](std::size_t index)
   {
      Node<T> *current = head;
      for (std::size_t i = 0; i < index; i++)
      {
         current = current->next;
      }
      return current->data;
   }

   LinkedList<T> &operator=(const LinkedList<T> &other)
   {
      if (this != &other)
      {
         destroy();

         // Copying process
         head = nullptr;
         Node<T> *current = other.head;
         while (current != nullptr)
         {
            insert(current->data);
            current = current->next;
         }
      }

      return *this;
   }
};

int main()
{
   // Testing integers
   LinkedList<int> list;
   list.insert(1);
   list.insert(2);
   list.insert(3);
   list.print();

   list.erase(2);
   list.print();

   // Testing strings
   LinkedList<std::string> listString;
   listString.insert("Hello");
   listString.insert("World");

   listString.print();
   listString.erase("World");
   listString.print();

   // Testing initializer list
   LinkedList<int> list2 = {1, 2, 3, 4, 5};
   list2.print();

   // Testing operator=;
   LinkedList<int> list3 = list2;
   list3.print();

   // Testing operator[]
   std::cout << list3[2] << std::endl;

   // Testing Iterator;
   std::cout << *(list3.begin()) << std::endl;

   // Testing traversal
   for (auto it = list3.begin(); it != list3.end(); ++it)
      std::cout << *it << ", ";

   std::cout << *(list3.find(3)) << std::endl;
   std::cout << list3.contains(3) << std::endl;

   return 0;
}