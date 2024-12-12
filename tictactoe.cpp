#include <iostream>
#include <vector>
using namespace std;

#define DEFAULT 3
bool turno = true;//verdadero -> jugador : falsa -> minimax
int modo;

struct Movimiento{
  int i,j;
};

void dibujarTablero(const vector<vector<char>> &tablero) {
    cout << "\n  0   1   2\n";
    for (int i = 0; i < 3; ++i) {
        cout << i << " ";
        for (int j = 0; j < 3; ++j) {
            cout << tablero[i][j];
            if (j < 2) cout << " | ";
        }
        cout << "\n";
        if (i < 2) cout << " ---+---+---\n";
    }
    cout << endl;
}

bool valida(int i, int j){
  if(i>=0 && i<=2 && j>=0 && j<=2){
  	return true;
  }
  return false;
}

//evalue tablero: int -> regresar -algo si gana minimax algo si gana jugador regresar 0 si es empate y regresar default = 3

int evaluarTablero(vector<vector<char>> &tablero, int dif){
  	for (int i = 0; i < 3; i++) {
        if (tablero[i][0] == 'X' && tablero[i][1] == 'X' && tablero[i][2] == 'X') {
            return 10;
        }

        if (tablero[0][i] == 'X' && tablero[1][i] == 'X' && tablero[2][i] == 'X') {
            return 10;
        }
    }
    for (int i = 0; i < 3; i++) {
        if (tablero[i][0] == 'O' && tablero[i][1] == 'O' && tablero[i][2] == 'O') {
            return -10;
        }

        if (tablero[0][i] == 'O' && tablero[1][i] == 'O' && tablero[2][i] == 'O') {
            return -10;
        }
    }

    if ((tablero[0][0] == 'X' && tablero[1][1] == 'X' && tablero[2][2] == 'X') || 
        (tablero[0][2] == 'X' && tablero[1][1] == 'X' && tablero[2][0] == 'X')) {
        return 10;
    }

	else if ((tablero[0][0] == 'O' && tablero[1][1] == 'O' && tablero[2][2] == 'O') || 
        (tablero[0][2] == 'O' && tablero[1][1] == 'O' && tablero[2][0] == 'O')) {
        return -10;
    }
    
  	bool empate = true;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (tablero[i][j] == ' ') {
                empate = false;
            }
        }
    }
    if (empate){
        return 0;
    } 
    else{
      	if(dif == 1){
          for (int i = 0; i < 3; ++i) {
		        for (int j = 0; j < 2; ++j) {
		            if (tablero[i][j] == 'O' && tablero[i][j + 1] == 'O') {
		                if (j + 2 < 3 && tablero[i][j + 2] == ' ') return 10;  
		                if (j - 1 >= 0 && tablero[i][j - 1] == ' ') return 10; 
		            }
		            if (tablero[i][j] == 'X' && tablero[i][j + 1] == 'X') {
		                if (j + 2 < 3 && tablero[i][j + 2] == ' ') return -10;
		                if (j - 1 >= 0 && tablero[i][j - 1] == ' ') return -10; 
		            }
		        }
		    }
		
		    for (int j = 0; j < 3; ++j) {
		        for (int i = 0; i < 2; ++i) {
		            if (tablero[i][j] == 'O' && tablero[i + 1][j] == 'O') {
		                if (i + 2 < 3 && tablero[i + 2][j] == ' ') return 10;  
		                if (i - 1 >= 0 && tablero[i - 1][j] == ' ') return 10; 
		            }
		            if (tablero[i][j] == 'X' && tablero[i + 1][j] == 'X') {
		                if (i + 2 < 3 && tablero[i + 2][j] == ' ') return -10; 
		                if (i - 1 >= 0 && tablero[i - 1][j] == ' ') return -10; 
		            }
		        }
		    }
		
			if(tablero[0][0] == 'O' && tablero[0][0] == tablero[1][1]){
				return -11;
			}
			else if(tablero[1][1] == 'O' && tablero[2][2] == tablero[1][1]){
				return -11;
			}
			
			if(tablero[0][0] == 'X' && tablero[0][0] == tablero[1][1]){
				return 11;
			}
			else if(tablero[1][1] == 'X' && tablero[2][2] == tablero[1][1]){
				return 11;
			}
			
			if(tablero[0][2] == 'O' && tablero[0][2] == tablero[1][1]){
				return -11;
			}
			else if(tablero[1][1] == 'O' && tablero[2][0] == tablero[1][1]){
				return -11;
			}
			
			if(tablero[0][2] == 'X' && tablero[0][2] == tablero[1][1]){
				return 11;
			}
			else if(tablero[1][1] == 'X' && tablero[2][0] == tablero[1][1]){
				return 11;
			}
		
		
		
		    return 0; 
        }     
			
    	else if(dif == 2){
        
         if((tablero[1][1] == 'X')){
	          return 10;
	        }
	        else if(tablero[1][1] == 'O'){
	          return -10;
	        }
	        else{
	          return 0;
	        }
      	}
      
	    
		return DEFAULT;
	     
    }
}

int miniMaxM(vector<vector<char>> &tablero, bool turno, int nivel){
  int estado = evaluarTablero(tablero, 2);
  
  if(estado != DEFAULT || nivel == 5){
    return estado;
  }
  int valorTope;
  if(turno){
    valorTope = -1000;
  }
  else{
    valorTope = 1000;
  }
  
  for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
          if(tablero[i][j] == ' '){
            if(turno){
              tablero[i][j] = 'X';
            }
            else{
              tablero[i][j] = 'O';
            }
            
            int valorMov = miniMaxM(tablero, !turno, nivel+1);
            tablero[i][j] = ' ';
            
            if(turno){
              if(valorMov > valorTope){
                valorTope = valorMov;
              }
            }
            else{
              if(valorMov < valorTope){
                valorTope = valorMov;
              }
            }
          }
      }
  }
  return valorTope;
}

