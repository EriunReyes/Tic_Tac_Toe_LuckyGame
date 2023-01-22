#include <iostream>
#include <random>
#include <vector>
#include <algorithm>


void TTT(){
    
    //vector created to add players letters & iterate their size 
    std::vector<char> tic_tac_toe = {'0','1','2','3','4','5','6','7','8'} ;

    //created to add the random numbers only if it is not already
    std::vector<int> addings_numbers ;

    //function to add the random numbers from specified range
    std::mt19937 rng(std::random_device{}()) ;

    std::uniform_int_distribution<int> dist(0, 8) ;

    int turns = 0 ;

    int player1 , player2 ;

    int points_player1 , points_player2 ;

    std::string result ;

    while (turns <= tic_tac_toe.size()) {

        int random_number = dist(rng) ;
        
        addings_numbers.push_back(random_number) ;


        if (std::find(addings_numbers.begin(), addings_numbers.end(), random_number) != addings_numbers.end()) {
            
            std::cout << std::endl ;

            std::cout << "Player1: Enter a number between 1 and 10: " ;

            std::cin >> player1 ;


            if (player1 > 10 || player1 < 0) {
                
                std::cout << "Player1 is out of range\n" ; break ; 

                }


            if ((player1 + random_number) % 2 == 0) {

                std::cout << "Player1 guessed it correctly\n" ;

                tic_tac_toe[turns] = 'X' ;

                turns++ ;
            }
            
            else {

                std::cout << " Player1 has gave a chance to player2 \n" ;

                tic_tac_toe[turns] = 'O' ;

                turns++;
            }

            std::cout << std::endl ;

            std::cout << " Player2: Enter a number between 1 and 10: " ;

            std::cin >> player2 ;


            if (player2 > 10 || player2 < 0) {

                std::cout << "Player2 is out of range\n" ; 

                break ;

            }


            if ((player2 + random_number) % 2 == 1) {

                std::cout << "Player2 guessed it correctly\n" ;

                tic_tac_toe[turns] = 'O' ;

                turns++ ;
            }

            else {

                std::cout << " Player2 has gave a chance to player1 \n" ;

                tic_tac_toe[turns] = 'X' ;

                turns++ ;
            }

        } else { 

            continue ; 
        
        }

        }
    std::cout << " -|" << tic_tac_toe[0] << " |--" << "-|" << tic_tac_toe[1] << " |--" << "-|" << tic_tac_toe[2] << " |- \n" ;

    std::cout << " -|" << tic_tac_toe[3] << " |--" << "-|" << tic_tac_toe[4] << " |--" << "-|" << tic_tac_toe[5] << " |- \n" ;
    
    std::cout << " -|" << tic_tac_toe[6] << " |--" << "-|" << tic_tac_toe[7] << " |--" << "-|" << tic_tac_toe[8] << " |- \n" ; 

    std::cout << std::endl ;

    for (int i = 0; i < tic_tac_toe.size(); i++) {

        if  (tic_tac_toe[i] == 'X') {

            points_player1 ++ ;

        }

        else {

            points_player2 ++ ;

        }
    }


    if (points_player1 != points_player2) {

        result = (points_player1 > points_player2) ? "player1 wins" : "player2 wins" ;

        std::cout <<  "player1 " << points_player1 << " ----- " <<  "player2 "<< points_player2 << std::endl ;

        std::cout << result << std::endl ;


    } else {

        std::cout << "Its a Tie!" << std::endl ;

        std::cout <<  "player1 " << points_player1 << " ----- " <<  "player2 "<< points_player2 << std::endl ;
    }

    std::cout << std::endl ;

}

int main() {

    TTT() ;

}