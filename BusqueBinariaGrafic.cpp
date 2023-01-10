/* **************************************************** *********************
* UFA - ESPE
*FECHA DE CREACION:15/12/2022
*FECHA DE MODIFICACION: 08/01/2023
* Nombres: Jefferson Guamaní, Kevin Coloma, Sergio Villalva
*NIVEL: NRC : 8000
* ENUNCIADO DEL PROBLEMA: Calculadora de notacion POLACA INVERSA
**************************************************** ******************* */
#include <iostream>

class Node {
 public:
  int data;
  Node* next;

  Node(int data, Node* next) : data(data), next(next) {}
};

class LinkedList {
 public:
  Node* head;

  LinkedList() : head(nullptr) {}

  void InsertionSort() {
    Node* sorted = nullptr;
    while (head != nullptr) {
      Node* current = head;
      head = head->next;
      if (sorted == nullptr || sorted->data >= current->data) {
        current->next = sorted;
        sorted = current;
      } else {
        Node* currentSorted = sorted;
        while (currentSorted->next != nullptr && currentSorted->next->data < current->data) {
          currentSorted = currentSorted->next;
        }
        current->next = currentSorted->next;
        currentSorted->next = current;
      }
    }
    head = sorted;
  }

  void DrawList() {
    Node* current = head;
    int i = 1;
    while (current != nullptr) {
      for (int j = 0; j < current->data; ++j) {
        std::cout << '*';
      }
      std::cout << '\n';
      current = current->next;
      ++i;
    }
  }
};

int main() {
  LinkedList list;
  int value;

  std::cout << "Ingrese numeros enteros (ingrese -1 para finalizar):\n ";
  std::cin >> value;
  while (value != -1) {
    list.head = new Node(value, list.head);
    std::cin >> value;
  }
  
    std::cout << "______________________________________________________________________________ ";
      std::cout << "Graficando la lista de numeros ingresada):\n ";
	  list.DrawList();
	        std::cout << "______________________________________________________________________________ ";
      std::cout << "Graficando la lista ordenada de numeros ingresada):\n ";
  list.InsertionSort();
  list.DrawList();

  return 0;
}
