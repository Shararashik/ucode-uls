#include "uls.h"

flags_t* mx_init_flags(char **flags_str, int argc) {
    flags_t *flags = malloc(sizeof(flags_t));
    for(int i = 0; i < argc; i++) {
        int minus = 0, count = 0;
        for(int j = 0; j < mx_strlen(flags_str[i]); j++) {
            count++;
            //check minus
            if (flags_str[i][j] == '-') {
                minus++;
            }
            if (minus > 1) {
                if (flags_str[i][j] == '-' && flags_str[i][j - 1] != '-') {
                    //err, 'cause try type ls -l-
                    mx_printstr("err");
                }                
                if (minus >= 2 && flags_str[i][j - 1] == '-') {
                    break;
                }
                //NOT err but two minuses. just do nothing???
                //prob just do i+1 and move to next arg???
            }
            if (count > 1 && flags_str[i][0] == '-') {
                //if already second symbol and it's not minus do
                //init flag
                if (flags_str[i][j] == 'R') { 
                    flags->R = true;
                }
                else if (flags_str[i][j] == 'a') { 
                    flags->a = true;
                }       
                else if (flags_str[i][j] == 'A') { 
                    flags->A = true;
                }              
                else if (flags_str[i][j] == 'G') { 
                    flags->G = true;
                }     
                else if (flags_str[i][j] == 'h') { 
                    flags->h = true;
                }        
                else if (flags_str[i][j] == '@') { 
                    flags->dog = true;
                }          
                else if (flags_str[i][j] == 'e') { 
                    flags->e = true;
                }       
                else if (flags_str[i][j] == 'T') { 
                    flags->T = true;
                }       
                else if (flags_str[i][j] == 'l') { 
                    flags->l = true;
                }         
                else if (flags_str[i][j] == '1') { 
                    flags->one = true;
                }            
                else if (flags_str[i][j] == 'C') { 
                    flags->C = true;
                }       
                else if (flags_str[i][j] == 'r') { 
                    flags->r = true;
                }           
                else if (flags_str[i][j] == 't') { 
                    flags->t = true;
                }   
                else if (flags_str[i][j] == 'u') { 
                    flags->u = true;
                }             
                else if (flags_str[i][j] == 'c') { 
                    flags->c = true;
                }         
                if (flags_str[i][j] == 'S') { 
                    flags->S = true;
                }                                                                                                                                                                                             
            }
        }   
    }
    return flags;
}









