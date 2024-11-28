// В этом файле определения функций.
// За основу возьмите решение предыдущей задачи.
#include <iostream>
#include <string>
#include <cmath>
#include "calculator.h"

using Number = double;

bool ReadNumber(Number& result){
    std::cin >> result;
    if (std::cin.fail()){
        std::cerr << "Error: Numeric operand expected";
        return false;
    }   
    return true;
}

bool RunCalculatorCycle(){
    Number first_number = 0;
    Number second_numbe = 0;
    double memory_cell = 0;
    std::string sign;
    bool remember = false;
    bool inf = false;
    if (ReadNumber(first_number)){
   
        while (sign != "q"){
            std::cin >> sign;
            
            if (sign == "+"){

                if (ReadNumber(second_numbe)){
                    first_number += second_numbe;
                }
                else{
                    return false;
                }
            }
            
            else if (sign == "-"){

                if (ReadNumber(second_numbe)){
                    first_number -= second_numbe;
                }
                else{
                    return false;
                }
            }
            
            else if (sign == "*"){
 
               if (ReadNumber(second_numbe)){
                    first_number *= second_numbe;
                }
                else{
                    return false;
                }
            }
            
            else if (sign == "/"){
                
                if (ReadNumber(second_numbe)){
                    if (second_numbe == 0){
                        inf = true;
                    }
                    first_number /= second_numbe;
                }
                else{
                    return false;
                }
            }
            
            else if (sign == "**"){
                
                if (ReadNumber(second_numbe)){
                    first_number = pow(first_number, second_numbe);
                }
                else{
                    return false;
                }
            }
            
            else if (sign == ":"){
                
                if (ReadNumber(second_numbe)){
                    first_number = second_numbe;
                    inf = false;
                }
                else{
                    return false;
                }
            }
            
            else if (sign == "c"){
                first_number = 0;
            }
            
            else if (sign == "="){
                
                if (inf){
                    std::cout << "inf" << std::endl;
                }
                
                else{
                std::cout << first_number << std::endl;
                }
            }
            
            else if (sign == "q"){
                return true;
                break;
            }   
            else if (sign == "s"){
                memory_cell = first_number;
                remember = true;
            }
            
            else if (sign == "l"){
                if (remember){
                   first_number = memory_cell;
                }
                else{
                    std::cerr << "Error: Memory is empty";
                    break;
                }
            }
            
            else{
                std::cerr << "Error: Unknown token " << sign;
                return false;
                break;
            }
        }
    }
    return false;
}
