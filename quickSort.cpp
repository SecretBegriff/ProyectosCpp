#include <iostream>

using namespace std;

void swap(int &a, int &b){      //Esta funcion intercambia dos valores
                                //Se ponen con & para que no se modifiquen copias sino los valores og
    int temp = a;               //creamos un temporal para guardar a
    a = b;                      //a se convierte en b
    b = temp;                   //b se convierte en el a original
}

int partition(int arr[], int low, int high){
    int pivot = arr[high];                  //Se crea el pivote tomando el ultimo elemento del arr

    int i = low - 1;                        //Se apunta al primer elemento del arr menos 1

    for(int j = low; j < high; j++){        //Se recorre todo el arreglo comparando con el pivote
        if(arr[j] <= pivot){                //Si la comparacion es menor o igual al pivote...
            i++;                            //Primero se mueve el apuntador a la derecha
            swap(arr[i], arr[j]);           //Como el valor es menor que el pivote debe ir a la izquierda
                                            //Por lo que se llama a swap
        }
                                            //Si el valor es mayor no se hace nada
    }

    swap(arr[i+1], arr[high]);              //Por ultimo intercambiamos el pivote que esta al final
                                            //A la derecha del apuntador que es el ultimo valor mas
                                            //Pequeño que el pivote
    return i+1;                             //Y retornamos la posicion del pivote para futuros QS
}

void quickSort(int arr[], int low, int high){     //primero se llama a QS
    if(low < high){                              //verifica que haya mas de un elemento
        int pi = partition (arr, low, high);     //pi servira para definir el inicio y final de los subarreglos
                                                 //Ademas de que se manda a llama la funcion de particion
        quickSort(arr, low, pi-1);               //Se ordena la parte izquierda del pivote
        quickSort(arr, pi+1, high);              //Se ordena la parte derecha del pivote
    }
}

int main() {
  int n;                                //aqui declaramos el tamaño de arreglo
  std::cin>>n;                               //ingresamor tamaño
  int juguetes[n];
  for(int i = 0; i < n; i++){
    std::cin >> juguetes[i];                 //creamos e ingresamos arreglo
  }

  for(int i = 0; i < n; i++){           //imprimimos version og de arr
    std::cout << juguetes[i];
    std::cout << " ";
  }
  std::cout << endl;

  quickSort(juguetes, 0, n);            //llamamos al QS

  for(int i = 0; i < n; i++){           
    std::cout << juguetes[i];                //imprimimos arr ordenado
    std::cout << " ";
  }
  std::cout << endl;

  

  return 0;
}