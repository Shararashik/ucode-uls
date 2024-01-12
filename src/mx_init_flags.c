#include "../inc/uls.h"

flags_t* mx_init_flags(char **flags_str, int argc) {
    flags_t *flags = malloc(sizeof(flags_t));
    int index = 0;
    bool ind = false;
    for(int i = 0; i < argc; i++) {
        int minus = 0, count = 0;
        
        if (flags_str[i][0] != '-' && ind == false) {
            index = i;
            ind = true;
            //mx_printint(index);
            break;
        }
        
        for(int j = 0; j < mx_strlen(flags_str[i]); j++) {
            if (flags_str[i][j] == '-') {
                minus++;
                if (minus >= 3) {
                    //err
                    mx_flag_error(&flags, '-');
                }
            }        
        }
        //cycle in case we have 3 minuses       
        minus = 0;
        for(int j = 0; j < mx_strlen(flags_str[i]); j++) {
            count++;
            if (flags_str[i][j] == '-') {
                //check minus
                minus++;
            }
            if (minus > 1) {
                if (flags_str[i][j] == '-' && flags_str[i][j - 1] != '-') {
                    //err, 'cause try type ls -l-
                    mx_flag_error(&flags, '-');
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
                    flags->A = false;
                }       
                //all, with dots
                else if (flags_str[i][j] == 'A') { 
                    flags->A = true;
                    flags->a = false;
                } 
                //dots, exept . and ..             
                else if (flags_str[i][j] == 'G') { 
                    flags->G = true;
                }     
                //color flag
                else if (flags_str[i][j] == 'h') { 
                    flags->h = true;
                }        
                //bytes, kilobytes etc
                else if (flags_str[i][j] == '@') { 
                    flags->dog = true;
                }          
                //Display extended attribute keys and sizes
                //show something only with -l
                else if (flags_str[i][j] == 'e') { 
                    flags->e = true;
                }       
                //Print the Access Control List (ACL) associated with the file,
                // if present, in long (-l) output (???)
                // doesnt work on macOS, while tested. Skip?? // pizdish, vse work
                else if (flags_str[i][j] == 'T') { 
                    flags->T = true;
                }       
                //ONLY with -l, display
                //complete time information for the file, including month, day,
                //hour, minute, second, and year.
                else if (flags_str[i][j] == 'l') { 
                    flags->longf = true;
                    flags->one = false;
                } 
                //eto baza        
                else if (flags_str[i][j] == '1') { 
                    flags->one = true;
                    flags->longf = false;
                }            
                //output in column, priority high, cannot work with -l
                else if (flags_str[i][j] == 'C') { 
                    flags->C = true;
                }       
                //print in multi-column but this is already standart view
                //Useless flag, skip? Also doesn't work with -l, like -1
                else if (flags_str[i][j] == 'r') { 
                    flags->r = true;
                }      
                //reverse, priority low     
                else if (flags_str[i][j] == 't') { 
                    flags->t = true;
                }   
                //Sort by time modified
                else if (flags_str[i][j] == 'u') { 
                    flags->u = true;
                    flags->c = false;
                }             
                //Use time of last access(ACL?), instead of last modification of the file
                //work with -l and -t
                else if (flags_str[i][j] == 'c') { 
                    flags->c = true;
                    flags->u = false;
                }         
                //Use time when file status was last changed for sorting or printing
                //Show nothing while testing
                else if (flags_str[i][j] == 'S') { 
                    flags->S = true;
                } 
                //Sort files by size
                else {
                    mx_flag_error(&flags, flags_str[i][j]);
                }                                                                                                                                                                                            
            }
        }
    }
    //cycle for init_path
    if (ind) {
        flags->files_and_flags = true;
        for (int i = index; i < argc; i++)  {
            struct stat path_stat;
            if (stat(flags_str[i], &path_stat) == -1) {
                mx_file_error(flags_str[i]);
                //uls: xxx: No such file or directory
            }
            if(S_ISREG(path_stat.st_mode)) {
                mx_push_back(&flags->files, flags_str[i]);
            } else if(S_ISDIR(path_stat.st_mode)) {
                mx_push_back(&flags->folders, flags_str[i]);
            } else {
                mx_file_error(flags_str[i]);
            }

        }   
    } else {
        flags->files_and_flags = false;
        flags->files = false;
        flags->folders = false;
    } 
    flags->file_o = false;
    return flags;
}










