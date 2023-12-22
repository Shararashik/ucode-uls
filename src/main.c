#include "uls.h"

int main(int argc, char *argv[])
{
    char *flags_str[argc - 1];
    mx_get_flags(argc, argv, flags_str);
    
    flags_t *flags = mx_init_flags(flags_str, argc - 1);
    // for(int i = 0; i < argc - 1; i++) {
    //     mx_printstr(flags[i]);
    // }
    if (flags->R == 1) {
         mx_printstr("R worked");
    }
    // if (flags->a == 1) {
    //     mx_printstr("a worked");
    // }    
    // if (flags->A == 1) {
    //     mx_printstr("A worked");
    // }    
    // if (flags->h == 1) {
    //     mx_printstr("h worked");
    // }      
    // if (flags->G == 1) {
    //     mx_printstr("G worked");
    // }    
    // if (flags->dog == 1) {
    //     mx_printstr("@ worked");
    // }      
    // if (flags->e == 1) {
    //     mx_printstr("e worked");
    // }       
    // if (flags->T == 1) {
    //     mx_printstr("T worked");
    // }   
    //if (flags->longf == 1) {
    //     mx_printstr("l worked");
    //}       
    // if (flags->one == 1) {
    //     mx_printstr("1 worked");
    // }     
    // if (flags->C == 1) {
    //     mx_printstr("C worked");
    // }         
    // if (flags->r == 1) {
    //     mx_printstr("r worked");
    // }               
    // if (flags->t == 1) {
    //     mx_printstr("t worked");
    // }        
    // if (flags->u == 1) {
    //     mx_printstr("u worked");
    // }     
    // if (flags->c == 1) {
    //     mx_printstr("c worked");
    // }         
    // if (flags->S == 1) {
    //     mx_printstr("S worked");
    // }
    //mx_simple_output();   
    mx_output_with_flag_one();

    return 0;
}