int miniMaxF(vector<vector<char>> &tablero, bool turno, int nivel){
  int estado = evaluarTablero(tablero, 1);
  
  if(estado != DEFAULT || nivel == 3){
    return estado;
  }
  int valorTope;
  if(turno){
    valorTope = -1000;
  }
  else{
    valorTope = 1000;
  }
  
  for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
          if(tablero[i][j] == ' '){
            if(turno){
              tablero[i][j] = 'X';
            }
            else{
              tablero[i][j] = 'O';
            }
            
            int valorMov = miniMaxF(tablero, !turno, nivel+1);
            tablero[i][j] = ' ';
            
            if(turno){
              if(valorMov > valorTope){
                valorTope = valorMov;
              }
            }
            else{
              if(valorMov < valorTope){
                valorTope = valorMov;
              }
            }
          }
      }
  }
  return valorTope;
}

int miniMax(vector<vector<char>> &tablero, bool turno){
  int estado = evaluarTablero(tablero, 3);
  
  if(estado == 0 || estado == -10 || estado == 10){
    return estado;
  }
  int valorTope;
  if(turno){
    valorTope = -1000;
  }
  else{
    valorTope = 1000;
  }
  
  for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
          if(tablero[i][j] == ' '){
            if(turno){
              tablero[i][j] = 'X';
            }
            else{
              tablero[i][j] = 'O';
            }
            
            int valorMov = miniMax(tablero, !turno);
            tablero[i][j] = ' ';
            
            if(turno){
              if(valorMov > valorTope){
                valorTope = valorMov;
              }
            }
            else{
              if(valorMov < valorTope){
                valorTope = valorMov;
              }
            }
          }
      }
  }
  return valorTope;
}


//Mejor Jugada: Movimiento
Movimiento jugadaOptima(vector<vector<char>> &tablero){
  Movimiento mov;
  
	if(modo == 1){//Modo Facil
	    int valorTope = 1000;
	    for (int i = 0; i < 3; i++) {
	        for (int j = 0; j < 3; j++) {
	            if (tablero[i][j] == ' ') {
	                  tablero[i][j] = 'O';
	                  int valorMov = miniMaxF(tablero, !turno, 0);
	                  tablero[i][j] = ' ';
	
	                  if (valorTope > valorMov) {
	                      valorTope = valorMov;
	                      mov.i = i;
	                      mov.j = j;
	                  }
	            }
	        }
	     }
	}
	  
  	else if(modo == 2){//Modo Medio
    	int valorTope = 1000;
          for (int i = 0; i < 3; i++) {
              for (int j = 0; j < 3; j++) {
                  if (tablero[i][j] == ' ') {
                      tablero[i][j] = 'O';
                      int valorMov = miniMaxM(tablero, !turno, 0);
                      tablero[i][j] = ' ';

                      if (valorTope > valorMov) {
                          valorTope = valorMov;
                          mov.i = i;
                          mov.j = j;
                      }
                  }
              }
          }
      
    } 
	else { // Modo difícil
          int valorTope = 1000;
          for (int i = 0; i < 3; i++) {
              for (int j = 0; j < 3; j++) {
                  if (tablero[i][j] == ' ') {
                      tablero[i][j] = 'O';
                      int valorMov = miniMax(tablero, !turno);
                      tablero[i][j] = ' ';

                      if (valorTope > valorMov) {
                          valorTope = valorMov;
                          mov.i = i;
                          mov.j = j;
                      }
                  }
              }
          }
    }
    return mov;
}


int main() {
    vector<vector<char>> tablero(3, vector<char>(3, ' '));
    char usuario = 'X';
    char ia = 'O';
    int fila, columna;

    cout << "Bienvenido al Juego de Gato!\n";
    cout << "Selecciona el nivel de dificultad (1: Fácil, 2: Medio, 3: Difícil) ";
    cin >> modo;


    dibujarTablero(tablero);

    while (true) {
        if (turno) {
            // Turno del jugador
            cout << "Ingresa las coordenadas para colocar tu " << usuario << ":\n";
            cout << "X Y: ";
            cin >> fila;
            cout << "Columna (0-2): ";
            cin >> columna;

            if (fila < 0 || fila > 2 || columna < 0 || columna > 2) {
                cout << "Coordenadas fuera de rango. Intenta de nuevo.\n";
                continue;
            }

            if (tablero[fila][columna] != ' ') {
                cout << "Celda ocupada. Intenta de nuevo.\n";
                continue;
            }

            tablero[fila][columna] = usuario;
        } else {
            // Turno de la IA
            cout << "Turno de la IA (" << ia << "):\n";
            Movimiento mov = jugadaOptima(tablero);
            tablero[mov.i][mov.j] = ia;
        }

        // Dibujar el tablero actualizado
        dibujarTablero(tablero);

        // Evaluar el estado del juego
        int estado = evaluarTablero(tablero, 3);
        if (estado == 10) {
            cout << "¡Felicidades! Ganaste.\n";
            break;
        } else if (estado == -10) {
            cout << "La IA ha ganado. ¡Suerte la próxima vez!\n";
            break;
        } else if (estado == 0) {
            cout << "Es un empate.\n";
            break;
        }

        // Cambiar turno
        turno = !turno;
    }

    return 0;
}
